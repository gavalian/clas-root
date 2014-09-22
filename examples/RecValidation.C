/**
 * Example script for reading Evio files from ROOT/CINT.
 * Author: G.Gavalian
 */
{
  /**
   * Loading shared library of evio-root package.
   */
  gSystem->Load("../lib/libEvioRoot.so");
  //gSystem->SetOptStat(11111);
  //gSystem->SetFitStat(11111);

  /**
   * TEvioFileReader - interface to EVIO file. reads events in sequence from one file.
   *                   To chain several files use TEvioDataSource class.
   * TEvioDataEvent - class for holding the EVIO structure on one event. it is initialized
   *                  in the TEvioFileReader (with getEvent(event) method). But also can 
   *                  be used separately with it's constructor TEvioDataEvent(uint32_t *b, int len)
   */
  TEvioFileReader reader;
  TEvioDataEvent  event;

  reader.open("rec_output.evio");

  /**
   * Declare ROOT histograms for ADC and TDC values.
   */
  int icounter = 0;

  TH1F  *H1_PRES   = new TH1F("H1_PRES","",100,-1.5,1.5);
  TH2F  *H1_PRES_VS_P   = new TH2F("H1_PRES_VS_P","",100,0.0,5.0,100,-1.5,1.5);

  TH1F  *H1_MASS   = new TH1F("H1_MASS","",100,-0.5,1.4);
  TH1F  *H1_MULT   = new TH1F("H1_MULT","",100,-0.5,6.5);
  TH2F  *H1_M_VS_P = new TH2F("H1_M_VS_P","",100,0.0,5.2,100,-0.5,1.4);
  TH2F  *H1_B_VS_P = new TH2F("H1_B_VS_P","",100,0.0,5.2,100,0.4,1.2);

  double Chi2Range = 30.0;

  TH1F  *H1_CHI2SC   = new TH1F("H1_SCI2SC","",100,-Chi2Range,Chi2Range);
  TH1F  *H1_CHI2PC   = new TH1F("H1_SCI2PC","",100,-Chi2Range,Chi2Range);
  TH1F  *H1_CHI2EI   = new TH1F("H1_SCI2EI","",100,-Chi2Range,Chi2Range);
  TH1F  *H1_CHI2EO   = new TH1F("H1_SCI2EO","",100,-Chi2Range,Chi2Range);
  /**
   * Loop over the events in the file. reader.next() returns false
   * when the end of file is reached.
   */
  while( reader.next() == true ){
  //for(int nev = 0; nev < 300; nev++){
    //reader.next();
    icounter++;
    if(icounter%100==0) cout << "-------> processed " << icounter << endl;
    /**
     * initilize the event with the current buffer read from the file.
     */
    reader.getEvent(event);

    TArrayF mass = event.getFloatArray(4501,4);
    TArrayF beta = event.getFloatArray(4501,5);
    TArrayF scpath = event.getFloatArray(4501,16);
    TArrayF sctime = event.getFloatArray(4501,17);
    TArrayF px   = event.getFloatArray(4501,13);
    TArrayF py   = event.getFloatArray(4501,14);
    TArrayF pz   = event.getFloatArray(4501,15);

    TArrayD pxg  = event.getDoubleArray(20,2);
    TArrayD pyg  = event.getDoubleArray(20,3);
    TArrayD pzg  = event.getDoubleArray(20,4);
    TVector3  pvecg(pxg.At(0)/1000.0,pyg.At(0)/1000.0,pzg.At(0)/1000.0);

    TArrayF chi2sc     = event.getFloatArray(4501,21);
    TArrayF chi2pcal   = event.getFloatArray(4501,25);
    TArrayF chi2ecin   = event.getFloatArray(4501,29);
    TArrayF chi2ecout  = event.getFloatArray(4501,29);
    int multCounter = 0;
    if(mass.GetSize()>0){
      for(int loop = 0; loop < mass.GetSize(); loop++){
	TVector3  pvec(px.At(loop),py.At(loop),pz.At(loop));

	//cout << pvecg.Mag() << " mom = " << pvec.Mag() << endl;
	//cout << " counter = " << icounter << "  mom = "  << pvecg.Mag() << endl;
	H1_PRES.Fill((pvec.Mag()-pvecg.Mag())/pvecg.Mag());
	H1_PRES_VS_P.Fill(pvecg.Mag(),(pvec.Mag()-pvecg.Mag())/pvecg.Mag());
	if(sctime.At(loop)>0.01 && scpath.At(loop)>10.0){
	  H1_MASS->Fill(mass.At(loop));
	  H1_M_VS_P->Fill(pvecg.Mag(),mass.At(loop));
	  multCounter++;
	}
	//cout << "entry = " << loop << "  mass = " << mass.At(loop) << "  time = " << sctime.At(loop) 
	//<< " path = " << scpath.At(loop) << endl;
	//cout << "entry = " << loop << "  mom = " << pvec.Mag() << "  beta = " << beta.At(loop) << endl;
	H1_B_VS_P->Fill(pvec.Mag(),beta.At(loop));

	if(pvec.Phi()>=0.0){
	  H1_CHI2SC.Fill(chi2sc.At(loop));
	  H1_CHI2PC.Fill(chi2pcal.At(loop));
	  H1_CHI2EI.Fill(chi2ecin.At(loop));
	  H1_CHI2EO.Fill(chi2ecout.At(loop));
	} else {
	  H1_CHI2SC.Fill(-chi2sc.At(loop));
          H1_CHI2PC.Fill(-chi2pcal.At(loop));
          H1_CHI2EI.Fill(-chi2ecin.At(loop));
          H1_CHI2EO.Fill(-chi2ecout.At(loop));
	}
      }
    }
    H1_MULT->Fill(multCounter);
  }
  
  cout << " Events in the FILE = " << icounter << endl;
  reader.close();
  /**
   * Draw histograms on ROOT canvas.
   */

  TCanvas *c1 = new TCanvas("c1","",800,700);
  c1->Divide(2,2);
  c1->cd(1);
  H1_MASS->Draw();
  c1->cd(2);
  H1_B_VS_P->Draw("box");
  c1->cd(3);
  //H1_PRES->Draw();
  H1_MULT->Draw();
  c1->cd(4);
  H1_M_VS_P->Draw();

  TCanvas *c2 = new TCanvas("c2","",800,700);
  c2->Divide(2,2);
  c2->cd(1);
  H1_CHI2SC->Draw();
  c2->cd(2);
  H1_CHI2PC->Draw();
  c2->cd(3);
  H1_CHI2EI->Draw();
  c2->cd(4);
  H1_CHI2EO->Draw();
}

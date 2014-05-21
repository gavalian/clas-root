/**
 * Example script for reading Evio files from ROOT/CINT.
 * Author: G.Gavalian
 */
{
  /**
   * Loading shared library of evio-root package.
   */
  gSystem->Load("../lib/libEvioRoot.so");
  
  /**
   * TEvioFileReader - interface to EVIO file. reads events in sequence from one file.
   *                   To chain several files use TEvioDataSource class.
   * TEvioDataEvent - class for holding the EVIO structure on one event. it is initialized
   *                  in the TEvioFileReader (with getEvent(event) method). But also can 
   *                  be used separately with it's constructor TEvioDataEvent(uint32_t *b, int len)
   */
  TEvioFileReader reader;
  TEvioDataEvent  event;

  reader.open("/Users/gavalian/Work/Software/Release-5.0/COATJAVA/coatjava-5.0/lib/data/proton_testFW.ev");

  /**
   * Declare ROOT histograms for ADC and TDC values.
   */
  TH1F *H1_ADCL    = new TH1F("H_ADCL","FTOF ADC Left" ,100,0.,2000.);
  TH1F *H1_ADCR    = new TH1F("H_ADCR","FTOF ADC Right",100,0.,2000.);
  TH1F *H1_ADCDIFF = new TH1F("H_ADCDIFF","FTOF ADC Diff",200,-500.,500.);

  TH1F *H1_TDCL    = new TH1F("H_TDCL","FTOF TDC Left" ,100,0.,200000.);
  TH1F *H1_TDCR    = new TH1F("H_TDCR","FTOF TDC Right",100,0.,200000.);
  TH1F *H1_TDCDIFF = new TH1F("H_TDCDIFF","FTOF TDC Diff",200,-1500.,1500.);

  int icounter = 0;  

  /**
   * Loop over the events in the file. reader.next() returns false
   * when the end of file is reached.
   */
  while( reader.next() == true ){
    icounter++;
    /**
     * initilize the event with the current buffer read from the file.
     */
    reader.getEvent(event);

    /**
     * request an array of integers with tag=60 and num=22 - 25.
     * tag 60 corresponds to the FTOF bank. To get a double array
     * use event.getDoubleArray(60,1) for example. tag=60 num=1 
     * corresponds to Etot variable in the FTOF bank.
     */
    TArrayI adcL = event.getIntegerArray(60,22);
    TArrayI adcR = event.getIntegerArray(60,23);
    TArrayI tdcL = event.getIntegerArray(60,24);
    TArrayI tdcR = event.getIntegerArray(60,25);
    /**
     * Loop over the entries in the array (number of hits) and
     * fill the histograms.
     */
    for(int loop = 0; loop < adcL.GetSize(); loop++){
	H1_ADCL->Fill(adcL.At(loop));
	H1_ADCR->Fill(adcR.At(loop));
	H1_ADCDIFF->Fill(adcL.At(loop)-adcR.At(loop));
	
	H1_TDCL->Fill(tdcL.At(loop));
        H1_TDCR->Fill(tdcR.At(loop));
        H1_TDCDIFF->Fill(tdcL.At(loop)-tdcR.At(loop));
	//cout << tdcL.At(loop) << endl;
    }

  }
  
  cout << " Events in the FILE = " << icounter << endl;
  reader.close();
  /**
   * Draw histograms on ROOT canvas.
   */

  TCanvas *c1 = new TCanvas("c1","",800,700);

  c1->Divide(3,2);
  c1->cd(1);
  H1_ADCL->Draw();
  c1->cd(2);
  H1_ADCR->Draw();
  c1->cd(3);
  H1_ADCDIFF->Draw();
  c1->cd(4);
  H1_TDCL->Draw();
  c1->cd(5);
  H1_TDCR->Draw();
  c1->cd(6);
  H1_TDCDIFF->Draw();

}

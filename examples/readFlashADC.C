/**
 * Sample script to read evio files from ROOT.
 * author: G.Gavalian.
 */
{
  /* 
   * Loading the evio-root shared library. Change the path if running the script
   * from a different directory.
   */
  gSystem->Load("../lib/libEvioRoot.so");  
  TEvioFileReader *reader = new TEvioFileReader();
  TEvioDataEvent  *event  = new TEvioDataEvent();
  reader->open("../ltcc0test_000490.evio");

  TH1D *H1_ADC = new TH1D("H1_ADC","",100,0.0,100.);
  int icounter = 0;

  while( reader->next() == true ){
    icounter++;
    if(icounter%500==0) cout << " processed " << icounter << "  events " << endl;
    //reader->getEvent(*event);

    TClonesArray *flash = reader->getFlashADC(43,57601);
    
    int nentries = flash->GetEntries();
    for(int loop = 0; loop < nentries; loop++){
      TADCClass *adc = (TADCClass *) flash->At(loop);
      //cout << " SLOT = " << adc->GetSlot() << "  CHANNEL = " << adc->GetChannel() << endl;
      //if(adc->GetSlot()==4 && adc->GetChannel()==8){
      int slot    = adc->GetSlot();
      int channel = adc->GetChannel();
      for(int i = 0; i < adc->GetRows(); i++){
	
	int value = adc->GetValue(i);
	//cout <<  " " << value << endl; 
	H1_ADC->Fill(i,value);
      }
      //cout << endl;
      //}
    }
    delete flash;
  }

  H1_ADC->Draw();
}

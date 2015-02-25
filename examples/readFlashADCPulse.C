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
  reader->open("../ltcc0test_000517.evio");

  TH1D *H1_TDC = new TH1D("H1_TDC","",100,0.0,5000.);
  int icounter = 0;

  while( reader->next() == true ){
    icounter++;
    if(icounter%500==0) cout << " processed " << icounter << "  events " << endl;
    //reader->getEvent(*event);
    
    TClonesArray *flash = reader->getFlashADCPulse(43,57602);
    int nentries = flash->GetEntries();
    
    for(int loop = 0; loop < nentries; loop++){
      TADCClassPulse *adc = (TADCClassPulse *) flash->At(loop);
      int slot    = adc->GetSlot();
      int channel = adc->GetChannel();
      // adc->GetValue(0) - ADC integral value
      // adc->GetValue(1) - TDC value
      // adc->GetValue(2) - Pedistal value
      // adc->GetValue(3) - ADC Max value

      H1_TDC->Fill(adc->GetValue(1));
      if(icounter<100){
	adc->Print();
      }
      //delete flash;
    }
  }
  H1_TDC->Draw();
}

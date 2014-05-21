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
  
  TEvioFileReader reader;
  reader.open("/Users/gavalian/Work/Software/Release-5.0/COATJAVA/coatjava-5.0/lib/data/proton_testFW.ev");

  TH1F *H1 = new TH1F("H1","",100,0.0,2000.0);
  while( reader.next() == true ){
    TArrayI *array = reader.getArrayInt(60,22);
    if(array->GetSize()>0){
      H1.Fill(array->At(0));
    }
  }

  H1->Draw();
}

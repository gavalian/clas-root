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
  
  TFileEvio *hf = new TFileEvio("histograms.evio");
  TCanvas *c1 = new TCanvas("c1","Evio Histogram Reader",800,800);
  c1->Divide(2,2);
  c1->cd(1);
  TH1D* H100 = (TH1D*) hf->Get("h100");
  H100->Draw();
  c1->cd(2);
  TH1D* H101 = (TH1D*) hf->Get("h101");
  H101->Draw();
  c1->cd(3);
  TH1D* H102 = (TH1D*) hf->Get("h102");
  H102->Draw();
}

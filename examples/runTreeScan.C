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
  //TTreeEvio *tree = new TTreeEvio("gemc_out_2kevents.evio");
  TTreeEvio *tree = new TTreeEvio("out.evio");
  //TBenchmark *gBenchmark = new TBenchmark();
  gBenchmark->Start("evio");
  //tree->Draw("FTOF1B.paddle","FTOF1B.paddle<200");
  //tree->Draw("FTOF1B.paddle");
  //tree->TestLoop(1500);
  
  int nentries = tree->GetEntries();
  for(int steps = 0; steps < 100; steps++)
  for(int loop = 0; loop < nentries; loop++){
    tree->LoadTree(loop);
  }
  gBenchmark->Stop("evio");
  gBenchmark->Show("evio");
}

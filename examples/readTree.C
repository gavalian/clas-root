{
  /* 
   * Loading the evio-root shared library. Change the path if running the script
   * from a different directory.
   */
  gSystem->Load("../lib/libEvioRoot.so");
  
  TTreeEvio tree("input.evio");

  int nentries = tree.GetEntries();

  TH1D *H1 = new TH1D("H1","Ftof 1B Paddles",80,0.0,2.4);

  for(int loop = 0; loop < nentries; loop++){
    
    tree.LoadTree(loop);

    Int_t nrows = tree.GetNRows("TimeBasedTrkg::TBTracks");
    cout << " NRows =  " << nrows << endl;
    for(int row = 0; row < nrows; row++){
      cout << row << "  p = " << tree.GetValueD(row,"TimeBasedTrkg::TBTracks","p") 
	   << endl;
      H1->Fill(tree.GetValueD(row,"TimeBasedTrkg::TBTracks","p"));
    }
    //cout << " loop = " << loop << "  nrows = " << nrowsFTOF->GetValue(0) << endl;    
  }

  H1->Draw();
}

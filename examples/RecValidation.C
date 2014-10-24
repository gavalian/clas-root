/**
 * Example script for reading Evio files from ROOT/CINT.
 * Author: G.Gavalian
 */
{
  /**
   * Loading shared library of evio-root package.
   */

  gSystem->Load("../lib/libEvioRoot.so");

  TTreeEvio  *tree = new TTreeEvio("input.evio");

  int nentries = tree->GetEntries();
  
  int icounter = 0;

  TH1F  *H1_PRES    = new TH1F("H1_PRES" ,"",100, -0.5, 0.5);
  TH1F  *H1_GPIDE   = new TH1F("H1_GPIDE","",100,  0.5, 5.5);
  TH1F  *H1_RPIDE   = new TH1F("H1_RPIDE","",100,  0.5, 5.5);
  TH1F  *H1_RPIDO   = new TH1F("H1_RPIDO","",100,  0.5, 5.5);

  TVector3 genPart, recPart;

  for(int eloop = 0; eloop < nentries; eloop++){

    tree.LoadTree(eloop);
    icounter++;
    if(icounter%2000==0) cout << "-------> processed " << icounter << endl;
    if(tree.GetNRows("GenPart::true")>0&&tree.GetNRows("EVENTHB::particle")>0){
      genPart.SetXYZ(
		     tree.GetValueD(0,"GenPart::true","px")/1000.0,
		     tree.GetValueD(0,"GenPart::true","py")/1000.0,
		     tree.GetValueD(0,"GenPart::true","pz")/1000.0
		     );
      recPart.SetXYZ(
		     tree.GetValueF(0,"EVENTHB::particle","px"),
		     tree.GetValueF(0,"EVENTHB::particle","py"),
		     tree.GetValueF(0,"EVENTHB::particle","pz")
		     );
      
      H1_PRES->Fill((genPart.Mag()-recPart.Mag())/genPart.Mag());
      
      int genPID = tree.GetValueI(0,"GenPart::true","pid");
      int recPID = tree.GetValueI(0,"EVENTHB::particle","pid");
      //************************
      // PID 11 check
      if(genPID==11){
	H1_GPIDE->Fill(genPart.Mag());
	if(recPID==11){
	  H1_RPIDE->Fill(genPart.Mag());
	} else {
	  H1_RPIDO->Fill(genPart.Mag());
	}
      }
      //************************

    }
  }
  
  cout << " Events in the FILE = " << icounter << endl;

  /**
   * Draw histograms on ROOT canvas.
   */

  TCanvas *c1 = new TCanvas("c1","",800,700);
  c1->Divide(2,2);
  c1->cd(1);
  H1_PRES->Draw();
  c1->cd(2);
  H1_GPIDE->Draw();
  H1_RPIDE->Draw("same");
  H1_RPIDO->Draw("same");
}

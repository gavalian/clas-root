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


  TXMLBankDictionary *xml = new TXMLBankDictionary();

  xml->ParseFile("/Users/gavalian/Work/Software/Release-7.0/COATJAVA/coatjava/lib/bankdefs/clas12/FTOF.xml");
}

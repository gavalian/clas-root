#include <iostream>
#include "EvioFileReader.h"
//#include "TEvioFileReader.h"
#include "EvioBankIndex.h"
#include <stdio.h>
#include <stdlib.h>
#include "evioUtil.hxx"
#include "evioBankIndex.hxx"

void  decodeDeserialize(uint32_t *buffer);
void  decodeIndexing(uint32_t *buffer);


int main(int argc, const char** argv){
  printf("Testing out program\n");
  //TEvioFileReader *treader = new TEvioFileReader();
  //cout << " testing program " << endl;
  //cout << argv[0] << endl;
  //cout << argv[1] << endl;
  //string filename = argv[1];
  //string filename = "/Users/gavalian/Work/DataSpace/clas12/gemc_output_5deg_phi.evio";
  char file[128];// = "/Users/gavalian/Work/DataSpace/clas12/gemc_output_5deg_phi.evio";
  sprintf(file,"%s",argv[1]);
  //cout << "[Decoder]-----> opennign file : " << filename.c_str() << endl;
  //cout << "[Decoder]-----> opennign file : " << file << endl;
  //EvioDataEvent  event;
  EvioFileReader *reader = new EvioFileReader();
  EvioBankIndex  *bankIndex = new EvioBankIndex();
  //reader->open(filename.c_str());
  
  reader->open(file);

  int ic = 0;
  //  while(reader->next()){
  for(int loop = 0; loop < 500; loop++){
    ic++;
    if(ic%1000==0) cout << " processed -----> " << ic << endl;
    reader->readEvent(loop+1);
    cout << "---> processing event # " << loop << endl;
    vector<CompositeADC_t> flashData = reader->getEvent().getCompositeDataUp(5,57601);
    cout << "---> decoding done # " << loop << endl;
    reader->getEvent().getBankIndex().list();
    cout << "data length = " << flashData.size() << endl;
    for(int i = 0; i < flashData.size(); i++){
      cout << "SLOT/CHANNEL " << flashData[i].slot << "  " << flashData[i].channel << endl;
      //for(int c = 0; c < flashData[i].samples.size();c++){
      //cout << c << " ->  " << flashData[i].samples[c] << "  "; 
      //}
      //cout << endl;
    }
    
  }
  cout << "processed " << ic << " events " << endl;
}


void  decodeIndexing(uint32_t *buffer){
  evio::evioBankIndex b0(buffer,0);
}

void  decodeDeserialize(uint32_t *buffer){
  evio::evioDOMTree event(buffer);
  evio::evioDOMNodeListP fullList     = event.getNodeList();
  evio::evioDOMNodeList::const_iterator iter;
  int tag = 0;
  int num = 0;
  for(iter=fullList->begin(); iter!=fullList->end(); iter++) {
    tag = (*iter)->tag;
    num = (*iter)->num;
    //cout << "bank type,tag,num are: " << hex << "  0x" << (*iter)->getContentType() << dec << "  "  << (*iter)->tag
   //<< "  " << (int)((*iter)->num) << endl;
  }
}

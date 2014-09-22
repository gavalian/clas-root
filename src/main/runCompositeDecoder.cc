#include <iostream>
#include "EvioFileReader.h"
#include <stdio.h>
#include <stdlib.h>


int main(int argc, const char** argv){
  printf("Testing out program\n");
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
  EvioDataEvent  *event  = new EvioDataEvent();
  //reader->open(filename.c_str());
  
  reader->open(file);

  int ic = 0;
  while(reader->next()){
    ic++;
    if(ic%1000==0) cout << " processed -----> " << ic << endl;
    reader->getEvent(*event);
    //event->getList();
    event->getCompositeData(57601,0);
    //vector<int32_t> *buffer = event->getIntegerVector(57601,0);
    //cout << " buffer size = " << buffer->size() << endl;
  }
  cout << "processed " << ic << " events " << endl;
}

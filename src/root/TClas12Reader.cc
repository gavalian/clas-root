/**
* Autogenerated Source File for TClas12Reader
* \\file TClas12Reader.cc
* \\author G.Gavalian
* \\date 2014-09-08
*/
#include "TClas12Reader.h"


TClas12Reader::TClas12Reader()
{
}
/* 
TClas12Reader::TClas12Reader(const TClas12Reader &obj)
{
}
*/
TClas12Reader::~TClas12Reader()
{
}

void TClas12Reader::addFile(const char *file){
  files.push_back(string(file));
}

void TClas12Reader::open()
{
  if(files.size()>0){
    reader.open(files[0].c_str());
  }
}
bool TClas12Reader::next()
{
  bool status = reader.next();
  if(status==true){
    reader.getEvent(event);
  }
  return status;
}

TPhysicsEvent *TClas12Reader::getGeneratedEvent()
{
  TPhysicsEvent *physevent = new TPhysicsEvent();
  
  TArrayI pid  = event.getIntegerArray(20,1);
  TArrayD pxg  = event.getDoubleArray(20,2);
  TArrayD pyg  = event.getDoubleArray(20,3);
  TArrayD pzg  = event.getDoubleArray(20,4);
  
  for(int loop = 0; loop < pid.GetSize(); loop++){
    physevent->AddParticle(pid.At(loop),pxg.At(loop)/1000.0,pyg.At(loop)/1000.0,pzg.At(loop)/1000.0,
			   0.0,0.0,0.0,0.0);
  }
  return physevent;
}

TPhysicsEvent *TClas12Reader::getEvent()
{
  TArrayI pid  = event.getIntegerArray(4601,3);
  TArrayF pxg  = event.getFloatArray(4601,7);
  TArrayF pyg  = event.getFloatArray(4601,8);
  TArrayF pzg  = event.getFloatArray(4601,9);
  TPhysicsEvent *physevent = new TPhysicsEvent();
  for(int loop = 0; loop < pid.GetSize(); loop++){
    physevent->AddParticle(pid.At(loop),-pxg.At(loop),-pyg.At(loop),-pzg.At(loop),
			   0.0,0.0,0.0,0.0);
  }
  return physevent;
}
/* const TClas12Reader &TClas12Reader::operator=(const TClas12Reader &obj){} */

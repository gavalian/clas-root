/**
* Autogenerated Source File for TEvioDataEvent
* \\file TEvioDataEvent.cc
* \\author G.Gavalian
* \\date 2014-05-14
*/
#include "TEvioDataEvent.h"

ClassImp(TEvioDataEvent)

TEvioDataEvent::TEvioDataEvent()
{
}
/* 
TEvioDataEvent::TEvioDataEvent(const TEvioDataEvent &obj)
{
}
*/
TEvioDataEvent::~TEvioDataEvent()
{
}

void TEvioDataEvent::init(uint32_t *ptr, int len)
{
    dataEvent.init(ptr,len);
}

TClonesArray  *TEvioDataEvent::getFlashADC(int tag, int num){

  vector<CompositeADC_t>  vec = dataEvent.getCompositeData(tag,num);
  TClonesArray *fcaADCStore  = new TClonesArray("TADCClass",4);
  int nADCStore = 0;
  for(int loop = 0; loop < vec.size();loop++){
    TADCClass class_adc(vec[loop].slot,vec[loop].channel,(int) vec[loop].samples.size());
    for(int vloop = 0; vloop < vec[loop].samples.size(); vloop++)
      class_adc.SetValue(loop,vec[loop].samples[vloop]);
    TClonesArray &tADCStore = *fcaADCStore;
    new(tADCStore[nADCStore++]) TADCClass(class_adc);
  }
  return fcaADCStore;
  //cout << " Readnig composite data size = " << vec.size() << endl;
}

/* const TEvioDataEvent &TEvioDataEvent::operator=(const TEvioDataEvent &obj){} */
TArrayD   TEvioDataEvent::getDoubleArray(int tag, int num)
{
    vector<double> *vptr = dataEvent.getDoubleVector(tag,num);
    TArrayD darray;
    if(vptr==NULL){
        cout << " ERROR in getting the " << tag << " " << num << endl;
        return darray;
    }
    darray.Set(vptr->size(),vptr->data());
    return darray;
}

TArrayF   TEvioDataEvent::getFloatArray(int tag, int num)
{
  vector<float> *vptr = dataEvent.getFloatVector(tag,num);
  TArrayF iarray;
  if(vptr==NULL){
    cout << " ERROR in getting the " << tag << " " << num << endl;
    return iarray;
  }
  iarray.Set(vptr->size(),vptr->data());
  return iarray;
}

TArrayI   TEvioDataEvent::getIntegerArray(int tag, int num)
{
    vector<int32_t> *vptr = dataEvent.getIntegerVector(tag,num);
    TArrayI iarray;
    if(vptr==NULL){
        cout << " ERROR in getting the " << tag << " " << num << endl;
        return iarray;
    }
    iarray.Set(vptr->size(),vptr->data()); 
    return iarray;
}

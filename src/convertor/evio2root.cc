#include <iostream>
#include "EvioFileReader.h"
//#include "TEvioFileReader.h"
#include "EvioBankIndex.h"
#include <stdio.h>
#include <stdlib.h>
#include "evioUtil.hxx"
#include "evioBankIndex.hxx"
#include "TTree.h"
#include "TFile.h"
#include "TROOT.h"

void printMessage();
void fill_Detector(EvioFileReader *reader);
void fill_Event(EvioFileReader *reader);
void fill_Generated_Event(EvioFileReader *reader);

int  npart = 0;
int  pid[20];
int  status[20];
int  charge[20];

float  mass[20];
float  beta[20];
float  px[20];
float  py[20];
float  pz[20];
float  vx[20];
float  vy[20];
float  vz[20];

int gpart = 0;
int gid[20];
float  gpx[20];
float  gpy[20];
float  gpz[20];
float  gvx[20];
float  gvy[20];
float  gvz[20];


int  ndet = 0;
int  detector[50];
int  pindex[50];
int  sector[50];
int  layer[50];
float X[50];
float Y[50];
float Z[50];
float hX[50];
float hY[50];
float hZ[50];
float path[50];
float energy[50];
float ptime[50];

int main(int argc, const char** argv){

  if(argc<2){
    printf("error -> provide a file name \n\n");
  }

  TFile *f   = new TFile("peter.root","recreate");
  TTree* c12 = new TTree("clas12","CLAS12 Reconstruction");

  c12->Branch("npart",&npart,"npart/I");
  c12->Branch("charge",charge,"charge[npart]/I");
  c12->Branch("status",status,"status[npart]/I");
  c12->Branch("pid",pid,"pid[npart]/I");
  c12->Branch("mass",mass,"mass[npart]/F");
  c12->Branch("beta",beta,"beta[npart]/F");
  c12->Branch("px",px,"px[npart]/F");
  c12->Branch("py",py,"py[npart]/F");
  c12->Branch("pz",pz,"pz[npart]/F");
  c12->Branch("vx",vx,"vx[npart]/F");
  c12->Branch("vy",vy,"vy[npart]/F");
  c12->Branch("vz",vz,"vz[npart]/F");

  c12->Branch("gpart",&gpart,"gpart/I");
  c12->Branch("gid",gid,"gid[gpart]/I");
  c12->Branch("gpx",gpx,"gpx[gpart]/F");
  c12->Branch("gpy",gpy,"gpy[gpart]/F");
  c12->Branch("gpz",gpz,"gpz[gpart]/F");
  c12->Branch("gvx",gvx,"gvx[gpart]/F");
  c12->Branch("gvy",gvy,"gvy[gpart]/F");
  c12->Branch("gvz",gvz,"gvz[gpart]/F");

  c12->Branch("ndet",&ndet,"ndet/I");
  c12->Branch("detector",detector,"detector[ndet]/I");
  c12->Branch("pindex",pindex,"pindex[ndet]/I");
  c12->Branch("sector",sector,"sector[ndet]/I");
  c12->Branch("layer",layer,"layer[ndet]/I");
  c12->Branch("X",X,"X[ndet]/F");
  c12->Branch("Y",Y,"Y[ndet]/F");
  c12->Branch("Z",Z,"Z[ndet]/F");
  c12->Branch("hX",hX,"hX[ndet]/F");
  c12->Branch("hY",hY,"hY[ndet]/F");
  c12->Branch("hZ",hZ,"hZ[ndet]/F");
  c12->Branch("path",path,"path[ndet]/F");
  c12->Branch("energy",energy,"energy[ndet]/F");
  c12->Branch("time",ptime,"time[ndet]/F");    

  printMessage();

  char file[128];// = "/Users/gavalian/Work/DataSpace/clas12/gemc_output_5deg_phi.evio";
  sprintf(file,"%s",argv[1]);

  EvioFileReader *reader = new EvioFileReader();
  
  reader->open(file);

  int ic = 0;

  for(int loop = 0; loop < 500; loop++){
    ic++;
    if(ic%1000==0) cout << " processed -----> " << ic << endl;
    reader->readEvent(loop+1);
    fill_Event(reader);
    fill_Generated_Event(reader);
    fill_Detector(reader);

    c12->Fill();
    //vector<int32_t>* vec_pid = reader->getEvent().getIntegerVector(4601,1);
    //printf("pid size = %d\n" , vec_pid->size());
  }
  cout << "processed " << ic << " events " << endl;
  f->Write();
  f->Close();
}


void fill_Event(EvioFileReader *reader){

  vector<int32_t>* vec_pid = reader->getEvent().getIntegerVector(4601,3);
  vector<int32_t>* vec_st  = reader->getEvent().getIntegerVector(4601,1);
  vector<int32_t>* vec_ch  = reader->getEvent().getIntegerVector(4601,2);

  vector<float>* vec_mass  = reader->getEvent().getFloatVector(4601,5);
  vector<float>* vec_beta  = reader->getEvent().getFloatVector(4601,6);

  vector<float>* vec_px  = reader->getEvent().getFloatVector(4601,7);
  vector<float>* vec_py  = reader->getEvent().getFloatVector(4601,8);
  vector<float>* vec_pz  = reader->getEvent().getFloatVector(4601,9);
  
  vector<float>* vec_vx  = reader->getEvent().getFloatVector(4601,10);
  vector<float>* vec_vy  = reader->getEvent().getFloatVector(4601,11);
  vector<float>* vec_vz  = reader->getEvent().getFloatVector(4601,12);

  npart = vec_pid->size();
  if(npart>20) npart = 20;

  for(int i = 0; i < npart;i++){
    /*
    printf("pid = %4d status = %4d charge = %4d  px %8.5f py %8.5f pz %8.5f\n", 
      (*vec_pid)[i], (*vec_st)[i], (*vec_ch)[i],
      (*vec_px)[i],(*vec_py)[i],(*vec_pz)[i] );
  */
    status[i] = (*vec_st)[i];
    charge[i] = (*vec_ch)[i];
    pid[i]    = (*vec_pid)[i];
    mass[i]   = (*vec_mass)[i];
    beta[i]   = (*vec_beta)[i];
    px[i]     = (*vec_px)[i];
    py[i]     = (*vec_py)[i];
    pz[i]     = (*vec_pz)[i];        
    vx[i]     = (*vec_vx)[i];
    vy[i]     = (*vec_vy)[i];
    vz[i]     = (*vec_vz)[i];   
  }

}

void fill_Detector(EvioFileReader *reader){

  vector<int32_t>* vec_det    = reader->getEvent().getIntegerVector(4602,3);
  vector<int32_t>* vec_pid    = reader->getEvent().getIntegerVector(4602,1);
  vector<int32_t>* vec_sector = reader->getEvent().getIntegerVector(4602,4);
  vector<int32_t>* vec_layer  = reader->getEvent().getIntegerVector(4602,6);  

  vector<float>* vec_path   = reader->getEvent().getFloatVector(4602,13);
  vector<float>* vec_time   = reader->getEvent().getFloatVector(4602,14);
  vector<float>* vec_energy = reader->getEvent().getFloatVector(4602,15);

  vector<float>* vec_x  = reader->getEvent().getFloatVector(4602,7);
  vector<float>* vec_y  = reader->getEvent().getFloatVector(4602,8);
  vector<float>* vec_z  = reader->getEvent().getFloatVector(4602,9);
  
  vector<float>* vec_hx  = reader->getEvent().getFloatVector(4602,10);
  vector<float>* vec_hy  = reader->getEvent().getFloatVector(4602,11);
  vector<float>* vec_hz  = reader->getEvent().getFloatVector(4602,12);

  ndet = vec_pid->size();
  if(ndet>40) ndet = 40;

  for(int i = 0; i < ndet;i++){
    /*
    printf("pid = %4d status = %4d charge = %4d  px %8.5f py %8.5f pz %8.5f\n", 
      (*vec_pid)[i], (*vec_st)[i], (*vec_ch)[i],
      (*vec_px)[i],(*vec_py)[i],(*vec_pz)[i] );
  */

    detector[i] = (*vec_det)[i];
    layer[i]   = (*vec_layer)[i];
    sector[i]  = (*vec_sector)[i];
    pindex[i]  = (*vec_pid)[i];
    path[i]    = (*vec_path)[i];
    ptime[i]    = (*vec_time)[i];
    energy[i]   = (*vec_energy)[i];    
    X[i]     = (*vec_x)[i];
    Y[i]     = (*vec_y)[i];
    Z[i]     = (*vec_z)[i];        
    hX[i]     = (*vec_hx)[i];
    hY[i]     = (*vec_hy)[i];
    hZ[i]     = (*vec_hz)[i];   

  }

}


void fill_Generated_Event(EvioFileReader *reader){

  vector<int32_t>* vec_pid = reader->getEvent().getIntegerVector(20,1);
  vector<double>* vec_px  = reader->getEvent().getDoubleVector(20,2);
  vector<double>* vec_py  = reader->getEvent().getDoubleVector(20,3);
  vector<double>* vec_pz  = reader->getEvent().getDoubleVector(20,4);
  
  vector<double>* vec_vx  = reader->getEvent().getDoubleVector(20,5);
  vector<double>* vec_vy  = reader->getEvent().getDoubleVector(20,6);
  vector<double>* vec_vz  = reader->getEvent().getDoubleVector(20,7);

  gpart = vec_pid->size();
  if(gpart>20) gpart = 20;

  for(int i = 0; i < gpart;i++){
    /*
    printf("pid = %4d status = %4d charge = %4d  px %8.5f py %8.5f pz %8.5f\n", 
      (*vec_pid)[i], (*vec_st)[i], (*vec_ch)[i],
      (*vec_px)[i],(*vec_py)[i],(*vec_pz)[i] );
  */
    gid[i]    = (*vec_pid)[i];
    gpx[i]     = (*vec_px)[i]/1000.0;
    gpy[i]     = (*vec_py)[i]/1000.0;
    gpz[i]     = (*vec_pz)[i]/1000.0;        
    gvx[i]     = (*vec_vx)[i]/1000.0;
    gvy[i]     = (*vec_vy)[i]/1000.0;
    gvz[i]     = (*vec_vz)[i]/1000.0;   
  }

}

void printMessage(){
  printf("\n\n");
  printf("EVIO 2 ROOT Convertor for CLAS12");
  printf("\n\n");
}

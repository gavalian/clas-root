/**
* Autogenerated Header File for TClas12Reader
* \\file TClas12Reader.h
* \\author G.Gavalian
* \\date 2014-09-08
*/
#ifndef __TCLAS12READER__
#define __TCLAS12READER__
#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include "TPhysicsEvent.h"
#include "TEvioFileReader.h"
#include "TEvioDataEvent.h"
//#include "common_std.h"
#include <_types/_uint8_t.h>

using namespace std;
//! A Brief Description
/*
 * A detailed description
 */
class TClas12Reader  {

private:

  vector<string>  files;
  TEvioFileReader reader;
  TEvioDataEvent  event;
public:

/** Default Constructor */
TClas12Reader();
/** Default Destructor */
~TClas12Reader();
/** Copy Constructor if one is needed */
/*TClas12Reader( const TClas12Reader &obj); */
/** An operator = if one is needed */
/* const TClas12Reader &operator=(const TClas12Reader &obj); */

 void  addFile(const char *file);
 void  open();
 bool  next();

 TPhysicsEvent *getGeneratedEvent();
 TPhysicsEvent *getEvent();

};
#endif

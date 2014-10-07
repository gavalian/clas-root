//
// File generated by /opt/local/libexec/root5/bin/rootcint at Tue Oct  7 09:50:28 2014

// Do NOT change. Changes will be lost next time file is generated
//

#define R__DICTIONARY_FILENAME srcdIrootdITADCClassDict
#include "RConfig.h" //rootcint 4834
#if !defined(R__ACCESS_IN_SYMBOL)
//Break the privacy of classes -- Disabled for the moment
#define private public
#define protected public
#endif

// Since CINT ignores the std namespace, we need to do so in this file.
namespace std {} using namespace std;
#include "TADCClassDict.h"

#include "TClass.h"
#include "TBuffer.h"
#include "TMemberInspector.h"
#include "TInterpreter.h"
#include "TVirtualMutex.h"
#include "TError.h"

#ifndef G__ROOT
#define G__ROOT
#endif

#include "RtypesImp.h"
#include "TIsAProxy.h"
#include "TFileMergeInfo.h"

// Direct notice to TROOT of the dictionary's loading.
namespace {
   static struct DictInit {
      DictInit() {
         ROOT::RegisterModule();
      }
   } __TheDictionaryInitializer;
}

// START OF SHADOWS

namespace ROOT {
   namespace Shadow {
   } // of namespace Shadow
} // of namespace ROOT
// END OF SHADOWS

namespace ROOT {
   void TADCClass_ShowMembers(void *obj, TMemberInspector &R__insp);
   static void *new_TADCClass(void *p = 0);
   static void *newArray_TADCClass(Long_t size, void *p);
   static void delete_TADCClass(void *p);
   static void deleteArray_TADCClass(void *p);
   static void destruct_TADCClass(void *p);
   static void streamer_TADCClass(TBuffer &buf, void *obj);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TADCClass*)
   {
      ::TADCClass *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TADCClass >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TADCClass", ::TADCClass::Class_Version(), "./src/root/TADCClass.h", 23,
                  typeid(::TADCClass), DefineBehavior(ptr, ptr),
                  &::TADCClass::Dictionary, isa_proxy, 0,
                  sizeof(::TADCClass) );
      instance.SetNew(&new_TADCClass);
      instance.SetNewArray(&newArray_TADCClass);
      instance.SetDelete(&delete_TADCClass);
      instance.SetDeleteArray(&deleteArray_TADCClass);
      instance.SetDestructor(&destruct_TADCClass);
      instance.SetStreamerFunc(&streamer_TADCClass);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TADCClass*)
   {
      return GenerateInitInstanceLocal((::TADCClass*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::TADCClass*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

//______________________________________________________________________________
atomic_TClass_ptr TADCClass::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TADCClass::Class_Name()
{
   return "TADCClass";
}

//______________________________________________________________________________
const char *TADCClass::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TADCClass*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TADCClass::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TADCClass*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
void TADCClass::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TADCClass*)0x0)->GetClass();
}

//______________________________________________________________________________
TClass *TADCClass::Class()
{
   if (!fgIsA) { R__LOCKGUARD2(gCINTMutex); if(!fgIsA) {fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TADCClass*)0x0)->GetClass();} }
   return fgIsA;
}

//______________________________________________________________________________
void TADCClass::Streamer(TBuffer &R__b)
{
   // Stream an object of class TADCClass.

   UInt_t R__s, R__c;
   if (R__b.IsReading()) {
      Version_t R__v = R__b.ReadVersion(&R__s, &R__c); if (R__v) { }
      TObject::Streamer(R__b);
      R__b >> slot_number;
      R__b >> channel_number;
      adcValue.Streamer(R__b);
      R__b.CheckByteCount(R__s, R__c, TADCClass::IsA());
   } else {
      R__c = R__b.WriteVersion(TADCClass::IsA(), kTRUE);
      TObject::Streamer(R__b);
      R__b << slot_number;
      R__b << channel_number;
      adcValue.Streamer(R__b);
      R__b.SetByteCount(R__c, kTRUE);
   }
}

//______________________________________________________________________________
void TADCClass::ShowMembers(TMemberInspector &R__insp)
{
      // Inspect the data members of an object of class TADCClass.
      TClass *R__cl = ::TADCClass::IsA();
      if (R__cl || R__insp.IsA()) { }
      R__insp.Inspect(R__cl, R__insp.GetParent(), "slot_number", &slot_number);
      R__insp.Inspect(R__cl, R__insp.GetParent(), "channel_number", &channel_number);
      R__insp.Inspect(R__cl, R__insp.GetParent(), "adcValue", &adcValue);
      R__insp.InspectMember(adcValue, "adcValue.");
      TObject::ShowMembers(R__insp);
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TADCClass(void *p) {
      return  p ? new(p) ::TADCClass : new ::TADCClass;
   }
   static void *newArray_TADCClass(Long_t nElements, void *p) {
      return p ? new(p) ::TADCClass[nElements] : new ::TADCClass[nElements];
   }
   // Wrapper around operator delete
   static void delete_TADCClass(void *p) {
      delete ((::TADCClass*)p);
   }
   static void deleteArray_TADCClass(void *p) {
      delete [] ((::TADCClass*)p);
   }
   static void destruct_TADCClass(void *p) {
      typedef ::TADCClass current_t;
      ((current_t*)p)->~current_t();
   }
   // Wrapper around a custom streamer member function.
   static void streamer_TADCClass(TBuffer &buf, void *obj) {
      ((::TADCClass*)obj)->::TADCClass::Streamer(buf);
   }
} // end of namespace ROOT for class ::TADCClass

/********************************************************
* src/root/TADCClassDict.cc
* CAUTION: DON'T CHANGE THIS FILE. THIS FILE IS AUTOMATICALLY GENERATED
*          FROM HEADER FILES LISTED IN G__setup_cpp_environmentXXX().
*          CHANGE THOSE HEADER FILES AND REGENERATE THIS FILE.
********************************************************/

#ifdef G__MEMTEST
#undef malloc
#undef free
#endif

#if defined(__GNUC__) && __GNUC__ >= 4 && ((__GNUC_MINOR__ == 2 && __GNUC_PATCHLEVEL__ >= 1) || (__GNUC_MINOR__ >= 3))
#pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif

extern "C" void G__cpp_reset_tagtableTADCClassDict();

extern "C" void G__set_cpp_environmentTADCClassDict() {
  G__cpp_reset_tagtableTADCClassDict();
}
#include <new>
extern "C" int G__cpp_dllrevTADCClassDict() { return(30051515); }

/*********************************************************
* Member function Interface Method
*********************************************************/

/* TADCClass */
static int G__TADCClassDict_217_0_1(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
   TADCClass* p = NULL;
   char* gvp = (char*) G__getgvp();
   int n = G__getaryconstruct();
   if (n) {
     if ((gvp == (char*)G__PVOID) || (gvp == 0)) {
       p = new TADCClass[n];
     } else {
       p = new((void*) gvp) TADCClass[n];
     }
   } else {
     if ((gvp == (char*)G__PVOID) || (gvp == 0)) {
       p = new TADCClass;
     } else {
       p = new((void*) gvp) TADCClass;
     }
   }
   result7->obj.i = (long) p;
   result7->ref = (long) p;
   G__set_tagnum(result7,G__get_linked_tagnum(&G__TADCClassDictLN_TADCClass));
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__TADCClassDict_217_0_2(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
   TADCClass* p = NULL;
   char* gvp = (char*) G__getgvp();
   //m: 1
   if ((gvp == (char*)G__PVOID) || (gvp == 0)) {
     p = new TADCClass((int) G__int(libp->para[0]));
   } else {
     p = new((void*) gvp) TADCClass((int) G__int(libp->para[0]));
   }
   result7->obj.i = (long) p;
   result7->ref = (long) p;
   G__set_tagnum(result7,G__get_linked_tagnum(&G__TADCClassDictLN_TADCClass));
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__TADCClassDict_217_0_3(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
   TADCClass* p = NULL;
   char* gvp = (char*) G__getgvp();
   //m: 3
   if ((gvp == (char*)G__PVOID) || (gvp == 0)) {
     p = new TADCClass(
(int) G__int(libp->para[0]), (int) G__int(libp->para[1])
, (int) G__int(libp->para[2]));
   } else {
     p = new((void*) gvp) TADCClass(
(int) G__int(libp->para[0]), (int) G__int(libp->para[1])
, (int) G__int(libp->para[2]));
   }
   result7->obj.i = (long) p;
   result7->ref = (long) p;
   G__set_tagnum(result7,G__get_linked_tagnum(&G__TADCClassDictLN_TADCClass));
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__TADCClassDict_217_0_4(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
   TADCClass* p = NULL;
   char* gvp = (char*) G__getgvp();
   //m: 1
   if ((gvp == (char*)G__PVOID) || (gvp == 0)) {
     p = new TADCClass(*(TADCClass*) libp->para[0].ref);
   } else {
     p = new((void*) gvp) TADCClass(*(TADCClass*) libp->para[0].ref);
   }
   result7->obj.i = (long) p;
   result7->ref = (long) p;
   G__set_tagnum(result7,G__get_linked_tagnum(&G__TADCClassDictLN_TADCClass));
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__TADCClassDict_217_0_5(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      G__letint(result7, 105, (long) ((TADCClass*) G__getstructoffset())->GetSlot());
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__TADCClassDict_217_0_6(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      G__letint(result7, 105, (long) ((TADCClass*) G__getstructoffset())->GetChannel());
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__TADCClassDict_217_0_7(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      G__letint(result7, 105, (long) ((TADCClass*) G__getstructoffset())->GetRows());
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__TADCClassDict_217_0_8(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      ((TADCClass*) G__getstructoffset())->SetValue((int) G__int(libp->para[0]), (int) G__int(libp->para[1]));
      G__setnull(result7);
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__TADCClassDict_217_0_9(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      G__letint(result7, 115, (long) ((TADCClass*) G__getstructoffset())->GetValue((int) G__int(libp->para[0])));
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__TADCClassDict_217_0_10(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      ((TADCClass*) G__getstructoffset())->Init((int) G__int(libp->para[0]));
      G__setnull(result7);
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__TADCClassDict_217_0_11(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      ((TADCClass*) G__getstructoffset())->SetSlotChannel((int) G__int(libp->para[0]), (int) G__int(libp->para[1]));
      G__setnull(result7);
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__TADCClassDict_217_0_12(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      ((TADCClass*) G__getstructoffset())->Init((int) G__int(libp->para[0]), (int) G__int(libp->para[1])
, (int) G__int(libp->para[2]));
      G__setnull(result7);
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__TADCClassDict_217_0_13(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      {
         const TArrayS& obj = ((TADCClass*) G__getstructoffset())->Data();
         result7->ref = (long) (&obj);
         result7->obj.i = (long) (&obj);
      }
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__TADCClassDict_217_0_14(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      G__letint(result7, 85, (long) TADCClass::Class());
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__TADCClassDict_217_0_15(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      G__letint(result7, 67, (long) TADCClass::Class_Name());
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__TADCClassDict_217_0_16(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      G__letint(result7, 115, (long) TADCClass::Class_Version());
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__TADCClassDict_217_0_17(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      TADCClass::Dictionary();
      G__setnull(result7);
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__TADCClassDict_217_0_21(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      ((TADCClass*) G__getstructoffset())->StreamerNVirtual(*(TBuffer*) libp->para[0].ref);
      G__setnull(result7);
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__TADCClassDict_217_0_22(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      G__letint(result7, 67, (long) TADCClass::DeclFileName());
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__TADCClassDict_217_0_23(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      G__letint(result7, 105, (long) TADCClass::ImplFileLine());
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__TADCClassDict_217_0_24(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      G__letint(result7, 67, (long) TADCClass::ImplFileName());
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__TADCClassDict_217_0_25(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      G__letint(result7, 105, (long) TADCClass::DeclFileLine());
   return(1 || funcname || hash || result7 || libp) ;
}

// automatic destructor
typedef TADCClass G__TTADCClass;
static int G__TADCClassDict_217_0_26(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
   char* gvp = (char*) G__getgvp();
   long soff = G__getstructoffset();
   int n = G__getaryconstruct();
   //
   //has_a_delete: 1
   //has_own_delete1arg: 0
   //has_own_delete2arg: 0
   //
   if (!soff) {
     return(1);
   }
   if (n) {
     if (gvp == (char*)G__PVOID) {
       delete[] (TADCClass*) soff;
     } else {
       G__setgvp((long) G__PVOID);
       for (int i = n - 1; i >= 0; --i) {
         ((TADCClass*) (soff+(sizeof(TADCClass)*i)))->~G__TTADCClass();
       }
       G__setgvp((long)gvp);
     }
   } else {
     if (gvp == (char*)G__PVOID) {
       delete (TADCClass*) soff;
     } else {
       G__setgvp((long) G__PVOID);
       ((TADCClass*) (soff))->~G__TTADCClass();
       G__setgvp((long)gvp);
     }
   }
   G__setnull(result7);
   return(1 || funcname || hash || result7 || libp) ;
}

// automatic assignment operator
static int G__TADCClassDict_217_0_27(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
   TADCClass* dest = (TADCClass*) G__getstructoffset();
   *dest = *(TADCClass*) libp->para[0].ref;
   const TADCClass& obj = *dest;
   result7->ref = (long) (&obj);
   result7->obj.i = (long) (&obj);
   return(1 || funcname || hash || result7 || libp) ;
}


/* Setting up global function */

/*********************************************************
* Member function Stub
*********************************************************/

/* TADCClass */

/*********************************************************
* Global function Stub
*********************************************************/

/*********************************************************
* Get size of pointer to member function
*********************************************************/
class G__Sizep2memfuncTADCClassDict {
 public:
  G__Sizep2memfuncTADCClassDict(): p(&G__Sizep2memfuncTADCClassDict::sizep2memfunc) {}
    size_t sizep2memfunc() { return(sizeof(p)); }
  private:
    size_t (G__Sizep2memfuncTADCClassDict::*p)();
};

size_t G__get_sizep2memfuncTADCClassDict()
{
  G__Sizep2memfuncTADCClassDict a;
  G__setsizep2memfunc((int)a.sizep2memfunc());
  return((size_t)a.sizep2memfunc());
}


/*********************************************************
* virtual base class offset calculation interface
*********************************************************/

   /* Setting up class inheritance */

/*********************************************************
* Inheritance information setup/
*********************************************************/
extern "C" void G__cpp_setup_inheritanceTADCClassDict() {

   /* Setting up class inheritance */
   if(0==G__getnumbaseclass(G__get_linked_tagnum(&G__TADCClassDictLN_TADCClass))) {
     TADCClass *G__Lderived;
     G__Lderived=(TADCClass*)0x1000;
     {
       TObject *G__Lpbase=(TObject*)G__Lderived;
       G__inheritance_setup(G__get_linked_tagnum(&G__TADCClassDictLN_TADCClass),G__get_linked_tagnum(&G__TADCClassDictLN_TObject),(long)G__Lpbase-(long)G__Lderived,1,1);
     }
   }
}

/*********************************************************
* typedef information setup/
*********************************************************/
extern "C" void G__cpp_setup_typetableTADCClassDict() {

   /* Setting up typedef entry */
   G__search_typename2("Short_t",115,-1,0,-1);
   G__setnewtype(-1,"Signed Short integer 2 bytes (short)",0);
   G__search_typename2("Int_t",105,-1,0,-1);
   G__setnewtype(-1,"Signed integer 4 bytes (int)",0);
   G__search_typename2("Version_t",115,-1,0,-1);
   G__setnewtype(-1,"Class version identifier (short)",0);
   G__search_typename2("vector<ROOT::TSchemaHelper>",117,G__get_linked_tagnum(&G__TADCClassDictLN_vectorlEROOTcLcLTSchemaHelpercOallocatorlEROOTcLcLTSchemaHelpergRsPgR),0,-1);
   G__setnewtype(-1,NULL,0);
   G__search_typename2("reverse_iterator<const_iterator>",117,G__get_linked_tagnum(&G__TADCClassDictLN_reverse_iteratorlEvectorlEROOTcLcLTSchemaHelpercOallocatorlEROOTcLcLTSchemaHelpergRsPgRcLcLiteratorgR),0,G__get_linked_tagnum(&G__TADCClassDictLN_vectorlEROOTcLcLTSchemaHelpercOallocatorlEROOTcLcLTSchemaHelpergRsPgR));
   G__setnewtype(-1,NULL,0);
   G__search_typename2("reverse_iterator<iterator>",117,G__get_linked_tagnum(&G__TADCClassDictLN_reverse_iteratorlEvectorlEROOTcLcLTSchemaHelpercOallocatorlEROOTcLcLTSchemaHelpergRsPgRcLcLiteratorgR),0,G__get_linked_tagnum(&G__TADCClassDictLN_vectorlEROOTcLcLTSchemaHelpercOallocatorlEROOTcLcLTSchemaHelpergRsPgR));
   G__setnewtype(-1,NULL,0);
   G__search_typename2("vector<TVirtualArray*>",117,G__get_linked_tagnum(&G__TADCClassDictLN_vectorlETVirtualArraymUcOallocatorlETVirtualArraymUgRsPgR),0,-1);
   G__setnewtype(-1,NULL,0);
   G__search_typename2("reverse_iterator<const_iterator>",117,G__get_linked_tagnum(&G__TADCClassDictLN_reverse_iteratorlEvectorlETVirtualArraymUcOallocatorlETVirtualArraymUgRsPgRcLcLiteratorgR),0,G__get_linked_tagnum(&G__TADCClassDictLN_vectorlETVirtualArraymUcOallocatorlETVirtualArraymUgRsPgR));
   G__setnewtype(-1,NULL,0);
   G__search_typename2("reverse_iterator<iterator>",117,G__get_linked_tagnum(&G__TADCClassDictLN_reverse_iteratorlEvectorlETVirtualArraymUcOallocatorlETVirtualArraymUgRsPgRcLcLiteratorgR),0,G__get_linked_tagnum(&G__TADCClassDictLN_vectorlETVirtualArraymUcOallocatorlETVirtualArraymUgRsPgR));
   G__setnewtype(-1,NULL,0);
   G__search_typename2("iterator<std::bidirectional_iterator_tag,TObject*,std::ptrdiff_t,const TObject**,const TObject*&>",117,G__get_linked_tagnum(&G__TADCClassDictLN_iteratorlEbidirectional_iterator_tagcOTObjectmUcOlongcOconstsPTObjectmUmUcOconstsPTObjectmUaNgR),0,-1);
   G__setnewtype(-1,NULL,0);
   G__search_typename2("iterator<bidirectional_iterator_tag,TObject*,std::ptrdiff_t,const TObject**,const TObject*&>",117,G__get_linked_tagnum(&G__TADCClassDictLN_iteratorlEbidirectional_iterator_tagcOTObjectmUcOlongcOconstsPTObjectmUmUcOconstsPTObjectmUaNgR),0,-1);
   G__setnewtype(-1,NULL,0);
   G__search_typename2("iterator<bidirectional_iterator_tag,TObject*>",117,G__get_linked_tagnum(&G__TADCClassDictLN_iteratorlEbidirectional_iterator_tagcOTObjectmUcOlongcOconstsPTObjectmUmUcOconstsPTObjectmUaNgR),0,-1);
   G__setnewtype(-1,NULL,0);
   G__search_typename2("iterator<bidirectional_iterator_tag,TObject*,long>",117,G__get_linked_tagnum(&G__TADCClassDictLN_iteratorlEbidirectional_iterator_tagcOTObjectmUcOlongcOconstsPTObjectmUmUcOconstsPTObjectmUaNgR),0,-1);
   G__setnewtype(-1,NULL,0);
   G__search_typename2("iterator<bidirectional_iterator_tag,TObject*,long,const TObject**>",117,G__get_linked_tagnum(&G__TADCClassDictLN_iteratorlEbidirectional_iterator_tagcOTObjectmUcOlongcOconstsPTObjectmUmUcOconstsPTObjectmUaNgR),0,-1);
   G__setnewtype(-1,NULL,0);
}

/*********************************************************
* Data Member information setup/
*********************************************************/

   /* Setting up class,struct,union tag member variable */

   /* TADCClass */
static void G__setup_memvarTADCClass(void) {
   G__tag_memvar_setup(G__get_linked_tagnum(&G__TADCClassDictLN_TADCClass));
   { TADCClass *p; p=(TADCClass*)0x1000; if (p) { }
   G__memvar_setup((void*)0,105,0,0,-1,G__defined_typename("Int_t"),-1,4,"slot_number=",0,(char*)NULL);
   G__memvar_setup((void*)0,105,0,0,-1,G__defined_typename("Int_t"),-1,4,"channel_number=",0,(char*)NULL);
   G__memvar_setup((void*)0,117,0,0,G__get_linked_tagnum(&G__TADCClassDictLN_TArrayS),-1,-1,4,"adcValue=",0,(char*)NULL);
   G__memvar_setup((void*)0,85,0,0,G__get_linked_tagnum(&G__TADCClassDictLN_TClass),G__defined_typename("atomic_TClass_ptr"),-2,4,"fgIsA=",0,(char*)NULL);
   }
   G__tag_memvar_reset();
}

extern "C" void G__cpp_setup_memvarTADCClassDict() {
}
/***********************************************************
************************************************************
************************************************************
************************************************************
************************************************************
************************************************************
************************************************************
***********************************************************/

/*********************************************************
* Member function information setup for each class
*********************************************************/
static void G__setup_memfuncTADCClass(void) {
   /* TADCClass */
   G__tag_memfunc_setup(G__get_linked_tagnum(&G__TADCClassDictLN_TADCClass));
   G__memfunc_setup("TADCClass",786,G__TADCClassDict_217_0_1, 105, G__get_linked_tagnum(&G__TADCClassDictLN_TADCClass), -1, 0, 0, 1, 1, 0, "", (char*)NULL, (void*) NULL, 0);
   G__memfunc_setup("TADCClass",786,G__TADCClassDict_217_0_2, 105, G__get_linked_tagnum(&G__TADCClassDictLN_TADCClass), -1, 0, 1, 1, 1, 0, "i - - 0 - nrows", (char*)NULL, (void*) NULL, 0);
   G__memfunc_setup("TADCClass",786,G__TADCClassDict_217_0_3, 105, G__get_linked_tagnum(&G__TADCClassDictLN_TADCClass), -1, 0, 3, 1, 1, 0, 
"i - - 0 - slot i - - 0 - channel "
"i - - 0 - nrows", (char*)NULL, (void*) NULL, 0);
   G__memfunc_setup("TADCClass",786,G__TADCClassDict_217_0_4, 105, G__get_linked_tagnum(&G__TADCClassDictLN_TADCClass), -1, 0, 1, 1, 1, 0, "u 'TADCClass' - 11 - obj", (char*)NULL, (void*) NULL, 0);
   G__memfunc_setup("GetSlot",706,G__TADCClassDict_217_0_5, 105, -1, G__defined_typename("Int_t"), 0, 0, 1, 1, 0, "", (char*)NULL, (void*) NULL, 0);
   G__memfunc_setup("GetChannel",985,G__TADCClassDict_217_0_6, 105, -1, G__defined_typename("Int_t"), 0, 0, 1, 1, 0, "", (char*)NULL, (void*) NULL, 0);
   G__memfunc_setup("GetRows",715,G__TADCClassDict_217_0_7, 105, -1, G__defined_typename("Int_t"), 0, 0, 1, 1, 0, "", (char*)NULL, (void*) NULL, 0);
   G__memfunc_setup("SetValue",809,G__TADCClassDict_217_0_8, 121, -1, -1, 0, 2, 1, 1, 0, 
"i - - 0 - row i - - 0 - value", (char*)NULL, (void*) NULL, 0);
   G__memfunc_setup("GetValue",797,G__TADCClassDict_217_0_9, 115, -1, G__defined_typename("Short_t"), 0, 1, 1, 1, 0, "i - - 0 - row", (char*)NULL, (void*) NULL, 0);
   G__memfunc_setup("Init",404,G__TADCClassDict_217_0_10, 121, -1, -1, 0, 1, 1, 1, 0, "i - - 0 - nrows", (char*)NULL, (void*) NULL, 0);
   G__memfunc_setup("SetSlotChannel",1415,G__TADCClassDict_217_0_11, 121, -1, -1, 0, 2, 1, 1, 0, 
"i - - 0 - slot i - - 0 - channel", (char*)NULL, (void*) NULL, 0);
   G__memfunc_setup("Init",404,G__TADCClassDict_217_0_12, 121, -1, -1, 0, 3, 1, 1, 0, 
"i - - 0 - slot i - - 0 - channel "
"i - - 0 - nrows", (char*)NULL, (void*) NULL, 0);
   G__memfunc_setup("Data",378,G__TADCClassDict_217_0_13, 117, G__get_linked_tagnum(&G__TADCClassDictLN_TArrayS), -1, 1, 0, 1, 1, 0, "", (char*)NULL, (void*) NULL, 0);
   G__memfunc_setup("Class",502,G__TADCClassDict_217_0_14, 85, G__get_linked_tagnum(&G__TADCClassDictLN_TClass), -1, 0, 0, 3, 1, 0, "", (char*)NULL, (void*) G__func2void( (TClass* (*)())(&TADCClass::Class) ), 0);
   G__memfunc_setup("Class_Name",982,G__TADCClassDict_217_0_15, 67, -1, -1, 0, 0, 3, 1, 1, "", (char*)NULL, (void*) G__func2void( (const char* (*)())(&TADCClass::Class_Name) ), 0);
   G__memfunc_setup("Class_Version",1339,G__TADCClassDict_217_0_16, 115, -1, G__defined_typename("Version_t"), 0, 0, 3, 1, 0, "", (char*)NULL, (void*) G__func2void( (Version_t (*)())(&TADCClass::Class_Version) ), 0);
   G__memfunc_setup("Dictionary",1046,G__TADCClassDict_217_0_17, 121, -1, -1, 0, 0, 3, 1, 0, "", (char*)NULL, (void*) G__func2void( (void (*)())(&TADCClass::Dictionary) ), 0);
   G__memfunc_setup("IsA",253,(G__InterfaceMethod) NULL,85, G__get_linked_tagnum(&G__TADCClassDictLN_TClass), -1, 0, 0, 1, 1, 8, "", (char*)NULL, (void*) NULL, 1);
   G__memfunc_setup("ShowMembers",1132,(G__InterfaceMethod) NULL,121, -1, -1, 0, 1, 1, 1, 0, "u 'TMemberInspector' - 1 - -", (char*)NULL, (void*) NULL, 1);
   G__memfunc_setup("Streamer",835,(G__InterfaceMethod) NULL,121, -1, -1, 0, 1, 1, 1, 0, "u 'TBuffer' - 1 - -", (char*)NULL, (void*) NULL, 1);
   G__memfunc_setup("StreamerNVirtual",1656,G__TADCClassDict_217_0_21, 121, -1, -1, 0, 1, 1, 1, 0, "u 'TBuffer' - 1 - ClassDef_StreamerNVirtual_b", (char*)NULL, (void*) NULL, 0);
   G__memfunc_setup("DeclFileName",1145,G__TADCClassDict_217_0_22, 67, -1, -1, 0, 0, 3, 1, 1, "", (char*)NULL, (void*) G__func2void( (const char* (*)())(&TADCClass::DeclFileName) ), 0);
   G__memfunc_setup("ImplFileLine",1178,G__TADCClassDict_217_0_23, 105, -1, -1, 0, 0, 3, 1, 0, "", (char*)NULL, (void*) G__func2void( (int (*)())(&TADCClass::ImplFileLine) ), 0);
   G__memfunc_setup("ImplFileName",1171,G__TADCClassDict_217_0_24, 67, -1, -1, 0, 0, 3, 1, 1, "", (char*)NULL, (void*) G__func2void( (const char* (*)())(&TADCClass::ImplFileName) ), 0);
   G__memfunc_setup("DeclFileLine",1152,G__TADCClassDict_217_0_25, 105, -1, -1, 0, 0, 3, 1, 0, "", (char*)NULL, (void*) G__func2void( (int (*)())(&TADCClass::DeclFileLine) ), 0);
   // automatic destructor
   G__memfunc_setup("~TADCClass", 912, G__TADCClassDict_217_0_26, (int) ('y'), -1, -1, 0, 0, 1, 1, 0, "", (char*) NULL, (void*) NULL, 1);
   // automatic assignment operator
   G__memfunc_setup("operator=", 937, G__TADCClassDict_217_0_27, (int) ('u'), G__get_linked_tagnum(&G__TADCClassDictLN_TADCClass), -1, 1, 1, 1, 1, 0, "u 'TADCClass' - 11 - -", (char*) NULL, (void*) NULL, 0);
   G__tag_memfunc_reset();
}


/*********************************************************
* Member function information setup
*********************************************************/
extern "C" void G__cpp_setup_memfuncTADCClassDict() {
}

/*********************************************************
* Global variable information setup for each class
*********************************************************/
static void G__cpp_setup_global0() {

   /* Setting up global variables */
   G__resetplocal();

}

static void G__cpp_setup_global1() {

   G__resetglobalenv();
}
extern "C" void G__cpp_setup_globalTADCClassDict() {
  G__cpp_setup_global0();
  G__cpp_setup_global1();
}

/*********************************************************
* Global function information setup for each class
*********************************************************/
static void G__cpp_setup_func0() {
   G__lastifuncposition();

}

static void G__cpp_setup_func1() {
}

static void G__cpp_setup_func2() {
}

static void G__cpp_setup_func3() {
}

static void G__cpp_setup_func4() {
}

static void G__cpp_setup_func5() {
}

static void G__cpp_setup_func6() {
}

static void G__cpp_setup_func7() {
}

static void G__cpp_setup_func8() {
}

static void G__cpp_setup_func9() {
}

static void G__cpp_setup_func10() {
}

static void G__cpp_setup_func11() {
}

static void G__cpp_setup_func12() {
}

static void G__cpp_setup_func13() {

   G__resetifuncposition();
}

extern "C" void G__cpp_setup_funcTADCClassDict() {
  G__cpp_setup_func0();
  G__cpp_setup_func1();
  G__cpp_setup_func2();
  G__cpp_setup_func3();
  G__cpp_setup_func4();
  G__cpp_setup_func5();
  G__cpp_setup_func6();
  G__cpp_setup_func7();
  G__cpp_setup_func8();
  G__cpp_setup_func9();
  G__cpp_setup_func10();
  G__cpp_setup_func11();
  G__cpp_setup_func12();
  G__cpp_setup_func13();
}

/*********************************************************
* Class,struct,union,enum tag information setup
*********************************************************/
/* Setup class/struct taginfo */
G__linked_taginfo G__TADCClassDictLN_TClass = { "TClass" , 99 , -1 };
G__linked_taginfo G__TADCClassDictLN_TBuffer = { "TBuffer" , 99 , -1 };
G__linked_taginfo G__TADCClassDictLN_TMemberInspector = { "TMemberInspector" , 99 , -1 };
G__linked_taginfo G__TADCClassDictLN_TObject = { "TObject" , 99 , -1 };
G__linked_taginfo G__TADCClassDictLN_vectorlEROOTcLcLTSchemaHelpercOallocatorlEROOTcLcLTSchemaHelpergRsPgR = { "vector<ROOT::TSchemaHelper,allocator<ROOT::TSchemaHelper> >" , 99 , -1 };
G__linked_taginfo G__TADCClassDictLN_reverse_iteratorlEvectorlEROOTcLcLTSchemaHelpercOallocatorlEROOTcLcLTSchemaHelpergRsPgRcLcLiteratorgR = { "reverse_iterator<vector<ROOT::TSchemaHelper,allocator<ROOT::TSchemaHelper> >::iterator>" , 99 , -1 };
G__linked_taginfo G__TADCClassDictLN_vectorlETVirtualArraymUcOallocatorlETVirtualArraymUgRsPgR = { "vector<TVirtualArray*,allocator<TVirtualArray*> >" , 99 , -1 };
G__linked_taginfo G__TADCClassDictLN_reverse_iteratorlEvectorlETVirtualArraymUcOallocatorlETVirtualArraymUgRsPgRcLcLiteratorgR = { "reverse_iterator<vector<TVirtualArray*,allocator<TVirtualArray*> >::iterator>" , 99 , -1 };
G__linked_taginfo G__TADCClassDictLN_iteratorlEbidirectional_iterator_tagcOTObjectmUcOlongcOconstsPTObjectmUmUcOconstsPTObjectmUaNgR = { "iterator<bidirectional_iterator_tag,TObject*,long,const TObject**,const TObject*&>" , 115 , -1 };
G__linked_taginfo G__TADCClassDictLN_TArrayS = { "TArrayS" , 99 , -1 };
G__linked_taginfo G__TADCClassDictLN_TADCClass = { "TADCClass" , 99 , -1 };

/* Reset class/struct taginfo */
extern "C" void G__cpp_reset_tagtableTADCClassDict() {
  G__TADCClassDictLN_TClass.tagnum = -1 ;
  G__TADCClassDictLN_TBuffer.tagnum = -1 ;
  G__TADCClassDictLN_TMemberInspector.tagnum = -1 ;
  G__TADCClassDictLN_TObject.tagnum = -1 ;
  G__TADCClassDictLN_vectorlEROOTcLcLTSchemaHelpercOallocatorlEROOTcLcLTSchemaHelpergRsPgR.tagnum = -1 ;
  G__TADCClassDictLN_reverse_iteratorlEvectorlEROOTcLcLTSchemaHelpercOallocatorlEROOTcLcLTSchemaHelpergRsPgRcLcLiteratorgR.tagnum = -1 ;
  G__TADCClassDictLN_vectorlETVirtualArraymUcOallocatorlETVirtualArraymUgRsPgR.tagnum = -1 ;
  G__TADCClassDictLN_reverse_iteratorlEvectorlETVirtualArraymUcOallocatorlETVirtualArraymUgRsPgRcLcLiteratorgR.tagnum = -1 ;
  G__TADCClassDictLN_iteratorlEbidirectional_iterator_tagcOTObjectmUcOlongcOconstsPTObjectmUmUcOconstsPTObjectmUaNgR.tagnum = -1 ;
  G__TADCClassDictLN_TArrayS.tagnum = -1 ;
  G__TADCClassDictLN_TADCClass.tagnum = -1 ;
}


extern "C" void G__cpp_setup_tagtableTADCClassDict() {

   /* Setting up class,struct,union tag entry */
   G__get_linked_tagnum_fwd(&G__TADCClassDictLN_TClass);
   G__get_linked_tagnum_fwd(&G__TADCClassDictLN_TBuffer);
   G__get_linked_tagnum_fwd(&G__TADCClassDictLN_TMemberInspector);
   G__get_linked_tagnum_fwd(&G__TADCClassDictLN_TObject);
   G__get_linked_tagnum_fwd(&G__TADCClassDictLN_vectorlEROOTcLcLTSchemaHelpercOallocatorlEROOTcLcLTSchemaHelpergRsPgR);
   G__get_linked_tagnum_fwd(&G__TADCClassDictLN_reverse_iteratorlEvectorlEROOTcLcLTSchemaHelpercOallocatorlEROOTcLcLTSchemaHelpergRsPgRcLcLiteratorgR);
   G__get_linked_tagnum_fwd(&G__TADCClassDictLN_vectorlETVirtualArraymUcOallocatorlETVirtualArraymUgRsPgR);
   G__get_linked_tagnum_fwd(&G__TADCClassDictLN_reverse_iteratorlEvectorlETVirtualArraymUcOallocatorlETVirtualArraymUgRsPgRcLcLiteratorgR);
   G__get_linked_tagnum_fwd(&G__TADCClassDictLN_iteratorlEbidirectional_iterator_tagcOTObjectmUcOlongcOconstsPTObjectmUmUcOconstsPTObjectmUaNgR);
   G__get_linked_tagnum_fwd(&G__TADCClassDictLN_TArrayS);
   G__tagtable_setup(G__get_linked_tagnum_fwd(&G__TADCClassDictLN_TADCClass),sizeof(TADCClass),-1,63232,(char*)NULL,G__setup_memvarTADCClass,G__setup_memfuncTADCClass);
}
extern "C" void G__cpp_setupTADCClassDict(void) {
  G__check_setup_version(30051515,"G__cpp_setupTADCClassDict()");
  G__set_cpp_environmentTADCClassDict();
  G__cpp_setup_tagtableTADCClassDict();

  G__cpp_setup_inheritanceTADCClassDict();

  G__cpp_setup_typetableTADCClassDict();

  G__cpp_setup_memvarTADCClassDict();

  G__cpp_setup_memfuncTADCClassDict();
  G__cpp_setup_globalTADCClassDict();
  G__cpp_setup_funcTADCClassDict();

   if(0==G__getsizep2memfunc()) G__get_sizep2memfuncTADCClassDict();
  return;
}
class G__cpp_setup_initTADCClassDict {
  public:
    G__cpp_setup_initTADCClassDict() { G__add_setup_func("TADCClassDict",(G__incsetup)(&G__cpp_setupTADCClassDict)); G__call_setup_funcs(); }
   ~G__cpp_setup_initTADCClassDict() { G__remove_setup_func("TADCClassDict"); }
};
G__cpp_setup_initTADCClassDict G__cpp_setup_initializerTADCClassDict;


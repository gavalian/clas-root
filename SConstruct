#-----------------------------------------------------------------------
#  SConstruct file for compiling the GooLibrary (date: 09/23/2011)
#  The New version includes Configure script for scons to determine
#  if the system has all neccessary components installed.
#
#  NOTE: Mainly needed libraries are HDF5 - for data input/output
#        also Minuit2 is needed if MINUIT fitting is to be used.
#        if   Minuit2 does not exist the genetic fitting algorythm
#        can be used to do the fits.
#-----------------------------------------------------------------------
import glob
import os
import sys
from loadROOTLibrary import initROOTLibrary
#-----------------------------------------------------------------------
#  Trying to Load modules for compilation scripts
#-----------------------------------------------------------------------
if os.getenv('ROOTSYS') == None:
   print '****************************************'
   print '**************   ERROR  ****************'
   print '****************************************'
   print '\n The environmental variable ROOTSYS is not set. Please set it'
   print '\n\n'
   sys.exit(1)
#-----------------------------------------------------------------------
#  Loaded the Library Files.
#-----------------------------------------------------------------------
#env = Environment(CPPPATH=["/opt/local/include","include",".","src/evioroot","src/reader"])
env = Environment(CPPPATH=["/opt/local/include","include",".","src/root","src/reader","src/tools"])
env.Append(ENV = os.environ)
env.Append(CPPPATH=["src/root","src/evio"])
env.Append(CCFLAGS=["-O2","-fPIC","-m64","-fmessage-length=0","-g"])
#env.Append(CCFLAGS=["-O2","-fPIC","-m32","-fmessage-length=0"])
env.Append(LIBPATH=["/opt/local/lib","/usr/lib","lib"])
#env.Append(LIBS=["iG5io"])
#-----------------------------------------------------------------------
#  Parsing input Arguments
#-----------------------------------------------------------------------
compileMode = ARGUMENTS.get('debug',0)

if ARGUMENTS.get('verbose') != '1':
   print 'Entering quite mode. type scons verbose=1 for more output'
#   env['CXXCOMSTR']  = "--> Compiling : $TARGET"
#   env['CCCOMSTR']   = "--> Compiling : $TARGET"
   env['LINKCOMSTR'] = "[==] --> Linking : $TARGET"
#   env['ARCOMSTR']   = "[==] --> Archiving : $TARGET"
   env.Append(CCFLAGS=["-w"])

if int(compileMode):
   print '-->  Compiling library in debug mode...'
   env.Append(CCFLAGS=['-g'])

if os.getenv('OSTYPE') != None:
   if os.getenv('OSTYPE')=='darwin':
      env.Append(CCFLAGS=['-DDarwin'])
#------------------------------------------------------------------------
# Check Essential setup of enviromental variables (GOOLIB and HDF5_DIR) -
#------------------------------------------------------------------------
conf = Configure(env)

if not conf.CheckLib('libexpat'):
   print '\n---> Please install XML2 library..'
   sys.exit(1)

if not conf.CheckLib('libdl'):
   sys.exit(1)

if not conf.CheckLib('libpthread'):
   sys.exit(1)

env = conf.Finish()

#------------------------------------------------------------------------
#  Compile the libraries
#------------------------------------------------------------------------
# List of the files for HDF5/IO library
#
#rootcint -f TEventReaderDict.cc -c -p -I../writer TEventReader.h TEventReaderLinkDef.h
#env.Command('env','','env | grep LD_',ENV = {'LD_LIBRARY_PATH','ROOT'})

listDICT = [
'src/root/TEvioFileReaderDict.cc',
'src/root/TFileEvioDict.cc',
'src/root/TTreeEvioDict.cc',
'src/root/TXMLBankDictionaryDict.cc',
'src/root/TBankDescriptorDict.cc',
'src/root/TADCClassDict.cc',
'src/root/TEvioDataBankDict.cc',
'src/root/TEvioDataDescriptorDict.cc',
'src/root/TEvioDataEventDict.cc',
'src/root/TClas12ReaderDict.cc',
'src/tools/TPhysicsEventDict.cc',
'src/tools/TEventOperationDict.cc'
]

env.Clean('dict',listDICT)

env.Command('TEvioFileReaderDict.cc','',os.getenv('ROOTSYS') + '/bin/rootcint -f src/root/TEvioFileReaderDict.cc -c -p -Isrc/reader -Isrc/evio -Isrc/root src/root/TEvioFileReader.h src/root/TEvioFileReaderLinkDef.h')
env.Command('TFileEvioDict.cc','',os.getenv('ROOTSYS') + '/bin/rootcint -f src/root/TFileEvioDict.cc -c -p -Isrc/reader -Isrc/evio -Isrc/root src/root/TFileEvio.h src/root/TFileEvioLinkDef.h')
env.Command('TTreeEvioDict.cc','',os.getenv('ROOTSYS') + '/bin/rootcint -f src/root/TTreeEvioDict.cc -c -p -Isrc/reader -Isrc/evio -Isrc/root src/root/TTreeEvio.h src/root/TTreeEvioLinkDef.h')
env.Command('TXMLBankDictionaryDict.cc','',os.getenv('ROOTSYS') + '/bin/rootcint -f src/root/TXMLBankDictionaryDict.cc -c -p -Isrc/reader -Isrc/evio -Isrc/root src/root/TXMLBankDictionary.h src/root/TXMLBankDictionaryLinkDef.h')
env.Command('TBankDescriptorDict.cc','',os.getenv('ROOTSYS') + '/bin/rootcint -f src/root/TBankDescriptorDict.cc -c -p -Isrc/reader -Isrc/evio -Isrc/root src/root/TBankDescriptor.h src/root/TBankDescriptorLinkDef.h')
env.Command('TADCClassDict.cc','',os.getenv('ROOTSYS') + '/bin/rootcint -f src/root/TADCClassDict.cc -c -p -Isrc/reader -Isrc/evio -Isrc/root src/root/TADCClass.h src/root/TADCClassLinkDef.h')
env.Command('TEvioDataBankDict.cc','',os.getenv('ROOTSYS') + '/bin/rootcint -f src/root/TEvioDataBankDict.cc -c -p -Isrc/reader -Isrc/evio -Isrc/root src/root/TEvioDataBank.h src/root/TEvioDataBankLinkDef.h')
env.Command('TEvioDataDescriptorDict.cc','',os.getenv('ROOTSYS') + '/bin/rootcint -f src/root/TEvioDataDescriptorDict.cc -c -p -Isrc/reader -Isrc/evio -Isrc/root src/root/TEvioDataDescriptor.h src/root/TEvioDataDescriptorLinkDef.h')
env.Command('TEvioDataEventDict.cc','',os.getenv('ROOTSYS') + '/bin/rootcint -f src/root/TEvioDataEventDict.cc -c -p -Isrc/reader -Isrc/evio -Isrc/root src/root/TEvioDataEvent.h src/root/TEvioDataEventLinkDef.h')
env.Command('TClas12ReaderDict.cc','',os.getenv('ROOTSYS') + '/bin/rootcint -f src/root/TClas12ReaderDict.cc -c -p -Isrc/reader -Isrc/tools -Isrc/evio -Isrc/root src/root/TClas12Reader.h src/root/TClas12ReaderLinkDef.h')
env.Command('TPhysicsEventDict.cc','',os.getenv('ROOTSYS') + '/bin/rootcint -f src/tools/TPhysicsEventDict.cc -c -p -Isrc/reader -Isrc/tools -Isrc/evio -Isrc/root src/tools/TPhysicsEvent.h src/tools/TPhysicsEventLinkDef.h')
env.Command('TEventOperationDict.cc','',os.getenv('ROOTSYS') + '/bin/rootcint -f src/tools/TEventOperationDict.cc -c -p -Isrc/reader -Isrc/tools -Isrc/evio -Isrc/root src/tools/TEventOperation.h src/tools/TEventOperationLinkDef.h')

initROOTLibrary(env)

env.Append(LIBS=["XMLParser","XMLIO"])

listEVIOLIB = glob.glob('src/evio/*.cc') + glob.glob('src/evio/*.c')
listROOTLIB = glob.glob('src/root/*.cc')
listCPPLIB  = glob.glob('src/reader/*.cc')
listTOOLS   = glob.glob('src/tools/*.cc')
listDECODER = ['src/main/runCompositeDecoder.cc']

if 'src/root/TTreeEvioDict.cc' in listROOTLIB:
   listDICT = []

env.SharedLibrary(target="lib/libEvioRoot.so",source = listROOTLIB + listEVIOLIB + listCPPLIB + listTOOLS + listDICT)
env.Library(target="lib/libEvioClas12.a",source = listCPPLIB)
#env.Program(target="bin/runCompositeDecoder",source = listEVIOLIB + listCPPLIB + listDECODER)



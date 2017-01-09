#----------------------------------------
# HDF5 Library PATHs
#----------------------------------------

import os

def  initROOTLibrary(env):
    OSENV   = os.environ
    ROOTSYS = OSENV['ROOTSYS']
    env.Append(CXXPATH=ROOTSYS+'/include')
    env.Append(CXXPATH=ROOTSYS+'/include/root')
    rootlibs = []
    root_config_libs = os.popen('$ROOTSYS/bin/root-config --glibs').readline()[:-1].split()

    for item in root_config_libs:
        if item[:2] == '-l':
            rootlibs += [item[2:]]

    rootlibs.append('EG')
    env.Append(LIBPATH=os.popen('$ROOTSYS/bin/root-config --libdir').readline()[:-1])
    env.Append(LIBS=rootlibs)


    rootflags = os.popen('$ROOTSYS/bin/root-config --cflags').readline()[:-1].split() 
    env.Append(CXXFLAGS=rootflags)

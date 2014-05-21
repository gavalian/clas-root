#----------------------------------------
# HDF5 Library PATHs
#----------------------------------------

import os

def  initROOTLibrary(env):
    OSENV   = os.environ
    ROOTSYS = OSENV['ROOTSYS']
    env.Append(CPPPATH=ROOTSYS+'/include')
    env.Append(CPPPATH=ROOTSYS+'/include/root')
    rootlibs = []
    root_config_libs = os.popen('$ROOTSYS/bin/root-config --glibs').readline()[:-1].split()

    for item in root_config_libs:
        if item[:2] == '-l':
            rootlibs += [item[2:]]

    rootlibs.append('EG')
    env.Append(LIBPATH=[ROOTSYS+'/lib'])
    env.Append(LIBPATH=[ROOTSYS+'/lib/root'])
    env.Append(LIBS=rootlibs)

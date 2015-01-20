#ifndef PROCESSESFACTORY_H
#define PROCESSESFACTORY_H

#include "processesimpl.h"

class ProcessesFactory
{
public:
    ProcessesFactory();
    
    static ProcessesFactory * GetProcessesFactory();
    
    virtual ProcessesImpl * MakeProcesses() = 0;
};

#endif

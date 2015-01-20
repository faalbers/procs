#ifndef OSXPROCESSESIMPL_H
#define OSXPROCESSESIMPL_H

#include "../../processesimpl.h"

class OSXProcessesImpl
    :   public ProcessesImpl
{
public:
    OSXProcessesImpl();

    virtual int Scan();


};

#endif

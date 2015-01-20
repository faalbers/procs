#ifndef OSXFACTORY_H
#define OSXFACTORY_H

#include "../../processesfactory.h"
#include "../../processesimpl.h"

class OSXFactory
    :   public ProcessesFactory
{
public:
    OSXFactory();

    static OSXFactory * GetFactoryInstance();

    virtual ProcessesImpl * MakeProcesses();
};

#endif

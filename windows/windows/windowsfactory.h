#ifndef WINDOWSFACTORY_H
#define WINDOWSFACTORY_H

#include "../../processesfactory.h"
#include "../../processesimpl.h"

class WindowsFactory
    :   public ProcessesFactory
{
public:
    WindowsFactory();

    static WindowsFactory * GetFactoryInstance();

    virtual ProcessesImpl * MakeProcesses();
};

#endif

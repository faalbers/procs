#ifndef LINUXFACTORY_H
#define LINUXFACTORY_H

#include "../../processesfactory.h"
#include "../../processesimpl.h"

class LinuxFactory
    :   public ProcessesFactory
{
public:
    LinuxFactory();

    static LinuxFactory * GetFactoryInstance();

    virtual ProcessesImpl * MakeProcesses();
};

#endif

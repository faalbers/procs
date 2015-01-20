#ifndef LINUXPROCESSESIMPL_H
#define LINUXPROCESSESIMPL_H

#include "../../processesimpl.h"

class LinuxProcessesImpl
    :   public ProcessesImpl
{
public:
    LinuxProcessesImpl();
    virtual ~LinuxProcessesImpl();

    virtual int Scan();

};

#endif

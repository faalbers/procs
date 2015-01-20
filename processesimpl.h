#ifndef PROCESSESIMPL_H
#define PROCESSESIMPL_H

#include "process.h"
#include <vector>

class ProcessesImpl
{
public:
    ProcessesImpl();

    virtual int Scan() = 0;
    int GetCount();
    const char * GetName(const int which);
    int GetPID(const int which);

protected:
    std::vector <Process> m_processList;
};

#endif

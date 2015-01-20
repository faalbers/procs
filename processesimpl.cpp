#include "processesimpl.h"

#include <iostream>

ProcessesImpl::ProcessesImpl()
{
    //std::cout << "Construct: ProcessesImpl" << std::endl;
}

int ProcessesImpl::GetCount()
{
    return (int) m_processList.size();
}

const char * ProcessesImpl::GetName(const int which)
{
    return m_processList[which].GetName();
}

int ProcessesImpl::GetPID(const int which)
{
    return m_processList[which].GetPID();
}



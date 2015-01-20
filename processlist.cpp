#include "processlist.h"
#include "processesfactory.h"

#include <iostream>

ProcessList::ProcessList()
    : m_processesImpl(0)
{
    //std::cout << "Construct: ProcessList" << std::endl;
    ProcessesFactory *factory =
        ProcessesFactory::GetProcessesFactory();
    if (factory)
        m_processesImpl = factory->MakeProcesses();
}

int ProcessList::Scan()
{
    //std::cout << "Running: ProcessList::Scan()" << std::endl;
    if(m_processesImpl)
        return m_processesImpl->Scan();
    return -1;
}

int ProcessList::GetCount()
{
    //std::cout << "Running: ProcessList::GetCount()" << std::endl;
    if(m_processesImpl)
        return m_processesImpl->GetCount();
    return -1;
}

const char * ProcessList::GetName(const int i)
{
    //std::cout << "Running: ProcessList::GetName()" << std::endl;
    if(m_processesImpl)
        return m_processesImpl->GetName(i);
    return 0;
}

int ProcessList::GetPID(const int i)
{
    //std::cout << "Running: ProcessList::GetPID()" << std::endl;
    if(m_processesImpl)
        return m_processesImpl->GetPID(i);
    return -1;
}


#include "osxprocessesimpl.h"

#include <iostream>

OSXProcessesImpl::OSXProcessesImpl()
{
    //std::cout << "Construct: OSXProcessesImpl" << std::endl;
}

int OSXProcessesImpl::Scan()
{
    //std::cout << "Running: OSXProcessesImpl::Scan()" << std::endl;
    
    m_processList.clear();
    
    return 0;
}



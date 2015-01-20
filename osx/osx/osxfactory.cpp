#include "osxfactory.h"

#include "osxprocessesimpl.h"

#include <iostream>

OSXFactory::OSXFactory()
{
    //std::cout << "Construct: OSXFactory" << std::endl;
}

OSXFactory * OSXFactory::GetFactoryInstance()
{
    //std::cout << "Run Static: OSXFactory::GetFactoryInstance" << std::endl;

    static OSXFactory * factory = 0;

    if (! factory)
        factory = new OSXFactory;
    return factory;
}

ProcessesImpl * OSXFactory::MakeProcesses()
{
    //std::cout << "Run: OSXFactory->MakeProcesses" << std::endl;
    
    return new OSXProcessesImpl;
}


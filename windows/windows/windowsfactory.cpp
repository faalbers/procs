#include "windowsfactory.h"

#include "windowsprocessesimpl.h"

#include <iostream>

WindowsFactory::WindowsFactory()
{
    //std::cout << "Construct: WindowsFactory" << std::endl;
}

WindowsFactory * WindowsFactory::GetFactoryInstance()
{
    //std::cout << "Run Static: WindowsFactory::GetFactoryInstance" << std::endl;

    static WindowsFactory * factory = 0;

    if (! factory)
        factory = new WindowsFactory;
    return factory;
}

ProcessesImpl * WindowsFactory::MakeProcesses()
{
    //std::cout << "Run: WindowsFactory->MakeProcesses" << std::endl;
    
    return new WindowsProcessesImpl;
}


#include "linuxfactory.h"

#include "linuxprocessesimpl.h"

#include <iostream>

LinuxFactory::LinuxFactory()
{
    //std::cout << "Construct: LinuxFactory" << std::endl;
}

LinuxFactory * LinuxFactory::GetFactoryInstance()
{
    //std::cout << "Run Static: LinuxFactory::GetFactoryInstance" << std::endl;

    static LinuxFactory * factory = 0;

    if (! factory)
        factory = new LinuxFactory;
    return factory;
}

ProcessesImpl * LinuxFactory::MakeProcesses()
{
    //std::cout << "Run: LinuxFactory->MakeProcesses" << std::endl;
    
    return new LinuxProcessesImpl;
}


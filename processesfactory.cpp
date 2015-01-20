#include "processesfactory.h"

#ifdef HAVE_LINUX
#include "linux/linux/linuxfactory.h"
#endif

#ifdef HAVE_WINDOWS
#include "windows/windows/windowsfactory.h"
#endif

#ifdef HAVE_OSX
#include "osx/osx/osxfactory.h"
#endif

#include <iostream>

ProcessesFactory::ProcessesFactory()       
{
    //std::cout << "Construct: ProcessesFactory" << std::endl;
}

ProcessesFactory * ProcessesFactory::GetProcessesFactory()
{
    //std::cout << "Run Static: ProcessesFactory::GetProcessesFactory" << std::endl;
    // Get platform specific processes factory
    static ProcessesFactory *processesFactory = 0;

    if (!processesFactory) {
#ifdef HAVE_LINUX
        processesFactory = LinuxFactory::GetFactoryInstance();
#endif

#ifdef HAVE_WINDOWS
        processesFactory = WindowsFactory::GetFactoryInstance();
#endif

#ifdef HAVE_OSX
        processesFactory = OSXFactory::GetFactoryInstance();
#endif
    }

    return processesFactory;
}


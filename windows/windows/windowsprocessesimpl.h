#ifndef WINDOWSPROCESSESIMPL_H
#define WINDOWSPROCESSESIMPL_H

#include "../../processesimpl.h"
#include <windows.h>
//#include <stdio.h>
//#include <tchar.h>
#include "psapi.h"

class WindowsProcessesImpl
    :   public ProcessesImpl
{
public:
    WindowsProcessesImpl();

    virtual int Scan();

private:
    void printProcessesNameAndID( DWORD processID );
    void ScanProcesses();
};

#endif

#include "windowsprocessesimpl.h"

#include <iostream>

WindowsProcessesImpl::WindowsProcessesImpl()
{
    //std::cout << "Construct: WindowsProcessesImpl" << std::endl;
}

int WindowsProcessesImpl::Scan()
{
    //std::cout << "Running: WindowsProcessesImpl::Scan()" << std::endl;
    
    m_processList.clear();
    
    ScanProcesses();
    
    return 0;
}

void WindowsProcessesImpl::printProcessesNameAndID( DWORD processID )
{
    TCHAR szProcessName[MAX_PATH] = TEXT("<unknown>");
    
    // Get handle to process
    HANDLE hProcess = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ,
        FALSE, processID);
    
    // Get the process name
    if (NULL != hProcess) {
        HMODULE hMod;
        DWORD cbNeeded;
        
        if (EnumProcessModules(hProcess, &hMod, sizeof(hMod), &cbNeeded)) {
            GetModuleBaseName(hProcess, hMod, szProcessName,
                sizeof(szProcessName)/sizeof(TCHAR));
        }
    }
    
    // Print the process name and identifier
    Process proc;
    proc.SetPID(processID);
    proc.SetName(szProcessName);
    m_processList.push_back(proc);
}

void WindowsProcessesImpl::ScanProcesses()
{
    // Get list of process identifiers
    DWORD aProcesses[1024], cbNeeded, cProcesses;
    unsigned int i;

    if (!EnumProcesses(aProcesses, sizeof(aProcesses), &cbNeeded))
        return;
    
    // Calculate how many process identifiers where returned
    cProcesses = cbNeeded / sizeof(DWORD);
    
    // Calculate how many process identifiers for each process
    for ( i = 0; i < cProcesses; i++ )
        if (aProcesses[i] != 0)
            printProcessesNameAndID( aProcesses[i]);
}


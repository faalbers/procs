#ifndef PROCESSLIST_H
#define PROCESSLIST_H

#include "processesimpl.h"

/*  ProcessList
    List of platform independent commands to handel the process list
*/
class ProcessList {
public:
    ProcessList();

    // read the current list of processes
    int Scan();

    // get number of processes
    int GetCount();

    // get name of the ith process found
    const char * GetName(const int i);
    
    // get process ID the ith process found
    int GetPID(const int i);
    
private:
    ProcessesImpl   *m_processesImpl;
    
};

#endif


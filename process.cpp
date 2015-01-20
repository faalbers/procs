#include "process.h"
#include <string.h>

#include <iostream>

Process::Process()
    :   pid(0)
{
    memset(name, '\0', sizeof(name));
}

void Process::SetPID(const int i)
{
    pid = i;
}

void Process::SetName(const char * n)
{
    memcpy(name, n, 1024);
}

char * Process::GetName()
{
    return name;
}

int Process::GetPID()
{
    return pid;
}

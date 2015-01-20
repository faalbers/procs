#include <stdio.h>
#include "../../processlist.h"

#include <iostream>

int main(int , char **)
{
    ProcessList processList;
    processList.Scan();

    int count = (int) processList.GetCount();
    for (int i = 0; i < count; i++) {
        printf("%d %s\n", processList.GetPID(i), processList.GetName(i));
    }
    
    return 0;
}


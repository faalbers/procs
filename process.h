#ifndef PROCESS_H
#define PROCESS_H

class Process {
public:
    Process();
    
    void SetPID(const int i);
    void SetName(const char * n);
    
    char * GetName();
    int GetPID();

private:
    int     pid;
    char    name[1024];
};

#endif


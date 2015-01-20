#include "linuxprocessesimpl.h"

#include <string.h>
#include <stdlib.h>
//#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
//#include <ctype.h>
#include <dirent.h>

#include <iostream>

LinuxProcessesImpl::LinuxProcessesImpl()
{
    //std::cout << "Construct: LinuxProcessesImpl" << std::endl;
}

LinuxProcessesImpl::~LinuxProcessesImpl()
{
}

int LinuxProcessesImpl::Scan()
{
    //std::cout << "Running: LinuxProcessesImpl::Scan()" << std::endl;
    
    DIR *dir;
    m_processList.clear();

    dir = opendir("/proc");
    
    if ( dir == 0 )
        return 0;
    
    std::string name;
    struct dirent *dirEnt;
    struct stat statBuf;

    while ((dirEnt = readdir(dir))) {
        name = "/proc/";
        name += dirEnt->d_name;
        
        if (!stat(name.c_str(), &statBuf)) {
            char *p;
            p = dirEnt->d_name;
            bool allDigits = true;
            while (*p) {
                if (!isdigit(*p)) {
                    allDigits = false;
                    break;
                }
                p++;
            }
            if (allDigits) {
                Process proc;
                
                proc.SetPID(atoi(dirEnt->d_name));
                std::string path = name + std::string("/cmdline");
                int fd = open(path.c_str(), O_RDONLY);
                if (fd != -1) {
                    char buf[1024];
                    memset(buf, '\0', sizeof(buf));
                    int n;
                    if ((n = read(fd, buf, sizeof(buf)-1)) > 0 ) {
                        proc.SetName(buf);
                        m_processList.push_back(proc);
                    } else if (n == 0) {
                        path = name + std::string("/status");
                        int fd2 = open(path.c_str(), O_RDONLY);
                        if (fd2 != -1) {
                            memset(buf, '\0', sizeof(buf));
                            if ((n = read(fd2, buf, sizeof(buf)-1)) > 0) {
                                char *p = buf;
                                while (*p) {
                                    if (*p == '\n') {
                                        *p = '\0';
                                        break;
                                    }
                                    p++;
                                }
                                if ((p = strstr(buf, "Name:")))  {
                                    while (*p && isspace(*p))
                                        p++;
                                } else
                                    p = buf;
                                proc.SetName(p);
                                m_processList.push_back(proc);
                            }
                            close(fd2);
                        }
                    }
                    close(fd);
                }
            }
        }
    }
    closedir(dir);
    
    return m_processList.size();;
}


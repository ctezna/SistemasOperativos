#include <fcntl.h> /* for 0_* constants */
#include <sys/stat.h>  /* for mode constants */
#include <semaphore.h>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cerrno>
#include "names.h"

using namespace std;

int main (void) {
    
    for(int i = 0; i < nSem; ++i){
        if (sem_unlink(names[i]) == -1){
            cerr << "Error removing semaphore: " << strerror(errno)
            << endl;
        }
    }

    return EXIT_SUCCESS;
}


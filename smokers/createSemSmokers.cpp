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
    
    sem_t *semaphores[3];

    for (long unsigned i = 0; i < 3; ++i){
        semaphores[i] = sem_open(names[i],
                        O_CREAT | O_EXCL,
                        S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP, 0);

        if(semaphores[i] == nullptr){
            cerr << "Error creating semaphores: " << strerror(errno) << endl;
        }
        sem_close(semaphores[i]);
    }
    return EXIT_SUCCESS;

}
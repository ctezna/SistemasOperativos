#include <fcntl.h> /* for 0_* constants */
#include <sys/stat.h>  /* for mode constants */
#include <semaphore.h>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cerrno>
#include "names.h"

using namespace std;

static void agent(sem_t *[]);

int main (void){
    
    sem_t *semaphores[nSem];

    for(int i = 0; i < nSem; ++i){
        semaphores[i] = sem_open(names[i], 0);
    }
    

    agent(semaphores);

    return EXIT_SUCCESS;
}


static void agent(sem_t *semaphores[]) {
    for (;;){
        int val = rand() % 3;
        cout << "Serving ingredients . . ." << endl;
        sem_post(semaphores[val]);
        sem_wait(semaphores[nSem-1]);
    }
}
#include <iostream>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <cstdlib>
#include <cerrno>
#include <cstring>

using namespace std;

static void usage(const char* progname);

//removeSemaphore <semkey>

int main(int argc, char *argv[]){
    if(argc != 2) usage(argv[0]);

    int key = atoi(argv[1]);
    int semid = semget(key, 1, 0660);

    if (semid == -1){
        cerr << "Error accessing semaphore: "
             << strerror(errno) << endl;
        return EXIT_FAILURE;
    }

    if (semctl(semid, 0, IPC_RMID) == -1){
        cerr << "Error removing semaphore: "
             << strerror(errno) << endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

static void usage(const char* progname){
    cerr << "Uso: " << progname
         << " <semkey> " << endl;
    exit(EXIT_FAILURE);
}
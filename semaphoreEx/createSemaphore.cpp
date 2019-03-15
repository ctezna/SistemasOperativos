#include <iostream>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <cstdlib>
#include <cerrno>
#include <cstring>

using namespace std;

static void usage(const char* progname);

//createSemaphore <keysem>

int main(int argc, char *argv[]){
    if(argc != 2) usage(argv[0]);

    int key = atoi(argv[1]);
    int semid = semget(key, 1, IPC_CREAT | IPC_EXCL | 0660);

    if (semid == -1){
        cerr << "Error creating semaphore: "
             << strerror(errno) << endl;
        return EXIT_FAILURE;
    }

    if (semctl(semid, 0, SETVAL, 0) == -1){
        cerr << "Error establishing semaphore value: "
             << strerror(errno) << endl;
        return EXIT_FAILURE;
    }

    cout << "Created semaphore with <semid>: "
         << semid << endl;
    return EXIT_SUCCESS;
}

static void usage(const char* progname){
    cerr << "Uso: " << progname
         << " <semkey> " << endl;
    exit(EXIT_FAILURE);
}

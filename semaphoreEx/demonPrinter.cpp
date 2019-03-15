#include <iostream>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <cstdlib>
#include <cerrno>
#include <cstring>

using namespace std;

static void usage(const char* progname);

//demonPrinter <semkey>

int main(int argc, char *argv[]){
    if(argc != 2) usage(argv[0]);

    int key = atoi(argv[1]);
    int semid = semget(key, 1, 0660);

    if (semid == -1){
        cerr << "Error accessing semaphore: "
             << strerror(errno) << endl;
        return EXIT_FAILURE;
    }

    for(;;){
        struct sembuf ops[1] = {{0, -1, 0}};
        //wait(sem)
        ops[0].sem_num = 0;
        ops[0].sem_op = -1;
        ops[0].sem_flg = 0;
        cout << "Waiting for messages from printer" << endl;
        semop(semid,ops,1);
        cout << "Message recieved" << endl;
    }

    return EXIT_SUCCESS;
}

static void usage(const char* progname){
    cerr << "Uso: " << progname
         << " <semkey> " << endl;
    exit(EXIT_FAILURE);
}
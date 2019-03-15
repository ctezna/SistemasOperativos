#include <iostream>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <cstdlib>
#include <cerrno>
#include <cstring>
#include <unistd.h>

using namespace std;

void deamonP(int);
void client(int);


int main(int argc, char *argv[]){
    int semid = semget(IPC_PRIVATE, 1, IPC_CREAT | IPC_EXCL | 0660);

    if (semid == -1){
        cerr << "Error creating semaphore: "
             << strerror(errno) << endl;
        return EXIT_FAILURE;
    }
    int val = 0;
    if(semctl(semid, 0, SETVAL, val) == -1){
        cerr << "Error establishing semaphore value: "
             << strerror(errno) << endl;
        return EXIT_FAILURE;
    }

    pid_t pDem, pCln;

    if((pDem = fork()) == 0){
        deamonP(semid);
    } else if ((pCln = fork()) == 0){
        client(semid);
    }else {
        int status;
        waitpid(pDem, &status, 0);
        waitpid(pCln, &status, 0);
    }

    return EXIT_SUCCESS;
}

static void usage(const char* progname){
    cerr << "Uso: " << progname
         << " <semkey> " << endl;
    exit(EXIT_FAILURE);
}

void deamonP(int semid){
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
}

void client(int semid){
    for (;;) {
        struct sembuf ops[1]; //  = { { 0, -1, 0} };
    
        sleep(10);
        ops[0].sem_num = 0;
        ops[0].sem_op  = 1;
        ops[0].sem_flg = 0;
        cout << "Sending message..." << endl;
        semop(semid, ops, 1);
    }
}
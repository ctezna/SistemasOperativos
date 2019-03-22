#include <fcntl.h> /* for 0_* constants */
#include <sys/stat.h>  /* for mode constants */
#include <semaphore.h>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cerrno>

using namespace std;

static void usage(const char*);
static void smoker(const char*,sem_t*,sem_t*);

int main (int argc, char *argv[]){
    if (argc != 3) usage(argv[0]);

    sem_t *wait = sem_open(argv[1], 0);
    

    if (wait == nullptr) {
        cerr << "Error opening " << argv[1]
             << " semaphore: "
             << strerror(errno) << endl;
    }
    sem_t *agent = sem_open(argv[2], 0);
    if (agent == nullptr) {
        cerr << "Error opening " << argv[2]
             << " semaphore: "
             << strerror(errno) << endl;
    }
    smoker(argv[1], wait, agent);

    return EXIT_SUCCESS;
}

static void usage(const char* progname) {
    cerr << "Use: " << progname
         << " <name sem> "
         << endl;
    exit(EXIT_FAILURE);
}

static void smoker(const char *name, sem_t *wait, sem_t *agent) {
    for (;;){
        sem_wait(wait);
        cerr << "Smoker: " << name
             << " smoking" << endl;

        sem_post(agent);
    }
}
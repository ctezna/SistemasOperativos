#include "table.h"

int Table::nPhilosophers = 5;

Table::Table() {
    sems = new sem_t[nPhilosophers];
    for(int i = 0; i < nPhilosophers; ++i){
        sem_init(&sems[i], 0, 1);
    }
}

Table::~Table() {
    delete []sems;
}

void Table::take_fork(int i) {
    sem_wait(&sems[i]);
}

void Table::put_fork(int i){
    sem_post(&sems[i]);
}
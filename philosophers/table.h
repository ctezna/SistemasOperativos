#pragma once
#include <semaphore.h>

class Table {
    public:
        static int nPhilosophers;
        Table();
        ~Table();
        void take_fork(int i);
        void put_fork(int i);
    private:
        sem_t *sems;
};
#include <iostream>
#include <pthread.h>
#include <cstdlib>
#include <unistd.h>
#include "table.h"


using namespace std;

struct InfoPhilo {
    InfoPhilo(Table& table, int pos) : table(table), pos(pos) {}
    Table& table;
    int pos;
};

void* philosopher(void *arg);

int main(void) {
    pthread_t thread_philosopher[Table::nPhilosophers];
    Table *table = new Table();

    for (int i = 0; i < Table::nPhilosophers; ++i){
        InfoPhilo *info = new InfoPhilo(*table, i);
        pthread_create(&thread_philosopher[i], NULL, philosopher,(void *) info);
    }

    pthread_join(thread_philosopher[0],NULL);
    return EXIT_SUCCESS;
}

void* philosopher(void *arg) {
    InfoPhilo *info = (InfoPhilo *) arg;
    
    for(;;){
        cout << "Philosopher: " << info->pos << " thinking" << endl;
        sleep(rand() % 5 + 1); //thinking
        info->table.take_fork(info->pos);
        info->table.take_fork((info->pos +1) % Table::nPhilosophers);
        cout << "Philosopher: " << info->pos << " eating" << endl;
        sleep(rand() % 3 + 1); //eating
        info->table.take_fork(info->pos);
        info->table.take_fork((info->pos +1) % Table::nPhilosophers);

    }

    return NULL;
}
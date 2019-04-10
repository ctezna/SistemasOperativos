#include <iostream>
#include <pthread.h>
#include <cstdlib>
#include <unistd.h>
#include "infophilo.h"
#include "table.h"
#include "aux_functions.h"

using namespace std;

static void* philosopher(void *arg);

int
main(void) {

  pthread_t thread_philosopher[Table::nPhilosophers];

  Table *table = new Table();

  for (int i = 0; i < Table::nPhilosophers; ++i) {
    PInfoFilo info = new infophilo(*table,i);
    pthread_create(&thread_philosopher[i], NULL, philosopher, (void *) info);
  }

  pthread_join(thread_philosopher[0], NULL);
  return EXIT_SUCCESS;
}

void*
philosopher(void *arg) {
  PInfoFilo info = (PInfoFilo) arg;

  for (;;) {
    // pensando
    printPhilo(info->pos, " thinking");
    sleep(rand() % 5 + 1);
    info->table.take_fork(info->pos);
    info->table.take_fork((info->pos + 1) % Table::nPhilosophers);
    // comer
    printPhilo(info->pos, " comiendo");
    sleep(rand() % 3 + 1);
    info->table.put_fork(info->pos);
    info->table.put_fork((info->pos + 1) % Table::nPhilosophers);
  }

  return NULL;
}
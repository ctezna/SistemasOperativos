#include "aux_functions.h"
#include <semaphore.h>
#include <iostream>

using namespace std;

static sem_t *printPhiloMutex = nullptr;

static void createMutex() {
  if (printPhiloMutex == nullptr) {
    printPhiloMutex = new sem_t;
    sem_init(printPhiloMutex, 0, 1);
  }
}

void
printPhilo(int i, const char* message) {
  if (printPhiloMutex == nullptr) createMutex();

  sem_wait(printPhiloMutex);
  cout << "Filosofo: " << i
       << message << endl;
  sem_post(printPhiloMutex);
}
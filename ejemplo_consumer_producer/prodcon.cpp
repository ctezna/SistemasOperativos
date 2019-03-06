#include <iostream>
#include <cstdlib>
#include <pthread.h>
#include "elemento.h"

void* productor(void* arg);
void* consumidor(void* arg);

const int n = N;

struct elemento buffer[n];
int entra, sale;
int contador;

int main(int argc, char *argv[]) {
  entra = sale = contador = 0;
  pthread_t thr_con, thr_prod;
  int *start = new int;
  *start = 10;
  
  pthread_create(&thr_prod, NULL, productor, (void *) start);
  pthread_create(&thr_con, NULL, consumidor, NULL);

  pthread_join(thr_con, NULL);
  pthread_join(thr_prod, NULL);

  return EXIT_SUCCESS;
}

void* productor(void *arg) {
  int *p = static_cast<int*>(arg);
  do {
    struct elemento sigp;
    sigp.valor = (*p)++;

    while (contador == n);
    buffer[entra] = sigp;
    entra = (entra + 1) % n;
    contador++;

  } while (true);
}

void* consumidor(void *arg) {
  do {
    while (contador == 0);
    struct elemento sigc = buffer[sale];
    sale = (sale + 1) % n;
    contador--;

    std::cout << "Elemento obtenido: " << sigc.valor << std::endl;
  } while (true);
}

#include <iostream>
#include <cstdlib>
#include <thread>
#include "elemento.h"

void productor(int start);
void consumidor();

const int n = N;

struct elemento buffer[n];
int entra, sale;
int contador;

int main(int argc, char *argv[]) {
  entra = sale = contador = 0;
  std::thread thr_prod(productor, 10), thr_con(consumidor);

  thr_con.join();
  thr_prod.join();

  return EXIT_SUCCESS;
}

void productor(int start) {
  do {
    struct elemento sigp;
    sigp.valor = start++;

    while (contador == n);
    buffer[entra] = sigp;
    entra = (entra + 1) % n;
    contador++;

  } while (true);
}

void consumidor() {
  do {
    while (contador == 0);
    struct elemento sigc = buffer[sale];
    sale = (sale + 1) % n;
    contador--;

    std::cout << "Elemento obtenido: " << sigc.valor << std::endl;
  } while (true);
}

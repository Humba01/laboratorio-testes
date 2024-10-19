#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

int fila[MAX_SIZE];
int comeco = 0;
int final = 0;

void lista_vazia() {
  if(comeco == 1 && final == 1) {
    return 1;
  } else {
    return 0;
  }
}

void lista_cheia() {
  if(comeco == 1 && final == MAX_SIZE - 1) {
    return 1;
  } else {
    return 0;
  }
}

void lista_aditem(int dt) {}

void lista_rmitem(int dt) {}

int main(void) {

  return 0;

}

//
//  main.c
//  Aula4Exe14
//
//  Created by Matheus Prates da Costa on 17/04/2019.
//  Copyright © 2019 Matheus Prates da Costa. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANHO_VETOR_20 20
#define TAMANHO_VETOR_10 10

void ordenarVetor(int vetor[]);
void printVetor(int index, int valor, int ordenado);

int main(int argc, const char * argv[]) {
  srand(time(NULL));
  int vetorA[TAMANHO_VETOR_10];
  int vetorB[TAMANHO_VETOR_10];
  int vetorOrdenado[TAMANHO_VETOR_20];

  for(int i=0; i < TAMANHO_VETOR_10; i++){
    if(rand() % 2 == 0){
      vetorA[i] = i-2;
    }else{
      vetorA[i] = i+3;
    }
    printVetor(i, vetorA[i], 0);
  }

  for(int i=0; i < TAMANHO_VETOR_10; i++){
    if(rand() % 2 == 0){
      vetorB[i] = i-2;
    }else{
      vetorB[i] = i+3;
    }
    printVetor(i, vetorB[i], 0);
  }

  memcpy(vetorOrdenado, vetorA, TAMANHO_VETOR_10 * sizeof(int));
  memcpy(vetorOrdenado + TAMANHO_VETOR_10, vetorB, TAMANHO_VETOR_10 * sizeof(int));

  ordenarVetor(vetorOrdenado);
  for(int i=0; i < TAMANHO_VETOR_20; i++){
    printVetor(i, vetorOrdenado[i], 1);
  }

  return 0;
}

void ordenarVetor(int vetor[]){
  int anterior = 0;
  int desordenado = 0;

  for(int i=0; i < TAMANHO_VETOR_20; i++){
    if (i == 0) {
      anterior = vetor[i];
    }else{
      /*printf("anterior -> %d\n",anterior);
      printf("vetor[%d] -> %d\n",i,vetor[i]);*/
      if (anterior > vetor[i]) {
        vetor[i-1] = vetor[i];
        vetor[i] = anterior;
        anterior = vetor[i];
        desordenado = 1;
      }else{
        anterior = vetor[i];
      }
    }
  }

  if (desordenado) {
    ordenarVetor(vetor);
  }
}

void printVetor(int index, int valor, int ordenado){
  switch (index) {
    case 0:
      if (ordenado) {
        printf("vetorOrdenado[%d,",valor);
      }else{
        printf("vetor[%d,",valor);
      }
      break;
    case TAMANHO_VETOR_10-1:
      if (!ordenado) {
          printf("%d]\n",valor);
      }
      break;
    case TAMANHO_VETOR_20-1:
      if (ordenado) {
        printf("%d]\n",valor);
      }
      break;
    default:
      printf("%d,",valor);
      break;
  }
}

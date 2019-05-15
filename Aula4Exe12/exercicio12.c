//
//  main.c
//  Aula4Exe12
//
//  Created by Matheus Prates da Costa on 17/04/2019.
//  Copyright © 2019 Matheus Prates da Costa. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANHO_VETOR 100
void ordenarVetor(int vetor[]);
void printVetor(int index, int valor, int ordenado);

int main(int argc, const char * argv[]) {
  srand(time(NULL));
  int vetor[TAMANHO_VETOR];

  for(int i=0; i < TAMANHO_VETOR; i++){
    if(rand() % 2 == 0){
      vetor[i] = i-2;
    }else{
      vetor[i] = i+3;
    }

    printVetor(i,vetor[i],0);
    //printf("vetor[%d] -> %d\n",i,vetor[i]);
  }

  ordenarVetor(vetor);

  for(int i=0; i < TAMANHO_VETOR; i++){
    //printf("vetorOrdenado[%d] -> %d\n",i,vetor[i]);
    printVetor(i,vetor[i],1);
  }
  return 0;
}

void ordenarVetor(int vetor[]){
  int anterior = 0;
  int desordenado = 0;

  for(int i=0; i < TAMANHO_VETOR; i++){
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
    case TAMANHO_VETOR-1:
      printf("%d]\n",valor);
      break;
    default:
      printf("%d,",valor);
      break;
  }
}

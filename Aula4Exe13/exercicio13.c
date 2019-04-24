//
//  main.c
//  Aula4Exe13
//
//  Created by Matheus Prates da Costa on 17/04/2019.
//  Copyright © 2019 Matheus Prates da Costa. All rights reserved.
//

#include <stdio.h>

#define TAMANHO_VETOR 20

int main(int argc, const char * argv[]) {
  int vetor[TAMANHO_VETOR];

  for(int i=0; i < TAMANHO_VETOR; i++){
    vetor[i] = i+1;
    printf("vetorInicial[%d] -> %d\n", i, vetor[i]);
  }

  for(int i=0; i < TAMANHO_VETOR / 2; i++){
    int aux = vetor[i];
    vetor[i] = vetor[TAMANHO_VETOR-1-i];
    vetor[TAMANHO_VETOR-1-i] = aux;
  }

  for(int i=0; i < TAMANHO_VETOR; i++){
    printf("vetorFinal[%d] -> %d\n", i, vetor[i]);
  }

  return 0;
}

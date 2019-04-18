//
//  main.c
//  Aula4Exe3
//
//  Created by Matheus Prates da Costa on 17/04/2019.
//  Copyright © 2019 Matheus Prates da Costa. All rights reserved.
//

#include <stdio.h>

void preencher(int indice, int vetor[]);

int main(int argc, const char * argv[]) {
  int vetor[10];
  int indice;

  puts("Digite 10 para preencher o vetor com 10 ou 20 para preencher com 20: ");
  scanf("%d", &indice);

  preencher(indice,vetor);

  for(int i=0; i < 10; i++){
    printf("vetor[%d] -> %d\n",i,vetor[i]);
  }

  return 0;
}

void preencher(int indice, int vetor[]){
  for(int i=0; i < 10; i++){
    if (indice == 10) {
      vetor[i] = 10;
    }else if (indice == 20){
      vetor[i] = 20;
    }
  }
}

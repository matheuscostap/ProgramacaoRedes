//
//  main.c
//  Aula4Exe4
//
//  Created by Matheus Prates da Costa on 17/04/2019.
//  Copyright © 2019 Matheus Prates da Costa. All rights reserved.
//

#include <stdio.h>

int contarNumPar(int vetor[]);

int main(int argc, const char * argv[]) {
  int vetor[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};

  for(int i=0; i < 20; i++){
    printf("vetor[%d] -> %d \n",i,vetor[i]);
  }

  printf("%Quantidade de numeros pares no vetor: %d\n", contarNumPar(vetor));

  return 0;
}

int contarNumPar(int vetor[]){
  int contador = 0;
  for(int i=0; i < 20; i++){
    if (vetor[i] % 2 == 0) {
      contador++;
    }
  }
  return contador;
}

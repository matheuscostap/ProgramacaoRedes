//
//  main.c
//  Aula4Exe11
//
//  Created by Matheus Prates da Costa on 17/04/2019.
//  Copyright © 2019 Matheus Prates da Costa. All rights reserved.
//

#include <stdio.h>

int adicionar(int numero, int vetorPar[], int vetorImpar[]);
int adicionarParaVetor(int numero, int vetor[]);

int main(int argc, const char * argv[]) {
  int vetorPar[10] = {0};
  int vetorImpar[10] = {0};
  int entrada = 0;
  int adicionado = 0;

  do {
    printf("Digite um numero ou 0 para sair: \n");
    scanf("%d",&entrada);

    if (entrada != 0) {
      adicionado = adicionar(entrada, vetorPar, vetorImpar);
    }

  } while(entrada != 0 && adicionado);


  for(int i = 0; i < 10; i++){
    printf("vetorPar[%d] -> %d \n", i, vetorPar[i]);
  }

  for(int i = 0; i < 10; i++){
    printf("vetorImpar[%d] -> %d \n", i, vetorImpar[i]);
  }

  return 0;
}

int adicionar(int numero, int vetorPar[], int vetorImpar[]){
  if (numero % 2 == 0) {
    printf("Vetor par -> ");
    return adicionarParaVetor(numero, vetorPar);
  }else{
    printf("Vetor impar -> ");
    return adicionarParaVetor(numero, vetorImpar);
  }
}

int adicionarParaVetor(int numero, int vetor[]){
  int indexUltimoVazio = -1;
  for(int i = 0; i < 10; i++){
    if (vetor[i] == 0) {
      indexUltimoVazio = i;
    }
  }

  if (indexUltimoVazio != -1) {
    vetor[indexUltimoVazio] = numero;
    printf("%d adicionado. \n", numero);
    return 1;
  }else{
    printf("cheio! \n");
    return 0;
  }
}

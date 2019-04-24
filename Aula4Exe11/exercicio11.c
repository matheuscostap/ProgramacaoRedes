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
int verificaVetorCheio(int vetor[]);

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
    return adicionarParaVetor(numero, vetorPar);
  }else{
    return adicionarParaVetor(numero, vetorImpar);
  }
}

int adicionarParaVetor(int numero, int vetor[]){
  for(int i = 0; i < 10; i++){
    if (!verificaVetorCheio(i,vetor)) {
      vetor[i] = numero;
      return 1;
    }else{
      return 0;
    }
  }
}

int verificaVetorCheio(int index, int vetor[]){
  if (vetor[index] != 0) {
    return 0;
  }else{
    return 1;
  }
}


for(int i = 0; i < 10; i++){
  if(vetorPar[i] == 0){
    vetorPar[i] = numero;
    printf("%d adicionado no vetor par. \n", numero);
    return 1;
  }else{
    printf("Vetor par cheio! \n");
    return 0;
  }
}

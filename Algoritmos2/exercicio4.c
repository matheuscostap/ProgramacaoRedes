//
//  main.c
//  Exercicio4
//
//  Created by Matheus Prates da Costa on 20/05/2019.
//  Copyright © 2019 Matheus Prates da Costa. All rights reserved.
//

#include <stdio.h>

//Constante para guardar o tamanho do vetor
#define TAMANHO_VETOR 20

//Declarando assinatura da função
int retornarPares(int vetor[]);

int main(int argc, const char * argv[]) {
  //Vetor
  int vetor[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};

  //Invoca a função
  printf("Quantidade de numeros pares: %d\n",retornarPares(vetor));
  return 0;
}

//Declarando a estrutura da função
int retornarPares(int vetor[]){
  //Variável para armazenar o numero de pares
  int pares = 0;
  //For para percorrer os vetores
  for(int i = 0; i < TAMANHO_VETOR; i++){
    if(vetor[i] % 2 == 0){
      //Incrementa em 1
      pares++;
    }
  }
  //Retorno da função
  return pares;
}

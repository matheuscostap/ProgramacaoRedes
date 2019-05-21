//
//  main.c
//  Exercicio5
//
//  Created by Matheus Prates da Costa on 20/05/2019.
//  Copyright © 2019 Matheus Prates da Costa. All rights reserved.
//

#include <stdio.h>

//Constante para guardar o tamanho do vetor
#define TAMANHO_VETOR 10

//Declarando assinatura da função
void multiplicarVetores(int vetor1[], int vetor2[], int vetor3[]);

int main(int argc, const char * argv[]) {
  //Vetores
  int vetor1[] = {1,2,3,4,5,6,7,8,9,10};
  int vetor2[] = {10,20,30,40,50,60,70,80,90,10};
  int vetor3[TAMANHO_VETOR];

  //Invoca a função
  multiplicarVetores(vetor1,vetor2,vetor3);
  return 0;
}

//Declarando a estrutura da função
void multiplicarVetores(int vetor1[], int vetor2[], int vetor3[]){
  //For para percorrer os vetores
  for(int i = 0; i < TAMANHO_VETOR; i++){
    vetor3[i] = vetor1[i] * vetor2[i];
    //Exibe na tela a multiplicação
    printf("vetor3[%d] -> %d\n", i, vetor3[i]);
  }
}

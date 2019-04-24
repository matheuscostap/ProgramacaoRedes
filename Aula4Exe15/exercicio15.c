//
//  main.c
//  Aula4Exe15
//
//  Created by Matheus Prates da Costa on 17/04/2019.
//  Copyright © 2019 Matheus Prates da Costa. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANHO_VETOR 6

void ordenarVetor(int vetor[]);
void printVetor(int index, int valor);
void somarElementos(int vetor[]);
void multiplicarElementos(int vetor[]);
void mediaElementos(int vetor[]);
void printMenu();

int main(int argc, const char * argv[]) {
  srand(time(NULL));
  int vetor[TAMANHO_VETOR];
  int op = 0;

  for(int i=0; i < TAMANHO_VETOR; i++){
    if(rand() % 2 == 0){
      vetor[i] = i-2;
    }else{
      vetor[i] = i+3;
    }
  }

  do {
    printMenu();
    scanf("%d", &op);
    switch (op) {
      case 1:
        somarElementos(vetor);
        break;

      case 2:
        multiplicarElementos(vetor);
        break;

      case 3:
        mediaElementos(vetor);
        break;

      case 4:
        ordenarVetor(vetor);
        for(int i=0; i < TAMANHO_VETOR; i++){
          printVetor(i,vetor[i]);
        }
        break;

      case 5:
        for(int i=0; i < TAMANHO_VETOR; i++){
          printVetor(i,vetor[i]);
        }
        break;
    }
  } while(op != 0);

  return 0;
}

void printMenu(){
  printf("****************************************\n");
  printf("1 - Soma dos Elementos\n");
  printf("2 - Produto dos Elementos\n");
  printf("3 - Media dos Elementos\n");
  printf("4 - Ordene os elementos em ordem crescente\n");
  printf("5 - Mostre o Vetor\n");
  printf("0 - Sair\n");
  printf("****************************************\n");
}

void somarElementos(int vetor[]){
  int soma = 0;
  for(int i=0; i < TAMANHO_VETOR; i++){
    soma+= vetor[i];
  }

  printf("Soma dos elementos: %d\n",soma);
}

void multiplicarElementos(int vetor[]){
  int mult = 1;
  for(int i=0; i < TAMANHO_VETOR; i++){
    mult = vetor[i] * mult;
  }

  printf("Produto dos elementos: %d\n",mult);
}

void mediaElementos(int vetor[]){
  float media = 0;
  int soma = 0;
  for(int i=0; i < TAMANHO_VETOR; i++){
    soma+= vetor[i];
  }

  media = (float) soma / TAMANHO_VETOR;

  printf("Media dos elementos: %.f\n",media);
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

void printVetor(int index, int valor){
  switch (index) {
    case 0:
        printf("vetor[%d,",valor);
      break;
    case TAMANHO_VETOR-1:
        printf("%d]\n",valor);
      break;
    default:
      printf("%d,",valor);
      break;
  }
}

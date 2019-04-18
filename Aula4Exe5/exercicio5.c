//
//  main.c
//  Aula4Exe5
//
//  Created by Matheus Prates da Costa on 17/04/2019.
//  Copyright © 2019 Matheus Prates da Costa. All rights reserved.
//

#include <stdio.h>

void multiplicarVetores(int vetor1[], int vetor2[], int vetor3[]);

int main(int argc, const char * argv[]) {
  int vetor1[] = {10,20,30,40,50,60,70,80,90,100};
  int vetor2[] = {1,2,3,4,5,6,7,8,9,10};
  int vetor3[10];

  multiplicarVetores(vetor1,vetor2,vetor3);

  for(int i=0; i < 10; i++){
    printf("%vetor1[%d] -> %d * vetor2[%d] -> %d = vetor3[%d] -> %d\n",
     i,vetor1[i],i,vetor2[i],i,vetor3[i]);
  }

  return 0;
}

void multiplicarVetores(int vetor1[], int vetor2[], int vetor3[]){
  for(int i=0; i < 10; i++){
    vetor3[i] = vetor1[i] * vetor2[i];
  }
}

//
//  main.c
//  Aula4Exe6
//
//  Created by Matheus Prates da Costa on 17/04/2019.
//  Copyright © 2019 Matheus Prates da Costa. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, const char * argv[]) {
  srand(time(NULL));
  int vetor[50];

  for(int i=0; i < 50; i++){
    vetor[i] = rand();
    printf("vetor[%d] -> %d\n",i,vetor[i]);
  }

  printf("Numeros Positivos\n");

  for(int i=0; i < 50; i++){
    if (vetor[i] >= 0) {
      printf("vetor[%d] -> %d\n",i,vetor[i]);
    }
  }

  return 0;
}

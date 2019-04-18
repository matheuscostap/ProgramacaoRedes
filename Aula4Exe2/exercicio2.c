//
//  main.c
//  Aula4Exe2
//
//  Created by Matheus Prates da Costa on 17/04/2019.
//  Copyright © 2019 Matheus Prates da Costa. All rights reserved.
//

#include <stdio.h>


int main(int argc, const char * argv[]) {
  int vetor[10];

  for(int i=0; i < 10; i++){
    vetor[i] = (i+1) * 10;
  }

  for(int i=0; i < 10; i++){
    printf("vetor[%d] -> %d\n",i,vetor[i]);
  }

  return 0;
}

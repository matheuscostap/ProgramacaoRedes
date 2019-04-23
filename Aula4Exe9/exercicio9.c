//
//  main.c
//  Aula4Exe9
//
//  Created by Matheus Prates da Costa on 17/04/2019.
//  Copyright © 2019 Matheus Prates da Costa. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
  int vetorM[] = {10,20,30,40,50,60,70,80,90,100};

  for(int i = 0; i < 10; i++){
    if(i < 5){
      int aux = vetorM[i];
      int index = (sizeof(vetorM) / sizeof(int)) / 2 + i;
      vetorM[i] = vetorM[index];
      vetorM[index] = aux;
    }
    printf("vetorM[%d] -> %d \n", i, vetorM[i]);
  }

  return 0;
}

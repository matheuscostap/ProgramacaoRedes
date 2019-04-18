//
//  main.c
//  Aula4Exe7
//
//  Created by Matheus Prates da Costa on 17/04/2019.
//  Copyright © 2019 Matheus Prates da Costa. All rights reserved.
//

#include <stdio.h>

void preencherVetor(int vetorX[], int vetorY[]);

int main(int argc, const char * argv[]) {
  int vetorX[] = {10,20,30,40,50,60,70,80,90,100};
  int vetorY[10];



  return 0;
}

void preencherVetor(int vetorX[], int vetorY[]){
    for(int i=0; i < 10; i++){
      if (i % 2 == 0) {
        vetorY[i] = vetorX[i] * 2;
      }else{
        vetorY[i] = vetorX[i] * 3;
      }
    }
}

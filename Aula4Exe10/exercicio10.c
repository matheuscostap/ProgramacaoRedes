//
//  main.c
//  Aula4Exe10
//
//  Created by Matheus Prates da Costa on 17/04/2019.
//  Copyright © 2019 Matheus Prates da Costa. All rights reserved.
//

#include <stdio.h>

void abastecerVetores(int numero, int vetorPares[], int vetorImpares[], int index);

int main(int argc, const char * argv[]) {
  int vetorPares[50];
  int vetorImpares[50];

  for(int i = 0; i < 100; i++){
    abastecerVetores(i,vetorPares,vetorImpares,i);
  }

  return 0;
}

void abastecerVetores(int numero, int vetorPares[], int vetorImpares[], int index){
  if (numero % 2 == 0) {
    vetorPares[index] = numero;
    printf("vetorPares[%d] -> %d \n", index, vetorPares[index]);
  }else{
    vetorImpares[index] = numero;
    printf("vetorImpares[%d] -> %d \n", index, vetorImpares[index]);
  }

}

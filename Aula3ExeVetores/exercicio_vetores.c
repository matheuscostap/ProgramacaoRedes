//
//  main.c
//  Aula3ExeVetores
//
//  Created by Matheus Prates da Costa on 10/04/2019.
//  Copyright © 2019 Matheus Prates da Costa. All rights reserved.
//

#include <stdio.h>


int main(int argc, const char * argv[]) {
  int vetor[] = {19,3,15,7,11,9,13,5,17,1};

  printf("%s%13s%17s\n","Elemento","Valor","Histograma");
  for (int i = 0; i < sizeof(vetor)/sizeof(int); i++) {
    printf("%7d%13d",i,vetor[i]);
    for (int i2 = 0; i2 < vetor[i]; i2++) {
      if (i2 == 0) {
        printf("%9c",'*');
      }else{
        printf("%c",'*');
      }
    }
    printf("\n");
  }

  return 0;
}

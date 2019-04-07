//
//  main.c
//  Aula2Exe10
//
//  Created by Matheus Prates da Costa on 07/04/2019.
//  Copyright © 2019 Matheus Prates da Costa. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int maior;
    int numero;

    printf("Digite 3 numeros inteiros\n");

    for(int i = 0; i < 3; i++){
      scanf("%d", &numero);
      if (numero > maior) {
        maior = numero;
      }
    }

    printf("O maior numero eh: %d\n", maior);

    return 0;
}

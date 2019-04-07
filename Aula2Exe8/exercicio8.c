//
//  main.c
//  Aula2Exe8
//
//  Created by Matheus Prates da Costa on 05/04/2019.
//  Copyright © 2019 Matheus Prates da Costa. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int numero;
    int contPar;
    int contImpar;
    int somaPar;
    int somaImpar;

    printf("Digite um numero inteiro positivo: \n");
    scanf("%d", &numero);

    for(int i = 1; i <= numero; i++){
      if (i % 2 == 0) {
        printf("%d eh par \n", i);
        contPar++;
        somaPar += i;
      }else{
        printf("%d eh impar \n", i);
        contImpar++;
        somaImpar += i;
      }
    }

    printf("Total de numeros pares encontrados entre 1 e %d eh: %d \n",numero,contPar);
    printf("Somatorio dos numeros pares entre 1 e %d eh: %d \n",numero,somaPar);
    printf("Total de numeros impares encontrados entre 1 e %d eh: %d \n",numero,contImpar);
    printf("Somatorio dos numeros impares entre 1 e %d eh: %d \n",numero,somaImpar);

    return 0;
}

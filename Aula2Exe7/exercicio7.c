//
//  main.c
//  Aula2Exe7
//
//  Created by Matheus Prates da Costa on 05/04/2019.
//  Copyright © 2019 Matheus Prates da Costa. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int numero;

    printf("Digite um numero: \n");
    scanf("%d", &numero);

    if (numero % 2 == 0) {
        printf("%d eh um numero par", numero);
    }else{
        printf("%d eh um numero impar", numero);
    }
    return 0;
}

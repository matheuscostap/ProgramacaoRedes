//
//  main.c
//  Aula2Exe9
//
//  Created by Matheus Prates da Costa on 07/04/2019.
//  Copyright © 2019 Matheus Prates da Costa. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int a;
    int b;
    int flag1 = 1;

    do {
      printf("Digite um numero A: \n");
      scanf("%d", &a);
      printf("Digite um numero B maior que A: \n");
      scanf("%d", &b);

      if (a < b) {
        flag1 = 0;
      }else{
        printf("A deve ser menor que B \n");
      }
    }while (flag1);

    printf("Os numeros digitados pelo usuario foram: %d e %d \n",a,b);

    int flag2 = 1;
    int soma;

    for(int i = a; i < b;i++){
      if (i % 5 == 0) {
        if (flag2) {
          flag2 = 0;
          printf("Os numeros inteiros divisiveis por 5 entre %d e %d sao:",a,b);
          printf("%d ", i);
          soma += i;
        }else{
          printf("%d ", i);
          soma += i;
        }
      }
    }

    if (soma != 0) {
      printf("\nA soma dos numeros inteiros divisiveis por 5 eh: %d\n", soma);
    }else{
      printf("Nenhum inteiro divisiveis por 5 encontrado entre %d e %d",a,b);
    }

    return 0;
}

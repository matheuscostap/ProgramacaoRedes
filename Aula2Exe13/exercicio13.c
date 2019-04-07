//
//  main.c
//  Aula2Exe13
//
//  Created by Matheus Prates da Costa on 07/04/2019.
//  Copyright © 2019 Matheus Prates da Costa. All rights reserved.
//

#include <stdio.h>

void calcularValorMeiaDuzia(int laranjas);
void calcularValorDuzia(int laranjas);

int main(int argc, const char * argv[]) {
    int laranjas;

    printf("Digite o numero de laranjas a serem compradas: \n");
    scanf("%d", &laranjas);

    if (laranjas > 0) {
      printf("--- Valor da Compra ---\n");
      if (laranjas < 12) {
        calcularValorMeiaDuzia(laranjas);
      }else{
        calcularValorDuzia(laranjas);
      }
    }else{
      printf("Nenhum item esta sendo comprado...");
    }


    return 0;
}

void calcularValorMeiaDuzia(int laranjas){
  float valor;
  for (int i = 0; i < laranjas; i++){
    valor += 0.30;
  }

  printf("%d unidade(s) de laranja a R$0.30 a unidade: %.2f\n",laranjas,valor);
}

void calcularValorDuzia(int laranjas){
  float valor;
  for (int i = 0; i < laranjas; i++){
    valor += 0.25;
  }

  printf("%d unidade(s) de laranja a R$0.25 a unidade: %.2f\n",laranjas,valor);
}

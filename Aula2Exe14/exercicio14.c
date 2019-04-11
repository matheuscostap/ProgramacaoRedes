//
//  main.c
//  Aula2Exe14
//
//  Created by Matheus Prates da Costa on 07/04/2019.
//  Copyright © 2019 Matheus Prates da Costa. All rights reserved.
//

#include <stdio.h>

void printMenu();
void calcularBanana(int quantidade);
void calcularLaranja(int quantidade);
void calcularMaca(int quantidade);
void calcularKiwi(int quantidade);

int main(int argc, const char * argv[]) {
  int produto;
  int quantidade;

  printMenu();
  printf("Escolha o produto desejado ou digite -1 para sair: \n");
  scanf("%d", &produto);

  if (produto >= 1 && produto <= 4) {

    switch (produto) {
      case 1:
        printf("Escolha a quantidade de Banana desejada: \n");
        scanf("%d", &quantidade);
        calcularBanana(quantidade);
        break;

      case 2:
        printf("Escolha a quantidade de Laranja desejada: \n");
        scanf("%d", &quantidade);
        calcularLaranja(quantidade);
        break;

      case 3:
        printf("Escolha a quantidade de Maca desejada: \n");
        scanf("%d", &quantidade);
        calcularMaca(quantidade);
        break;

      case 4:
        printf("Escolha a quantidade de Kiwi desejada: \n");
        scanf("%d", &quantidade);
        calcularKiwi(quantidade);
        break;
    }
  }else{
    printf("Operacao finalizada.");
  }

  return 0;
}

void printMenu(){
  printf("--- Lista de Produtos e Precos ---\n");
  printf("1 - Banana -> R$0.30 menos que uma duzia ou R$0.25 uma duzia ou mais\n");
  printf("2 - Laranja -> R$0.40 menos que uma duzia ou R$0.35 uma duzia ou mais\n");
  printf("3 - Maca -> R$0.50 menos que uma duzia ou R$0.45 uma duzia ou mais\n");
  printf("4 - Kiwi -> R$0.40 menos que uma duzia ou R$0.30 uma duzia ou mais\n");
  printf("----------------------------------\n");
}

void calcularBanana(int quantidade){
  printf("----- Valor da Compra -----\n");
  float valor;
  if (quantidade < 12) {
    valor = quantidade * 0.30;
    printf("%d unidade(s) de Banana a R$0.30 a unidade: ", quantidade);
  }else{
    valor = quantidade * 0.25;
    printf("%d unidade(s) de Banana a R$0.25 a unidade: ", quantidade);
  }

  printf("R$ %.2f", valor);
}

void calcularLaranja(int quantidade){
  printf("----- Valor da Compra -----\n");
  float valor;
  if (quantidade < 12) {
    valor = quantidade * 0.40;
    printf("%d unidade(s) de Laranja a R$0.40 a unidade: ", quantidade);
  }else{
    valor = quantidade * 0.35;
    printf("%d unidade(s) de Laranja a R$0.35 a unidade: ", quantidade);
  }

  printf("R$ %.2f", valor);
}

void calcularMaca(int quantidade){
  printf("----- Valor da Compra -----\n");
  float valor;
  if (quantidade < 12) {
    valor = quantidade * 0.50;
    printf("%d unidade(s) de Maca a R$0.50 a unidade: ", quantidade);
  }else{
    valor = quantidade * 0.45;
    printf("%d unidade(s) de Maca a R$0.45 a unidade: ", quantidade);
  }

  printf("R$ %.2f", valor);
}

void calcularKiwi(int quantidade){
  printf("----- Valor da Compra -----\n");
  float valor;
  if (quantidade < 12) {
    valor = quantidade * 0.40;
    printf("%d unidade(s) de Kiwi a R$0.40 a unidade: ", quantidade);
  }else{
    valor = quantidade * 0.30;
    printf("%d unidade(s) de Kiwi a R$0.30 a unidade: ", quantidade);
  }

  printf("R$ %.2f", valor);
}

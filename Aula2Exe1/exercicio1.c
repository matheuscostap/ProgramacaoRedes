//
//  main.c
//  Aula2Exe1
//
//  Created by Matheus Prates da Costa on 05/04/2019.
//  Copyright © 2019 Matheus Prates da Costa. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
 int lado = 0;
 printf("Digite o valor do lado do quadrado: \n");
 scanf("%d",&lado);
 
 printf("Area do quadrado: %d", lado * lado);
 return 0;
 }

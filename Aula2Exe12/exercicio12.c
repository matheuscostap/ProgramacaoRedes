//
//  main.c
//  Aula2Exe12
//
//  Created by Matheus Prates da Costa on 07/04/2019.
//  Copyright © 2019 Matheus Prates da Costa. All rights reserved.
//

#include <stdio.h>

int formaTriangulo(int a, int b, int c);
int ehIsosceles(int a, int b, int c);
int ehEquilatero(int a, int b, int c);
int ehEscaleno(int a, int b, int c);

int main(int argc, const char * argv[]) {
    int a;
    int b;
    int c;

    printf("Digite os valores dos 3 lados do triangulo: \n");
    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);

    if (formaTriangulo(a,b,c)){
      if(ehEscaleno(a,b,c)){
        printf("Os valores formam um triangulo escaleno");
      }else if(ehEquilatero(a,b,c)){
        printf("Os valores formam um triangulo equilatero");
      }else if (ehIsosceles(a,b,c)) {
        printf("Os valores formam um triangulo isosceles");
      }
    }else{
      printf("Os valores nao formam um triangulo");
    }

    return 0;
}

int formaTriangulo(int a, int b, int c){
  if ((a < b + c) && (b < a + c) && (c < a + b)) {
    return 1;
  }else{
    return 0;
  }
}

int ehIsosceles(int a, int b, int c){
  if ((a==b) || (a==c) || (b==c)) {
    return 1;
  }else{
    return 0;
  }
}

int ehEquilatero(int a, int b, int c){
  if ((a==b) && (b==c)) {
    return 1;
  }else{
    return 0;
  }
}

int ehEscaleno(int a, int b, int c){
  if ((a!=b) && (a!=c) && (b!=c)) {
    return 1;
  }else{
    return 0;
  }
}

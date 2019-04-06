//
//  main.c
//  Aula2Exe6
//
//  Created by Matheus Prates da Costa on 05/04/2019.
//  Copyright © 2019 Matheus Prates da Costa. All rights reserved.
//

#include <stdio.h>

double calcularPorcentagem(double votos, double eleitores);

int main(int argc, const char * argv[]) {
    int numEleitores;
    int votosBrancos;
    int votosNulos;
    int votosValidos;
    int executar = 1;
    
    printf("Digite o numero de eleitores do municipio: \n");
    scanf("%d", &numEleitores);
    
    while(executar){
        printf("Digite o numero de votos em branco: \n");
        scanf("%d", &votosBrancos);
        
        if (votosBrancos < numEleitores) {
            executar = 0;
        }else{
            printf("O numero de votos brancos nao pode ser maior que o de eleitores \n");
        }
    }
    
    executar = 1;

    while(executar){
        printf("Digite o numero de votos nulos: \n");
        scanf("%d", &votosNulos);
        
        if (votosNulos < numEleitores) {
            executar = 0;
        }else{
            printf("O numero de votos nulos nao pode ser maior que o de eleitores \n");
        }
    }

    executar = 1;
    
    while(executar){
        printf("Digite o numero de votos validos: \n");
        scanf("%d", &votosValidos);
        
        if (votosValidos < numEleitores) {
            executar = 0;
        }else{
            printf("O numero de votos validos nao pode ser maior que o de eleitores \n");
        }
    }
    
    printf("Resultado: \n");
    double resBrancos = calcularPorcentagem((double) votosBrancos, (double) numEleitores);
    printf("%.1lf%% de votos brancos\n", resBrancos);
    
    double resNulos = calcularPorcentagem((double) votosNulos, (double) numEleitores);
    printf("%.1lf%% de votos nulos\n", resNulos);
    
    double resValidos = calcularPorcentagem((double) votosValidos, (double) numEleitores);
    printf("%.1lf%% de votos validos\n", resValidos);
    
    return 0;
}

double calcularPorcentagem(double votos, double eleitores){
    double ret = votos / eleitores * 100;
    return ret;
}

//= ((eleitores - votos)/eleitores) * 100;

//
//  main.c
//  Aula2Exe5
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
    
    printf("Digite o numero de eleitores do municipio: \n");
    scanf("%d", &numEleitores);
    
    printf("Digite o numero de votos em branco: \n");
    scanf("%d", &votosBrancos);
    
    printf("Digite o numero de votos nulos: \n");
    scanf("%d", &votosNulos);
    
    printf("Digite o numero de votos validos: \n");
    scanf("%d", &votosValidos);
    
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

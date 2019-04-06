//
//  main.c
//  Aula2Exe3
//
//  Created by Matheus Prates da Costa on 05/04/2019.
//  Copyright © 2019 Matheus Prates da Costa. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int temp;
    
    printf("Digite a temperatura em Fahrenheit: \n");
    scanf("%d", &temp);
    
    float tempCelsius = (temp - 32) * 5/9;
    
    printf("Temperatura em graus Celcius: %.1f", tempCelsius);
    return 0;
}

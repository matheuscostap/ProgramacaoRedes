//
//  main.c
//  Aula2Exe4
//
//  Created by Matheus Prates da Costa on 05/04/2019.
//  Copyright © 2019 Matheus Prates da Costa. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int temp;
    
    printf("Digite a temperatura em Celcius: \n");
    scanf("%d", &temp);
    
    float tempFahr = (temp * 9/5) + 32;
    
    printf("Temperatura em graus Fahrenheit: %.1f", tempFahr);
    return 0;
}

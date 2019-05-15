//
//  main.c
//  ProvaExercicio9
//
//  Created by Matheus Prates da Costa on 01/05/2019.
//  Copyright © 2019 Matheus Prates da Costa. All rights reserved.
//

#include <stdio.h>

//Declaração dos protótipos das funções...
float calculaMediaParcial(float notaGA, float notaGB);
float calculaQtoPrecisaGC(float GA, float GB);
void emiteStatusAluno(float notaGA, float notaGB, float mediaParcial, float qtoPrecisaGC);

//Função principal do programa onde as funções são chamadas...
int main(int argc, const char * argv[]) {
  //Declaração de variáveis...
  float notaGA = 0, notaGB = 0;
  //Leitura de dados
  puts("Entre com as notas GA e GB respectivamente: ");
  scanf("%f%f", &notaGA, &notaGB);
  //chamada das funções
  emiteStatusAluno(notaGA, notaGB, calculaMediaParcial(notaGA, notaGB), calculaQtoPrecisaGC(notaGA, notaGB));

 return 0;
 }

//Função para calcular a média parcial entre duas notas.
//recebe o valor das notas e retorna o valor da média parcial.
float calculaMediaParcial(float notaGA, float notaGB){
  float mediaParcial = (notaGA + notaGB) / 2;
  return mediaParcial;
}

//Função para calcular quanto o aluno irá precisar no GC.
//recebe notas GA e GB e retorna o quanto ele precisará no GC.
float calculaQtoPrecisaGC(float GA, float GB){
  float mediaParcial = (GA + GB) / 2;
  float qtoPrecisaGC = 3 * 5.0 - mediaParcial;
  return qtoPrecisaGC;
}

//Função para gerar o resultado final - imprimir o resultado final...
void emiteStatusAluno(float notaGA, float notaGB, float mediaParcial, float qtoPrecisaGC){
  if (mediaParcial >= 7.0) {
    //Aprovado
    printf("Aluno aprovado com media = %.1f\n", mediaParcial);
  }else{
    //Reprovado
    printf("Aluno reprovado com media = %.1f\n", mediaParcial);
    if (qtoPrecisaGC < 10) {
      //Tem chance
      float antiga = 15 - (notaGA + notaGB);
      printf("Aluno ira precisar de 5 no Grau C");
      printf("(na norma antiga da FTEC seria %.1f ou seja, 15 - (GA(%.1f) + GB(%.1f)))", antiga, notaGA, notaGB);
    }else{
      //Reprovado
      printf("Não tem mais chances no Grau C pois precisa de %.1f\n", qtoPrecisaGC);
    }
  }
}

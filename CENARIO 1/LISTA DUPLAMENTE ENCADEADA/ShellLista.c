/** @file BubbleLista.c
 *  @brief Realiza as N interações.

 *  @author Lucas S. Oliveira RGA 201521901005 && Gustavo da Costa 201521901011
 *
 * @brief  Realiza a ordenação de Lista pelo método ShellSort.
 */

#include <stdlib.h>
#include <stdio.h>
#include<time.h>
#include "Lista_dupla.h"
int MAX=10000;
int seed = 10;

int main()
{printf("\n# Trabalho : Analise de algoritmos de ordenação #\n# Disciplina Estrutura de Dados                 #\n# Prof. Frederico S. Oliveira                   #\n# Autor:Lucas S. de Oliveira  RGA: 201521901005 #\n# Autor:Gustavo da Costa RGA:201521901011 #");
  lista *l;
   clock_t tempo_i, tempo_f;
   srand(time(NULL));




  while (MAX<=50000) {




    CriaLista(l);
    for(int i=0; i<MAX; i++)
    {
        int j=rand()%seed;
        Insere(j,l);

    }
    Insere('#',l);

    tempo_i = clock();
    ShellLista(l,MAX);
      //  ImprimePrimeiroUltimo(l);
    tempo_f = clock();
    printf("MAX: %d\nTestes: %1.f\n Movimentações: %1.f",MAX,testesh,movish);
    printf(" ShellLista: %lu segundos \n", (tempo_f - tempo_i)/CLOCKS_PER_SEC);

  ApagaLista(l);
  ZeraVariaveis();
  MAX=MAX+10000;



}


}

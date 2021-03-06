/** @file analisevetorsruct.c
 *  @brief Realiza as N interações e troca de sementes e gera arquivo de saida com dados estatisticos de cada metodo
 *         de ordenação.

 *  @author Lucas S. Oliveira RGA 201521901005 && Gustavo da Costa 201521901011
 *
 * @brief  MAIN para reaizar as analises dos metodos de ordenação.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "Ordenacoesstruct.h" // É importado a biblioteca criada
registro *V;
int main(int argc, char *argv[])
{
    clock_t tempo_i, tempo_f,tempo_medio;
printf("\n# Trabalho : Analise de algoritmos de ordenação #\n# Disciplina Estrutura de Dados                 #\n# Prof. Frederico S. Oliveira                   #\n# Autor:Lucas S. de Oliveira  RGA: 201521901005 #\n# Autor:Gustavo da Costa RGA:201521901011 #");
double testetotall=0; // São criado variaveis para realizar a soma de total de todas as N interações dos algoritmos de ordenação
double  movitotall=0;


    int i,MAX;
    int seed=10; // Valor da semente inicial
    char str[100];


    FILE *entrada;
    FILE *saida;
    entrada = fopen(argv[1], "r"); //abre o arquivo de entrada para leitura, refente ao argumento de entrada que contem os tamnhos do vetores a serem testados
    saida = fopen(argv[2], "w");//abre o arquivo de saida para gravacao, refente ao arquivo de saida com as estatisticas
    fprintf(saida, "Tamanho N:       Tempo:           Testes:           Movimentacoes:              Semente:\n" );

    if(argc == 3)  //verifica se todos os argumentos  deram entrada
    {



        if (strcmp (argv[0], "./bubblesort") == 0) // compara se o metodo escolhido foi bubblesort
        {

            while(fgets(str, 100, entrada) != NULL)//percorre o arquivo de entrada
            {
                MAX = atoi(str); //max recebe os dados do arquivo de entrada convertido para inteiro

                while(seed<10000000) // Laço de repetição para controlar a semente
                {

                V =  Preenche(V,MAX,seed); // Função que preenche aleatoriamente o vetor do tipo registro
                    if(MAX!=0)
                    {
                        tempo_i = clock();
                        BubbleSort (V,MAX);  // O metodo de ordenacao é chamado da biblioteca Ordenacoesstruct.h
                          free(V);
                        testetotall=testetotall+testetotal; // É somado o total de comparações das N interações do trabalho
                        movitotall=movitotall+movitotal;  // É somado o total de copias de regitro das N interações do trabalho
                        tempo_f = clock();
                        tempo_medio=(tempo_f - tempo_i)/CLOCKS_PER_SEC; // É calculado o tempo medio per clock do processador
                        fprintf(saida,"%d               %lu               %1.f                  %1.f                   %d\n\n",MAX,tempo_medio,testeb,movib,seed);//Grava as informacao no arquivo de saida
                        ZeraVariaveis(); // Zera as variaveis utilizadas para contar as comparações e trocas de registro no fim de cada interação
                    }
                    seed=seed*10; // A semente é mudada para cada interação com um vetor de tamanho N
                }
                seed=10; // A semente volta ao valor inicial quando se troca o tamanho N do Vetor

            }

        }
        /*                                                                                                                *
        *                                                                                                                 *
        *                     OS COMENTARIOS ACIMA VALEM PARA TODOS OS TESTES ABAIXO                                      *
        *                                                                                                                 *
        *                                                                                                                 */


        if (strcmp (argv[0], "./insertionsort") == 0)  // compara se o metodo escolhido foi insertionsort
        {
            while(fgets(str, 100, entrada) != NULL)//percorre o arquivo de entrada
            {
                MAX = atoi(str); //max recebe os dados do arquivo de entrada convertido para inteiro


                while(seed<10000000)
                {

                    V=Preenche(V,MAX,seed);

                    if(MAX!=0)
                    {
                        tempo_i = clock();
                        InsertionSort(V,MAX);
                        free(V);
                        testetotall=testetotall+testetotal;
                        movitotall=movitotall+movitotal;
                        tempo_f = clock();
                        tempo_medio=(tempo_f - tempo_i)/CLOCKS_PER_SEC;
                        fprintf(saida,"%d               %lu               %1.f                  %1.f                   %d\n\n",MAX,tempo_medio,testei,movii,seed);//Grava as informacao no arquivo de saida
                        ZeraVariaveis();
                    }
                    seed=seed*10;
                }
                seed=10;

            }

        }
        if (strcmp (argv[0], "./selectionsort") == 0)// compara se o metodo escolhido foi selectionsort
        {
            while(fgets(str, 100, entrada) != NULL)//percorre o arquivo de entrada
            {
                MAX = atoi(str); //max recebe os dados do arquivo de entrada convertido para inteiro


                while(seed<10000000)
                {

                  V=  Preenche(V,MAX,seed);
                    if(MAX!=0)
                    {
                        tempo_i = clock();
                        SelectionSort(V,MAX);
                        free(V);
                        testetotall=testetotall+testetotal;
                        movitotall=movitotall+movitotal;
                        tempo_f = clock();
                        tempo_medio=(tempo_f - tempo_i)/CLOCKS_PER_SEC;
                      fprintf(saida,"%d               %lu               %1.f                  %1.f                   %d\n\n",MAX,tempo_medio,testes,movis,seed);//Grava as informacao no arquivo de saida
                        ZeraVariaveis();
                    }
                    seed=seed*10;
                }
                seed=10;

            }

        }

        if (strcmp (argv[0], "./shellsort") == 0)// compara se o metodo escolhido foi shellsort
        {
            while(fgets(str, 100, entrada) != NULL)//percorre o arquivo de entrada
            {
                MAX = atoi(str); //max recebe os dados do arquivo de entrada convertido para inteiro


                while(seed<10000000)
                {

                  V=  Preenche(V,MAX,seed);

                    if(MAX!=0)
                    {
                        tempo_i = clock();
                        ShellSort(V,MAX);
                        free(V);
                        testetotall=testetotall+testetotal;
                        movitotall=movitotall+movitotal;
                        tempo_f = clock();
                        tempo_medio=(tempo_f - tempo_i)/CLOCKS_PER_SEC;
                        fprintf(saida,"%d               %lu               %1.f                  %1.f                   %d\n\n",MAX,tempo_medio,testesh,movish,seed);//Grava as informacao no arquivo de saida
                        ZeraVariaveis();
                    }
                    seed=seed*10;
                }
                seed=10;

            }

        }

        if (strcmp (argv[0], "./heapsort") == 0)// compara se o metodo escolhido foi heapsort
        {
            while(fgets(str, 100, entrada) != NULL)//percorre o arquivo de entrada
            {
                MAX = atoi(str); //max recebe os dados do arquivo de entrada convertido para inteiro


                while(seed<10000000)
                {

                  V=  Preenche(V,MAX,seed);

                    if(MAX!=0)
                    {
                        tempo_i = clock();
                        HeapSort(V,MAX);
                        free(V);
                        testetotall=testetotall+testetotal;
                        movitotall=movitotall+movitotal;
                        tempo_f = clock();
                        tempo_medio=(tempo_f - tempo_i)/CLOCKS_PER_SEC;
                        fprintf(saida,"%d               %lu               %1.f                  %1.f                   %d\n\n",MAX,tempo_medio,testeh,movih,seed);//Grava as informacao no arquivo de saida
                        ZeraVariaveis();
                    }
                    seed=seed*10;
                }
                seed=10;

            }

        }

        if (strcmp (argv[0],"./quicksort") == 0)// compara se o metodo escolhido foi quicksort
        {
            while(fgets(str, 100, entrada) != NULL)//percorre o arquivo de entrada
            {
                MAX = atoi(str); //max recebe os dados do arquivo de entrada convertido para inteiro

                while(seed<10000000)
                {

                    V=Preenche(V,MAX,seed);
                    if(MAX!=0)
                    {
                        tempo_i = clock();
                        QuickSort(V,MAX);
                        free(V);
                        testetotall=testetotall+testetotal;
                        movitotall=movitotall+movitotal;
                        tempo_f = clock();
                        tempo_medio=(tempo_f - tempo_i)/CLOCKS_PER_SEC;
                        fprintf(saida,"%d               %lu               %1.f                  %1.f                   %d\n\n",MAX,testeq,tempo_medio,moviq,seed);//Grava as informacao no arquivo de saida
                        ZeraVariaveis();

                    }
                    seed=seed*10;
                }
                seed=10;

            }

        }
    }
    printf("\n\n ORDENADO!\n");
    fprintf(saida,"Media total de trocas: %1.f\n Media total de Movimentações: %1.f \n",(testetotal)/42,(movitotal)/42);
    fclose(entrada); //fecha arquivo de entrada
    fclose(saida);//fecha arquivo de saida

    return 0;
}

/** @file mergesortstruct.c
 *  @brief Realiza as N interações.

 *  @author Lucas S. Oliveira RGA 201521901005 && Gustavo da Costa 201521901011
 *
 * @brief  Realiza a ordenação de vetores struct pelo método MergeSort.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
double testem=0,movim=0;
double testetotal=0, movitotal=0;


// FOI DEFINIDO A TAD boolean para o tipo boleano ausente na liguaguem C
enum boolean
{
    true = 1, false = 0
};
typedef  enum boolean  bool;

// Foi DEFINIDO a TAD registro que sera utilizada para as ordenações
typedef struct registro
{
    int inteiro;
    char cadeia1[200],cadeia2[200],cadeia3[200],cadeia4[200],cadeia5[200],cadeia6[200],cadeia7[200],cadeia8[200],cadeia9[200],cadeia10[200];
    float a,b,c,d;
    bool bole;

}registro;



/**	Preenche
 * @brief  Preenche um vetor do tipo registro
 * @param Um vetor do tipo registro e o tamanho deste vetor e a semente para o sorteio dos numeros
 */
registro *Preenche(registro *V,int MAX,int seed)
{
    srand(time(NULL));
    V=malloc(MAX*sizeof(registro));
    for(int i=0; i<MAX; i++)
    {

        V[i].inteiro=rand()%seed;
        for(int j=0; j<200; j++)
        {
            V[i].cadeia1[j]=rand()%seed;
            V[i].cadeia2[j]=rand()%seed;
            V[i].cadeia3[j]=rand()%seed;
            V[i].cadeia4[j]=rand()%seed;
            V[i].cadeia5[j]=rand()%seed;
            V[i].cadeia6[j]=rand()%seed;
            V[i].cadeia7[j]=rand()%seed;
            V[i].cadeia8[j]=rand()%seed;
            V[i].cadeia9[j]=rand()%seed;
            V[i].cadeia10[j]=rand()%seed;
        }
        V[i].a=rand()%seed;
        V[i].b=rand()%seed;
        V[i].c=rand()%seed;
        V[i].d=rand()%seed;
        V[i].bole=true;




    }


    return V;

}


/**	MergeSort
 * @brief  Ordena utilizando o metodo MergeSort
 *  Usa o principio de divisao e conquista, divide o vetor em sub vetores ate que nao seja mais possivel a divisao
 * e depois os ordena.
 *  Tem o custo de  O(nlog(n))
 */

void MergeSort( registro *vetor, int posicaoInicio, int posicaoFim) {
    int i, j, k, metadeTamanho;


registro *vetorTemp;
    if(posicaoInicio == posicaoFim)
     return;
    // ordenacao recursiva das duas metades
    metadeTamanho = (posicaoInicio + posicaoFim ) / 2;
    MergeSort(vetor, posicaoInicio, metadeTamanho);
    MergeSort(vetor, metadeTamanho + 1, posicaoFim);

    // intercalacao no vetor temporario t
    i = posicaoInicio;
    j = metadeTamanho + 1;
    k = 0;
vetorTemp = (registro *) malloc(sizeof(registro) * (posicaoFim - posicaoInicio + 1));


    while(i < metadeTamanho + 1 || j  < posicaoFim + 1) {
        if (i == metadeTamanho + 1 ) { // i passou do final da primeira metade, pegar v[j]
            vetorTemp[k] = vetor[j];
            movim++;
            j++;
            k++;
        }
        else {
            if (j == posicaoFim + 1) { // j passou do final da segunda metade, pegar v[i]
                vetorTemp[k] = vetor[i];
                movim++;
                i++;
                k++;
            }
            else {
                if (vetor[i].inteiro < vetor[j].inteiro && testem++) {
                    vetorTemp[k] = vetor[i];
                    movim++;
                    i++;
                    k++;
                }
                else {
                    vetorTemp[k] = vetor[j];
                    movim++;
                    j++;
                    k++;
                }
            }
        }

    }
    // copia vetor intercalado para o vetor original
    for(i = posicaoInicio; i <= posicaoFim; i++) {
        vetor[i] = vetorTemp[i - posicaoInicio];
    }

free(vetorTemp);
testetotal=testem;
movitotal=movim;
}

void Imprime(registro *V,int MAX)
{
    for(int i=0; i<MAX; i++)
    {

        printf("%d\n",V[i].inteiro);
    }

}


int main(){
int MAX=100000;
int seed=10;
printf("\n# Trabalho : Analise de algoritmos de ordenação #\n# Disciplina Estrutura de Dados                 #\n# Prof. Frederico S. Oliveira                   #\n# Autor:Lucas S. de Oliveira  RGA: 201521901005 #\n# Autor:Gustavo da Costa RGA:201521901011 #");
clock_t tempo_i, tempo_f,tempo_medio;

while (MAX<=700000) {
registro *V;
V= Preenche(V,MAX,seed);
tempo_i = clock();
MergeSort(V,0,MAX);
tempo_f = clock();
tempo_medio=(tempo_f - tempo_i)/CLOCKS_PER_SEC;

printf("Testes      Movimentações     Tempo     Tamanho     Semente\n%1.f     %1.f           %lu        %d      %d\n\n",testem,movim,tempo_medio,MAX,seed);

  MAX=MAX+200000;
  seed=seed*10;
free(V);

}



}

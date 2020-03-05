/** @file Ordenacoesstruct.h
 *  @brief Todas a funções referentes aos metodos de ordenação apresentados em sala de aula e algumas auxiliares
           para a realização da analise do trabalho.

           Modificações foram realizadas para que um vetor de struct fosse ordenado.

    ***** FUNCIONA COMO UMA BIBLIOTECA DE FUNÇÕES PARA A REALIZAÇÃO DA ANALISE *****

 *  @author Lucas S. Oliveira RGA 201521901005 && Gustavo da Costa 201521901011
 *
 * @brief BIBLIOTECA dos algoritmos de ordenacão.
 */


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
double testes=0,movis=0,testeq=0,moviq=0,testeh=0,movih=0,movim=0,testem=0,movii=0,testei=0,testesh=0,movish=0,testeb=0,movib=0;
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

} registro;



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


/**	Imprime
 * @brief  Imprime um vetor do inicio ao fim
 * @param Um vetor do tipo registro e o tamanho deste vetor
 */
void Imprime(registro *V,int MAX)
{
    for(int i=0; i<MAX; i++)
    {

        printf("%d\n",V[i].inteiro);
    }

}


/**	SelectionSort
 * @brief  Ordena um vetor ,pelo metodo de seleção.
 * percorre o vetor diversas vezes colocando o menor elemento na posição inicial depois
 faz isso para n-1 elementos da lista.
 *  Tem custo de O(n^2)
 *
 * @param Um vetor do tipo registro e o tamanho deste vetor
 */

void *SelectionSort(registro *V, int n)
{
    int i,j,min;
    registro aux;
    for (i=0; i<n-1; i++)
    {
        min = i;
        for (j=i+1; j<n; j++)
        {
            if (V[j].inteiro < V[min].inteiro && testes++)
                min = j;
        }


        aux = V[i];
        V[i] = V[min];
        V[min] = aux;
        movis=movis+3;
    }

    testetotal=testes;
    movitotal=movis;
}

/**	InsertionSort
 * @brief  Ordena um vetor ,pelo metodo de inserção.
 * percorre o vetor diversas vezes colocando o testando se o elemento da esquerda é maior que o atual
 caso seja ele troca de posição com o elemento da esquerda ate q essa condição seja falsa.
 *  Tem custo de O(n^2)
 *
 * @param Um vetor do tipo registro e o tamanho deste vetor
 */


void InsertionSort(registro *V, int n)
{
    int i,j;
    registro aux;
    for (i=0; i<n; i++)
    {
        j = i;
        while (j>0 && V[j-1].inteiro > V[j].inteiro && testei++)
        {
            aux = V[j];
            V[j] = V[j-1];
            V[j-1] = aux;
            movii=movii+3;
            j--;


        }

    }
    //printf("TESTE: %1.f \n",testei);
    testetotal=testei;
    movitotal=movii;
}


/**	BubbleSort
 * @brief  Ordena um vetor , podemos chamar o metodo de bolha como metodo de modo bruto,
 * pois percorre o vetor diversas vezes colocando o maior elemento em no final da lista.
 *  Tem custo de O(n^2)
 *
 * @param Um vetor do tipo inteiro e o tamanho deste vetor
 */
void BubbleSort ( registro *V, int n)
{
    int i,j;
    registro aux;
    for (i=0; i<n-1; i++)
    {
        for (j=0; j<n-1; j++)
        {
            if (V[j].inteiro > V[j+1].inteiro && testeb++)
            {
                aux = V[j+1];
                V[j+1] = V[j];
                V[j] = aux;
                movib=movib+3;

            }

        }
    }
    testetotal=testeb;
    movitotal=movib;

}



/**	ShellSort
 * @brief  Ordena um vetor ,pelo metodo ShellSort.
 * É uma melhoria muito eficiente para vetores do metodo InsertionSort, pois nao depende apenas dos vizinhos da aresta para realizar as comaparações
 *  Nao é matematica mente provado mas tem custo medio de O(nlog(n))
 * @param Um vetor do tipo inteiro e o tamanho deste vetor
 */
void ShellSort(registro *V, int n)
{
    int i,j,h;
    registro aux;
    h = 1;
    do
    {
        h = (h*3)+1;
    }
    while(h<=n);


    do
    {
        h = h/3;

        for (i=h; i<n; i++)
        {
            j = i-h;
            while (j>=0 && V[j+h].inteiro < V[j].inteiro && testesh++)
            {
                aux = V[j];
                V[j] = V[j+h];
                V[j+h] = aux;
                movish=movish+3;
                j = j-h;

            }

        }
    }
    while (h>1);

    testetotal=testesh;
    movitotal=movish;
}



/**	Particao
 * @brief  Função auxiliar para o metodo QuickSort.
 *  Particona o vetor em sub vetores a partir da escolha de um pivô
 *  Seu pior caso é O(n^2), mas normalmente acontece O(nlog(n))
 */

void Particao (int esq, int dir, int *i, int *j, registro *V)
{

    int x;
    registro aux;
    *i = esq;
    *j = dir;
    x = V[(*i + *j)/2].inteiro;
    do
    {
        while (x>V[*i].inteiro&&testeq++)
        {
            (*i)++;

        }

        while (x<V[*j].inteiro&&testeq++)
        {
            (*j)--;
        }


        if (*i<=*j)
        {
            aux = V[*i];
            V[*i] = V[*j];
            V[*j] = aux;
            moviq=moviq+3;
            (*i)++;
            (*j)--;

        }
    }
    while (*i <=*j);

    testetotal=testeq;
    movitotal=moviq;

}


/**	Ordena
 * @brief  Função auxiliar para o metodo QuickSort.
 *  Reparticiona usando a função Particao e separa os elementos pelo pivo.
 *  Seu pior caso é O(n^2), mas normalmente acontece O(nlog(n))
 */
void Ordena (int esq, int dir, registro *V)
{
    int j=0, i=0;
    Particao (esq,dir,&i,&j,V);
    if (esq<j)
    {
        Ordena(esq,j,V);
    }

    if (i<dir)
    {
        Ordena(i,dir,V);
    }



}


/**	QuickSort
 * @brief Ordena com o metodo QuickSort.
 *  Particona o vetor em sub vetores a partir da escolha de um pivô e os ordena.
 *  Seu pior caso é O(n^2), mas normalmente acontece O(nlog(n))
 */
void QuickSort (registro *V, int n)
{
    Ordena(0,n-1,V);

}



/**	ConstroiHeap
 * @brief  Função auxiliar para o metodo HeapSort.
 *  Cria a estrutura do Heap para ordenar um vetor
 *
 */

void ConstroiHeap(registro *V, int n, int i)
{
    int maior = i;
    int l = 2*i+1, r = 2*i+2;
    if (l<n && V[l].inteiro > V[maior].inteiro && testeh++)
    {
        maior = l;
    }

    if (r<n && V[r].inteiro>V[maior].inteiro && testeh++)
    {
        maior = r;
    }

    if (maior != i)
    {

        registro aux = V[i];
        V[i] = V[maior];
        V[maior] = aux;
        movih=movih+3;
        ConstroiHeap(V,n,maior);
    }

}


/**	HeapSort
 * @brief  Ordena utilizando o metodo HeapSort
 *  Utiliza da fila de prioridades como principio de ordenação e tambem da estrutura heap para realizar esta fila de prioridades
 * Tem custo medio de O(nlog(n))
 */

void HeapSort( registro *V, int n)
{
    int i;
    for (i=(n/2)-1; i>=0; i--)
    {
        ConstroiHeap(V,n,i);
    }
    for (i=n-1; i>=0; i--)
    {
        registro aux = V[0];
        V[0] = V[i];
        V[i] = aux;
        movih=movih+3;
        ConstroiHeap(V,i,0);
    }

    testetotal=testeh;
    movitotal=movih;
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







/**	ZeraVariaveis
 * @brief  Zera as variaveis contadoras utilizadas nos metodos de ordenacao.
 */


void ZeraVariaveis()
{
    testes=0;
    movis=0;
    testeq=0;
    moviq=0;
    testeh=0;
    movih=0;
    movim=0;
    testem=0;
    movii=0;
    testei=0;
    testesh=0;
    movish=0;
    testeb=0;
    movib=0;

}

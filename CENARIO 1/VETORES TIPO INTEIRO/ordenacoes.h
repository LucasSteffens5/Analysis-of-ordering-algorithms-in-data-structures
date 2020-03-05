/** @file ordenacoes.h
 *  @brief Todas a funções referentes aos metodos de ordenação apresentados em sala de aula e algumas auxiliares
           para a realização da analise do trabalho.

    ***** FUNCIONA COMO UMA BIBLIOTECA DE FUNÇÕES PARA A REALIZAÇÃO DA ANALISE *****

 *  @author Lucas S. Oliveira RGA 201521901005 && Gustavo da Costa 201521901011
 */
/**
 * @brief BIBLIOTECA dos algoritmos de ordenacão.
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<time.h>
double testes=0,movis=0,testeq=0,moviq=0,testeh=0,movih=0,movim=0,testem=0,movii=0,testei=0,testesh=0,movish=0,testeb=0,movib=0;
double testetotal=0, movitotal=0;



/**	SelectionSort
 * @brief  Ordena um vetor ,pelo metodo de seleção.
 * percorre o vetor diversas vezes colocando o menor elemento na posição inicial depois
 faz isso para n-1 elementos da lista.
 *  Tem custo de O(n^2)
 *
 * @param Um vetor do tipo inteiro e o tamanho deste vetor
 */
void SelectionSort(int V[], int n)  // Função referente ao metodo de ordenacao SelectionSort
{
    int i,j,aux,min;
    for (i=0; i<n-1; i++)
    {
        min = i;
        for (j=i+1; j<n; j++ && testes++) // a cada interação do for é realizado um teste, basta saber se conta dois ou um, pois ha um teste no for e um do if.
        {
            if (V[j] < V[min])
                min = j;


        }

        aux = V[i];    // É realizado a copia de registros para a ordenacao do vetor
        V[i] = V[min];
        V[min] = aux;
        movis=movis+3;
    }
    testetotal=testes;                        // É somado a uma vairavel global a quantia total de movimentações e teste do metodo, e esta quantidade é importada pela função principal que executa o algoritmo
    movitotal=movis;                          // Essa variaveis são utilizadas para calcular a "média" de testes e copias de registros

}


/**	InsertionSort
 * @brief  Ordena um vetor ,pelo metodo de inserção.
 * percorre o vetor diversas vezes colocando o testando se o elemento da esquerda é maior que o atual
 caso seja ele troca de posição com o elemento da esquerda ate q essa condição seja falsa.
 *  Tem custo de O(n^2)
 *
 * @param Um vetor do tipo inteiro e o tamanho deste vetor
 */
void InsertionSort(int V[], int n) // Função referente ao metodo de ordenacao InsertionSort
{
    int i,j,aux;
    for (i=0; i<n; i++)
    {
        j = i;
        while (j>0 && V[j-1] > V[j] && testei++)
        {
            aux = V[j];
            V[j] = V[j-1];
            V[j-1] = aux;
            j--;
            movii=movii+3;
               //   Toda vez que esse laço é executado é realizado um teste e 3 copias  de registro

        }


    }
    testetotal=testei;  // É somado a uma vairavel global a quantia total de movimentações e teste do metodo, e esta quantidade é importada pela função principal que executa o algoritmo
    movitotal=movii;  // Essa variaveis são utilizadas para calcular a "média" de testes e copias de registros
}




/**	BubbleSort
 * @brief  Ordena um vetor , podemos chamar o metodo de bolha como metodo de modo bruto,
 * pois percorre o vetor diversas vezes colocando o maior elemento em no final da lista.
 *  Tem custo de O(n^2)
 *
 * @param Um vetor do tipo inteiro e o tamanho deste vetor
 */
void BubbleSort (int V[], int n)  // Função referente ao metodo de ordenacao BubbleSort
{
    int i,j,aux;
    for (i=0; i<n-1; i++)
    {
        for (j=0; j<n-1; j++) /// Toda vez que este laço é executado acontece um teste entre os termos do vetor
        {
            if (V[j] > V[j+1] && testeb++)
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


void ShellSort(int V[], int n) // Função referente ao metodo de ordenacao ShellSort
{
    int i,j,aux,h;
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
            while (j>=0 && V[j+h] < V[j] && testesh++)  // A cada repetição do laço é contado um teste entre os termos do vetor
            {
                aux = V[j];
                V[j] = V[j+h];
                V[j+h] = aux;
                j = j-h;
                movish=movish+3;  // Aqui sao contabilizados tres copias de registros

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


void Particao (int esq, int dir, int *i, int *j, int *V)  // Função referente ao metodo QuickSort, a função particiona o vetor em vetores menores conforme o pivô.
{
    int x, aux;
    *i = esq;
    *j = dir;
    x = V[(*i + *j)/2];
    do
    {
        while (x>V[*i]&&testeq++) // Aqui sao contabilizados testes entre os termos do vetor e ou subvetor
            (*i)++;
        while (x<V[*j]&&testeq++) // Aqui sao contabilizados testes entre os termos do vetor e ou subvetor
            (*j)--;
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

}


/**	Ordena
 * @brief  Função auxiliar para o metodo QuickSort.
 *  Reparticiona usando a função Particao e separa os elementos pelo pivo.
 *  Seu pior caso é O(n^2), mas normalmente acontece O(nlog(n))
 */

void Ordena (int esq, int dir, int V[]) // Função referente a ordenacao do metodo QuickSort
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

void QuickSort (int V[], int n) // Função referente ao metodo de ordenacao QuickSort recursivo
{
    Ordena(0,n-1,V);
testetotal=testeq;
    movitotal=moviq;
}


/**	ConstroiHeap
 * @brief  Função auxiliar para o metodo HeapSort.
 *  Cria a estrutura do Heap para ordenar um vetor
 *
 */


void ConstroiHeap(int V[], int n, int i)  // Função referente ao metodo de ordenacao HeapSort, esta função controi a estrutura HEAP
{
    int maior = i;
    int l = 2*i+1, r = 2*i+2;
    if (l<n && V[l] > V[maior]&&testeh++)  // Aqui sao contabilizados testes entre os elementos do vetor
    {
        maior = l;
    }



    if (r<n && V[r]>V[maior]&&testeh++) // Aqui sao contabilizados testes entre os elementos do vetor
    {
        maior = r;
    }


    if (maior != i )
    {

        int aux = V[i];
        V[i] = V[maior];
        V[maior] = aux;
        movih=movih+3;
        ConstroiHeap(V,n,maior); //Recursivamente cria o heap pra a subarvore
    }

}

/**	HeapSort
 * @brief  Ordena utilizando o metodo HeapSort
 *  Utiliza da fila de prioridades como principio de ordenação e tambem da estrutura heap para realizar esta fila de prioridades
 * Tem custo medio de O(nlog(n))
 */

void HeapSort(int V[], int n) // Função referente ao metodo de ordenacao QuickSort
{
    int i;
    for (i=(n/2)-1; i>=0; i--)
    {
        ConstroiHeap(V,n,i);
    }
    for (i=n-1; i>=0; i--)
    {
        int aux = V[0];
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


void MergeSort(int *vetor, int posicaoInicio, int posicaoFim)  // Função referente ao metodo de ordenacao MergeSort recursivo
{
    int i, j, k, metadeTamanho, *vetorTemp;

    if(posicaoInicio == posicaoFim)
        return;

    // ordenacao recursiva das duas metades
    metadeTamanho = (posicaoInicio + posicaoFim ) / 2;
    MergeSort(vetor, posicaoInicio, metadeTamanho);
    MergeSort(vetor, metadeTamanho + 1, posicaoFim);

    // intercalacao no vetor temporario
    i = posicaoInicio;
    j = metadeTamanho + 1;
    k = 0;
    vetorTemp = (int *) malloc(sizeof(int) * (posicaoFim - posicaoInicio + 1));

    while(i < metadeTamanho + 1 || j  < posicaoFim + 1)
    {
        if (i == metadeTamanho + 1 )
        {
            vetorTemp[k] = vetor[j];
            movim++;
            j++;
            k++;
        }
        else
        {
            if (j == posicaoFim + 1)
            {
                vetorTemp[k] = vetor[i];
                movim++;
                i++;
                k++;
            }
            else
            {
                if (vetor[i] < vetor[j] && testem++) // Aqui sao contabilizados testes entre os elementos do vetor
                {
                    vetorTemp[k] = vetor[i];
                    movim++;
                    i++;
                    k++;
                }
                else
                {
                    vetorTemp[k] = vetor[j];
                    movim++;
                    j++;
                    k++;
                }
            }
        }

    }
    // copia vetor intercalado para o vetor original
    for(i = posicaoInicio; i <= posicaoFim; i++)
    {
        vetor[i] = vetorTemp[i - posicaoInicio];
    }
    free(vetorTemp); // Libera a memoria do vetor temporario
    testetotal=testem;
    movitotal=movim;
}



/**	ZeraVariaveis
 * @brief  Zera as variaveis contadoras utilizadas nos metodos de ordenacao.
 */

void ZeraVariaveis() // Funcao que zera as variaveis globais utilizadas em cada função, se faz isso pois na função principal serao realizada varias interações com os mesmos metodos
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

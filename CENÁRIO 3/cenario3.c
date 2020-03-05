/** @file cenario3.c
 *  @brief Funções referentes aos metodos de ordenação apresentados em sala de aula e algumas auxiliares para ordenar
  e realizar a analise do trabalho.

    ***** SÓ É CONSIDERADO COMPARACOES AS COMPARACOES REALIZADAS ENTRE TERMOS DO VETOR *****
      ***** TODA COPIA DE REGISTRO ADVINDA DE UM VETOR É CONTABILIZADO COMO CÓPIA REALIZADA*****

 *  @author Lucas S. Oliveira RGA 201521901005 && Gustavo da Costa 201521901011
 */
/**
 * @brief Algoritmos de ordenacão.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#define MAX 10000 // EH NECESSARIO A ALTERACAO DO MAX (TAMANHO DO VETOR )PARA A ANALISE
#define seed 10000 // EH NECESSARIO A ALTERACAO DO SEED(SEMENTE)PARA A ANALISE
#define m 100 // EH NECESSARIO A ALTERACAO DO M (QUICKSORT INSERCAO )PARA A ANALISE
#define RANGE 5
int movih=0,moveg=0,testeg=0,movim=0,movitotal=0,testeh=0,testem=0,m4=0,q4=0,testetotal=0;
// INICIO QUICKSORT INSERCAO

void InsertionSort(int V[], int n)
{
    int i,j,aux;
    for (i=0; i<n; i++)
    {
        j = i;
        while (q4++ && j>0 && V[j-1] > V[j])
        {
            aux = V[j];
            V[j] = V[j-1];
            V[j-1] = aux;
            m4++;
            j--;
        }
    }
}
void QuickSortInsercao(int *vet, int inicio, int fim){
	int i = inicio;
	int j = fim;
	int tmp;
	if ( i >= j)
   {
	    return;
	}
	if((fim -inicio)< m){
      InsertionSort(&vet[inicio],fim-inicio+1);
      return;
   }
	int pivo = vet[(int)(inicio+fim)/2];
	while (i < j)
   {
	    while (q4++ && i<j && vet[i] < pivo) {
			i++;
		}
	    while (q4++ && i<j && vet[j] > pivo) {
			j--;
		}
	    if (i < j)
        {
		    tmp = vet[i];
		    vet[i] = vet[j];
		    vet[j] = tmp;
		    m4=m4+3;
		    i++;
		    j--;
	    }
	}
	if (j < i)
	{
	    tmp = j;
	    j = i;
	    i = tmp;
	}
	QuickSortInsercao(vet, inicio, i);
	if(i == inicio){
		QuickSortInsercao(vet,i+1,fim);
    }
	else{
		QuickSortInsercao(vet,i,fim);
    }
}
//FIM QUICKSORT INSERCAO

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

void mergeSort(int *vetor, int posicaoInicio, int posicaoFim) {
    int i, j, k, metadeTamanho, *vetorTemp;

    if(posicaoInicio == posicaoFim) return;
	
    // ordenacao recursiva das duas metades
    metadeTamanho = (posicaoInicio + posicaoFim ) / 2;
    mergeSort(vetor, posicaoInicio, metadeTamanho);
    mergeSort(vetor, metadeTamanho + 1, posicaoFim);
	
    // intercalacao no vetor temporario t
    i = posicaoInicio;
    j = metadeTamanho + 1;
    k = 0;
    vetorTemp = (int *) malloc(sizeof(int) * (posicaoFim - posicaoInicio + 1));
	
    while(i < metadeTamanho + 1 || j  < posicaoFim + 1) {
        if (testem++ && i == metadeTamanho + 1 ) { // i passou do final da primeira metade, pegar v[j]
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
                if (testem&& vetor[i] < vetor[j]) {
                    vetorTemp[k] = vetor[i];
                    movim++;
                    i++;
                    k++;
                }
                else {
                    vetorTemp[k] = vetor[j];
                    j++;
                    k++;
                    movim++;
                }
            }
        }

    }
    // copia vetor intercalado para o vetor original
    for(i = posicaoInicio; i <= posicaoFim; i++) {
        vetor[i] = vetorTemp[i - posicaoInicio];
		movim++;
    }
    free(vetorTemp);
}

void GnomeSort(int V[],int n){
	int prox = 0, ant = 0;
	int i = 0, aux;
	for(i = 0; i < n ; i++) {
		if(testeg++ && V[i] > V[i + 1]) {
			ant = i;
			prox = i + 1;
			while(testeg++ && V[ant] > V[prox])  {
				aux = V[ant];
				V[ant] = V[prox];
				V[prox] = aux;
				moveg = moveg + 3;
				if(ant > 0)
					ant--;
				if(prox > 0) 
					prox--;
			}
		}
	}
}

int main(){
	clock_t tempo_i, tempo_f;
	int *v = malloc(sizeof(int)*MAX);
	int *v1 = malloc(sizeof(int)*MAX);
	int *v2 = malloc(sizeof(int)*MAX);
	int *v3 = malloc(sizeof(int)*MAX);
	int *v4 = malloc(sizeof(int)*MAX);
	int i;
	srand(time(NULL));
	for(i=0;i<MAX;i++){
		v[i] = rand()%seed;
		v1[i] = v[i];
		v2[i] = v[i];
		v3[i] = v[i];
		v4[i] = v[i];
//		printf(" %d ",v3[i]);
	}printf("\n");
	  printf("Valor de n: %d",MAX);
	  printf("\n");
	  printf("Valor da semente: %d",seed);
      printf("\n");
      
      tempo_i = clock();
      QuickSortInsercao(v1,0,MAX);
      tempo_f = clock();
	  printf("Quicksort Inserção : %lu segundos \n", (tempo_f - tempo_i)/CLOCKS_PER_SEC);
	  printf("COMPARACOES : %d MOVIMENTACOES : %d\n",q4,m4);
	  
	  printf("\n");
	
      tempo_i = clock();
      HeapSort(v2,MAX);
      tempo_f = clock();
	  printf("Heapsort : %lu segundos \n", (tempo_f - tempo_i)/CLOCKS_PER_SEC);
	  printf("COMPARACOES : %d MOVIMENTACOES : %d\n",testetotal,movitotal);
	  printf("\n");
      
      tempo_i = clock();
      mergeSort(v3,0,MAX);
      tempo_f = clock();
	  printf("Mergesort : %lu segundos \n", (tempo_f - tempo_i)/CLOCKS_PER_SEC);
	  printf("COMPARACOES : %d MOVIMENTACOES : %d\n",testem,movim);
	  printf("\n"); 
		  
	  tempo_i = clock();
	  GnomeSort(v4,MAX);
	  tempo_f = clock();
	  printf("GnomeSort : %lu segundos \n", (tempo_f - tempo_i)/CLOCKS_PER_SEC);
	  printf("COMPARACOES : %d MOVIMENTACOES : %d\n",testeg,moveg);
	  printf("\n");
	//for(i=0;i<MAX;i++){
	//	printf(" %d ",v3[i]);
//	}printf("\n");
	
	
	free(v);
	free(v1);
	free(v2);
	free(v3);
	free(v4);
return 0;
}

/** @file quicksort.c
 *  @brief Funções referentes aos metodos de ordenação apresentados em sala de aula e algumas auxiliares para ordenar
  e realizar a analise do trabalho.

    ***** SÓ É CONSIDERADO COMPARACOES AS COMPARACOES REALIZADAS ENTRE TERMOS DO VETOR *****
      ***** TODA COPIA DE REGISTRO ADVINDA DE UM VETOR É CONTABILIZADO COMO CÓPIA REALIZADA*****

 *  @author Lucas S. Oliveira RGA 201521901005 && Gustavo da Costa 201521901011
 */
/**
 * @brief Algoritmos de ordenacão. Variações do QUICKSORT
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 1000 // EH NECESSARIO A ALTERACAO DO MAX (TAMANHO DO VETOR )PARA A ANALISE
#define seed 100 // EH NECESSARIO A ALTERACAO DO SEED(SEMENTE)PARA A ANALISE
#define m 100 // EH NECESSARIO A ALTERACAO DO M (QUICKSORT INSERCAO )PARA A ANALISE
int q1,q2,q3,q4,q5,q6;
int m1,m2,m3,m4,m5,m6;
// 1 - INICIO QUICKSORT RECURSIVO
void ParticaoRecursivo (int esq, int dir, int *i, int *j, int *V)
{
    int x, aux;
    *i = esq;
    *j = dir;
    x = V[(*i + *j)/2];
    do
    {
        while (x>V[*i] && q1++)
            (*i)++;

        while (x<V[*j] && q1++)
            (*j)--;

        if (*i<=*j)
        {
            aux = V[*i];
            V[*i] = V[*j];
            V[*j] = aux;
            m1=m1+3;
            (*i)++;
            (*j)--;
        }
    }
    while (*i <=*j);
}
void OrdenaRecursivo (int esq, int dir, int V[])
{
    int j=0, i=0;
    ParticaoRecursivo (esq,dir,&i,&j,V);
    if (esq<j)
    {
        OrdenaRecursivo(esq,j,V);
    }
    if (i<dir)
    {
        OrdenaRecursivo(i,dir,V);
    }
}

void QuickSortRecursivo (int V[], int n)
{
    OrdenaRecursivo(0,n-1,V);
}

//FIM QUICKSORT RECURSIVO


// 2 - INICIO QUICKSORT EMPILHA INTELIGENTE RECURSIVO

void ParticaoRecursivoInteligente (int esq, int dir, int *i, int *j, int *V)
{
    int x, aux;
    *i = esq;
    *j = dir;
    x = V[(*i + *j)/2];
    do
    {
        while (x>V[*i] && q2++)
            (*i)++;

        while (x<V[*j] && q2++)
            (*j)--;

        if (*i<=*j)
        {
            aux = V[*i];
            V[*i] = V[*j];
            V[*j] = aux;
            m2=m2+3;
            (*i)++;
            (*j)--;
        }
    }
    while (*i <=*j);
}
void OrdenaRecursivoEmpilhaInteligente(int esq, int dir, int V[])
{
    int j=0;
    int i=0;
    ParticaoRecursivoInteligente(esq,dir,&i,&j,V);
    if (esq <dir){
    if (j-esq < dir-i){
		OrdenaRecursivoEmpilhaInteligente(esq,j,V);
		OrdenaRecursivoEmpilhaInteligente(i,dir,V);
    }
    else{
		OrdenaRecursivoEmpilhaInteligente(i,dir,V);
		OrdenaRecursivoEmpilhaInteligente(esq,j,V);
	}
}
}

void QuickRecursivoEmpilhaInteligente(int V[], int n){
    OrdenaRecursivoEmpilhaInteligente(0,n-1,V);
}

//FIM QUICKSORT EMPILHA INTELIGENTE RECURSIVO

// 3 - INICIO QUICKSORT MEDIANA
void ParticaoMediana (int esq, int dir, int *i, int *j, int *V)
{
    int x,aux,meio;
    *i = esq;
    *j = dir;
    meio = (*i + *j)/2;
    x = (V[meio] + V[*i] + V[*j])/3; // k = 3
    do
    {
        while (x>V[*i] && q3++)
            (*i)++;

        while (x<V[*j] && q3++)
            (*j)--;

        if (*i<=*j)
        {
            aux = V[*i];
            V[*i] = V[*j];
            V[*j] = aux;
            m3=m3+3;
            (*i)++;
            (*j)--;
        }
    }
    while (*i <=*j);
}
void OrdenaMediana (int esq, int dir, int V[])
{
    int j=0, i=0;
    ParticaoMediana (esq,dir,&i,&j,V);
    if (esq<j)
    {
        OrdenaMediana(esq,j,V);
    }
    if (i<dir)
    {
        OrdenaMediana(i,dir,V);
    }
}
void QuickSortMediana (int V[], int n)
{
	   OrdenaMediana(0,n-1,V);
}
//FIM QUICKSORT MEDIANA

// 4 - INICIO QUICKSORT INSERCAO

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
            m4=m4+3;
            j--;
        }
    }
}
void QuickSortInsercao(int *vet, int inicio, int fim){
	int i = inicio;
	int j = fim;
	int tmp;
	if (i >= j)
   {
	    return;
	}
	if((fim -inicio)< m){
      InsertionSort(&vet[inicio],fim-inicio+1);
      return;
   }
	int pivo = vet[(int)(inicio+fim)/2];
	while ( i < j)
   {
	    while (q4++ && i<j && vet[i] < pivo) {
			i++;
		}
	    while (q4++ && i<j && vet[j] > pivo) {
			j--;
		}
	    if ( i < j)
        {
		    tmp= vet[i];
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

// 5 -INICIO QUICKSORT INTERATIVO
static int
separa (int v[], int p, int r)
{
   int c = v[p], i = p+1, j = r, t;
   m5++;
   m6++;
   while (i <= j) {
      if (v[i] <= c && q5++ && q6++){
		  ++i;
      }
      else if (c < v[j] && q5++ && q6++) {
		  --j;
      }
      else {
         t = v[i],
         v[i] = v[j],
         v[j] = t;
         m5=m5+3;
         m6=m6+3;
         ++i;
         --j;
      }
   }
   v[p] = v[j], v[j] = c;
   m5=m5+2;
   m6=m6+2;
   return j;
}
void QuickSortIterative (int v[], int p, int r)
{
   int j, *pilhap, *pilhar, t;
   pilhap = malloc ((r-p+1) * sizeof (int));
   pilhar = malloc ((r-p+1) * sizeof (int));
   pilhap[0] = p;
   pilhar[0] = r;
   t = 0;

   while (t >= 0) {
      p = pilhap[t];
      r = pilhar[t];
      m5=m5+2;
      t--;
      if ( p < r) {
         j = separa (v, p, r);
         t++;
         pilhap[t] = p;
         pilhar[t] = j-1;
         t++;
         pilhap[t] = j+1;
         pilhar[t] = r;
         m5=m5+4;

      }
   }
}
//FIM QUICKSORT INTERATIVO

// 6 - INICIO DO QUICKSORT INTERATIVO EMPILHA INTELIGENTE
void QuickSortInterativoInteligente (int v[], int p, int r)
{
   int j, *pilhap, *pilhar, t;
   pilhap = malloc ((r-p+1) * sizeof (int));
   pilhar = malloc ((r-p+1) * sizeof (int));
   pilhap[0] = p; pilhar[0] = r; t = 0;
   m6=m6+2;
   while (t >= 0) {
      p = pilhap[t]; r = pilhar[t]; --t;
      m6=m6+2;
      while (p < r) {
         j = separa (v, p, r);
         ++t; pilhap[t] = p; pilhar[t] = j-1;
         p = j + 1;
         m6=m6+2;
      }
   }
}
// FIM DO QUICKSORT INTERATIVO EMPILHA INTELIGENTE
int main(){
	int i;
    clock_t tempo_i, tempo_f;

    int *V, *V1, *V2,*V3,*V4,*V5,*V6;
    V = malloc(MAX*sizeof(int));
    V1 = malloc(MAX*sizeof(int));
    V2 = malloc(MAX*sizeof(int));
    V3 = malloc(MAX*sizeof(int));
    V4 = malloc(MAX*sizeof(int));
    V5 = malloc(MAX*sizeof(int));
    V6 = malloc(MAX*sizeof(int));
    srand(time(NULL));
    for(i=0; i<MAX; i++)
    {
        V[i] = rand()%seed;
        V1[i] = V[i];
        V2[i] = V[i];
        V3[i] = V[i];
        V4[i] = V[i];
        V5[i] = V[i];
        V6[i] = V[i];

    }


	tempo_i = clock();
    QuickSortRecursivo(V1,MAX);
    tempo_f = clock();
    printf("QuickSortRecursivo: %lu segundos \n", (tempo_f - tempo_i)/CLOCKS_PER_SEC);
    printf("COMPARACOES : %d MOVIMENTACOES : %d\n",q1,m1);

	tempo_i = clock();
    QuickSortMediana(V2,MAX);
    tempo_f = clock();
    printf("\nQuickSortMediana: %lu segundos \n", (tempo_f - tempo_i)/CLOCKS_PER_SEC);
	printf("COMPARACOES : %d MOVIMENTACOES : %d\n",q3,m3);

    tempo_i = clock();
    QuickRecursivoEmpilhaInteligente(V3,MAX);
    tempo_f = clock();
    printf("\nQuickSortEmpilhaRecursivo: %lu segundos \n", (tempo_f - tempo_i)/CLOCKS_PER_SEC);
    printf("COMPARACOES : %d MOVIMENTACOES : %d\n",q2,m2);

	tempo_i = clock();
    QuickSortInsercao(V4,0,MAX);
    tempo_f = clock();
	printf("\nQuickSortInsercao: %lu segundos \n", (tempo_f - tempo_i)/CLOCKS_PER_SEC);
	printf("COMPARACOES : %d MOVIMENTACOES : %d\n",q4,m4);

	tempo_i = clock();
    QuickSortIterative(V5,0,MAX);
    tempo_f = clock();
    printf("\nQuickSortInterativo: %lu segundos \n", (tempo_f - tempo_i)/CLOCKS_PER_SEC);
	printf("COMPARACOES : %d MOVIMENTACOES : %d\n",q5,m5);

	tempo_i = clock();
    QuickSortInterativoInteligente(V6,0,MAX);
    tempo_f = clock();
	printf("\nQuickSortInterativoInteligente: %lu segundos \n", (tempo_f - tempo_i)/CLOCKS_PER_SEC);
	printf("COMPARACOES : %d MOVIMENTACOES : %d\n",q6,m6);


/*	for(i=0; i<MAX; i++)
    {
		printf(" %d ", V5[i]);
    }
    printf("\n");*/

    free(V);
    free(V1);
    free(V2);
    free(V3);
    free(V4);
    free(V5);
    free(V6);
return 0;
}

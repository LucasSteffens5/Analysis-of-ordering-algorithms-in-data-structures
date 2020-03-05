/** @file counting.c
 *  @brief Função referente ao metodo de ordenação countingSort - ORDENACAO POR CONTAGEM.

 *  @author Lucas S. Oliveira RGA 201521901005 && Gustavo da Costa 201521901011
 */
/**
 * @brief Algoritmos de ordenacão.
 */


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 1000 // EH NECESSARIO A ALTERACAO DO MAX (TAMANHO DO VETOR )PARA A ANALISE
#define seed 1000																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																											

void counting(int A[], int B[], int C[],int n){
	int i;
	for(i=0;i<n;i++) 
		C[A[i]]++;
	for(i=1;i<seed;i++)
		C[i] += C[i-1];
	for(i=n-1;i>=0;i--){
		B[C[A[i]]] = A[i];
		C[A[i]]--;
	}
}
int main(){
	clock_t tempo_i, tempo_f;
	int *a = malloc(sizeof(int)*MAX);
	int *b = malloc(sizeof(int)*MAX);															
	int *c = malloc(sizeof(int)*MAX);																																																							
	int i;																															
	srand(time(NULL));
	for(i=0;i<MAX;i++){
		a[i] = rand()%seed;
		b[i] = 0;
		c[i] = 0;
		//printf(" %d ",a[i]);
	}printf("\n");
	
	tempo_i = clock();
	counting(a,b,c,MAX);
	tempo_f = clock();
	printf("CountigSort : %lu segundos \n", (tempo_f - tempo_i)/CLOCKS_PER_SEC);
	
/*	for(i=0;i<MAX;i++){
		printf(" %d ",c[i]);
	}printf("\n");*/
	return 0;
	free(a);
	free(b);
	free(c);
}

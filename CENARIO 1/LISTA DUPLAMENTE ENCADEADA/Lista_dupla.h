/** @file ordenacoes.h
 *  @brief Todas a funções referentes aos metodos de ordenação apresentados em sala de aula e algumas auxiliares
           para a realização da analise do trabalho.

    ***** FUNCIONA COMO UMA BIBLIOTECA DE FUNÇÕES PARA A REALIZAÇÃO DA ANALISE *****

 *  @author Lucas S. Oliveira RGA 201521901005 && Gustavo da Costa 201521901011
 *
 * @brief BIBLIOTECA dos algoritmos de ordenacão.
 */
#include <sys/time.h>
#include <stdlib.h>
#include <stdio.h>
#include<time.h>
#include<string.h>
double testes=0,movis=0,testeq=0,moviq=0,testeh=0,movih=0,movim=0,testem=0,movii=0,testei=0,testesh=0,movish=0,testeb=0,movib=0;
double testetotal=0, movitotal=0;
/* variaveis globais foram declaradas para serem utilizadas como contadores   */


/*  Noh_duplo
@brief TAD utilizada pra a criação dos nós pertencentes a uma lista
  */

typedef struct Noh_duplo
{
    int item;
    struct Noh_duplo *prox;
    struct Noh_duplo *ant;
} noh;



/* TAD Lista
@brief TAD utilizada para a criação do tipo lista
 @param Dois ponteiros do tipo NOH
  */
typedef struct
{
    noh *primeiro;
    noh *ultimo;
} lista;

/** CRIALISTA
 * @brief Cria uma lista vazia, atribuindo o endereco a um ponteiro passado como parametro.
 *  O primeiro elemento da lista eh sempre um noh vazio. Ao criar uma lista vazia, aponta-se os ponteiros primeiro e ultimo para esse noh vazio.
 * @param  ponteiro do tipo lista.
 */
void CriaLista(lista *l)
{
    l->primeiro = (noh *) malloc(sizeof(noh));
    l->ultimo = l->primeiro;
    l->primeiro->prox = NULL;
    l->primeiro->ant = NULL;
}
/** VAZIA
 * @brief Verefica se a lista esta vazia
 *
 * @param ponteiro do tipo lista
 */

int Vazia(lista *l)
{
    return (l->primeiro == l->ultimo);
}



/* INSERE
@brief Insere um noh, que corresponde a um termo da lista.
 @param Um ponteiro do tipo Lista e um intero a ser adicionado.
  */
void Insere(int x, lista *l)
{
    noh *aux = (noh *)malloc(sizeof(noh));
    l->ultimo->prox = aux;
    aux->ant = l->ultimo;
    l->ultimo = aux;
    l->ultimo->item = x;
    l->ultimo->prox = NULL;
}



/* ImprimePrimeiroUltimo
@brief Imprime uma lista do primeiro ate o ultimo termo
 @param Ponteiro do tipo lista.
  */

void ImprimePrimeiroUltimo(lista *l)
{
    noh *aux;
    aux = l->primeiro;
    while (aux->prox->item!='#')
    {
        printf("%d\n", aux->item);

        aux = aux->prox;
    }
}


/**	APAGA LISTA
 * @brief Apaga toda a lista, liberando o espaço de memoria alocado
 *
 * @param ponteiro do tipo lista.
 */void ApagaLista(lista *l)
{
    noh *q;
    while(!Vazia(l))
    {
        q = l->primeiro;
        l->primeiro = l->primeiro->prox;
        free(q);
    }
    free(l->primeiro);
    l->primeiro=l->ultimo = NULL;
}






/**	BubbleSortlista
 * @brief  Ordena a lista , podemos chamar o metodo de bolha como metodo de modo bruto,
 * pois percorre a lista diversas vezes colocando o maior elemento em no final da lista.
 *  Tem custo de O(n^2)
 *
 * @param ponteiro do tipo lista
 */

void BubbleSortlista(lista *l)
{
    noh *aux,*aux2;
    int aux1;
    aux=l->primeiro;
    aux2=l->primeiro;
    while(aux->prox!=l->ultimo)
    {


        while (aux2->prox!=NULL)
        {
            if(aux2->item > aux2->prox->item && testeb++)
            {
                aux1=aux2->prox->item;
                aux2->prox->item=aux2->item;
                aux2->item=aux1;
                movib=movib+3;

            }
            aux2=aux2->prox;



        }
        aux=aux->prox;
        aux2=l->primeiro;


    }
testetotal=testeb;
    movitotal=movib;

}




/**	InsertionLista
 * @brief  Ordena a lista ,pelo metodo de inserção.
 * percorre a lista diversas vezes colocando o testando se o elemento da esquerda é maior que o atual
 caso seja ele troca de posição com o elemento da esquerda ate q essa condição seja falsa.
 *  Tem custo de O(n^2)
 *
 * @param ponteiro do tipo lista
 */


void InsertionLista(lista *l)
{
    noh *aux,*aux1,*aux2;
    int min=0;
    aux=l->primeiro;
    while(aux->prox->item!='#')
    {

        while(min>0 && aux->ant->item > aux->item && testei++)
        {
            aux2=aux->item;
            aux->item=aux->ant->item;
            aux->ant->item=aux2;
            min--;
            aux=aux->ant;
            movii=movii+3;

        }
        aux=aux->prox;
        min++;


    }
testetotal=testei;
    movitotal=movii;

}

/**	amplitude
 * @brief  Função auxiliar para o metodo Sheel ShellSort para listas.
 *   percorre a lista conforme a amplitude desejada na execução do metodo ShellSort
 *
 * @param ponteiro do tipo noh e um inteiro que significa a amplitude
 retorna um noh
 */

noh *amplitude(noh *aux,int h)
{

    for(int i=0; i<h; i++)
    {
        aux=aux->prox;
    }
    if(aux!=NULL)
        return aux;
    else
        return NULL;
}

/**	ShellLista
 * @brief  Ordena a lista ,pelo metodo ShellSort.
 * É uma melhoria muito eficiente para vetores do metodo InsertionSort
 *  Para listas ele nao é muito eficiente tendo o limite de 5000 elementos, apos isso se torna inviavel
 * @param ponteiro do tipo lista e um inteiro indicando o tamanho da lista
 */

ShellLista(lista *l, int MAX)
{
    int i,j,h = 1;
    noh *auxamplitude;
    noh *aux=l->primeiro;
    do
    {
        h = (h*3)+1;
    }
    while(h<=MAX);

    while(h>1)
    {
        h = h/3;

        for (i=h; i<MAX; i++)
        {
            auxamplitude=amplitude(aux,i);
            j = i-h;
            int valor=auxamplitude->item;

            while (j>=0 && valor < amplitude(aux,j)->item && testesh++ )
            {
                amplitude(aux,j+h)->item=amplitude(aux,j)->item;
                j = j-h;
                movish++;


                amplitude(aux,j+h)->item=valor;
            }



        }

    }
testetotal=testesh;
movitotal=movish;

}


/**	SelectionSortLista
 * @brief  Ordena a lista ,pelo metodo de seleção.
 * percorre a lista diversas vezes colocando o menor elemento na posição inicial depois
 faz isso para n-1 elementos da lista.
 *  Tem custo de O(n^2)
 *
 * @param ponteiro do tipo lista
 */

void SelectionSortLista(lista *l)
{


    noh *h = l->primeiro;
    noh *aux = h,*aux2,*min;


    while (aux->prox->item !='#')
    {

        min = aux;
        aux2=aux->prox;
        while (aux2->prox->item !='#' && testes++)
        {
            if(aux2->item<min->item)
                min=aux2;
            aux2=aux2->prox;
        }


        int valor;
        valor=min->item;
        min->item=aux->item;
        aux->item= valor;
        movis=movis+3;
        aux=aux->prox;
    }
    
 testetotal=testes;
    movitotal=movis;
}

/**	ZeraVariaveis
 * @brief  Zera as variaveis contadoras utilizadas nos metodos de ordenacao.
 */
void ZeraVariaveis()
{
    double testeb=0;
    double movib=0;
    double testei=0;
    double movii=0;
    double testes=0;
    double movis=0;
    double testesh=0;
    double movish=0;
}

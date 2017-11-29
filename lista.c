/*
* Tipo Abstrato de Dados de Lista
*
* Contém funções de manipulação (criação, inserção, remoção e liberação de memória), e também de impressão e cópia.
*
*/
#define FALSE 0
#define TRUE  1

#include <stdlib.h>
#include <stdio.h>
#include "lista.h"


void criaLista(LinkLista lista){
	lista->primeiro = NULL;
    lista -> len=0;
    lista->ultimo = lista->primeiro;
}


void inserePrimeiro(LinkVertice vertice, LinkLista lista){

	LinkCelula primeiro  = (LinkCelula) malloc(sizeof(Celula));
	primeiro->anterior = NULL;
	primeiro->prox= lista -> primeiro;

	if(lista->len == 0){
		lista ->ultimo = primeiro;
	}
	else{
		lista->primeiro->anterior = primeiro;
	}
	lista->primeiro = primeiro;
	lista->primeiro->vertice = vertice;
    lista -> len++;
}

void insereUltimo(LinkVertice pagina, LinkLista memoria){

	LinkCelula ultimo = (LinkCelula) malloc(sizeof(Celula));
	ultimo -> prox = NULL;
	ultimo -> anterior = memoria -> ultimo;

	if(memoria->len == 0){
		memoria->primeiro = ultimo;
	}
	else{
		memoria->ultimo->prox = ultimo;
	}
	memoria->ultimo = ultimo;
	memoria->ultimo->vertice = pagina;
	memoria -> len ++;

}
int estaNoTopo(LinkCelula moldura, LinkLista memoria){
	if(moldura->anterior == NULL)
		return TRUE;
	return FALSE;
}
int estaNoFundo(LinkCelula moldura, LinkLista memoria){
	if(moldura->prox == NULL)
		return TRUE;
	return FALSE;
}
void sobeNaPilha(LinkCelula vaiSubir, LinkLista memoria){
	if(!estaNoTopo(vaiSubir,memoria)){
		LinkCelula anterior, proximo;
		anterior = vaiSubir->anterior;
		proximo = vaiSubir ->prox;

		anterior->prox = proximo;
		if(!estaNoFundo(vaiSubir,memoria)){
			proximo ->anterior = anterior;
		}
		else{
			memoria ->ultimo = anterior;

		}
		vaiSubir ->anterior = NULL;
		vaiSubir -> prox = memoria->primeiro;

		memoria->primeiro->anterior = vaiSubir;
		memoria->primeiro = vaiSubir;
	}
}
void removePrimeiro(LinkLista memoria){

    // Se for o único elemento da lista
    if (memoria->len==0){
//    	liberaMemoria(memoria);
        return;
    }
    else{
        LinkCelula primeiro = memoria ->primeiro ;
        memoria -> primeiro = primeiro->prox;
        memoria -> primeiro ->anterior = NULL;
        memoria -> len--;
        free(primeiro);
    }
}
void removeUltimo(LinkLista memoria){
	if(memoria ->len == 0){

	}
	else{
		LinkCelula ultimo = memoria->ultimo;
		memoria ->ultimo = ultimo->anterior;
		memoria ->ultimo ->prox = NULL;
		memoria->len --;
		free (ultimo);
	}
}

void retira(LinkCelula moldura, LinkLista memoria){

	moldura->anterior->prox = moldura->prox;
	moldura->prox->anterior = moldura->anterior;
	memoria -> len --;
	free(moldura);
}

#ifndef _TADLISTA_H_
#define _TADLISTA_H_

//#define FIFO 0
//#define LFU 1
//#define LRU 2
/*
* Tipo Abstrato de Dados Memoria
*
* Contém funções de manipulação (criação, inserção, remoção e liberação de memória), e também de impressão e cópia.
*
*/

#include <stdlib.h>
#include <stdio.h>


typedef struct coord{
	double x;
	double y;

}Coordenadas;

typedef Coordenadas *LinkCoord;

typedef struct Celula *LinkCelula;

typedef struct {
  LinkCelula primeiro;
  LinkCelula ultimo;
  int len;
  int numCores;
}Lista;
typedef  Lista *LinkLista;

typedef struct vertice{
	Coordenadas coord;
	float raio;
	Lista arestas;
	int cor;

}Vertice;

typedef Vertice *LinkVertice;

typedef struct Celula {
	LinkVertice vertice;
	LinkCelula anterior;
	LinkCelula prox;


}Celula;


void criaLista(LinkLista lista);

int vazia(Lista lista);

void inserePrimeiro(LinkVertice pagina, LinkLista memoria);

void removePrimeiro(LinkLista lista);

void liberaMemoria(LinkLista lista);

void imprimeMemoria(Lista lista);

void imprimeReverso(Lista lista);

#endif

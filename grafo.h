#ifndef _TADGRAFO_H_ /* Prevenção contra múltiplas inclusões */
#define _TADGRAFO_H_

//
#include <stdlib.h>
#include "lista.h"

typedef struct grafo{
	//Array de ponteiros
	LinkVertice *vertices;
	int len;
	int inseridos;

}Grafo;

typedef Grafo *LinkGrafo;

void incializaGrafo(LinkGrafo grafo, int tam);
LinkVertice criaVertice(Coordenadas coord, float raio);
void insereVertice (LinkVertice vertice, LinkGrafo grafo,int pos);

void carregaGrafo(LinkGrafo grafo, FILE * p);
void imprimeVerticesGrafo(Grafo grafo);
void imprimeVetorVertices(LinkVertice *vertices, int tam);
void permute(LinkVertice *a, int i, int n,int *numCores, int debug);
void inserePosicaoCerta(LinkVertice vertice,LinkLista lista);

void maiorPrimeiro(LinkVertice *a,  int n,int *numCores);

#endif /* _TADARVORE_H_ */

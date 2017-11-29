#include<stdlib.h>
#include<stdio.h>
#include<math.h>

#define FALSE 0
#define TRUE  1

#include "grafo.h"


void incializaGrafo(LinkGrafo grafo,int tam){
	//Cria um vetor de ponteiros
	grafo -> vertices = (LinkVertice*) calloc (tam,sizeof(LinkVertice));
	grafo->len = tam;
	grafo->inseridos = 0;
}

float distancia(Coordenadas a, Coordenadas b){
	float difX,difY;
	difX = a.x - b.x;
	difY = a.y - b.y;
	difX = pow(difX,2);
	difY = pow(difY,2);


	return sqrt(difX + difY);
}
void carregaGrafo(LinkGrafo grafo, FILE * p){
	Coordenadas ptInsercao;
	LinkVertice linkVertice;
	int j;
	float raio,x,y;

	for( j= 0; j < grafo->len; j++){
			fscanf (p,"%f %f %f \n", &x,&y,&raio);
			ptInsercao.x = x;
			ptInsercao.y = y;
			linkVertice = criaVertice(ptInsercao,raio);
			insereVertice(linkVertice,grafo,j);
		}
}

int possuiInterferencia(LinkVertice a, LinkVertice b){
	float dist = distancia(a->coord,b->coord);
	float somaRaios = a->raio + b->raio;
	if(dist<=somaRaios)
		return TRUE;
	return FALSE;

}
void criaAresta(LinkVertice a, LinkVertice b){
	inserePrimeiro(a,&b->arestas);
	inserePrimeiro(b,&a->arestas);

}

//busca todas os vértices do grafo e insere quando necessário
void insereArestas(LinkVertice vertice,LinkGrafo grafo){
	int i;
	for(i=0; i<grafo->inseridos; i++){
		if(possuiInterferencia(grafo->vertices[i],vertice))
			criaAresta(vertice, grafo->vertices[i]);
	}
}
void insereVertice (LinkVertice vertice, LinkGrafo grafo, int pos){
	insereArestas(vertice, grafo);
	grafo->vertices[pos] = vertice;
	grafo->inseridos++;

}
void imprimeVertice(LinkVertice vertice){
	printf("[%.1f ,%.1f ];",vertice->coord.x,
			vertice->coord.y);
}
int verificaCorMinimaLivreVizinho(Lista vertices,int menor){
	int i;
	LinkCelula aux = vertices.primeiro;

	for(i=0;i < vertices.len; i++){
		if(menor == aux->vertice->cor ){
			menor = verificaCorMinimaLivreVizinho(vertices, menor+1);
			break;
		}
		else{
			aux = aux->prox;
		}
	}

	return menor;
}
void coloreVertice(LinkVertice vertice){
	vertice->cor = verificaCorMinimaLivreVizinho(vertice->arestas,1);
}



void imprimeVetorVertices(LinkVertice *vertices, int tam){
	int count;
	for(count=0;count<tam;count++){
			   imprimeVertice(vertices[count]);

	}
	printf("\n \n");
}
int coloreGrafo(LinkVertice *vertices, int tam){
	int count, numCores = 0;
	for(count=0;count<tam;count++){
		coloreVertice(vertices[count]);
		if(numCores < vertices[count]->cor )
			numCores = vertices[count]->cor;

	}
	return numCores;
}
void limpaGrafo(LinkVertice *vertices, int tam){
	int count;
	for(count=0;count<tam;count++)
		vertices[count]->cor = 0;
}
void imprimeVerticesGrafo(Grafo grafo){
	 imprimeVetorVertices(grafo.vertices, grafo.len);
}

LinkVertice criaVertice(Coordenadas coord, float raio){
	LinkVertice insert  = (LinkVertice) malloc(sizeof(Vertice));
	insert->coord = coord;
	insert ->raio = raio;
	criaLista(&insert->arestas);
	return insert;

}
/* Function to swap values at two pointers */
void swap (LinkVertice *x, LinkVertice *y)
{
    LinkVertice temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

/* Function to print permutations of string
   This function takes three parameters:
   1. String
   2. Starting index of the string
   3. Ending index of the vertices. */
void permute(LinkVertice *a, int i, int n, int *numCores,int debug){
   int j,valor;
   if (i == n){
	   valor = coloreGrafo(a,n+1);
	   if(debug){
	   	 imprimeVetorVertices(a,i+1);
	         printf("TERMINOU %d cores \n",valor);
  	   }
		
	   if (valor< *numCores)
		   *numCores = valor;
   }
   else {
	   limpaGrafo(a,n);
	   valor = coloreGrafo(a,i);
	   if(debug)
	   	 imprimeVetorVertices(a, i);
	   
	   if(valor <*numCores){
		   for (j = i; j <= n; j++){
			  swap((a+i), (a+j));
			  permute(a, i+1, n, numCores,debug);
			  swap((a+i), (a+j)); //backtrack
		   }
	   }
   }
}
int compare(int a, int b){
	if(a>b)
		return -1;
	return 1;

}
//Retorna número positivo caso a seja maior e negativo caso b seja maior

int compareGrau(LinkCelula a, LinkCelula b){
	int x = a->vertice->arestas.len;
	int y =  b->vertice->arestas.len;
	return compare(x,y);
}

void ordenaLista(LinkVertice *vetor,int tamanho){
	qsort(vetor,tamanho,sizeof(LinkVertice),compareGrau);
}
void maiorPrimeiro(LinkVertice *a,  int n,int *numCores){
	ordenaLista(a, n+1);
	*numCores = coloreGrafo(a,n+1);
}

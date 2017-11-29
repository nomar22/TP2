
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lista.h"
#include "grafo.h"
/*
 * tp2.c
 *
 *  Created on: 01/05/2013
 *      Author: rafaelramon
 */





int main(int argc, char** argv) {

	int numInstancias	;
	int count, numErbs;

	char *ArquivoInput = argv[1];  //Primeiro Parametro:Arquivo de Entrada.
	char *ArquivoOutput = argv[2]; //Segundo Parametro:Arquivo de Saída.
	int  debug = argv[3];
	Grafo grafo;
	
	

	FILE *fp;
	fp = fopen(ArquivoInput,"r"); //Abre arquivo para escrever
	FILE *arquivoSaida;
	arquivoSaida = fopen(ArquivoOutput,"w"); //Abre arquivo para escrever
	if(!fp){
		printf("Erro na leitura de entrada!");
		return 0;
	}


	fscanf (fp,"%d",&numInstancias);
	fscanf (fp,"%d",&numErbs);
	//Passa por todas as Instancias
	for(count=0;count<numInstancias;count++){
		incializaGrafo(&grafo, numErbs);
		carregaGrafo(&grafo,fp);
		int numCores = grafo.len;
		permute(grafo.vertices, 0, grafo.len-1,&numCores,debug);
		fprintf(arquivoSaida,"%d ",numCores);
	}


    return (0);
}

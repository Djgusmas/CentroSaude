#include<stdio.h>
#include<locale.h>
#include<stdlib.h>
#include <windows.h>

#include "structs.h"

void listarMedicos(NodoM *listaM){
	NodoM *aux;
	aux=listaM;
	while(aux!=NULL){
		printf("\nNome: %s", aux->pessoa.nome);
		printf("\nCodigo Medico: %d\n\n", aux->pessoa.codigo_medico);
		aux=aux->next;
	}
}

void inserirDadosMedicos(Medicos *mdc){
	
	printf("Nome do Médico:");
	fflush(stdin);
	gets(mdc->nome);
	printf("Código do médico:");
	scanf("%d", &mdc->codigo_medico);
}

void inserirNaListaDeMedicos(NodoM **listaM,Medicos dadosM){
	NodoM *novoNodoM=(NodoM*)malloc(sizeof(NodoM));
	novoNodoM->pessoa=dadosM;
	novoNodoM->next=*listaM;
	*listaM=novoNodoM;
}


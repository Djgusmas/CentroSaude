#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#include "structs.h"

void inserirDadosMedicos(Medicos *med, NodoM *listaM);
void inserirNaListaDeMedicos(NodoM **listaM, Medicos *dadosM);
void listarMedicos(NodoM *listaM);
int igualm(Medicos Med, Medicos Med2);
void editarMedicos(NodoM *listaM, Medicos valorProcurado);
void consultarMedicos(NodoM *listaM, Medicos valorProcurado);
int removerMedicos(NodoM **listaM, Medicos valorProcurado);
void guardarDadosM(NodoM *listaM);
void buscarDadosM(NodoM **listaM);

void inserirDadosMedicos(Medicos *med, NodoM *listaM){ //registar um novo medico 
	NodoM *aux;
    aux = listaM;
	printf("Código do médico:");
    scanf("%d", &med->codigo_medico);
    while (aux != NULL)
    {
        if (med->codigo_medico == aux->pessoam.codigo_medico)
        {
            printf("\n\n O código digitado já esta atribuido.\n");
            printf("Atribua outro código ao médico: ");
            scanf("%d", &med->codigo_medico);
            aux = listaM; // Reinicia a verificação do início da lista
        }
        else
        {
            aux = aux->next;
        }
    }
    printf("Nome do médico:");
    fflush(stdin);
    gets(med->nome);
}

void inserirNaListaDeMedicos(NodoM **listaM, Medicos *dadosM){ //insere o medico na lista total de medicos
    NodoM *novoNodoM=(NodoM*)malloc(sizeof(NodoM));
    novoNodoM->pessoam= *dadosM;
    novoNodoM->next=*listaM;
    *listaM=novoNodoM;
}

int igualm(Medicos Med, Medicos Med2) { //verifica se o médico exista
    return Med.codigo_medico == Med2.codigo_medico;
}

void editarMedicos(NodoM *listaM, Medicos valorProcurado){ //edita os dados do medico
    NodoM *aux;
    aux=listaM;
    int medicoEncontrado = 0;
    while(medicoEncontrado==0 && aux!=NULL ){
        if (igualm(aux->pessoam, valorProcurado)){
            medicoEncontrado++;

            printf("Introduza o novo nome:");
            fflush(stdin);
            scanf("%s",aux->pessoam.nome);
            
            printf("Introduza o novo código do médico:");
            scanf("%d", &aux->pessoam.codigo_medico);
        } else {
            aux = aux->next;
        }
    }
    if (!medicoEncontrado) {
        printf("\nMédico não encontrado\n\n");
    }
    system ("pause");
    system ("cls");
}


void listarMedicos(NodoM *listaM){ //apresenta a lista de todos os medicos
    if (listaM == NULL) {
        printf("Não há médicos na lista.\n");
        return;
    }

    NodoM *aux = listaM;
    while(aux != NULL){
        printf("\nCódigo Médico: %d\n", aux->pessoam.codigo_medico);
        printf("Nome: %s\n", aux->pessoam.nome);
        aux = aux->next;
    }
    system ("pause");
    system ("cls");
}


void consultarMedicos(NodoM *listaM, Medicos valorProcurado){ //consulta os dados do medico que pretendermos
    NodoM *aux;
    aux=listaM;
    int encontrou=0;
    while(encontrou==0 && aux!=NULL){
        if (igualm(aux->pessoam, valorProcurado))
        {
            printf("\nNome:%s\n",aux->pessoam.nome);
            printf("Código Médico:%d\n",aux->pessoam.codigo_medico);
            encontrou++;
			system("pause");
        }
        aux=aux->next;
    }

    if (encontrou == 0) {
    	system("pause");
        printf("Médico não encontrado.\n");
    }
}

int removerMedicos(NodoM **listaM, Medicos valorProcurado) { //remove o medico que pretendemos
    int encontrou = 0;
    NodoM *aux = *listaM;
    NodoM *ant = NULL;

    while (aux != NULL) {
        if (igualm(aux->pessoam, valorProcurado)) {
            encontrou = 1;
            break;
        }
        ant = aux;
        aux = aux->next;
    }

    if (encontrou) {
        if (ant == NULL) {
            *listaM = aux->next;
        } else {
            ant->next = aux->next;
        }
        free(aux);
        aux = NULL;
        return 1;
    } else {
        printf("Médico não encontrado.\n");
        return 0;
    }
}

void guardarDadosM(NodoM *listaM){ //guarda no ficheiro os dados de todos os médicos
	FILE *fp1; //criar o apontador para o ficheiro
	NodoM *aux;
	aux=listaM;
	fp1=fopen("dadosMedicos.txt","w"); //abrir o ficheiro de nome fp que vai guardar os dados em modo txt(texto)
	if(fp1==NULL){//certificar que o ficheiro abre e trabalha corretamente
		printf("erro");
	}
	else{
		while(aux!=NULL){
			fprintf(fp1,"%s,%d\n",aux->pessoam.nome,aux->pessoam.codigo_medico); //para escrever no ficheiro		
			aux=aux->next;
		}
		fclose(fp1);
	}	
}

void buscarDadosM(NodoM **listaM){ //vai buscar ao ficheiro os dados de todos os médicos
	FILE *fp1;
	Medicos dadosM;
	int n;
	fp1=fopen("dadosMedicos.txt","r");
	if(fp1==NULL){
		printf("erro");
	}
	else{
		while(!feof(fp1)){//enquanto não tiver chegado ao fim, ao end of file
			n=fscanf(fp1,"%[^,],%d",dadosM.nome,&dadosM.codigo_medico);//como é scanf e estamos a falar de strings metemos dessa maneira para ele saber que acaba quando ele chegar ao caracter (,)
			if(n==2){
				inserirNaListaDeMedicos(listaM, &dadosM);
			}
		}
		fclose(fp1);
	}
}

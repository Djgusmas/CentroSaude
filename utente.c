#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#include "structs.h"

void inserirDadosUtentes(Utentes *utn, NodoU *listaU,NodoM *listaM);
void inserirNaListaDeUtentes(NodoU **listaU,Utentes *dadosU);
void listarUtentes(NodoU *listaU);
int igual(Utentes Utn, Utentes Utn2);
void editarUtente(NodoU *listaU, NodoM *listaM, Utentes valorProcurado);
void consultarUtente(NodoU *listaU, Utentes valorProcurado);
int removerUtente(NodoU **listaU, Utentes valorProcurado);
void guardarDadosU(NodoU *listaU);
void buscarDadosU(NodoU **listaU);

void inserirDadosUtentes(Utentes *utn, NodoU *listaU, NodoM *listaM){ //registar um novo utente
	NodoU *aux;
	aux = listaU;
	int medicoEncontrado=0;
	NodoM *auxM;
	auxM=listaM;
    
    printf("Código do utente:");
    fflush(stdin);
    scanf("%d", &utn->codigo_utente);
	
	while (aux != NULL)
    {
        if (utn->codigo_utente == aux->pessoa.codigo_utente)
        {
            printf("\n\n O código digitado já está atribuido\n");
            printf(" Atribua outro código ao utente: ");
            scanf("%d", &utn->codigo_utente);
            aux = listaU; // Reinicia a verificação do início da lista
        }
        else
        {
            aux = aux->next;
        }
    }
    
    printf("Nome do utente:");
    fflush(stdin);
    fgets(utn->nome, tamNome, stdin);
    
    printf("Código do médico:");
    scanf("%d", &utn->codigo_medico);
    
    while (medicoEncontrado == 0) {
        auxM = listaM;
        while (auxM != NULL)
        {
            if (utn->codigo_medico == auxM->pessoam.codigo_medico)
            {
                printf("\n\n O código pertence ao médico: %s", auxM->pessoam.nome);
                printf("\n Esse é o médico atribuido ao utente\n");
                medicoEncontrado = 1;
                break; // sair do loop porque o médico foi encontrado
            }
            else
            {
                auxM = auxM->next;
            }
        }
        if (medicoEncontrado == 0) {
            printf("\n\n O código de médico que atribuíu não existe");
            printf("\n Digite outro código de médico: ");
            scanf("%d", &utn->codigo_medico);
        }
    }
}

// O programa não se encontra a verificar corretamente o código do médico


void inserirNaListaDeUtentes(NodoU **listaU,Utentes *dadosU){ //inserir na lista de total de utentes
    NodoU *novoNodoU=(NodoU*)malloc(sizeof(NodoU));
    novoNodoU->pessoa=*dadosU;
    novoNodoU->next=*listaU;
    *listaU=novoNodoU;
}

int igual(Utentes Utn, Utentes Utn2) { //função para verificação se o utente existe
    return Utn.codigo_utente == Utn2.codigo_utente;
}

void editarUtente(NodoU *listaU, NodoM *listaM, Utentes valorProcurado){ //editar dados dos utentes
    NodoU *aux;
    aux=listaU;
    int utenteEncontrado=0;
    int medicoEncontrado = 0;
    NodoM *auxM;

    while(utenteEncontrado==0 && aux!=NULL ){
        if (igual(aux->pessoa, valorProcurado)){
            utenteEncontrado++;

            printf("Introduza o novo nome:");
            fflush(stdin);
            scanf("%s",aux->pessoa.nome);
            
            printf("Introduza o novo código do médico:");
            scanf("%d", &aux->pessoa.codigo_medico);
            
            auxM = listaM;
            while (auxM != NULL)
	        {
	            if (aux->pessoa.codigo_medico == auxM->pessoam.codigo_medico)
	            {
	                printf("\n\n O código pertence ao médico: %s", auxM->pessoam.nome);
	                printf("\n Esse é o médico atribuido ao utente");
	                medicoEncontrado = 1;
	                break; // sair do loop porque o médico foi encontrado
	            }
	            else
	            {
	                auxM = auxM->next;
	            }
	        }
	        while (medicoEncontrado == 0) // mover para fora do primeiro loop
	        {
	            printf("\n\n O código de médico que atribuíu não existe");
	            printf("\n Digite outro código de médico: ");
	            scanf("%d", &aux->pessoa.codigo_medico);
	        
	            auxM = listaM; // reiniciar a verificação a partir do início da lista
	        
	            while (auxM != NULL)
	            {
	                if (aux->pessoa.codigo_medico == auxM->pessoam.codigo_medico)
	                {
	                    printf("\n\n O código pertence ao médico: %s", auxM->pessoam.nome);
	                    printf("\n Esse é o médico atribuido ao utente");
	                    medicoEncontrado = 1;
	                    break; // sair do loop porque o médico foi encontrado
	                }
	                else
	                {
	                    auxM = auxM->next;
	                }
	            }
	        }
        }
        aux=aux->next;
    }

    if (utenteEncontrado == 0) {
        printf("Utente não encontrado.\n");
    }
}



void listarUtentes(NodoU *listaU){ //apresenta a lista de todos os utentes
    NodoU *aux;
    aux=listaU;
    while(aux!=NULL){
        printf("\nCodigo Utente: %d", aux->pessoa.codigo_utente);
        printf("\nNome: %s", aux->pessoa.nome);
        printf("\nCodigo Medico: %d\n", aux->pessoa.codigo_medico);
        aux=aux->next;
    }
}

void consultarUtente(NodoU *listaU, Utentes valorProcurado){ //consulta o utente que pretendemos
    NodoU *aux;
    aux=listaU;
    int encontrou=0;
    while(encontrou==0 && aux!=NULL){
        if (igual(aux->pessoa, valorProcurado))
        {
            printf("\nNome:%s\n",aux->pessoa.nome);
            printf("Código Utente:%d\n",aux->pessoa.codigo_utente);
            printf("Código Médico:%d\n",aux->pessoa.codigo_medico);
            encontrou++;
            system("pause");
        }
        aux=aux->next;
    }

    if (encontrou == 0) {
        printf("Utente não encontrado.\n");
    }
}

int removerUtente(NodoU **listaU, Utentes valorProcurado){ //remove o utente que pretendemos
    NodoU *aux, *ant;
    int encontrou=0;
    aux=*listaU;
    ant=*listaU;
    while(!encontrou && aux!=NULL){
        if(igual(aux->pessoa, valorProcurado)) {
            encontrou=1;
        }
        else{
            ant=aux;
            aux=aux->next;
        }   
    }

    if(encontrou){
        if(ant==aux && aux==*listaU){
            *listaU=aux->next;
        }
        else{
            ant->next=aux->next;
        }
        free(aux);
        aux=NULL;
        return 1;    
    }
    else {
        printf("Utente não encontrado.\n");
        return 0;
    }
}

void guardarDadosU(NodoU *listaU){ //guarda no ficheiro os dados de todos os utentes
	FILE *fp; //criar o apontador para o ficheiro
	NodoU *aux;
	aux=listaU;
	fp=fopen("dadosUtentes.txt","w"); //abrir o ficheiro de nome fp que vai guardar os dados em modo txt(texto)
	if(fp==NULL){//certificar que o ficheiro abre e trabalha corretamente
		printf("erro");
	}
	else{
		while(aux!=NULL){
			fprintf(fp,"%d,%s,%d\n", aux->pessoa.codigo_utente,aux->pessoa.nome,aux->pessoa.codigo_medico); //para escrever no ficheiro		
			aux=aux->next;
		}
		fclose(fp);
	}	
}

void buscarDadosU(NodoU **listaU){ //vai buscar ao ficheiro os dados de todos os utentes
	FILE *fp;
	Utentes dadosU;
	int n;
	fp=fopen("dadosUtentes.txt","r");
	if(fp==NULL){
		printf("erro");
	}
	else{
		while(!feof(fp)){//enquanto não tiver chegado ao fim, ao end of file
			n=fscanf(fp,"%d,%[^,],%d",&dadosU.codigo_utente,dadosU.nome,&dadosU.codigo_medico);//como é scanf e estamos a falar de strings metemos dessa maneira para ele saber que acaba quando ele chegar ao caracter (,)
			if(n==3){
				inserirNaListaDeUtentes(listaU, &dadosU);
			}
		}
		fclose(fp);
	}
}

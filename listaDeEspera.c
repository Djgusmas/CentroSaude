#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>


#include "structs.h"

#define tamUtentes 100

FilaEspera *criarFila();
void registarUtente(FilaEspera **fila, Utentes *dadosU);
int pedirDados (Utentes *dadosU, int *num, NodoU *auxU);
int vazia(FilaEspera *fila);
Utentes* removerUtenteDaFila(FilaEspera **fila);
void listarListaDeEspera(FilaEspera *fila);
void retirarFE(FilaEspera *fila, NodoU *nodo);
int igual1(Utentes u1, Utentes u2);
void retirarutenteFE(FilaEspera *fila);
void listarFiladeMedico(FilaEspera **fila);
void apresentarNumUtentesMedico(FilaEspera **fila);
void mostrarMedicoFilaMaior(FilaEspera **fila);
void mostrarUtentesporMedico(NodoM **listaM, NodoU **listaU);
void guardarDadosFE(FilaEspera *fila);
void buscarDadosFE(FilaEspera **fila);

FilaEspera *criarFila(){ //criar fila de espera
	FilaEspera *aux=(FilaEspera*)malloc(sizeof(FilaEspera));
	aux->head=NULL;
	aux->tail=NULL;
	return aux;	
}

int pedirDados (Utentes *dadosU, int *num, NodoU *auxU) { //pede os dados do utente que queremos introduzir na lista de espera
	int num1;
	NodoU *aux;
	aux = auxU;
	printf ("Introduza o código do utente a introduzir na fila de espera: ");
	scanf ("%d", &num1);
	while (aux != NULL)	{
		if (num1 == aux->pessoa.codigo_utente) {		
			printf ("\n\n Nome: %s", aux->pessoa.nome);
			printf ("\n Código do utente: %d", aux->pessoa.codigo_utente);
			printf ("\n Código do médico: %d", aux->pessoa.codigo_medico);
			
			(*num)++;
			
			dadosU->numATD = *num;
			strcpy (dadosU->nome, aux->pessoa.nome);
			dadosU->codigo_utente = aux->pessoa.codigo_utente;
			dadosU->codigo_medico = aux->pessoa.codigo_medico; 
			
			printf ("\n\n Número de atendimento: %d", dadosU->numATD);
			
			printf ("\n\n");
			system ("pause");
			system ("cls");
			return -1;
			break;
		} 
		else
		{
			aux = aux->next;
		}
	}
	
	if (aux == NULL)
	{
    	printf ("\n\n Utente não existe");
    	printf ("\n\n");
		system ("pause");
		system ("cls");
    	return 0;
	}	
}

void registarUtente(FilaEspera **fila, Utentes *dadosU){ //introduz um novo utente na lista de espera
	NodoU *elemento=(NodoU*)malloc(sizeof(NodoU));
	elemento->pessoa=*dadosU;
	elemento->next=NULL;
	if((*fila)->head==NULL){
		(*fila)->head=elemento;
		(*fila)->tail=elemento;
	}
	else{
		((*fila)->tail)->next=elemento;
		(*fila)->tail=elemento;
	}
}

int vazia(FilaEspera *fila){ //verifica se a lista de espera nao esta vazia
	if(fila->head==NULL)
	   return 1;
	else
	   return 0;   
}
/*
Utentes* removerUtenteDaFila(FilaEspera **fila) { //remove um utente escolhido da fila de espera
    FilaEspera *lista = *fila;
	NodoU *aux = lista->head;   
    Utentes *utn = NULL;
    
    if (aux != NULL) {
        lista->head = aux->next;
        
        if(lista->head == NULL){ // Se a cabeça for NULL, então a cauda também deve ser NULL
            lista->tail = NULL;
        }
        
        utn = (Utentes*) malloc (sizeof(Utentes));
        *utn = aux->pessoa;
        free(aux);
    }
    
    return utn;
}
*/
void listarListaDeEspera(FilaEspera *fila) { //apresenta a lista de espera total
    NodoU *aux = fila->head;

    while (aux != NULL) {
        printf("Número de Atendimento: %d\n", aux->pessoa.numATD);
        printf("Nome: %s\n", aux->pessoa.nome);
        printf("Código Utente: %d\n", aux->pessoa.codigo_utente);
        printf("Código Médico: %d\n", aux->pessoa.codigo_medico);
        aux = aux->next;
    }
    system ("pause");
    system ("cls");
}

int igual1(Utentes u1, Utentes u2) { //verifica se o utente existe
    return u1.codigo_utente == u2.codigo_utente;
}

/*void retirarFE(FilaEspera *fila, NodoU *nodo) { 
    NodoU *ant = NULL;
    NodoU *aux = fila->head;
    while (aux != NULL && aux != nodo) {
        ant = aux;
        aux = aux->next;
    }
    if (aux == NULL) {
        printf("Utente não encontrado\n");
        return;
    }
    if (ant == NULL) {
        fila->head = aux->next;
    } else {
        ant->next = aux->next;
    }
    if (aux == fila->tail) {
        fila->tail = ant;
    }
    free(aux);
}
*/
void retirarutenteFE(FilaEspera *fila) { //retira utente da fila de espera
    int encontrado = 0;
    NodoU *aux = fila->head;
    NodoU *nodoParaRemover = NULL;
    Utentes valorProcurado;

    printf("Digite o código do utente que pretende remover da lista: ");
    fflush(stdin);
    scanf("%d", &valorProcurado.codigo_utente);

    while (aux != NULL) {
        if (igual1(aux->pessoa, valorProcurado)) {
            printf("\n\nDados do utente a remover: \n");
            printf("\nNome : %s", aux->pessoa.nome);
            printf("\nCódigo do utente : %d\n", aux->pessoa.codigo_utente);
            encontrado = 1;
            nodoParaRemover = aux;
            break;
        }
        aux = aux->next;
    }

    if (encontrado == 1) {
        retirarFE(fila, nodoParaRemover);
    } else {
        printf("\nUtente não encontrado \n");
    }
    printf ("\n");
    system ("pause");
    system ("cls");
}



void listarFiladeMedico(FilaEspera **fila) { //apresenta a lista de espera de um medico em especifico
    int encontrado = 0, codigo_med;
    printf("Digite o código do médico: ");
    scanf("%d", &codigo_med);
    NodoU *aux = (*fila)->head;
    while (aux != NULL) {
   	if (codigo_med == aux->pessoa.codigo_medico) {
   		printf ("\n\n Nome de utente: %s", aux->pessoa.nome);
   		printf ("\n Código de utente: %d", aux->pessoa.codigo_utente);
   		encontrado = 1;
	}
	aux = aux->next;
   	}
   	if (encontrado == 0) {
   	printf ("\n Não existe fila de espera");
   	}
    printf ("\n\n");
    system ("pause");
    system ("cls");
}

void apresentarNumUtentesMedico(FilaEspera **fila) { //apresenta quantos utentes um medico tem
	int codigo_med, i = 0, encontrado = 0;
	printf ("Digite o código do médico: ");
	scanf ("%d", &codigo_med);
	NodoU *aux = (*fila)->head;
	while (aux != NULL) {
	   	if (codigo_med == aux->pessoa.codigo_medico) {
	   		i++;
	   		encontrado = 1;
		}
		aux = aux->next;
    }
	if (encontrado == 0) {
   		printf ("\n Não existe fila de espera");
    } else {
   	printf ("\n O médico tem %d utentes", i);
    }
    printf ("\n\n");
    system ("pause");
    system ("cls");
}
void mostrarMedicoFilaMaior(FilaEspera **fila) { //apresenta o medico com mais utentes em fila de espera
    NodoU *aux = (*fila)->head;
    int maxUtn = 0, medMaxUtn = -1;
    
    while (aux != NULL) {
        NodoU *aux1 = (*fila)->head;
        int i = 0;
        
        while (aux1 != NULL) {
            if (aux1->pessoa.codigo_medico == aux->pessoa.codigo_medico) {
                i++;
            }
            aux1 = aux1->next;
        }
        
        if (i > maxUtn) {
            maxUtn = i;
            medMaxUtn = aux->pessoa.codigo_medico;
        }
        
        aux = aux->next;
    }
    
    if (medMaxUtn == -1) {
        printf("\nNão existem médicos com utentes em espera.\n");
    } else {
        printf("\nMédico com mais utentes em espera:\n\n");
        printf("Médico com o código %d\n-> com %d utentes\n", medMaxUtn, maxUtn);
    }
    
    printf("\n");
    system("pause");
    system("cls");
}

void mostrarUtentesporMedico(NodoM **listaM, NodoU **listaU) { //mostra os utentes ordenados pelos seus medicos
    NodoM *auxM = *listaM;
    printf(" Utentes por médico:\n\n\n");
    while (auxM != NULL) {
        NodoU *auxU = *listaU;
        printf(" Médico %s , Código %d\n\n", auxM->pessoam.nome, auxM->pessoam.codigo_medico);
                while (auxU != NULL) {
            if (auxU->pessoa.codigo_medico == auxM->pessoam.codigo_medico) {
                printf(" Nome do utente: %s\n", auxU->pessoa.nome);
                printf(" Código de utente: %d\n\n", auxU->pessoa.codigo_utente);
            }
            auxU = auxU->next;
        }
        auxM = auxM->next;
    }
    printf ("\n\n");
    system ("pause");
    system ("cls");
}

void guardarDadosFE(FilaEspera *fila){ //guarda os dados da fila de espera num ficheiro
	FILE *fp; //criar o apontador para o ficheiro
	NodoU *aux = fila->head;
	fp=fopen("filaEspera.txt","w"); //abrir o ficheiro de nome fp que vai guardar os dados em modo txt(texto)
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

void buscarDadosFE(FilaEspera **fila){ //vai buscar os dados do ficheiro que contem a lista de espera
	FILE *fp;
	Utentes dadosU;
	int n;
	fp=fopen("filaEspera.txt","r");
	if(fp==NULL){
		printf("erro");
	}
	else{
		while(!feof(fp)){//enquanto não tiver chegado ao fim, ao end of file
			n=fscanf(fp,"%[^;];%d;%d;%d;\n", dadosU.nome, &dadosU.codigo_utente, &dadosU.codigo_medico, &dadosU.numATD);//como é scanf e estamos a falar de strings metemos dessa maneira para ele saber que acaba quando ele chegar ao caracter (,)
			if(n==3){
				registarUtente(fila, &dadosU);
			}
		}
		fclose(fp);
	}
}

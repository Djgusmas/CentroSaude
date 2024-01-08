#include <stdio.h>
#include <locale.h>
#include <windows.h>

#include "structs.h"

void introducao()
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	setlocale(LC_ALL, "portuguese");
	SetConsoleTextAttribute(h, 6);
	printf("\n\n_______________________________________________________________________________________________________________________\n|\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t|");
	printf("\n|\t\t\t\tCENTRO DE SAÚDE DO CURSO DE ENGENHARIA E GESTÃO DE SISTEMAS DA INFORMAÇÃO\t\t\t\t|\n| ");
	printf("_____________________________________________________________________________________________________________________|\n\n");
	SetConsoleTextAttribute(h, 7);
	printf("\t\t\t    ________________| PRESSIONE ENTER PARA PROSSEGUIR |________________\n");
	SetConsoleTextAttribute(h, 6);
	printf("\n\n\n\n |INSTITUIÇÃO| ");
	SetConsoleTextAttribute(h, 7);
	printf("\n\n [Universidade do Minho]");
	SetConsoleTextAttribute(h, 6);
	printf("\n\n\n |AUTORES| ");
	SetConsoleTextAttribute(h, 7);
	printf("\n\n [Catarina Pinheiro] - [A104239]\n [David Gusmão] - [A102343]\n [Rodrigo Cunha] - [A103985]\n\n");
	int check = getchar();
	fflush(stdin);
}

void menuutente(NodoU **listaU, NodoM **listaM)
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE); //para usar cores diferentes
    setlocale(LC_ALL, "portuguese");
    int escolha=1;
    NodoU *auxU = *listaU;
    NodoM *auxM = *listaM;
    Utentes dadosU;
    buscarDadosU(&auxU);
    buscarDadosM(&auxM);
    while(escolha!=0)
    {
        system("cls");
        SetConsoleTextAttribute(h, 7);//muda a cor
        printf("\n\n_______________________________________________________________________________________________________________________\n|\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t|");
        printf("\n|\t\t\t\t                      MENU UTENTE                         \t\t\t\t|\n| ");
        printf("_____________________________________________________________________________________________________________________|\n\n");
        SetConsoleTextAttribute(h, 6);
        puts("\n\t\t\n1. Inserir utente:\n\n2. Editar utente:\n\n3. Consultar utente:\n\n4. Remover utente:\n\n5. Ver lista total de utentes:\n\n0. Menu inicial");
        SetConsoleTextAttribute(h, 7);
        printf("\n\nResposta: ");
        scanf("%d", &escolha);
        switch(escolha){
            case 1: system("cls");
                    inserirDadosUtentes(&dadosU, auxU, auxM);
                    inserirNaListaDeUtentes(&auxU, &dadosU);
                    SetConsoleTextAttribute(h, 6);
					printf("\t\t\t    ________________| PRESSIONE ENTER PARA PROSSEGUIR |________________\n");
                    break;
            case 2: system("cls");
					printf("Introduza o código de utente a editar:");
                    fflush(stdin);
                    scanf("%d", &dadosU.codigo_utente);
                    editarUtente(auxU, auxM, dadosU);
                    SetConsoleTextAttribute(h, 6);
					printf("\t\t\t    ________________| PRESSIONE ENTER PARA PROSSEGUIR |________________\n");
                    break;
            case 3: system("cls");
					printf("Introduza o código de utente a consultar:");
                    fflush(stdin);
                    scanf("%d", &dadosU.codigo_utente);
                    consultarUtente(auxU, dadosU);
                    SetConsoleTextAttribute(h, 6);
					printf("\t\t\t    ________________| PRESSIONE ENTER PARA PROSSEGUIR |________________\n");
                    break;
            case 4: system("cls");
			   	    printf("Introduza o código de utente a remover:");
                    fflush(stdin);
                    scanf("%d", &dadosU.codigo_utente);
                    removerUtente(&auxU, dadosU);
                    SetConsoleTextAttribute(h, 6);
					printf("\t\t\t    ________________| PRESSIONE ENTER PARA PROSSEGUIR |________________\n");
                    break;
            case 5:system("cls");
			       listarUtentes(auxU);
			       system("pause");
				   break;       
            case 0:guardarDadosU(auxU);
                return;
            default:
                puts("Opcao invalida!");
        }
    fflush(stdin);
    getchar();
    }
}


void menumedico(NodoM **listaM)
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    setlocale(LC_ALL, "portuguese");
    int escolha = 1;
    NodoM *auxM = *listaM;
    Medicos dadosM;
    buscarDadosM(&auxM);
    while (escolha != 0)
    {
        system("cls");
        SetConsoleTextAttribute(h, 7);
        printf("\n\n_______________________________________________________________________________________________________________________\n|\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t|");
        printf("\n|\t\t\t\t                      MENU MÉDICO                         \t\t\t\t|\n| ");
        printf("_____________________________________________________________________________________________________________________|\n\n");
        SetConsoleTextAttribute(h, 6);
        puts("\n\t\t\n1. Inserir médico:\n\n2. Editar médico:\n\n3. Consultar médico:\n\n4. Remover médico:\n\n5. Listar médicos:\n\n0. Menu inicial");
        SetConsoleTextAttribute(h, 7);
        printf("\n\nResposta: ");
        scanf("%d", &escolha);
        switch (escolha){
        	case 1: system("cls");
	            	inserirDadosMedicos(&dadosM, auxM);
	            	inserirNaListaDeMedicos(&auxM, &dadosM);
	            	SetConsoleTextAttribute(h, 6);
					printf("\t\t\t    ________________| PRESSIONE ENTER PARA PROSSEGUIR |________________\n");
	            	break;
        	case 2: system("cls");
	            	printf("Introduza o código do médico a editar:");
	            	fflush(stdin);
	            	scanf("%d", &dadosM.codigo_medico);
	            	getchar();
	            	editarMedicos(auxM, dadosM);
	            	SetConsoleTextAttribute(h, 6);
					printf("\t\t\t    ________________| PRESSIONE ENTER PARA PROSSEGUIR |________________\n");
	            	break;
        	case 3: system("cls");
	            	printf("Introduza o código do médico a consultar:");
	            	fflush(stdin);
	            	scanf("%d", &dadosM.codigo_medico);
	            	getchar();
	            	consultarMedicos(auxM, dadosM);
	            	SetConsoleTextAttribute(h, 6);
					printf("\t\t\t    ________________| PRESSIONE ENTER PARA PROSSEGUIR |________________\n");
	            	break;
        	case 4: system("cls");
	           		printf("Introduza o código do médico a remover:");
	            	fflush(stdin);
	            	scanf("%d", &dadosM.codigo_medico);
	            	getchar();
	            	removerMedicos(&auxM, dadosM);
	            	SetConsoleTextAttribute(h, 6);
					printf("\t\t\t    ________________| PRESSIONE ENTER PARA PROSSEGUIR |________________\n");
	            	break;
	        case 5: system("cls");
	           		listarMedicos(auxM);
	            	SetConsoleTextAttribute(h, 6);
					printf("\t\t\t    ________________| PRESSIONE ENTER PARA PROSSEGUIR |________________\n");
	            	break;
        	case 0: guardarDadosM(auxM);
            	return;
        	default:
            	puts("Opcao invalida!");
        }
        fflush(stdin);
    }
}

void menuRegisto(FilaEspera **fila, NodoU **listaU, NodoM **listaM)
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    setlocale(LC_ALL, "portuguese");
    int escolha = 1, next1 = 0;
    NodoU *auxU = *listaU;
    NodoM *auxM = *listaM;
    Utentes dadosU;
    Utentes *nextU;
    FilaEspera *auxFE = *fila;
    buscarDadosU(&auxU);
    buscarDadosM(&auxM);
    buscarDadosFE (&auxFE);
    while (escolha != 0)
    {
        system("cls");
        SetConsoleTextAttribute(h, 7);
        printf("\n\n_______________________________________________________________________________________________________________________\n|\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t|");
        printf("\n|\t\t\t\t                      MENU REGISTO                         \t\t\t\t|\n| ");
        printf("_____________________________________________________________________________________________________________________|\n\n");
        SetConsoleTextAttribute(h, 6);
        puts("\n\t\t\n1. Registar Utente:\n\n2. Indicar Próximo Utente:\n\n3. Exibir Lista de Espera:\n\n0. Menu inicial");
        SetConsoleTextAttribute(h, 7);
        printf("\n\nResposta: ");
        scanf("%d", &escolha);
        switch (escolha){
        	case 1: system("cls");
					if (pedirDados(&dadosU, &next1, auxU) == -1)
					{
						registarUtente (&auxFE, &dadosU); 
						break;	
					} else 
					break;
        	case 2: system("cls");
					if (!vazia(auxFE))
					{
						retirarutenteFE(auxFE);
						system ("cls");
						printf ("Proximo utente: \n\n");
						
						printf (" Numero de atendimento: %d \n", nextU->numATD);
						printf (" Código de utente: %d \n", nextU->codigo_utente); 
						printf (" Código de médico: %d \n", nextU->codigo_medico);
						printf ("\n Nome do utente: %s \n", nextU->nome);
						
						printf ("\n");
						system ("pause");
						system ("cls");
					}
					else
					{
					  printf ("Fila de Espera vazia"); 
					  printf ("\n\n");
					  system ("pause"); 
					  system ("cls"); 
					  break;
					}
        	case 3: system("cls");
					listarListaDeEspera(auxFE);
	            	break;
        	case 0: guardarDadosFE (auxFE);
            	return;
        	default:
            	puts("Opcao invalida!");
        }
        fflush(stdin);
    }
}

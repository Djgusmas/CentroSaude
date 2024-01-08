#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <conio.h>


#include "master.h"
#include "structs.h"

#define tamUtentes 100

int main(){
    introducao();
    
   	NodoU *listaM = NULL;
    NodoM *listaU = NULL;
    FilaEspera* fila = NULL;
    fila=criarFila();
    buscarDadosFE (&fila);
    int escolha=1,escolha1,proximo=0;
    setlocale (LC_ALL, "Portuguese");
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	setlocale(LC_ALL, "portuguese");
	while(escolha!=0)
	{
		system("cls");
		SetConsoleTextAttribute(h, 6);
		printf("\n\n_______________________________________________________________________________________________________________________\n|\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t|");
		printf("\n|\t\t\t\t                      MENU INICIAL                         \t\t\t\t|\n| ");
		printf("_____________________________________________________________________________________________________________________|\n\n");
		SetConsoleTextAttribute(h, 7);
		puts("\t\t\n\n1. Menu utente:\n\n2. Menu médico:\n\n3. Menu fila de espera:\n\n4. Ver lista de espera de médico:\n\n5. Mostrar número de utentes em espera por médico:\n\n6. Apresentar médico com maior lista:\n\n7. Mostrar todos os utentes por médico:\n\n0. Sair");
		SetConsoleTextAttribute(h, 6);
		printf("\n\nResposta: ");
		scanf("%d", &escolha);
		switch(escolha){
			case 1:system("cls");
				   menuutente(&listaU, &listaM);
				   break;
			case 2:system("cls");
			       menumedico(&listaM);
				   break;
			case 3:
			       menuRegisto(&fila, &listaU, &listaM);
				   break;				   
			case 4:system("cls");
			       listarFiladeMedico(&fila);
			       system("pause");
				   break;
			case 5:system("cls");
			       apresentarNumUtentesMedico(&fila);
				   system("pause");
				   break;
			case 6:system("cls");
			       mostrarMedicoFilaMaior(&fila);
				   system("pause");
				   break;
			case 7:system("cls");
			       mostrarUtentesporMedico(&listaU, &listaM);
				   system("pause");
				   break;
			case 0:
				break;
			default:
				puts("Opcao invalida!");
		}
	}
    return 0;
}

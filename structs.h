#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

// Definição de constantes
#define tamNome 50

typedef struct medico {
    int codigo_medico;
    char nome[tamNome];
} Medicos;

typedef struct nodom {
    Medicos pessoam;
    struct nodom *next;
} NodoM;

typedef struct utente {
    int codigo_utente;
    char nome[tamNome];
    int codigo_medico;
    int numATD;
} Utentes;

typedef struct nodo {
    Utentes pessoa;
    struct nodo *next;
} NodoU;

typedef struct queue{
	NodoU *head;
	NodoU *tail;
	struct nodo *utente;
	struct nodom *medico;
}FilaEspera;

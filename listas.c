#include "contactos.h"
#include "todos.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "listas.h"
#include "tabelas.h"
#define DIMTABELA 1021

/* inicializa uma lista de contactos */
Lista *init_lista()
{
    Lista *nova_lista = malloc(sizeof(Lista));
    nova_lista->primeiro = NULL;
    nova_lista->ultimo = NULL;
    return nova_lista;
}

/* introduz o contacto em ultimo lugar na lista */
Lista * introduz_lista(Lista *lista, Contacto *novo)
{
    if (lista->primeiro == NULL){
        lista->primeiro = novo;
        novo->anterior = NULL;
    }
    else
    {
        lista->ultimo->proximo = novo;
        novo->anterior = lista->ultimo;
    }
    novo->proximo = NULL;
    lista->ultimo = novo;
    return lista;    
}

/* imprime todos os contactos pela ordem em que foram inseridos */
void lista_contactos(Lista *lista)
{
    Contacto *aux;
    aux = lista->primeiro;
    while(aux != NULL){
        print_contacto(aux);
        aux = aux->proximo;
    }
    free(aux);
}

/* liberta o espaco de memoria associado a uma lista de contactos */
void liberta_lista(Lista *lista)
{
    Contacto *aux;
    while (lista->primeiro != NULL)
    {
        aux = lista->primeiro;
        lista->primeiro = aux->proximo;
        liberta_contacto(aux);
    }
    free(lista);
}

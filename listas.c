/*
 *  Antonio Elias
 *  93690
 *  listas.h
 */
#include "contactos.h"
#include <stdlib.h>
#include "listas.h"

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
    while(aux != NULL)
    {
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

/* apaga da lista um contacto */
void apaga_da_lista(Lista *lista, Contacto *contacto)
{
    if (contacto->anterior != NULL)
        contacto->anterior->proximo = contacto->proximo;
    else
        lista->primeiro = contacto->proximo;
    if (contacto->proximo != NULL)
        contacto->proximo->anterior = contacto->anterior;
    else
        lista->ultimo = contacto->anterior;
}
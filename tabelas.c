#include "contactos.h"
#include "todos.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "listas.h"
#include "tabelas.h"
#define DIMTABELA 1021

int hash(char *v, int M)
{
    int h = 0, a = 127;
    for (; *v != '\0'; v++)
        h = (a*h + *v) % M;
    return h;
}

/* inicializa uma tabela generica */
Link *init_tabela() {
    int i;
    Link *tabela;
    tabela = malloc( DIMTABELA * sizeof(Link));
    for (i = 0; i < DIMTABELA; i++) 
        tabela[i] = NULL;
    return tabela;
}

/* introduz o novo contacto na tabela_nomes */

void introduz_tab_nomes(Link * tabela_nomes, Contacto *novo_contacto)
{
    int id;
    Link novo_link = malloc(sizeof(struct no));
    id = hash(novo_contacto->nome, DIMTABELA);
    novo_link->contacto = novo_contacto;
    novo_link->proximo = tabela_nomes[id];
    tabela_nomes[id] = novo_link;
}



/* encontra o contacto a partir do seu nome, retornando o pointer para ele ou NULL caso nao encontre */

Contacto * encontra_contacto(Link *tabela_nomes, char nome[])
{
    int id;
    Link aux;
    id = hash(nome, DIMTABELA);
    aux = tabela_nomes[id];
    while (aux != NULL)
    {
        if (strcmp(nome, aux->contacto->nome) == 0)
            return aux->contacto;
        aux = aux->proximo;
    }
    return NULL;
}

/* liberta todos os links de uma tabela */
void liberta_tabela(Link *tabela)
{
    int i;
    Link *aux;
    aux = tabela;

    for (i = 0; i < DIMTABELA; i++)
        if (aux[i] != NULL)
            liberta_link(aux[i]);    
    free(aux);
}

/* liberta um link e o seu proximo */
void liberta_link(Link no)
{
    
    if (no->proximo != NULL)
        liberta_link(no->proximo);
    free(no);
}
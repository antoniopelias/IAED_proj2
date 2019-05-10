#include "contactos.h"
#include "tabelas.h"
#include <string.h>
#include <stdlib.h>
#define DIMTABELA 1021
#define TABN 'n'
#define TABD 'd'

/* faz a hash de uma string ate ao tamanho M */
int hash(char *v, int M)
{
    int h = 0, a = 127;
    for (; *v != '\0'; v++)
        h = (a*h + *v) % M;
    return h;
}

/* inicializa uma tabela generica */
Link *init_tabela() 
{
    int i;
    Link *tabela;
    tabela = malloc( DIMTABELA * sizeof(Link) );
    for (i = 0; i < DIMTABELA; i++) 
        tabela[i] = NULL;
    return tabela;
}

/* introduz o novo contacto na tabela_nomes */
void introduz_tabela(char tipo, Link *tabela, Contacto *novo_contacto)
{
    int id;
    Link novo_link = malloc(sizeof(struct no));
    if (tipo == TABN)
        id = hash(novo_contacto->nome, DIMTABELA);
    else
        id = hash(novo_contacto->email->dominio, DIMTABELA);
    novo_link->contacto = novo_contacto;
    novo_link->proximo = tabela[id];
    tabela[id] = novo_link;
}

/* encontra o contacto a partir do seu nome, retornando o pointer para ele ou NULL caso nao encontre */
Contacto *encontra(Link *tabela_nomes, char nome[])
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

/* retira um contacto de uma tabela */
void apaga_da_tabela(char tipo, Link *tabela, Contacto *contacto)
{
    int id;
    Link aux, aux2;
    if (tipo == TABN)
        id = hash(contacto->nome, DIMTABELA);
    else
        id = hash(contacto->email->dominio, DIMTABELA);
    
    aux = tabela[id];
    if (tabela[id]->proximo == NULL || strcmp(contacto->nome, aux->contacto->nome) == 0)
    {
        tabela[id] = tabela[id]->proximo;
        free(aux);
    } else
    {
        while (aux->proximo != NULL)
        {
            if (strcmp(contacto->nome, aux->proximo->contacto->nome) == 0)
            {
                aux2 = aux->proximo;
                aux->proximo = aux2->proximo;
                free(aux2);
                break;
            }
            aux = aux->proximo;
        } 
    }
}

/* retorna o numero de ocorrencias de um dado dominio */
int num_ocorencias(Link *tabela, char dominio[])
{
    int id, n = 0;
    Link aux;
    id = hash(dominio, DIMTABELA);
    aux = tabela[id];
    while (aux != NULL)
    {
        if ( strcmp(dominio, aux->contacto->email->dominio) == 0 )
            n++;
        aux = aux->proximo;
    }
    return n;
}
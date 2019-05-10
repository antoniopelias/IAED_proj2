#include "contactos.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "listas.h"
#include "tabelas.h"
#include "todos.h"
#define TABN 'n'
#define TABD 'd'

/* Inicializa a estrutura que liga as outras estruturas */
Todos * init_todos()
{
    Todos *novo = malloc(sizeof(Todos));
    novo->lista = init_lista();
    novo->tabela_nomes = init_tabela();
    novo->tabela_dominios = init_tabela();
    return novo;
}

/* liberta toda a memoria dos contactos */
void liberta_tudo(Todos *todos)
{
    liberta_lista(todos->lista);
    liberta_tabela(todos->tabela_nomes);
    liberta_tabela(todos->tabela_dominios);
    free(todos);
}

void apaga_contacto(Todos *todos, Contacto *contacto)
{
    apaga_da_lista(todos->lista, contacto);
    apaga_da_tabela(TABN, todos->tabela_nomes, contacto);
    apaga_da_tabela(TABD, todos->tabela_dominios, contacto);
    liberta_contacto(contacto);
}
#include "contactos.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "listas.h"
#include "tabelas.h"
#include "todos.h"

/* Inicializa a estrutura que liga as outras estruturas */
Todos * init_todos()
{
    Todos *novo = malloc(sizeof(Todos));
    novo->lista = init_lista();
    novo->tabela_nomes = init_tabela();
    return novo;
}

/* liberta toda a memoria dos contactos */
void liberta_tudo(Todos *todos)
{
    liberta_lista(todos->lista);
    liberta_tabela(todos->tabela_nomes);
    free(todos);
}

void apaga_contacto(Todos *todos, Contacto *contacto)
{
    apaga_da_lista(todos->lista, contacto);
    apaga_da_tabela(todos->tabela_nomes, contacto);
    liberta_contacto(contacto);
}
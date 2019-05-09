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
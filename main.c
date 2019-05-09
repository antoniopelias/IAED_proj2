#include "contactos.h"
#include "todos.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "listas.h"
#include "tabelas.h"
#define DIMTABELA 1021

#define TRUE 1
#define FALSE 0
#define NOME 1024
#define EMAIL 512
#define TELEFONE 64

void adiciona_contacto(Todos *todos);
void lista(Todos *todos);
void procura_contacto(Todos *todos);

int main()
{
    int comando;
    Todos *todos;
    todos = init_todos();
    comando = getchar();
    while(comando != EOF && comando != 'x') {
        switch (comando)
        {
            case 'a':
                adiciona_contacto(todos);
                break;
            case 'l':
                lista(todos);
                break;
            case 'p':
                procura_contacto(todos);
                break;
            /*case 'r':
                scanf("%s", nome);
                remove_contacto(lista, nome);
                break;
            case 'e':
                scanf("%s %s", nome, email);
                altera_email(lista, nome, email);
                break;
            case 'c':
                scanf("%s", email);
                conta_dominio(lista, email);
                break; */
        }
        comando = getchar();
    }
    liberta_lista(todos->lista);
    liberta_tabela(todos->tabela_nomes);
    free(todos);
    return 0;
}

/* cria um contacto usando o nome, email e telefone que recebe como input, e introduz-lo no sistema */
void adiciona_contacto(Todos *todos)
{
    char nome[NOME], email[EMAIL], telefone[TELEFONE];
    Contacto *novo_contacto;
    scanf("%s %s %s", nome, email, telefone);
    if (encontra_contacto(todos->tabela_nomes, nome) != NULL)
        printf("Nome existente.\n");
    else
    {
        novo_contacto = cria_contacto(nome, email, telefone);
        introduz_lista(todos->lista, novo_contacto);
        introduz_tab_nomes(todos->tabela_nomes, novo_contacto);
    }
}

void lista(Todos *todos)
{
    getchar();
    lista_contactos(todos->lista);
}

/* procura um contacto e imprime-o */
void procura_contacto(Todos *todos)
{
    char nome[NOME];
    Contacto *contacto;
    scanf("%s", nome);
    contacto = encontra_contacto(todos->tabela_nomes, nome);
    if (contacto != NULL)
        print_contacto(contacto);
    else
        printf("Nome inexistente.\n");   
}
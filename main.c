#include "contactos.h"
#include "todos.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "listas.h"
#include "tabelas.h"
#define DIMTABELA 1021

#define NOME 1024
#define EMAIL 512
#define TELEFONE 64
#define TABN 'n'
#define TABD 'd'

void adiciona_contacto(Todos *todos);
void lista(Todos *todos);
void procura_contacto(Todos *todos);
void remove_contacto(Todos *todos);
void altera_email(Todos *todos);
void conta_dominio(Todos *todos);

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
            case 'r':
                remove_contacto(todos);
                break;
            case 'e':
                altera_email(todos);
                break;
            case 'c':
                conta_dominio(todos);
                break;
        }
        comando = getchar();
    }
    liberta_tudo(todos);
    return 0;
}

/* cria um contacto usando o nome, email e telefone que recebe como input, e introduz-lo no sistema */
void adiciona_contacto(Todos *todos)
{
    char nome[NOME], email[EMAIL], telefone[TELEFONE];
    Contacto *novo_contacto;
    scanf("%s %s %s", nome, email, telefone);
    if (encontra(todos->tabela_nomes, nome) != NULL)
        printf("Nome existente.\n");
    else
    {
        novo_contacto = cria_contacto(nome, email, telefone);
        introduz_lista(todos->lista, novo_contacto);
        introduz_tabela(TABN, todos->tabela_nomes, novo_contacto);
        introduz_tabela(TABD, todos->tabela_dominios, novo_contacto);
    }
}

/* lista todos os contactos pela ordem em que foram inseridos */
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
    contacto = encontra(todos->tabela_nomes, nome);
    if (contacto != NULL)
        print_contacto(contacto);
    else
        printf("Nome inexistente.\n");    
}

/* remove um contacto */
void remove_contacto(Todos *todos)
{
    char nome[NOME];
    Contacto *velho_contacto;
    scanf("%s", nome);
    velho_contacto = encontra(todos->tabela_nomes, nome);
    if (velho_contacto != NULL)
        apaga_contacto(todos, velho_contacto);
    else 
        printf("Nome inexistente.\n");
}

/* altera o email de um contacto */
void altera_email(Todos *todos)
{
    char nome[NOME], email[EMAIL];
    Contacto *contacto;
    scanf("%s %s", nome, email);
    contacto = encontra(todos->tabela_nomes, nome);
    if (contacto != NULL)
    {
        apaga_da_tabela(TABD, todos->tabela_dominios, contacto);
        liberta_email(contacto->email);
        contacto->email = cria_email(email);
        introduz_tabela(TABD, todos->tabela_dominios, contacto);
    } else 
        printf("Nome inexistente.\n");
}

/* conta o numero de ocorrencias de um dominio */
void conta_dominio(Todos *todos)
{
    char dominio[EMAIL];
    int n;
    scanf("%s", dominio);
    n = num_ocorencias(todos->tabela_dominios, dominio);
    printf("%s:%d\n", dominio, n);
}
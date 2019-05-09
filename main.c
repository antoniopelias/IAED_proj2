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

void adiciona_contacto(Todos *todos, char nome_input[NOME], char email_input[EMAIL], char telefone_input[TELEFONE]);
void procura_contacto(Todos *todos, char nome[NOME]);

int main()
{
    int comando;
    char nome[NOME], email[EMAIL], telefone[TELEFONE];
    Todos *todos;
    todos = init_todos();
    comando = getchar();
    while(comando != EOF && comando != 'x') {
        switch (comando)
        {
            case 'a':
                scanf("%s %s %s", nome, email, telefone);
                adiciona_contacto(todos, nome, email, telefone);
                break;
            case 'l':
                getchar();
                lista_contactos(todos->lista);
                break;
            case 'p':
                scanf("%s", nome);
                procura_contacto(todos, nome);
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
void adiciona_contacto(Todos *todos, char nome_input[NOME], char email_input[EMAIL], char telefone_input[TELEFONE])
{
    Contacto *novo_contacto;
    Email *novo_email;
    char s[2] = "@";
    char *token;
    if (encontra_contacto(todos->tabela_nomes, nome_input) != NULL)
    {
        printf("Nome existente.\n");
        return;
    }
    novo_contacto = malloc(sizeof(Contacto));
    novo_email = malloc(sizeof(Email));
    novo_contacto->nome = malloc( ( strlen(nome_input) + 1 ) * sizeof(char) );
    novo_contacto->telefone = malloc( ( strlen(telefone_input) + 1 ) * sizeof(char) );
    strtok(email_input, s);
    token = strtok(NULL, s);
    novo_email->local = malloc( ( strlen(email_input) + 1 ) * sizeof(char) );
    novo_email->dominio = malloc( ( strlen(token) + 1 ) * sizeof(char) );
    strcpy(novo_contacto->nome, nome_input);
    strcpy(novo_contacto->telefone, telefone_input);
    strcpy(novo_email->local, email_input);
    strcpy(novo_email->dominio, token);
    novo_contacto->email = novo_email;
    encontra_contacto(todos->tabela_nomes, nome_input);
    introduz_lista(todos->lista, novo_contacto);
    introduz_tab_nomes(todos->tabela_nomes, novo_contacto);
}

/* procura um contacto e imprime-o */
void procura_contacto(Todos *todos, char nome[NOME])
{
    Contacto *contacto;
    contacto = encontra_contacto(todos->tabela_nomes, nome);
    if (contacto != NULL)
        print_contacto(contacto);
    else
        printf("Nome inexistente.\n");   
}
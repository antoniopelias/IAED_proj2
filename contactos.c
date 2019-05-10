#include "contactos.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define EMAIL 512

/* imprime o nome email e telefone do contacto no formato especificado */
void print_contacto(Contacto *contacto)
{
    printf("%s %s@%s %s\n", 
            contacto->nome, 
            contacto->email->local,
            contacto->email->dominio,
            contacto->telefone);
}

/* liberta o espaco de memoria associado a um contacto */
void liberta_contacto(Contacto *contacto)
{
    if (contacto != NULL)
    {
        liberta_email(contacto->email);
        free(contacto->telefone);
        free(contacto->nome);
    }
    free(contacto);    
}

/* liberta o espaco de memoria associado a um email */
void liberta_email(Email *email)
{
    if (email != NULL)
    {
        free(email->local);
        free(email->dominio);
    }    
    free(email);    
}

/* cria um contacto com o nome, email e telefone dados */
Contacto *cria_contacto(char nome[], char email[], char telefone[])
{
    Contacto *novo_contacto;
    novo_contacto = malloc(sizeof(Contacto));
    novo_contacto->nome = malloc( ( strlen(nome) + 1 ) * sizeof(char) );
    novo_contacto->telefone = malloc( ( strlen(telefone) + 1 ) * sizeof(char) );
    strcpy(novo_contacto->nome, nome);
    strcpy(novo_contacto->telefone, telefone);
    novo_contacto->email = cria_email(email);
    return novo_contacto;
}

/* cria um email com a string dada */
Email *cria_email(char email[])
{
    Email *novo_email;
    char s[2] = "@";
    char *token, local[EMAIL], dominio[EMAIL];
    novo_email = malloc(sizeof(Email));
    token = strtok(email, s);
    strcpy(local, token);
    token = strtok(NULL, s);
    strcpy(dominio, token);
    novo_email->local = malloc( ( strlen(local) + 1 ) * sizeof(char) );
    novo_email->dominio = malloc( ( strlen(dominio) + 1 ) * sizeof(char) );
    strcpy(novo_email->local, local);
    strcpy(novo_email->dominio, dominio);
    return novo_email;
}
#include "contactos.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "listas.h"
#include "tabelas.h"
#include "todos.h"
#define DIMTABELA 1021

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
        if (contacto->email != NULL)
        {
            free(contacto->email->local);
            free(contacto->email->dominio);
        }    
        free(contacto->telefone);
        free(contacto->nome);
        free(contacto->email);
    }
    free(contacto);    
}
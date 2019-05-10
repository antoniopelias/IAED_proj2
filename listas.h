/*
 *  Antonio Elias
 *  93690
 *  listas.h
 */

/* aponta para o primeiro contacto adicionado e para o adicionado mais recentemente */
typedef struct lista
{
    struct contacto *primeiro, *ultimo;
} Lista;

Lista *init_lista();
Lista *introduz_lista(Lista *lista, Contacto *novo);
void lista_contactos(Lista *lista);
void liberta_lista(Lista *lista);
void liberta_lista_head(Contacto *head);
void apaga_da_lista(Lista *lista, Contacto *contacto);

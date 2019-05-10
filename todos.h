/* estrutura que aponta para as outras estruturas em que estao guardados os contactos*/
typedef struct todos
{
    struct lista *lista;
    struct no **tabela_nomes, **tabela_dominios;
} Todos;

Todos *init_todos();
void liberta_tudo(Todos *todos);
void apaga_contacto(Todos *todos, Contacto *contacto);
/* contacto que aponta para o que foi adicionado anteriormente e depois */
typedef struct contacto
{
    struct contacto *proximo, *anterior;
    char *nome, *telefone;
    struct email *email;
} Contacto;

/* email de um contacto */
typedef struct email
{
    char *local, *dominio;
} Email;

void liberta_contacto(Contacto *contacto);
void print_contacto(Contacto *contacto);
Contacto *cria_contacto(char nome[], char email[], char telefone[]);
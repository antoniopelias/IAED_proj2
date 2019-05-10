/* tabela de contactos */
typedef struct no
{
    struct contacto *contacto;
    struct no *proximo;
} *Link;


Link *init_tabela();
int hash(char *v, int M);
void introduz_tabela(char tipo, Link *tabela, Contacto *novo_contacto);
Contacto *encontra(Link *tabela, char nome[]);
void liberta_tabela(Link *tabela);
void liberta_link(Link no);
void apaga_da_tabela(char tipo, Link *tabela, Contacto *contacto);

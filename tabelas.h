/* tabela de contactos */
typedef struct no
{
    struct contacto *contacto;
    struct no *proximo;
} *Link;


Link *init_tabela();
int hash(char *v, int M);
void introduz_tab_nomes(Link *tabela_nomes, Contacto *novo_contacto);
Contacto *encontra_contacto(Link *tabela_nomes, char nome[]);
void liberta_tabela(Link *tabela);
void liberta_link(Link no);
void apaga_da_tabela(Link *tabela, Contacto *contacto);

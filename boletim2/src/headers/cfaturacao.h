#ifndef _CFATURACAO_H_
#define _CFATURACAO_H_

#include "avl.h"
#include "globais.h"
#include "venda.h"

typedef struct registo *Registo;

typedef struct registos *Registos;

typedef Registos **FTSProduto;

typedef struct cfaturacao *CFaturacao;


#define TAMARRAY 10

CFaturacao novo_cfaturacao();
Registos novo_registos();
FTSProduto novo_ftsproduto();
Registo novo_registo();
Registo cria_registo(Quantidade quantidade, Preco preco);
Registos insere_registos(Registos registos, Registo registo);
void free_registos(Registos registos);
void free_registo(Registo registo);
void imprime_cfaturacao_avls(CFaturacao cfaturacao);
void insere_registoProduto_avl(CFaturacao faturacao, Venda venda);
int get_nregistos_ftsproduto(CFaturacao faturacao, Mes mes, String produto, Filial filial, Promo promo);
float get_faturado_ftsproduto(CFaturacao faturacao, Mes mes, String produto, Filial filial, Promo promo);
int get_nprodutos_cfaturacao(CFaturacao cfaturacao);
AVL get_mes_avl(CFaturacao faturacao, int x);
Boolean preenchido_filial_promo(FTSProduto ftsproduto, int i, int j);
void get_totreg_totfat_meses(CFaturacao cfaturacao, int mesi, int mesf, int *totreg, float *totfat);

/*Boolean insere_avl_avl_filial1_iter(gpointer key, gpointer value, gpointer data);
Boolean insere_avl_avl_filial2_iter(gpointer key, gpointer value, gpointer data);
Boolean insere_avl_avl_filial3_iter(gpointer key, gpointer value, gpointer data);*/

#endif /* _cfaturacao_h_ */ 
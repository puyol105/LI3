#ifndef _cfaturacao_h_
#define _cfaturacao_h_

#include "avl.h"
#include "globais.h"
#include "venda.h"

typedef struct registo *Registo;

typedef struct registos *Registos;

typedef Registos **FTSProduto;

typedef struct cfaturacao *CFaturacao;


#define TAMARRAY 2



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


#endif /* _cfaturacao_h_ */ 
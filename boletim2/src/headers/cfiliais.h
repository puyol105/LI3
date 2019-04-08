#ifndef _CFILIAIS_H_
#define _CFILIAIS_H_

#include "avl.h"
#include "globais.h"
#include "venda.h"

typedef struct cfiliais *CFiliais;

typedef AVL **ProdsCliente;

typedef struct qtprod *QTProd; 


CFiliais novo_cfiliais();

ProdsCliente novo_prodscliente();

QTProd novo_qtprod();

QTProd cria_qtprod(Quantidade quantidade);

void insere_registoCliente_avl(CFiliais cfiliais, Venda venda);

void imprime_cfiliais_avls(CFiliais cfiliais);

AVL get_filial_avl(CFiliais cfiliais, int x);

int get_nclientes_cfiliais(CFiliais cfiliais);

int get_quantidade_comprada_cliente(CFiliais cfiliais, String cliente, Filial j, Mes i);

AVL get_filial_promo_mes_avl(CFiliais cfiliais, String cliente, Filial filial, Promo promo, Mes mes);

#endif /* _CFILIAIS_H_ */ 
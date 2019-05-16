#ifndef _leituras_h_
#define _leituras_h_

#include "avl.h"
#include "cclientes.h"
#include "cfaturacao.h"
#include "cfiliais.h"
#include "cliente.h"
#include "cprodutos.h"
#include "globais.h"
#include "produto.h"
#include "venda.h"

void le_ficheiros_dados_clientes(CClientes clientes, char cam[]);

void le_ficheiros_dados_produtos(CProdutos produtos, char cam[]);

int le_ficheiros_dados_vendas(CFaturacao faturacao, CFiliais cfiliais, CClientes clientes, CProdutos produtos, char cam[]);

#endif /* _leituras_h_ */ 
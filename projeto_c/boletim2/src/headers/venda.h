/** 
 * @file venda.h
 * @brief 
 */

#ifndef _venda_h_
#define _venda_h_

#include "cclientes.h"
#include "cliente.h"
#include "cprodutos.h"
#include "globais.h"
#include "produto.h"

typedef struct venda *Venda;

String get_cliente_venda(Venda venda);

Filial get_filial_venda(Venda venda);

Quantidade get_quantidade_venda(Venda venda);

Mes get_mes_venda(Venda venda);

Preco get_preco_venda(Venda venda);

String get_produto_venda(Venda venda);

Promo get_promo_venda(Venda venda);

Venda cria_venda(String produto, Preco preco, Quantidade quantidade, Promo promo, String cliente, Mes mes, Filial filial);

void free_venda(Venda venda);

Venda valida_venda(String venda, CClientes clientes, CProdutos produtos);

Boolean valida_mes_venda(String string);

Boolean valida_produto_venda(String string, CProdutos produtos);

Boolean valida_cliente_venda(String string, CClientes clientes);

#endif /* _venda_h_ */ 
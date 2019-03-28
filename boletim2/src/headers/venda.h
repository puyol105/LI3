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

Cliente get_cliente_venda(Venda venda);

Filial get_filial_venda(Venda venda);

Quantidade get_quantidade_venda(Venda venda);

Mes get_mes_venda(Venda venda);

Preco get_preco_venda(Venda venda);

Produto get_produto_venda(Venda venda);

Promo get_promo_venda(Venda venda);

Boolean valida_venda(String venda, CClientes clientes, CProdutos produtos);

#endif /* _venda_h_ */ 
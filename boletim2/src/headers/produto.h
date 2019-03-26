/** 
 * @file produto.h
 * @brief 
 */

#ifndef _produto_h_
#define _produto_h_

#include "globais.h"

typedef struct produto *Produto;

Produto cria_produto(String codigo);

String get_codigo_produto(Produto produto);

Boolean valida_produto(String codigo);

#endif /* _produto_h_ */ 
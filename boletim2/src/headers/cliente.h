/** 
 * @file cliente.h
 * @brief 
 */

#ifndef _cliente_h_
#define _cliente_h_

#include "globais.h"

typedef struct cliente *Cliente;

Cliente cria_cliente(String codigo);

String get_codigo_cliente(Cliente cliente);

Boolean valida_cliente(String codigo);

#endif /* _cliente_h_ */ 
/** 
 * @file queries.h
 * @brief Ficheiro que contem a API relativa á implementação de uma AVL.
 */

#ifndef _queries_h_
#define _queries_h_

#include "cclientes.h"
#include "cfaturacao.h"
#include "cprodutos.h"
#include "globais.h"
#include "leituras.h"

void query1(CFaturacao faturacao, CClientes clientes, CProdutos produtos, char fv[], char fc[], char fp[]);
void query3(CFaturacao cfaturacao, Mes mes, String produto, char c);

#endif /* _queries_h_ */ 
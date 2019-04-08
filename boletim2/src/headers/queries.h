/** 
 * @file queries.h
 * @brief Ficheiro que contem a API relativa á implementação de uma AVL.
 */

#ifndef _queries_h_
#define _queries_h_

#include "avl.h"
#include "cclientes.h"
#include "cfaturacao.h"
#include "cfiliais.h"
#include "cprodutos.h"
#include "globais.h"
#include "leituras.h"
#include "lstrings.h"

int query1(CFaturacao faturacao, CFiliais cfiliais, CClientes clientes, CProdutos produtos, char fv[], char fc[], char fp[]);
void query2(CProdutos produtos, char c);
void query3(CFaturacao cfaturacao, Mes mes, String produto, char c);
void query4(CFaturacao cfaturacao, CProdutos produtos, char c);
void query5(CFiliais cfiliais);
void query6(CFaturacao cfaturacao, CFiliais cfiliais, CProdutos cprodutos, CClientes cclientes);
void query7(CFiliais cfiliais, String cliente);
void query8(CFaturacao cfaturacao, int mesi, int mesf);
void query9(CFiliais cfiliais, String produto, Filial filial, Promo promo);
void query10(CFiliais cfiliais, String cliente, Mes mes);
void query11(CFaturacao cfaturacao, int n, Filial filial);
void query12();

#endif /* _queries_h_ */ 
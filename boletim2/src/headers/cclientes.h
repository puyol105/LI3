/** 
 * @file cclientes.h
 * @brief Ficheiro que contem a API relativa á implementação de um catálogo de clientes.
 */

#ifndef _cclientes_h_
#define _cclientes_h_

#include "avl.h"
#include "cliente.h"
#include "globais.h"

/*Definição do tipo CClientes (apontador para uma estrutura cclientes)*/
typedef struct cclientes *CClientes;

Boolean existe_cliente(String codigo, CClientes clientes);

/**
 * @brief Inicializa um CClientes, isto é, a cada posição do array letras 
 * atribui uma AVL vazia.
 * @return Retorna um CClientes inicializado.
 */
CClientes novo_cclientes();

/**
 * @brief Insere um par chave/valor numa das várias AVL's da estrutura
 * apontada por clientes.
 * @param Estrutura que contém as várias AVL's.
 * @param Chave que corresponde ao par chave/valor a ser inserido na AVL.
 * @param Valor que corresponde ao par chave/valor a ser inserido na AVL.
 * @return Não tem valor de retorno.
 */
void insere_cclientes(CClientes clientes, String chave, Cliente valor);

/**
 * @brief Imprime, uma a uma, todas as AVL's da estrutura apontada por clientes.
 * @param Estrutura que contém as várias AVL's.
 * @return Não tem valor de retorno.
 */
void imprime_cclientes(CClientes clientes);

int get_nclientes(CClientes cclientes);

#endif /* _cclientes_h_ */ 


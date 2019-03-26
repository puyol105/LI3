/** 
 * @file cclientes.h
 * @brief Ficheiro que contem a API relativa á implementação de um catálogo de clientes.
 */

#ifndef _cclientes_h_
#define _cclientes_h_

#include "avl.h"
#include "globais.h"

/*Definição do tipo CatClientes (apontador para uma estrutura catClientes)*/
typedef struct catClientes *CatClientes;

/**
 * @brief Inicializa um CatClientes, isto é, a cada posição do array letras 
 * atribui uma AVL vazia.
 * @return Retorna um CatClientes inicializado.
 */
CatClientes novo_cat_clientes();

/**
 * @brief Insere um par chave/valor numa das várias AVL's da estrutura
 * apontada por clientes.
 * @param Estrutura que contém as várias AVL's.
 * @param Chave que corresponde ao par chave/valor a ser inserido na AVL.
 * @param Valor que corresponde ao par chave/valor a ser inserido na AVL.
 * @return Não tem valor de retorno.
 */
void insere_cat_clientes(CatClientes clientes, char *chave, void* valor);

/**
 * @brief Imprime, uma a uma, todas as AVL's da estrutura apontada por clientes.
 * @param Estrutura que contém as várias AVL's.
 * @return Não tem valor de retorno.
 */
void imprime_cat_clientes(CatClientes clientes);

#endif /* _cclientes_h_ */ 


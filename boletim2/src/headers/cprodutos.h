/** 
 * @file cprodutos.h
 * @brief Ficheiro que contem a API relativa á implementação de um catálogo de produtos.
 */

#ifndef _cprodutos_h_
#define _cprodutos_h_

#include "avl.h"
#include "globais.h"
#include "produto.h"

/*Definição do tipo CProdutos (apontador para uma estrutura cprodutos)*/
typedef struct cprodutos *CProdutos;

/**
 * @brief Inicializa um CProdutos, isto é, a cada posição do array letras 
 * atribui uma AVL vazia.
 * @return Retorna um CProdutos inicializado.
 */
CProdutos novo_cprodutos();

/**
 * @brief Insere um par chave/valor numa das várias AVL's da estrutura
 * apontada por produtos.
 * @param Estrutura que contém as várias AVL's.
 * @param Chave que corresponde ao par chave/valor a ser inserido na AVL.
 * @param Valor que corresponde ao par chave/valor a ser inserido na AVL.
 * @return Não tem valor de retorno.
 */
void insere_cprodutos(CProdutos produtos, String chave, Produto valor);

/**
 * @brief Imprime, uma a uma, todas as AVL's da estrutura apontada por produtos.
 * @param Estrutura que contém as várias AVL's.
 * @return Não tem valor de retorno.
 */
void imprime_cprodutos(CProdutos produtos);

#endif /* _cprodutos_h_ */ 


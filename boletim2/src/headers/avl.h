/** 
 * @file avl.h
 * @brief Ficheiro que contem a API relativa á implementação de uma AVL.
 */

#ifndef _avl_h_
#define _avl_h_

#include "globais.h"

/*Definição do tipo AVL (apontador para uma estrutura GTree da glib)*/
typedef struct GTree *AVL;


typedef char* Chave;
typedef void* Valor;

/**
 * @brief Inicializa uma AVL, isto é, chama a função g_tree_new da glib com 
 * uma função de comparação que indicará o tipo e forma de ordenação.
 * @return Retorna um apontador para uma GTree vazia, ou seja, retorna uma 
 * AVL vazia.
 */
AVL nova_avl();

/**
 * @brief Insere um par chave/valor na AVL recebida como argumentos, isto é, 
 * chama a função g_tree_insert da glib com esses mesmos parâmetros.
 * @param AVL onde irá inserir o par chave/valor.
 * @param Chave que corresponde ao par chave/valor a ser inserido.
 * @param Valor que corresponde ao par chave/valor a ser inserido.
 * @return Não tem valor de retorno.
 */
void insere_avl(AVL avl, Chave chave, Valor valor);

/**
 * @brief Imprime as entradas duma AVL pela ordem que estão organizadas.
 * @param AVL que irá imprimir.
 * @return Não tem valor de retorno.
 */
void imprime_avl(AVL avl);

#endif /* _avl_h_ */ 
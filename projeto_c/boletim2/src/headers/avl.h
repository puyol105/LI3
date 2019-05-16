/** 
 * @file avl.h
 * @brief Ficheiro que contem a API relativa á implementação de uma AVL.
 */

#ifndef _AVL_H_
#define _AVL_H_

#include "globais.h"
#include "lstrings.h"


/*Definição do tipo AVL (apontador para uma estrutura GTree da glib)*/
typedef struct GTree *AVL;

typedef struct GTree *AVLHEAP;

typedef char* Chave;
typedef int *IntKey;
typedef void* Valor;

/**
 * @brief Imprime as entradas duma AVL pela ordem que estão organizadas.
 * @param AVL que irá imprimir.
 * @return Não tem valor de retorno.
 */
void imprime_avl(AVL avl);

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
 * @brief Inicializa uma AVL, isto é, chama a função g_tree_new da glib com 
 * uma função de comparação que indicará o tipo e forma de ordenação.
 * @return Retorna um apontador para uma GTree vazia, ou seja, retorna uma 
 * AVL vazia.
 */
AVL nova_avl();

Valor procura_valor_avl(AVL avl, Chave chave);

Boolean procura_valor_avl_extended(AVL avl, Chave chave, Chave c, Valor v );

Valor imprime_para_array(AVL avl, Valor valor);

void insere_avl_avl(AVL avl, Valor valor);

void soma_qtsprods_cliente(AVL avl, Valor valor);

void get_totreg_totfat_mes(AVL avl, Valor valor);

void get_clientes_produto(AVL avl, Valor valor);



AVLHEAP nova_avlheap();

void insere_avlheap(AVLHEAP avlheap, int chave, Valor valor);

void imprime_avl_inteiros(AVLHEAP avlheap);

void prods_comprados_cliente(AVL avl, AVL valor);

void prods_mais_comprados_cliente(AVL avl, AVLHEAP avlheap);

Valor imprime_avl_todos_inteiros_para_array(AVL avl, Valor valor);

void quantidades_produtos0(AVL avl, Valor valor);

void quantidades_produtos1(AVL avl, Valor valor);

void quantidades_produtos2(AVL avl, Valor valor);

/*
void insere_avl_avl_filial1(AVL avl, Valor valor);

void insere_avl_avl_filial2(AVL avl, Valor valor);

void insere_avl_avl_filial3(AVL avl, Valor valor);
*/

int get_nnodos(AVL avl);

void retira_comuns_avl_avl(AVL avl, Valor valor);

/*void foreach_avl(AVL avl, void (*f)(void *, void *, void *), Valor valor);

void foreach_avl(AVL avl, (GTraverseFunc)func, Valor valor);*/

#endif /* _AVL_H_ */ 
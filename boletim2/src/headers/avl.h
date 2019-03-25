/** 
 * @file avl.h
 * @brief Ficheiro que contem a API relativa á implementação de uma AVL.
 */

#ifndef _avl_h_
#define _avl_h_

/*Definição do tipo AVL (apontador para uma estrutura GTree da glib)*/
typedef struct GTree *AVL;

/**
 * @brief Inicializa uma AVL, isto é, chama a função g_tree_new da glib com 
 * uma função de comparação que indicará o tipo e forma de ordenação.
 * @return Retorna um apontador para uma GTree vazia, ou seja, retorna uma 
 * AVL vazia.
 */
AVL init_avl();

#endif /* _avl_h_ */ 
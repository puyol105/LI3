/** 
 * @file cclientes.h
 * @brief Ficheiro que contem a API relativa á implementação de um catálogo de clientes.
 */

#ifndef _cclientes_h_
#define _cclientes_h_

/*Definição do tipo CatClientes (apontador para uma estrutura catClientes)*/
typedef struct catClientes *CatClientes;

/**
 * @brief Inicializa um CatClientes, isto é, a cada posição do array letras 
 * atribui uma AVL vazia.
 * @return Retorna um CatClientes inicializado.
 */
AVL init_cat_clientes();

#endif /* _cclientes_h_ */ 


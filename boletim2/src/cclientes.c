#include "headers/cclientes.h"

#include <stdio.h>
#include <stdlib.h>

struct catClientes{
	AVL letras[NR_LETRAS];
};

CatClientes novo_cat_clientes(){
	int i;
	CatClientes clientes = malloc(sizeof(struct catClientes));
	for(i = 0; i < NR_LETRAS; i++){
		clientes->letras[i] = nova_avl();
	}
	return clientes;
}

void insere_cat_clientes(CatClientes clientes, char *chave, void* valor){
	int i = chave[0] - 'A'; 
	insere_avl(clientes->letras[i], chave, valor);
}

void imprime_cat_clientes(CatClientes clientes){
	int i;
	for(i = 0; i < NR_LETRAS; i++){
		imprime_avl(clientes->letras[i]);
	}
}

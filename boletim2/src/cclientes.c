#include "headers/cclientes.h"
#include "headers/globais.h"
#include "headers/avl.h"

struct catClientes{
	AVL letras[NR_LETRAS];
};


CatClientes init_cat_clientes(){
	int i;
	
	CatClientes c = malloc(sizeof(struct catClientes))
	
	for(i = 0; i < NR_LETRAS; i++){
		letras[i] = init_avl();
	}
	
	return cat;
}
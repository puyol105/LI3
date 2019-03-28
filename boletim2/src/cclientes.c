#include "headers/cclientes.h"

#include <stdio.h>
#include <stdlib.h>

struct cclientes{
	AVL letras[NR_LETRAS];
};

Boolean existe_cliente(String codigo, CClientes clientes){
	int i;
	i = codigo[0] - 'A';
	if(procura_valor_avl(clientes->letras[i], codigo) == NULL)
		return FALSE;
	return TRUE;
}

CClientes novo_cclientes(){
	int i;
	CClientes clientes = malloc(sizeof(struct cclientes));
	for(i = 0; i < NR_LETRAS; i++){
		clientes->letras[i] = nova_avl();
	}
	return clientes;
}

void insere_cclientes(CClientes clientes, String chave, Cliente valor){
	int i = chave[0] - 'A';
	insere_avl(clientes->letras[i], chave, valor);
}

void imprime_cclientes(CClientes clientes){
	int i;
	for(i = 0; i < NR_LETRAS; i++){
		imprime_avl(clientes->letras[i]);
	}
}

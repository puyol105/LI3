#include "headers/cprodutos.h"

#include <stdio.h>
#include <stdlib.h>

struct cprodutos{
	AVL letras[NR_LETRAS][NR_LETRAS];
};

CProdutos novo_cprodutos(){
	int i, j;
	CProdutos produtos = malloc(sizeof(struct cprodutos));
	for(i = 0; i < NR_LETRAS; i++)
		for(j = 0; j < NR_LETRAS; j++)
			produtos->letras[i][j] = nova_avl();
	return produtos;
}

void insere_cprodutos(CProdutos produtos, String chave, Produto valor){
	int i, j; 
	i = chave[0] - 'A';
	j = chave[1] - 'A'; 
	insere_avl(produtos->letras[i][j], chave, valor);
}

void imprime_cprodutos(CProdutos produtos){
	int i, j;
	for(i = 0; i < NR_LETRAS; i++){
		for(j = 0; j < NR_LETRAS; j++)
			imprime_avl(produtos->letras[i][j]);
	}
}

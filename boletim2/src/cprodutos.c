#include "headers/cprodutos.h"

#include <stdio.h>
#include <stdlib.h>

struct cprodutos{
	int nprodutos;
	AVL letras[NR_LETRAS][NR_LETRAS];
};

Boolean existe_produto(String codigo, CProdutos produtos){
	int i, j;
	i = codigo[0] - 'A';
	j = codigo[1] - 'A'; 
	if(procura_valor_avl(produtos->letras[i][j], codigo) == NULL)
		return FALSE;
	return TRUE;
}

CProdutos novo_cprodutos(){
	int i, j;
	CProdutos produtos = malloc(sizeof(struct cprodutos));
	for(i = 0; i < NR_LETRAS; i++)
		for(j = 0; j < NR_LETRAS; j++)
			produtos->letras[i][j] = nova_avl();
	produtos->nprodutos = 0;
	return produtos;
}

void insere_cprodutos(CProdutos produtos, String chave, Produto valor){
	int i, j; 
	i = chave[0] - 'A';
	j = chave[1] - 'A'; 
	insere_avl(produtos->letras[i][j], chave, valor);
	produtos->nprodutos++;
}

void imprime_cprodutos(CProdutos produtos){
	int i, j;
	for(i = 0; i < NR_LETRAS; i++){
		for(j = 0; j < NR_LETRAS; j++)
			imprime_avl(produtos->letras[i][j]);
	}
}

AVL get_letras_avl(CProdutos produtos, int x, int y){
	return produtos->letras[x][y];
}

int get_nprodutos(CProdutos produtos){
	return produtos->nprodutos;
}

#include "headers/produto.h"

#include <ctype.h>
#include <stdlib.h>
#include <string.h>

struct produto{
	String codigo;
};

static Produto novo_produto();

Produto cria_produto(String codigo){
	Produto produto;
	int tamanho;
	tamanho = strlen(codigo) + 1;
	produto = novo_produto();
	produto->codigo = malloc(tamanho*sizeof(char));
	strcpy(produto->codigo, codigo);
	return produto;
}

String get_codigo_produto(Produto produto){
	return produto->codigo;
}

Boolean valida_produto(String codigo){
	if(isupper(codigo[0]) == 0 || isupper(codigo[1]) == 0)
		return FALSE;
	if(strlen(codigo) != 6)
		return FALSE;
	if(atoi(codigo+2) < 1000 || atoi(codigo+2) > 9999)
		return FALSE;
	return TRUE;
}


static Produto novo_produto(){
	Produto produto;
	produto = malloc(sizeof(struct produto));
	if(produto == NULL)
		return NULL;
	return produto;
}
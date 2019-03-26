#include "headers/cliente.h"

#include <ctype.h>
#include <stdlib.h>
#include <string.h>

struct cliente{
	String codigo;
};

static Cliente novo_cliente();

Cliente cria_cliente(String codigo){
	Cliente cliente;
	int tamanho;
	tamanho = strlen(codigo) + 1;
	cliente = novo_cliente();
	cliente->codigo = malloc(tamanho*sizeof(char));
	strcpy(cliente->codigo, codigo);
	return cliente;
}

String get_codigo_cliente(Cliente cliente){
	return cliente->codigo;
}

Boolean valida_cliente(String codigo){
	if(isupper(codigo[0]) == 0)
		return FALSE;
	if(strlen(codigo) != 5)
		return FALSE;
	if(atoi(codigo+1) < 1000 || atoi(codigo+1) > 5000)
		return FALSE;
	return TRUE;
}



static Cliente novo_cliente(){
	Cliente cliente;
	cliente = malloc(sizeof(struct cliente));
	if(cliente == NULL)
		return NULL;
	return cliente;
}



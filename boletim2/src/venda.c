#include "headers/venda.h"

#include <ctype.h>
/*eliminar isto, pus só para os printfs para fazer debug*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct venda{
	Produto produto;
	Preco preco;
	Quantidade quantidade;
	Promo promo;
	Cliente cliente;
	Mes mes;
	Filial filial;
};


/*static Venda nova_venda();*/
static Boolean valida_cliente_venda(String string, CClientes clientes);
static Boolean valida_filial_venda(String string);
static Boolean valida_quantidade_venda(String string);
static Boolean valida_mes_venda(String string);
static Boolean valida_preco_venda(String string);
static Boolean valida_produto_venda(String string, CProdutos produtos);
static Boolean valida_promo_venda(String string);


Cliente get_cliente_venda(Venda venda){
	return venda->cliente;
}

Filial get_filial_venda(Venda venda){
	return venda->filial;
}

Quantidade get_quantidade_venda(Venda venda){
	return venda->quantidade;
}

Mes get_mes_venda(Venda venda){
	return venda->mes;
}

Preco get_preco_venda(Venda venda){
	return venda->preco;
}

Produto get_produto_venda(Venda venda){
	return venda->produto;
}

Promo get_promo_venda(Venda venda){
	return venda->promo;
}

int valida_venda(String string, CClientes clientes, CProdutos produtos){
	
	int i, tamanho;
	String aux, campo;
	aux = malloc(MAXBUFVENDA*sizeof(char));
	char * campos[MAXCAMPOSVENDA] = {NULL};
	i = 0;

	strcpy(aux, string);

	campo = strtok(aux, " \n\r");
	tamanho = strlen(campo) + 1;
	campos[i] = malloc(tamanho*sizeof(char));
	strcpy(campos[i], campo);

	i++; 

	/*MELHORAR ESTA FUNÇÃO: ADICIONAR A CONDICAO "i<MAXCAMPOSVENDA+1" AO 
	WHILE E POR NO PRIMEIRO CHECK campos[MAXCAMPOSVENDA] != NULL EM VEZ 
	DE ARGS != MAXCAMPOSVENDA, ELIMINAR O ARGS PORQUE NAO FAZ FALTA*/
	/*coloca num array de strings várias strings correspondente a uma venda
	fragmentada nos seus vários campos*/
	while(i < MAXCAMPOSVENDA){
		campo = strtok(NULL, " \n\r");
		tamanho = strlen(campo) + 1;
		campos[i] = malloc(tamanho*sizeof(char));
		strcpy(campos[i], campo);
		i++; 
	}

	campo = strtok(NULL, " \n\r");

	if(campo != NULL)
		return FALSE;

	if(!valida_produto_venda(campos[0], produtos))
		return FALSE;

	if(!valida_preco_venda(campos[1]))
		return FALSE;

	if(!valida_quantidade_venda(campos[2]))
		return FALSE;

	if(!valida_promo_venda(campos[3]))
		return FALSE;

	if(!(valida_cliente_venda(campos[4], clientes)))
		return FALSE;

	if(!(valida_mes_venda(campos[5])))
		return FALSE;

	if(!(valida_filial_venda(campos[6])))
		return FALSE;

	return TRUE;
}

/*static Venda nova_venda(){
	return NULL;
}*/

static Boolean valida_cliente_venda(String string, CClientes clientes){
	if(valida_cliente(string) == FALSE)
		return FALSE;
	if(existe_cliente(string, clientes) == FALSE)
		return FALSE; 
	return TRUE;
}

static Boolean valida_filial_venda(String string){
	int i;
	for(i = 0; i < ((int) strlen(string)); i++)
		if(!isdigit(string[i]))
			return FALSE;
	if (atoi(string) < 1 || atoi(string) > 3)
		return FALSE;
	return TRUE;
}

static Boolean valida_quantidade_venda(String string){
	int i;
	for(i = 0; i < ((int) strlen(string)); i++)
		if(!isdigit(string[i]))
			return FALSE;
	if(atoi(string) < 1 || atoi(string) > 200)
		return FALSE;	
	return TRUE;
}

static Boolean valida_mes_venda(String string){
	int i;
	for(i = 0; i < ((int) strlen(string)); i++)
		if(!isdigit(string[i]))
			return FALSE;
	if (atoi(string) < 1 || atoi(string) > 12)
		return FALSE;
	return TRUE;
}

static Boolean valida_preco_venda(String string){
	int i;
	for(i = 0; i < ((int) strlen(string)) && string[i]!='.'; i++)
		if(!isdigit(string[i]))
			return FALSE;
	for(i=i+1; i < ((int) strlen(string)); i++)
		if(!isdigit(string[i]))
			return FALSE;
	if(atof(string) > 9999.99 || atof(string) < 0 )
		return FALSE; 
	return TRUE;
}

static Boolean valida_produto_venda(String string, CProdutos produtos){
	if(valida_produto(string) == FALSE)
		return FALSE;
	if(existe_produto(string, produtos) == FALSE)
		return FALSE; 
	return TRUE;
}

static Boolean valida_promo_venda(String string){
	if(!(strcmp(string, "N") == 0 || strcmp(string, "P") == 0))
		return FALSE;
	return TRUE;
}
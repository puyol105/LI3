#include "headers/leituras.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>


void le_ficheiros_dados_clientes(CClientes clientes, char cam[]){
	char str[MAXBUFCLI];
	Cliente cliente = NULL;
	String buf = NULL;
	FILE *fp = NULL;
	/*FILE *fp = fopen("../teste/Clientes1.txt","r"); se este ficheiro estiver junto à makefile*/
	
	if(0 == strcmp(cam, "nao abrir")){
		fp = fopen("../intocaveis/Clientes.txt","r"); /*se este ficheiro estiver junto à makefile*/
		if(fp == NULL){
			puts("Erro na abertura do ficheiro clientes.");
			return;
		}
	}
	else{
		fp= fopen(cam,"r");
		if(fp == NULL){
			puts("Erro na abertura do ficheiro clientes.");
			return;
		}
		else printf("O ficheiro '%s' foi lido\n", cam);
	}

	while(fgets(str, MAXBUFCLI, fp)){
		strtok(str,"\r\n");
		if(valida_cliente(str)){

			buf = (char *) malloc((strlen(str+1))*sizeof(char));
			strcpy(buf, str);

			cliente = cria_cliente(str); 

			insere_cclientes(clientes, buf, cliente);
		}
	}

	fclose(fp);

}

void le_ficheiros_dados_produtos(CProdutos produtos, char cam[]){
	char str[MAXBUFCLI];
	Produto produto = NULL;
	String buf = NULL;
	FILE *fp = NULL;
	/*FILE *fp = fopen("../teste/Produtos1.txt","r"); se este ficheiro estiver junto à makefile*/
	

	if(0 == strcmp(cam, "nao abrir")){
		fp = fopen("../intocaveis/Produtos.txt","r"); /*se este ficheiro estiver junto à makefile*/
		if(fp == NULL){
			puts("Erro na abertura do ficheiro produtos.");
			return;	
		}
	}
	else{
		fp = fopen(cam,"r");
		if(fp == NULL){
			puts("Erro na abertura do ficheiro produtos.");
			return;
		}
		else printf("O ficheiro '%s' foi lido\n", cam);
	}

	while(fgets(str, MAXBUFPROD, fp)){
		strtok(str,"\r\n");
		if(valida_produto(str)){
			buf = (char *) malloc((strlen(str+1))*sizeof(char));
			strcpy(buf, str);

			produto = cria_produto(str); 

			insere_cprodutos(produtos, buf, produto);
		}
	}

	fclose(fp);

}

/*só para testar, por enquanto, utilizamos a estrutura catalogo clientes*/
int le_ficheiros_dados_vendas(CFaturacao faturacao, CFiliais cfiliais, CClientes clientes, CProdutos produtos, char cam[]){
	char str[MAXBUFVENDA];
	int i = 0;
	Venda venda = NULL;
	FILE *fp = NULL;

	if(0 == strcmp(cam, "nao abrir")){
		fp = fopen("../intocaveis/Vendas_1M.txt","r"); /*se este ficheiro estiver junto à makefile*/
		if(fp == NULL){
			puts("Erro na abertura do ficheiro vendas.");
			return i;
		}
	}
	else{
		fp= fopen(cam,"r");
		if(fp == NULL){
			printf("AQUILO QUE LEU: |%s|\n", cam);
			puts("Erro na abertura do ficheiro vendas.");
			return i;
		}
		else printf("O ficheiro '%s' foi lido\n", cam);
	}


 	puts("Lendo o ficheiro vendas...\n");
	while(fgets(str, MAXBUFVENDA, fp)){
		strtok(str,"\r\n");
		if((venda = valida_venda(str, clientes, produtos)) != NULL){
			i++;

			insere_registoProduto_avl(faturacao, venda);
			insere_registoCliente_avl(cfiliais, venda);

			free_venda(venda);
		}
	}

	
	fclose(fp);
	return i;
}
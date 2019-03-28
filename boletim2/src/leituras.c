#include "headers/leituras.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>


void le_ficheiros_dados_clientes(CClientes clientes){
	char str[MAXBUFCLI];
	Cliente cliente = NULL;
	String buf = NULL;
	/*FILE *fp = fopen("../teste/Clientes1.txt","r"); se este ficheiro estiver junto à makefile*/
	FILE *fp = fopen("../intocaveis/Clientes.txt","r"); /*se este ficheiro estiver junto à makefile*/
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

void le_ficheiros_dados_produtos(CProdutos produtos){
	char str[MAXBUFCLI];
	Produto produto = NULL;
	String buf = NULL;
	/*FILE *fp = fopen("../teste/Produtos1.txt","r"); se este ficheiro estiver junto à makefile*/
	FILE *fp = fopen("../intocaveis/Produtos.txt","r"); /*se este ficheiro estiver junto à makefile*/
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
void le_ficheiros_dados_vendas(CClientes clientes, CProdutos produtos){
	char str[MAXBUFVENDA];
	int i = 0;
	/*Cliente cliente = NULL;*/
	/*String buf = NULL;*/
	/*FILE *fp = fopen("../teste/Clientes1.txt","r"); se este ficheiro estiver junto à makefile*/
	FILE *fp = fopen("../intocaveis/Vendas_1M.txt","r"); /*se este ficheiro estiver junto à makefile*/
	while(fgets(str, MAXBUFVENDA, fp)){
		strtok(str,"\r\n");
		if(valida_venda(str, clientes, produtos)){
			i++;
			/*buf = (char *) malloc((strlen(str+1))*sizeof(char));*/
			/*strcpy(buf, str);*/

			/*cliente = cria_cliente(str); */

			/*insere_cclientes(clientes, buf, cliente);*/
		}
	}

	printf("Clientes lidos: %d\n", i);
	fclose(fp);
}
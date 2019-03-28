
#include "headers/globais.h"
#include "headers/cclientes.h"
#include "headers/cprodutos.h"
#include "headers/leituras.h"

#include <stdlib.h>
#include <stdio.h>

#ifdef _WIN32
	#define CLEAR "cls"
#else
	#define CLEAR "clear"
#endif

/*CProdutos*/
/*Faturacao*/
/*Filial*/

void imprime_logo(){
	int i;
	i = system(CLEAR);
	if(i)
		exit(EXIT_FAILURE);
	puts(" ____   ____  ________  ____  _____  ______   _____  _____  ____    ____ ");
	puts("|_  _| |_  _||_   __  ||_   \\|_   _||_   _ `.|_   _||_   _||_   \\  /   _|");
	puts("  \\ \\   / /    | |_ \\_|  |   \\ | |    | | `. \\ | |    | |    |   \\/   |  ");
	puts("   \\ \\ / /     |  _| _   | |\\ \\| |    | |  | | | '    ' |    | |\\  /| |  ");
	puts("    \\ ' /     _| |__/ | _| |_\\   |_  _| |_.' /  \\ \\__/ /    _| |_\\/_| |_ ");
	puts("     \\_/     |________||_____|\\____||______.'    `.__.'    |_____||_____|");
	printf("\n");
	puts("                         Sistema de Gestão de Vendas");
	printf("\n\n\n");

}

void imprime_opcoes(){
	puts("01 - ");
	puts("02 - ");
	puts("03 - ");
	puts("04 - ");
	puts("05 - ");
	puts("06 - ");
	puts("07 - ");
	puts("08 - ");
	puts("09 - ");
	puts("10 - ");
	puts("11 - ");
	puts("12 - ");
}


int main(){

	CClientes clientes;
	clientes = novo_cclientes();

	CProdutos produtos;
	produtos = novo_cprodutos();

	imprime_logo();


	char opcao[MAXOP];

	int i = scanf("%s", opcao);

	printf("%d\n", i);

	switch(opcao[0]) {

	   case '0'  :
	      printf("Escolheu a opção 0\n");
	      le_ficheiros_dados_clientes(clientes);
	      /*imprime_cclientes(clientes);*/
	      le_ficheiros_dados_produtos(produtos);
	      /*imprime_cprodutos(produtos);*/
	      /*le_ficheiros_dados_vendas();*/
	      break; 
		
	   case '1'  :
	      printf("Escolheu a opção 1\n");

	      break; /* optional */
	  
	   
	   default :
	   printf("não entrei em nenhum dos outros\n");
	}

	return 0;
}


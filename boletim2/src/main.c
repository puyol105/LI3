
#include "headers/globais.h"
#include "headers/cclientes.h"
#include "headers/leituras.h"

#include <stdio.h>


CClientes clientes;

/*CProdutos*/
/*Faturacao*/
/*Filial*/

int main(){

	char opcao[MAXOP];

	int i = scanf("%s", opcao);

	printf("%d\n", i);

	switch(opcao[0]) {

	   case '0'  :
	      printf("ola, entrei no 0\n");
	      clientes = novo_cclientes();
	      le_ficheiros_dados(clientes);

	      imprime_cclientes(clientes);
	      printf("ola\n");
	      break; /* optional */
		
	   case '1'  :
	      printf("ola, entrei no 1\n");;

	      break; /* optional */
	  
	   
	   default :
	   printf("não entrei em nenhum dos outros\n");
	}

	return 0;
}

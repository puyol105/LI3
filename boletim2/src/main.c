
#include "headers/globais.h"
#include "headers/cclientes.h"
#include "headers/leituras.h"

#include <stdio.h>


CatClientes clientes;

/*CatProdutos*/
/*Faturacao*/
/*Filial*/

int main(){

	char opcao[MAXOP];

	scanf("%s", opcao);

	switch(opcao[0]) {

	   case '0'  :
	      printf("ola, entrei no 0\n");
	      clientes = novo_cat_clientes();
	      le_ficheiros_dados(clientes);

	      //imprime_cat_clientes(clientes);
	      break; /* optional */
		
	   case '1'  :
	      printf("ola, entrei no 1\n");;

	      break; /* optional */
	  
	   
	   default :
	   printf("não entrei em nenhum dos outros\n");
	}

	return 0;
}

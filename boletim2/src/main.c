
#include "headers/cclientes.h"
#include "headers/cfaturacao.h"
#include "headers/cfiliais.h"
#include "headers/cprodutos.h"
#include "headers/globais.h"
#include "headers/leituras.h"
#include "headers/queries.h"
#include "headers/venda.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define FLUSH_STDIN() { int c; while((c = getchar()) != EOF && (c != '\r' || c != '\n')); }

#ifdef _WIN32
	#define CLEAR "cls"
#else
	#define CLEAR "clear"
#endif


/*CProdutos*/
/*Faturacao*/
/*Filial*/


char* leLinha(char buffer[], int tamanho, FILE* stream){	
	char* linha = fgets(buffer, tamanho, stream);
	
	if(linha != NULL){
		int i = strcspn(linha, "\r\n");	

		if(linha[i] == '\0') /* ficaram carateres no stdin */
			FLUSH_STDIN()
		else
			linha[i] = '\0'; /* remove o carater de newline, se este existir */
	}
	return linha;
}


void imprime_logo(){
	int i;
	i = system(CLEAR);
	if(i)
		exit(EXIT_FAILURE);

	char *input = (char *) malloc(MAXOP * sizeof(char));


	puts(" ____   ____  ________  ____  _____  ______   _____  _____  ____    ____ ");
	puts("|_  _| |_  _||_   __  ||_   \\|_   _||_   _ `.|_   _||_   _||_   \\  /   _|");
	puts("  \\ \\   / /    | |_ \\_|  |   \\ | |    | | `. \\ | |    | |    |   \\/   |  ");
	puts("   \\ \\ / /     |  _| _   | |\\ \\| |    | |  | | | '    ' |    | |\\  /| |  ");
	puts("    \\ ' /     _| |__/ | _| |_\\   |_  _| |_.' /  \\ \\__/ /    _| |_\\/_| |_ ");
	puts("     \\_/     |________||_____|\\____||______.'    `.__.'    |_____||_____|");
	printf("\n");
	puts("                         Sistema de Gestão de Vendas");
	printf("\n\n\n");

	printf("\nPrima qualquer tecla para avançar...");
	if(NULL == leLinha(input, MAX_NAME_FILE, stdin))
		puts("Erro na leitura da tecla.");

}

void imprime_opcoes(){

	puts("Opções:\n");
	puts("[A] 01 - Leitura dos ficheiros de dados.");
	puts("[B] 02 - Produtos cujo código se inicia por uma dada letra");
	puts("[C] 03 - Nº de vendas e total faturado de um produto num mês.");
	puts("[D] 04 - Lista e nº dos códigos de produto que ninguém comprou.");
	puts("[E] 05 - Clientes que compraram em todas as filiais.");
	puts("[F] 06 - Nº de clientes que não compraram e nº de produtos não comprados.");
	puts("[G] 07 - Nº de produtos comprados por um cliente (por mês e filial).");
	puts("[H] 08 - Nº de registos de venda e total faturado num período.");
	puts("[I] 09 - Códigos dos clientes que compraram um produto.");
	puts("[J] 10 - Códigos dos produtos que um cliente mais comprou.");
	puts("[K] 11 - Lista dos N produtos mais vendidos em todo ano.");
	puts("[L] 12 - Três produtos mais caros");
	puts("[Q] 13 - Sair\n");

}

int imprime_menu1(CFaturacao faturacao, CFiliais cfiliais, CClientes clientes, CProdutos produtos){
	int flag = 0;
	char *fv = (char *) malloc(MAX_NAME_FILE * sizeof(char)); 
	char *fc = (char *) malloc(MAX_NAME_FILE * sizeof(char));
	char *fp = (char *) malloc(MAX_NAME_FILE * sizeof(char));
	
	char *input = (char *) malloc(MAXOP * sizeof(char));


	puts("\nQuer introduzir caminho para o ficheiro vendas?");
	input = leLinha(input, MAX_NAME_FILE, stdin);
	
	if((0 == strcmp(input, "sim")) || (0 == strcmp(input, "s"))){
		puts("'Caminho' do ficheiro de vendas:");
		fv = leLinha(fv, MAX_NAME_FILE, stdin);
	}
	else strcpy(fv, "nao abrir");



	puts("\nQuer introduzir caminho para o ficheiro clientes?");
	input = leLinha(input, MAX_NAME_FILE, stdin);

	if((0 == strcmp(input, "sim")) || (0 == strcmp(input, "s"))){
		puts("'Caminho' do ficheiro de clientes:");
		fc = leLinha(fc, MAX_NAME_FILE, stdin);
			puts("Erro na introdução do nome do ficheiro clientes.\n");
	}
	else strcpy(fc, "nao abrir");


	puts("\nQuer introduzir caminho para o ficheiro produtos?");
	input = leLinha(input, MAX_NAME_FILE, stdin);

	if((0 == strcmp(input, "sim")) || (0 == strcmp(input, "s"))){
		puts("'Caminho' do ficheiro de produtos:");
		fc = leLinha(fp, MAX_NAME_FILE, stdin);
			puts("Erro na introdução do nome do ficheiro produtos.\n");
	}
	else strcpy(fp, "nao abrir");

	puts("\n");



 	flag = query1(faturacao, cfiliais, clientes, produtos, fv, fc, fp);

  	printf("\nPrima qualquer tecla para avançar...");
	if(NULL == leLinha(input, MAX_NAME_FILE, stdin))
		puts("Erro na leitura da tecla.");

	return flag;
}

void imprime_menu2(CProdutos produtos){
	char *input = (char *) malloc(MAXOP * sizeof(char));

	int i;
	i = system(CLEAR);
	if(i)
		exit(EXIT_FAILURE);

	printf("\nInsira uma letra: ");
	if(NULL == leLinha(input, MAX_NAME_FILE, stdin))
		puts("Erro na leitura da letra.");

	if(isalpha(input[0]))
		query2(produtos, toupper(input[0]));
	else
		puts("O caratere inserido não é válido!");

	printf("\nPrima qualquer tecla para avançar...");
	if(NULL == leLinha(input, MAX_NAME_FILE, stdin))
		puts("Erro na leitura da tecla.");
}

void imprime_menu3(CFaturacao faturacao, CProdutos produtos){

	char input1[MAXOP];
	char input2[MAXOP];
	char input3[MAXOP];

	printf("Produto: ");
	if(NULL == leLinha(input1, MAX_NAME_FILE, stdin))
		puts("Erro na leitura do produto.");
	
	if(valida_produto_venda(input1, produtos) == FALSE){
		puts("Não introduziu um produto valido.");
		return;
	}

	printf("Mês: ");
	if(NULL == leLinha(input2, MAX_NAME_FILE, stdin))
		puts("Erro na leitura do mês.");
	
	if(valida_mes_venda(input2) == FALSE){
		puts("Não introduziu o número do mês correto.");
		return;
	}
	
	printf("Global (G) ou filial a filial(F): ");
	if(NULL == leLinha(input3, MAX_NAME_FILE, stdin))
		puts("Erro na leitura do caratere.");
	
	if(!(input3[0] == 'G' || input3[0] == 'g' || input3[0] == 'F' || input3[0] == 'f')){
		puts("Não introduziu o número do mês correto.");
		return;
	}

	query3(faturacao, atoi(input2), input1, input3[0]);

}

void imprime_menu4(CFaturacao faturacao, CProdutos produtos){
	char *input = (char *) malloc(MAXOP * sizeof(char));

	int i;
	i = system(CLEAR);
	if(i)
		exit(EXIT_FAILURE);

	printf("\nInsira G se pretende valor global, ou o identificador da filial: ");
	if(NULL == leLinha(input, MAX_NAME_FILE, stdin))
		puts("Erro na leitura da letra.");

	if((input[0] == 'G' || (input[0] == '1') || (input[0] == '2') || (input[0] == '3')) && strlen(input) == 1 ){
		query4(faturacao, produtos, input[0]);
	}
	else{
		puts("Opção errada. Identificador da filial ou G.");
	}

	printf("\nPrima qualquer tecla para avançar...");
	if(NULL == leLinha(input, MAX_NAME_FILE, stdin))
		puts("Erro na leitura da tecla.");

}



void imprime_menu5(CFiliais cfiliais){
	char *input = (char *) malloc(MAXOP * sizeof(char));

	query5(cfiliais);

	printf("\nPrima qualquer tecla para avançar...");
	if(NULL == leLinha(input, MAX_NAME_FILE, stdin))
		puts("Erro na leitura da tecla.");

}


void imprime_menu6(CFaturacao cfaturacao, CFiliais cfiliais, CProdutos cprodutos, CClientes cclientes){
	char *input = (char *) malloc(MAXOP * sizeof(char));

	query6(cfaturacao, cfiliais, cprodutos, cclientes);

	printf("\nPrima qualquer tecla para avançar...");
	if(NULL == leLinha(input, MAX_NAME_FILE, stdin))
		puts("Erro na leitura da tecla.");

}

void imprime_menu7(CFiliais cfiliais, CClientes clientes){
	char *input = (char *) malloc(MAXOP * sizeof(char));

	printf("Cliente: ");
	if(NULL == leLinha(input, MAX_NAME_FILE, stdin))
		puts("Erro na leitura do cliente.");
	
	if(valida_cliente_venda(input, clientes) == FALSE){
		puts("Não introduziu um cliente válido.");
	}
	else
		query7(cfiliais, input);

	printf("\nPrima qualquer tecla para avançar...");
	if(NULL == leLinha(input, MAX_NAME_FILE, stdin))
		puts("Erro na leitura da tecla.");
}

void imprime_menu8(CFaturacao cfaturacao){
	char input1[MAXOP];
	char input2[MAXOP];
	int mes1, mes2;

	puts("Insira o primeiro e o último mês pretendidos.");
	printf("Desde o mês: ");
	if(NULL == leLinha(input1, MAX_NAME_FILE, stdin))
		puts("Erro na leitura do primeiro mês.");
	
	if(valida_mes_venda(input1) == FALSE){
		puts("Não introduziu o número do mês correto.");
		return;
	}
	else{
		strtok(input1, " ");
		mes1 = atoi(input1);
	}

	printf("Até ao mês: ");
	if(NULL == leLinha(input2, MAX_NAME_FILE, stdin))
		puts("Erro na leitura do último mês.");
	
	if(valida_mes_venda(input2) == FALSE){
		puts("Não introduziu o número do mês correto.");
		return;
	}
	else{
		strtok(input2, " ");
		mes2 = atoi(input2);
		if(mes2 < mes1){
			puts("Inseriu um intervalo de meses inválido.");
			return;
		}
	}

	query8(cfaturacao, mes1-1, mes2-1);

}


void imprime_menu9(CFiliais cfiliais, CProdutos produtos){
	char input1[MAX_NAME_FILE];
	char input2[MAX_NAME_FILE];
	char input3[MAX_NAME_FILE];

	printf("Produto: ");
	if(NULL == leLinha(input1, MAX_NAME_FILE, stdin))
		puts("Erro na leitura do produto.");

	if(valida_produto_venda(input1, produtos) == FALSE){
		puts("Não introduziu um produto válido.");
		return;
	}

	printf("Filial: ");
	if(NULL == leLinha(input2, MAX_NAME_FILE, stdin))
		puts("Erro na leitura da filial.");

	if(((input2[0] == '1') || (input2[0] == '2') || (input2[0] == '3')) && strlen(input2) == 1 ){

		printf("P ou N? : ");
		if(NULL == leLinha(input3, MAX_NAME_FILE, stdin))
		puts("Erro na leitura da filial.");		
		
		if(((input3[0] == 'P') || (input3[0] == 'N')) && strlen(input3) == 1){
			if(input3[0] == 'P')
				query9(cfiliais, input1, atoi(input2)-1, 1);
			if(input3[0] == 'N')
				query9(cfiliais, input1, atoi(input2)-1, 0);
		}
		else
			puts("Não introduziu modo de compra correto.");	
	}
	else{
		puts("Não introduziu um identificador de filial válido.");
	}

}


void imprime_menu10(CFiliais cfiliais, CClientes clientes){
	char input1[MAX_NAME_FILE];
	char input2[MAX_NAME_FILE];

	printf("Cliente: ");
	if(NULL == leLinha(input1, MAX_NAME_FILE, stdin))
		puts("Erro na leitura do cliente.");
	
	if(valida_cliente_venda(input1, clientes) == FALSE){
		puts("Não introduziu um cliente válido.");
		return;
	}

	printf("Mês: ");
	if(NULL == leLinha(input2, MAX_NAME_FILE, stdin))
		puts("Erro na leitura do mês.");
	
	if(valida_mes_venda(input2) == FALSE){
		puts("Não introduziu o número do mês correto.");
		return;
	}

	query10(cfiliais, input1, atoi(input2)-1);

}

void imprime_menu11(CFaturacao faturacao){
	int i, n = 0;
	char input2[MAX_NAME_FILE];
	char input3[MAX_NAME_FILE];

	printf("Nº de produtos: ");
	if(NULL == leLinha(input2, MAX_NAME_FILE, stdin))
		puts("Erro na leitura do número.");
	
	for(i = 0; i < (int) strlen(input2); i++)
		if(isalpha(input2[i]))
			return;

	n = atoi(input2);

	if(n <= 0 && n > NR_PRODS){
		puts("Não introduziu o número de produtos correto.");
		return;
	}

	printf("Filial: ");
	if(NULL == leLinha(input3, MAX_NAME_FILE, stdin))
		puts("Erro na leitura da filial.");

	if(((input3[0] == '1') || (input3[0] == '2') || (input3[0] == '3')) && strlen(input3) == 1 ){
		query11(faturacao, n, atoi(input3)-1);
	}
}

void imprime_menu12(){
	query12();
}

int main(){

	
	int i, flag = 0;

	Boolean sair = FALSE;

	char *input = (char *) malloc(MAXOP * sizeof(char));

	CClientes clientes;
	clientes = novo_cclientes();

	CProdutos produtos;
	produtos = novo_cprodutos();

	CFaturacao faturacao;
	faturacao = novo_cfaturacao();

	CFiliais cfiliais;
	cfiliais = novo_cfiliais();

	imprime_logo();

	char opcao[MAXOP];

	while(sair == FALSE){

	i = system(CLEAR);
	if(i)
		exit(EXIT_FAILURE);


	imprime_opcoes();

	printf("Insira a opção: ");
	if(NULL == leLinha(opcao, MAX_NAME_FILE, stdin)){
		puts("Erro na leitura da opção");
	}

		switch(toupper(opcao[0])) {

		   	case 'A':
		   		flag = imprime_menu1(faturacao, cfiliais, clientes, produtos);
		      	break; 
			
			case 'B':
				if(flag > 0)
					imprime_menu2(produtos);
		    	else puts("Faça a leitura dos ficheiros.");
		    	break;

		    case 'C':
		    	if(flag > 0)
		  			imprime_menu3(faturacao, produtos);
		    	else puts("Faça a leitura dos ficheiros.");
		  		printf("\nPrima qualquer tecla para avançar...");
				if(NULL == leLinha(input, MAX_NAME_FILE, stdin))
					puts("Erro na leitura da tecla.");
				break;		   		

		    case 'D':
		    	if(flag > 0)
		  			imprime_menu4(faturacao, produtos);
		    	else puts("Faça a leitura dos ficheiros.");
				break;

		    case 'E':
		    	if(flag > 0)
		  			imprime_menu5(cfiliais);
		    	else puts("Faça a leitura dos ficheiros.");
				break;

		    case 'F':
		    	if(flag > 0)
		  			imprime_menu6(faturacao, cfiliais, produtos, clientes);
		    	else puts("Faça a leitura dos ficheiros.");
				break;

		    case 'G':
		    	if(flag > 0)
		  			imprime_menu7(cfiliais, clientes);
		    	else puts("Faça a leitura dos ficheiros.");
				break;

			case 'H':
				if(flag > 0)
					imprime_menu8(faturacao);
		    	else puts("Faça a leitura dos ficheiros.");
				printf("\nPrima qualquer tecla para avançar...");
				if(NULL == leLinha(input, MAX_NAME_FILE, stdin))
					puts("Erro na leitura da tecla.");
				break;

			case 'I':
				if(flag > 0)
					imprime_menu9(cfiliais, produtos);
		    	else puts("Faça a leitura dos ficheiros.");
		  		printf("\nPrima qualquer tecla para avançar...");
				if(NULL == leLinha(input, MAX_NAME_FILE, stdin))
					puts("Erro na leitura da tecla.");
				break;

			case 'J':
				if(flag > 0)
					imprime_menu10(cfiliais, clientes);
		    	else puts("Faça a leitura dos ficheiros.");
		  		printf("\nPrima qualquer tecla para avançar...");
				if(NULL == leLinha(input, MAX_NAME_FILE, stdin))
					puts("Erro na leitura da tecla.");
				break;

			case 'K':
				if(flag > 0)
					imprime_menu11(faturacao);
		    	else puts("Faça a leitura dos ficheiros.");
		  		printf("\nPrima qualquer tecla para avançar...");
				if(NULL == leLinha(input, MAX_NAME_FILE, stdin))
					puts("Erro na leitura da tecla.");
				break;

			case 'L':
				if(flag > 0)
					imprime_menu12();
		    	else puts("Faça a leitura dos ficheiros.");
		  		printf("\nPrima qualquer tecla para avançar...");
				if(NULL == leLinha(input, MAX_NAME_FILE, stdin))
					puts("Erro na leitura da tecla.");
				break;

		    case 'Q':
		    	sair = TRUE;
				break;		   		

		   	default :
		   	printf("não entrei em nenhum dos outros\n");
		   	break;

		}
	}

	return 0;
}
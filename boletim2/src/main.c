
#include "headers/cclientes.h"
#include "headers/cfaturacao.h"
#include "headers/cprodutos.h"
#include "headers/globais.h"
#include "headers/leituras.h"
#include "headers/queries.h"
#include "headers/venda.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

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
	puts("[D] 04 - ");
	puts("[E] 05 - ");
	puts("[F] 06 - ");
	puts("[G] 07 - ");
	puts("[H] 08 - ");
	puts("[I] 09 - ");
	puts("[J] 10 - ");
	puts("[K] 11 - ");
	puts("[L] 12 - ");
	puts("[Q] 13 - Sair\n");

}

void imprime_menu1(CFaturacao faturacao, CClientes clientes, CProdutos produtos){

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



 	query1(faturacao, clientes, produtos, fv, fc, fp);

  	printf("\nPrima qualquer tecla para avançar...");
	if(NULL == leLinha(input, MAX_NAME_FILE, stdin))
		puts("Erro na leitura da tecla.");
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

	query2(produtos, input[0]);

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

	printf("\nPrima qualquer tecla para avançar...");
	if(NULL == leLinha(input1, MAX_NAME_FILE, stdin))
		puts("Erro na leitura da tecla.");
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
		puts("Identificador da filial ou G.");
	}

	printf("\nPrima qualquer tecla para avançar...");
	if(NULL == leLinha(input, MAX_NAME_FILE, stdin))
		puts("Erro na leitura da tecla.");

}

int main(){

	
	int i;

	Boolean sair = FALSE;


	CClientes clientes;
	clientes = novo_cclientes();

	CProdutos produtos;
	produtos = novo_cprodutos();

	CFaturacao faturacao;
	faturacao = novo_cfaturacao();

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

		switch(opcao[0]) {

		   	case 'A':
		   		imprime_menu1(faturacao, clientes, produtos);
		      	
		      	break; 
			
			case 'B':
				imprime_menu2(produtos);
		    	break;

		    case 'C':
		  		imprime_menu3(faturacao, produtos);

				break;		   		

		    case 'D':
		  		imprime_menu4(faturacao, produtos);
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
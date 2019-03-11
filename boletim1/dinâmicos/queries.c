#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAXCLIS 20000
#define MAXBUFCLI 10

#define MAXPRODS 200000
#define MAXBUFPROD 10

#define MAXVENDAS 10000008
#define MAXBUFVENDAS 40
#define CAMPOSVENDA 7



struct venda {
	char* codProd;
	char* codCli;
	double precoUnit;
	int quantidade;
	char* tipo;
	int mes;
	int filial;
};

typedef struct venda* Venda;

struct vendas{
	Venda* venda ;
	int primLivre;
	int tam;
};

typedef struct vendas* Vendas;


Vendas vendasValidas;
char** clientesValidos;
char** produtosValidos;



Venda tokenizeLinhaVendaDyn(char* vendaRaw){

	Venda vendaAux = (Venda) malloc(sizeof(struct venda));

	char* token = strtok(vendaRaw, " ");
	vendaAux->codProd = strdup(token);

	token = strtok(NULL," ");
	vendaAux->precoUnit = atof(token);

	token = strtok(NULL," ");
	vendaAux->quantidade = atoi(token);

	token = strtok(NULL," ");
	vendaAux->tipo = strdup(token);

	token = strtok(NULL," ");
	vendaAux->codCli = strdup(token);

	token = strtok(NULL," ");
	vendaAux->mes = atoi(token);

	token = strtok(NULL," ");
	vendaAux->filial = atoi(token);

	return vendaAux;
}

int insereClientesValidos(FILE* fp){
	int i = 0;
	char str[MAXBUFCLI]; //assume-se que os clientes nunca vão ter mais que 15 chars 

	while(fgets(str, MAXBUFCLI, fp)){
		strtok(str,"\r\n");
		clientesValidos = (char**) realloc(clientesValidos, (i+2)*sizeof(char *));
		clientesValidos[i] = strdup(str);
		i++;
	}

	return 1;
}

int insereProdutosValidos(FILE* fp){
	int i = 0;
	char str[MAXBUFPROD]; //assume-se que os produtos nunca vão ter mais que 15 chars

	while(fgets(str, MAXBUFPROD, fp)){
		strtok(str,"\r\n");
		produtosValidos = (char**) realloc(produtosValidos, (i+2)*sizeof(char *));
		produtosValidos[i] = strdup(str);
		i++;
	}

	return 1;
}

int insereVendasValidas(FILE* fp){
	int i = 0;
	char str[MAXBUFVENDAS];
	vendasValidas = (Vendas) malloc(sizeof (struct vendas));

	while(fgets(str, MAXBUFVENDAS, fp)){
		strtok(str, "\n\r");
		vendasValidas->venda = (Venda*) realloc(vendasValidas->venda, (i+2)*sizeof (struct venda));
		vendasValidas->venda[i] = tokenizeLinhaVendaDyn(str);
		i++;
	}

	return 1;
}

void linhaMaisLonga(){
	int i = 0;
	int r = 0;
	int max = 0;
	char str[MAXBUFVENDAS];

	while(vendasValidas->venda[i] != NULL){

		sprintf(str, "%s %f %d %s %s %d %d",
		 	vendasValidas->venda[i]->codProd, 
		 	vendasValidas->venda[i]->precoUnit, 
		 	vendasValidas->venda[i]->quantidade,
			vendasValidas->venda[i]->tipo,  
			vendasValidas->venda[i]->codCli, 
			vendasValidas->venda[i]->mes, 
			vendasValidas->venda[i]->filial);

		r = strlen(str);

		if(r > max) max = r;

		i++;
	}

	printf("Linha mais longa: %d carateres\n", max);

}

char * ultimoCliente(){
	int i;

	for (i = 0; clientesValidos[i] != NULL ; i++);
	
	//printf("Último cliente: %s\n", clientesValidos[i-1]);

	return clientesValidos[i-1];
}

void imprimeVendaValida(Venda venda){
	printf("%s ", venda->codProd);

	printf("%f ", venda->precoUnit);

	printf("%d ", venda->quantidade);

	printf("%s ", venda->tipo);

	printf("%s ", venda->codCli);

	printf("%d ", venda->mes);

	printf("%d", venda->filial);
}

void nrVendasDoCliente(char * str){
	int i, n=0; 

	for(i = 0; vendasValidas->venda[i] != NULL ; i++)
		if(strcmp(vendasValidas->venda[i]->codCli, str) == 0)
			n++;

	printf("Número de compras do cliente %s: %d\n", str, n);
}

void vendasDaFilial(int f){
	int i, n=0;

	for(i = 0; vendasValidas->venda[i] != NULL ; i++)
		if(vendasValidas->venda[i]->filial == f)
			n++;
	
	printf("Número de vendas da filial %d: %d\n", f, n);
}

void nrClientesLetraInicial(char c){
	int i, n=0;

	for(i = 0; clientesValidos[i] != NULL ; i++){
		if( clientesValidos[i][0] == c)
			n++;
	}
	
	printf("Número de clientes com a letra incial '%c': %d\n", c, n);	
}

void faturacaoTotalRegistada(){
	int i;
	double tot = 0;

	for(i = 0; vendasValidas->venda[i] != NULL ; i++)
			tot += vendasValidas->venda[i]->precoUnit*(vendasValidas->venda[i]->quantidade);

	printf("Faturação total registada: %lf\n", tot);
}

int main(){
	FILE* fpc, *fpp, *fpv;

	clock_t start, end;
	double cpu_time_used;
	start = clock();

	fpc = fopen("/home/rrpereira/li3/intocaveis/ClientesValidos.txt","r");
	fpp = fopen("/home/rrpereira/li3/intocaveis/ProdutosValidos.txt","r");
	fpv = fopen("/home/rrpereira/li3/intocaveis/Vendas_1MValidas.txt","r");

	if (fpc == NULL || fpp == NULL || fpv == NULL){
		printf("I/O error\n");
		exit(1);
	}

	insereClientesValidos(fpc);
	insereProdutosValidos(fpp);
	insereVendasValidas(fpv);

	//linhaMaisLonga();
	//produtosEnvolvidos(); ???????????
	//clientesEnvolvidos(); ??????????? 
	//vendasEfetivas(); 	???????????
	//ultimoCliente();
	//nrVendasDoCliente(ultimoCliente());
	//vendasDaFilial(1);
	//vendasDaFilial(2);
	//nrClientesLetraInicial('A');
	//faturacaoTotalRegistada();

	fclose(fpc);
	fclose(fpp);
	fclose(fpv);

	end = clock();
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("CPU Time:%f\n", cpu_time_used );

	return 1;
}
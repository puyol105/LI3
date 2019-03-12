#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

//include GNU

#define MAXVENDAS 10000008
#define MAXBUFVENDAS 40
#define CAMPOSVENDA 7
#define MAXBUFCLI 10
#define MAXBUFPROD 10

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
	Venda* venda;
	int prox;
	int tam;
};

typedef struct vendas* Vendas;

Vendas vendasValidas = NULL;
char** clientesValidos = NULL;
char** produtosValidos = NULL;

/*
int maiorLinha(FILE *fp){
	int r = 0;
	int max = 0;
	char str[MAXBUFVENDAS];

	while(fgets(str, MAXBUFVENDAS, fp) != NULL){
		r = strlen(str);
		if(r > max) max = r;
	}

	printf("READED %d\n", max);

	return max;
}*/

void iniciaEstruturas(){
	vendasValidas = (Vendas) malloc(sizeof (struct vendas));
	vendasValidas->tam = 100000;
	vendasValidas->prox = 0;
	vendasValidas->venda = (Venda*) malloc((vendasValidas->tam)*sizeof (struct venda));
	vendasValidas->venda[0] = NULL;

	clientesValidos = (char**) malloc(50000*sizeof(char *));
	produtosValidos = (char**) malloc(300000*sizeof(char *));
}

int eFilialValida(char s[]){
	for(int i = 0; i < strlen(s); i++)
		if(!isdigit(s[i]))
			return 0;

	if (atoi(s) < 1 || atoi(s) > 3)
		return 0;

	return 1;
}

int eMesValido(char s[]){
	for(int i = 0; i < strlen(s); i++)
		if(!isdigit(s[i]))
			return 0;

	if (atoi(s) < 1 || atoi(s) > 12)
		return 0;

	return 1;
}

int eNrUnisValido(char s[]){
	for(int i = 0; i < strlen(s); i++)
		if(!isdigit(s[i]))
			return 0;

	if(atoi(s) < 1 || atoi(s) > 200)
		return 0;	

	return 1;
}

int ePrecoValido(char s[]){
	int i;

	for(i = 0; i < strlen(s) && s[i]!='.'; i++)
		if(!isdigit(s[i]))
			return 0;

	for(i=i+1; i < strlen(s); i++)
		if(!isdigit(s[i]))
			return 0;

	if(atof(s) > 9999.99 || atof(s) < 0 )
		return 0; 

	return 1;
}

int produtoExiste(char p[]){
	for(int i = 0; produtosValidos[i] != NULL; i++)
		if(strcmp(produtosValidos[i], p) == 0)
			return 1;

	return 0;
}

int clienteExiste(char s[]){
	for(int i = 0; clientesValidos[i] != NULL; i++)
		if(strcmp(clientesValidos[i], s) == 0)
			return 1;

	return 0;
}

//repetida
int eClienteValidoVenda(char s[]){
	
	if(isupper(s[0]) == 0)
		return 0;

	if(strlen(s) != 5)
		return 0;

	if(atoi(s+1) < 1000 || atoi(s+1) > 5000)
		return 0;

	if(clienteExiste(s) == 0)
		return 0; 

	return 1;
}

//repetida
int eProdutoValidoVenda(char p[]){
	if(isupper(p[0]) == 0 || isupper(p[1]) == 0)
		return 0;

	if(strlen(p) != 6)
		return 0;

	if(atoi(p+2) < 1000 || atoi(p+2) > 9999)
		return 0;
	
	if(produtoExiste(p) == 0)
		return 0; 

	return 1;
}

int eVendaValida(char t[]){
	int i = 0, args = 0;
	int preco;
	char s[strlen(t)];
	char * venda;
	char * fields[10] = {NULL};

	strcpy(s, t);

	venda = strtok(s, " \n\r");
	fields[i] = strdup(venda);
	i++; 
	args ++;

	/*coloca num array de strings várias strings correspondente a uma venda
	fragmentada nos seus vários campos*/
	while(fields[i-1] != NULL){
		venda = strtok(NULL, " \n\r");
		if(venda != NULL){
			fields[i] = strdup(venda);
			args++;
		}
		else fields[i] = NULL;
		i++;
	}
	//verifica o número de argumentos de uma venda
	if(args != CAMPOSVENDA )
		return 0;

	if(!eProdutoValidoVenda(fields[0]))
		return 0;

	if(!ePrecoValido(fields[1]))
		return 0;

	if(!eNrUnisValido(fields[2]))
		return 0;

	if(!(strcmp(fields[3], "N") == 0 || strcmp(fields[3], "P") == 0))
		return 0;

	if(!(eClienteValidoVenda(fields[4])))
		return 0;

	if(!(eMesValido(fields[5])))
		return 0;

	if(!(eFilialValida(fields[6])))
		return 0;

	return 1;
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

void insereVendasValidasFicheiro(){
	FILE *fp;

	fp = fopen("/home/rrpereira/li3/intocaveis/Vendas_1MValidas.txt","w+");

	for (int i = 0; vendasValidas->venda[i] != NULL; i++){

		fprintf(fp, "%s ", vendasValidas->venda[i]->codProd);

		fprintf(fp, "%f ", vendasValidas->venda[i]->precoUnit);

		fprintf(fp, "%d ", vendasValidas->venda[i]->quantidade);

		fprintf(fp, "%s ", vendasValidas->venda[i]->tipo);

		fprintf(fp, "%s ", vendasValidas->venda[i]->codCli);

		fprintf(fp, "%d ", vendasValidas->venda[i]->mes);

		fprintf(fp, "%d\n", vendasValidas->venda[i]->filial);
	}

	fclose(fp);
}


void imprimeVendasValidas(){
	for (int i = 0; vendasValidas->venda[i] != NULL; i++){
		imprimeVendaValida(vendasValidas->venda[i]);
		printf("\n");
	}
}

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

int insereVendasValidas(FILE* fp){
	int i = 0;
	char str[MAXBUFVENDAS];

	while(fgets(str, MAXBUFVENDAS, fp)){
		strtok(str, "\n\r");

		if(eVendaValida(str)){
			if(i+1 >= vendasValidas->tam){
				vendasValidas->venda = (Venda*) realloc(vendasValidas->venda, 2*(i+2)*sizeof (struct venda));
				vendasValidas->tam *= 2; 
			}
			vendasValidas->venda[i] = tokenizeLinhaVendaDyn(str);
			vendasValidas->venda[i+1] = NULL;
			vendasValidas->prox = ++i;
		}
		//else printf("VENDA INVÁLIDA %s \n", str);
	}

	return 1;
}

int insereClientesValidos(){
	int i = 0;
	char str[MAXBUFCLI]; //assume-se que os clientes nunca vão ter mais que 15 chars 

	FILE*  fp = fopen("/home/rrpereira/li3/intocaveis/ClientesValidos.txt","r");

	while(fgets(str, MAXBUFCLI, fp)){
		strtok(str,"\n\r");
		//clientesValidos = (char**) realloc(clientesValidos, (i+2)*sizeof(char *));
		clientesValidos[i] = strdup(str);
		clientesValidos[i+1] = NULL;
		i++;
	}

	fclose(fp);

	return 1;
}

int insereProdutosValidos(){
	int i = 0;
	char str[MAXBUFPROD]; //assume-se que os produtos nunca vão ter mais que 15 chars

	FILE*  fp = fopen("/home/rrpereira/li3/intocaveis/ProdutosValidos.txt","r");

	while(fgets(str, MAXBUFPROD, fp)){
		strtok(str, "\n\r");
		//produtosValidos = (char**) realloc(produtosValidos, (i+2)*sizeof(char *));
		produtosValidos[i] = strdup(str);
		produtosValidos[i+1] = NULL;
		i++;
	}

	fclose(fp);

	return 1;
}

int main(){

	FILE* fp;

	clock_t start, end;
	double cpu_time_used;
	start = clock();

	//fp = fopen("/home/rrpereira/li3/intocaveis/Vendas_1M.txt","r");
	fp = fopen("/home/rrpereira/li3/intocaveis/Vendas_1M.txt","r");

	if (fp == NULL){
		printf("I/O error\n");
		exit(1);
	}

	iniciaEstruturas();

	insereClientesValidos();

	insereProdutosValidos();

	insereVendasValidas(fp);

	//imprimeVendasValidas();

	insereVendasValidasFicheiro();

	fclose(fp);

	end = clock();
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("CPU Time:%f\n", cpu_time_used );

	return 1;
}
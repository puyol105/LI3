#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAXPRODS 200000
#define MAXBUFPROD 10

char* produtos[MAXPRODS];
char* produtosValidos[MAXPRODS];

int maiorLinha(FILE *fp){
	int r = 0;
	int max = 0;
	char str[MAXBUFPROD];

	while(fgets(str, MAXBUFPROD, fp) != NULL){
		r = strlen(str);
		if(r > max) max = r;
	}

	printf("READED %d\n", max);

	return max;
}

int eProdutosValido(char p[]){
	if(isupper(p[0]) == 0 || isupper(p[1]) == 0)
		return 0;

	if(strlen(p) != 6)
		return 0;

	if(atoi(p+2) < 1000 || atoi(p+2) > 9999)
		return 0;

	return 1;
}

void imprimeProdutosValidos(){
	for (int i = 0; produtosValidos[i]; i++){
		printf("%s\n", produtosValidos[i]);
	}
}

int insereProdutosValidos(){
	int i, j;
	char str[MAXBUFPROD]; //assume-se que os produtos nunca vão ter mais que 15 chars

	for(i=0, j=0; produtos[i]!=NULL; i++){
		if(eProdutosValido(produtos[i])){
			produtosValidos[j] = strdup(produtos[i]);
			j++;
		}
		else printf("PRODUTO INVÁLIDO %d -> %s\n", i, produtos[i]);
	}

	return 1;
}

int insereProdutos(FILE *fp){
	char str[MAXBUFPROD]; //assume-se que os produtos nunca vão ter mais que 15 chars
	char* prod;

	int index = 0;
	while(fgets(str, MAXBUFPROD, fp)){
		prod = strtok(str, "\n\r");
		produtos[index] = strdup(prod);
		index ++;
	}

	return 1;
}

void insereProdutosValidosFicheiro(){
	FILE *fp;

	fp = fopen("/home/rrpereira/li3/intocaveis/ProdutosValidos.txt","w+");

	for(int i = 0; produtosValidos[i] != NULL; i++){
		fprintf(fp, "%s\n", produtosValidos[i]);
	}

	fclose(fp);
}

int main(){
	FILE *fp;

	clock_t start, end;
	double cpu_time_used;
	start = clock();

	//fp = fopen("/home/rrpereira/li3/2016/Produtos.txt","r");
	fp = fopen("/home/rrpereira/li3/intocaveis/Produtos.txt","r");
	//fp = fopen("ProdutosTeste.txt","r");

	if (fp == NULL){
		printf("I/O error\n");
		exit(1);
	}

	insereProdutos(fp);

	insereProdutosValidos();

	//imprimeProdutosValidos();

	insereProdutosValidosFicheiro();

	fclose(fp);

	end = clock();
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("CPU Time:%f\n", cpu_time_used );

	return 1;
}
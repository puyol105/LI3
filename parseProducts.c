#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXPRODS 200000
#define MAXBUFPROD 10

char* produtos[MAXPRODS];
char* produtosValidos[MAXPRODS];

int maiorLinha(FILE *fp){
	int r = 0;
	int max = 0;
	char str[1024];

	while(fgets(str, 1000, fp) != NULL){
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
	char str[15]; //assume-se que os produtos nunca vão ter mais que 15 chars

	for(i=0, j=0; produtos[i]!=NULL; i++){
		if(eProdutosValido(produtos[i])){
			produtosValidos[j] = (char *)malloc((strlen(str)+1)*sizeof(char));
			strcpy(produtosValidos[j], produtos[i]);
			j++;
		}
		else printf("ONE INVALID PRODUCT %d -> %s tam:%ld\n", i, produtos[i], strlen(produtos[i]));
	}

	return 1;
}

int insereProdutos(FILE *fp){
	char str[10]; //assume-se que os produtos nunca vão ter mais que 15 chars
	char* prod;

	int index = 0;
	while(fgets(str, MAXBUFPROD, fp)){
		prod = strtok(str, "\n\r");
		produtos[index] = strdup(prod);
		index ++;
	}

	return 1;
}

int main(){
	FILE *fp;

	fp = fopen("ProdutosTeste.txt","r");

	if (fp == NULL){
		printf("I/O error\n");
		exit(1);
	}

	insereProdutos(fp);

	insereProdutosValidos();

	imprimeProdutosValidos();

	return 1;
}
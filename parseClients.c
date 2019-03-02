#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXCLIS 20000
#define MAXBUFCLI 10

char* clientes[MAXCLIS];
char* clientesValidos[MAXCLIS];

int maiorLinha(FILE *fp){
	int r = 0;
	int max = 0;
	char str[MAXBUFCLI];

	while(fgets(str, MAXBUFCLI, fp) != NULL){
		r = strlen(str);
		if(r > max) max = r;
	}

	printf("READED %d\n", max);

	return max;
}

int eClienteValido(char c[]){
	if(isupper(c[0]) == 0)
		return 0;

	if(strlen(c) != 5)
		return 0;

	if(atoi(c+1) < 1000 || atoi(c+1) > 5000)
		return 0;

	return 1;
}

void imprimeClientesValidos(){
	for (int i = 0; clientesValidos[i]; i++){
		printf("%s\n", clientesValidos[i]);
	}
}

int insereClientesValidos(){
	int i, j;
	char str[MAXBUFCLI]; //assume-se que os clientes nunca vão ter mais que 15 chars

	for(i=0, j=0; clientes[i] != NULL; i++){
		if(eClienteValido(clientes[i])){
			clientesValidos[j] = strdup(clientes[i]);
			j++;
		}
		else printf("CLIENTE INVÁLIDO: %d -> %s\n", i, clientes[i]);
	}

	return 1;
}

int insereClientes(FILE *fp){
	char str[MAXBUFCLI]; //assume-se que os clientes nunca vão ter mais que 15 chars
	char* prod;

	int index = 0;
	while(fgets(str, MAXBUFCLI, fp)){
		prod = strtok(str, "\n\r");
		clientes[index] = strdup(prod);
		index ++;
	}

	return 1;
}

int main(){
	FILE *fp;

	//fp = fopen("/home/rrpereira/li3/2016/Clientes.txt","r");
	//fp = fopen("/home/rrpereira/li3/intocaveis/Clientes.txt","r");
	fp = fopen("ClientesTeste.txt","r");


	if (fp == NULL){
		printf("I/O error\n");
		exit(1);
	}

	insereClientes(fp);

	insereClientesValidos();

	//imprimeClientesValidos();

	return 1;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAXCLIS 20000
#define MAXBUFCLI 10

char** clientesValidos;

int maiorLinha(){
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
	for (int i = 0; clientesValidos[i] != NULL ; i++){
		printf("%s\n", clientesValidos[i]);
	}
}

int insereClientesValidos(FILE* fp){
	int i = 0;
	char str[MAXBUFCLI]; //assume-se que os clientes nunca vão ter mais que 15 chars 

	while(fgets(str, MAXBUFCLI, fp)){
		if(eClienteValido(strtok(str,"\r\n"))){
			clientesValidos = (char**) realloc(clientesValidos, (i+2)*sizeof(char *));
			clientesValidos[i] = strdup(str);
			i++;
		}
		else printf("CLIENTE INVÁLIDO: %d -> %s\n", i, str);
	}

	return 1;
}


void insereClientesValidosFicheiro(){
	FILE *fp;

	fp = fopen("/home/rrpereira/li3/intocaveis/ClientesValidos.txt","w+");

	for(int i = 0; clientesValidos[i] != NULL; i++){
		fprintf(fp, "%s\n", clientesValidos[i]);
	}

	fclose(fp);
}

int main(){
	FILE *fp;

	clock_t start, end;
	double cpu_time_used;
	start = clock();

	//fp = fopen("/home/rrpereira/li3/2016/Clientes.txt","r");
	fp = fopen("/home/rrpereira/li3/intocaveis/Clientes.txt","r");
	//fp = fopen("ClientesTeste.txt","r");


	if (fp == NULL){
		printf("I/O error\n");
		exit(1);
	}

	insereClientesValidos(fp);

	//imprimeClientesValidos();

	insereClientesValidosFicheiro();

	fclose(fp);

	end = clock();
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("CPU Time:%f\n", cpu_time_used );

	return 1;
}
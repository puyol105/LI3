#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXPRODS 200000
#define MAXCLIS 20000

int longestLine(FILE *fpv){
	int r = 0;
	int max = 0;
	char str[1024];

	while(fgets(str, 1000, fpv) != NULL){
		r = strlen(str);
		if(r > max) max = r;
	}

	printf("READED %d\n", max);

	return max;
}

int isValidClient(char c[]){
	if(isupper(c[0]) == 0)
		return 0;

	if(strlen(c) != 6)
		return 0;

	if(atoi(c+1) < 1000 || atoi(c+1) > 5000)
		return 0;

	return 1;
}

int isValidProduct(char p[]){
	if(isupper(p[0]) == 0 || isupper(p[1]) == 0)
		return 0;

	if(strlen(p) != 7)
		return 0;

	if(atoi(p+2) < 1000 || atoi(p+2) > 9999)
		return 0;

	return 1;
}

void printValidClients(char *clients[]){
	for (int i = 0; clients[i]; i++){
		printf("%s\n", clients[i]);
	}
}

int insertValidClients(char *clients[], char *validClients[]){
	int i, j;
	char str[15]; //assume-se que os produtos nunca vão ter mais que 15 chars

	for(i=0, j=0; clients[i]!=NULL; i++){
		if(isValidClient(clients[i])){
			validClients[j] = (char *)malloc((strlen(str)+1)*sizeof(char));
			strcpy(validClients[j], clients[i]);
			j++;
		}
		else printf("ONE INVALID CLIENT\n");
	}

	return 1;
}

int insertClients(FILE *fpc, char *clients[]){
	int i = 0;
	char str[15]; //assume-se que os produtos nunca vão ter mais que 15 chars

	while(fgets(str, 15, fpc)){
		clients[i] = (char *)malloc((strlen(str)+1)*sizeof(char));
		strtok(str, "\n");
		strcpy(clients[i], str);
		i++;
	}

	return 1;
}

int parseClients(FILE *fpc){
	char *clients[MAXCLIS] = {NULL};
	char *validClients[MAXCLIS] = {NULL};

	insertClients(fpc, clients);

	insertValidClients(clients, validClients);

	//printValidClients(validClients);

	return 1;
}

int main(){

	FILE *fpc;
	
	fpc = fopen("ClientesTeste.txt","r");

	if (!fpc){
		printf("I/O error");
		return 0;
	}

	//ll = longestLine(fpv);
	//validProducts(ll);
	//insertProducts(fpp);

	parseClients(fpc);

	return 1;
}
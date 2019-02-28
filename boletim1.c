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

int isValidSale(char s[]){
	int i = 0, args = 0;
	int preco;
	char * fields[10] = {NULL};

	fields[i] = strtok(s, " ");
	i++; 
	args ++;

	/*coloca num array de strings várias strings correspondente a uma venda
	fragmentada nos seus vários campos*/
	while(fields[i-1] != NULL){
		fields[i] = strtok(NULL, " ");
		i++;
		args++;
	}

	//verifica o número de argumentos de uma venda
	//if(args > 8)
	//	return 0;
	//printf("verifica: %sola\n", fields[0]);
	printf("%s tam:%ld\n", fields[0], strlen(fields[0]));
	if(isValidProduct(fields[0]) == 0)
		return 0;

	//if(isValidPrice(fields[1]) == 0)
	//	return 0;

	//return isValid

	//return isValidClient(fields[4]);
	
	return 1;
}

void printValidClients(char *clients[]){
	for (int i = 0; clients[i]; i++){
		printf("%s\n", clients[i]);
	}
}

void printValidProducts(char *products[]){
	for (int i = 0; products[i]; i++){
		printf("%s\n", products[i]);
	}
}

void printValidSales(char *sales[]){
	for (int i = 0; sales[i]; i++){
		printf("%s\n", sales[i]);
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

int insertValidProducts(char *products[], char *validProducts[]){
	int i, j;
	char str[15]; //assume-se que os produtos nunca vão ter mais que 15 chars

	for(i=0, j=0; products[i]!=NULL; i++){
		if(isValidProduct(products[i])){
			validProducts[j] = (char *)malloc((strlen(str)+1)*sizeof(char));
			strcpy(validProducts[j], products[i]);
			j++;
		}
		else printf("ONE INVALID PRODUCT %d -> %s tam:%ld\n", i, products[i], strlen(products[i]));
	}

	return 1;
}

int insertValidSales(char *sales[], char *validSales[]){
	int i, j;
	char str[40];

	for(i=0, j=0; sales[i]!=NULL; i++){
		if(isValidSale(sales[i])){
		//if(1){
			validSales[j] = (char *)malloc((strlen(str)+1)*sizeof(char));
			strcpy(validSales[j], sales[i]);
			j++;
		}
		else printf("ONE INVALID SALES %d -> %s tam:%ld\n", i, sales[i], strlen(sales[i]));
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

int insertProducts(FILE *fpp, char *products[]){
	int i = 0;
	char str[15]; //assume-se que os produtos nunca vão ter mais que 15 chars

	while(fgets(str, 1024, fpp)){
		products[i] = (char *)malloc((strlen(str)+1)*sizeof(char));
		strcpy(str, strtok(str, "\n "));
		printf("AFTER STRTOK: %s tam:%ld\n", str, strlen(str));
		strcpy(products[i], str);
		i++;
	}

	return 1;
}

int insertSales(FILE *fpv, char *sales[]){
	int i = 0;
	char str[40];

	while(fgets(str, 1024, fpv)){
		sales[i] = (char *)malloc((strlen(str)+1)*sizeof(char));
		strtok(str, "\n");
		strcpy(sales[i], str);
		i++;
		printf("%s\n", sales[i-1]);
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

int parseProducts(FILE *fpp){
	char *products[MAXPRODS] = {NULL};
	char *validProducts[MAXPRODS] = {NULL};
	
	insertProducts(fpp, products);

	insertValidProducts(products, validProducts);

	//printValidProducts(validProducts);

	return 1;
}

int parseSales(FILE *fpv){
	//char *sales[1000000] = {NULL};
	//char *validSales[1000000] = {NULL};
	char *sales[100] = {NULL};
	char *validSales[100] = {NULL};


	insertSales(fpv, sales);

	insertValidSales(sales, validSales);

	//printValidSales(validSales);

	return 1;
}

int main(){
	int ll = 0;

	FILE *fpc;
	FILE *fpp;
	FILE *fpv;

	fpc = fopen("ClientesTeste.txt","r");
	fpp = fopen("ProdutosTeste.txt","r");
	fpv = fopen("Vendas_1MTeste.txt","r");

	if (!fpc | !fpp | !fpv ){
		printf("I/O error");
		return 0;
	}

	//ll = longestLine(fpv);
	//validProducts(ll);
	//insertProducts(fpp);

	parseClients(fpc);

	parseProducts(fpp);

	parseSales(fpv);

	return 1;
}
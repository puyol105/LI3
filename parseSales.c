#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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

void printValidSales(char *sales[]){
	for (int i = 0; sales[i]; i++){
		printf("%s\n", sales[i]);
	}
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

	FILE *fpv;

	fpv = fopen("Vendas_1MTeste.txt","r");

	if ( !fpv ){
		printf("I/O error");
		return 0;
	}

	//ll = longestLine(fpv);
	//validProducts(ll);
	//insertProducts(fpp);

	parseSales(fpv);

	return 1;
}
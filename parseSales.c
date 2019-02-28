#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXVENDAS 1000000
#define MAXBUFVENDAS 40
#define MAXPARAMVENDAS 

char* vendas[MAXVENDAS];
char* vendasValidas[MAXVENDAS];

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
}

int eNrUnisValido(char n[]){

}

int ePrecoValido(char s[]){
	int i;
	for(i = 0; i < strlen(s) && s[i]!='.'; i++){
		printf("carater: %c\n",s[i]);
		if(!isdigit(s[i]))
			return 0;
	}

	for(i=i+1; i < strlen(s) != '\0'; i++){
		if(!isdigit(s[i]))
			return 0;
	}	

	if(atof(s) > 9999.99)
		return 0; 

	return 1;
}

//repetida
int eClienteValido(char s[]){
	if(isupper(s[0]) == 0)
		return 0;

	if(strlen(s) != 5)
		return 0;

	if(atoi(s+1) < 1000 || atoi(s+1) > 5000)
		return 0;

	return 1;
}

//repetida
int eProdutosValido(char p[]){
	if(isupper(p[0]) == 0 || isupper(p[1]) == 0)
		return 0;

	if(strlen(p) != 6)
		return 0;

	if(atoi(p+2) < 1000 || atoi(p+2) > 9999)
		return 0;

	return 1;
}

int eVendaValida(char s[]){
	int i = 0, args = 0;
	int preco;
	char * venda;
	char * fields[10] = {NULL};

	venda = strtok(s, " \n\r");
	fields[i] = strdup(venda);
	i++; 
	args ++;

	/*coloca num array de strings várias strings correspondente a uma venda
	fragmentada nos seus vários campos*/
	while(fields[i-1] != NULL){
		venda = strtok(NULL, " \n\r");
		if(venda != NULL)
			fields[i] = strdup(venda);
		else fields[i] = NULL;
		i++;
		args++;
	}
	//verifica o número de argumentos de uma venda
	//if(args > 8)
	//	return 0;
	//printf("verifica: %sola\n", fields[0]);

	if(!eProdutosValido(fields[0]))
		return 0;


	if(!ePrecoValido(fields[1]))
		return 0;

	//if(!eNrUnisValido(fields[2])==0)

	//return isValid

	//return isValidClient(fields[4]);
	
	return 1;
}

void imprimeVendasValidas(){
	for (int i = 0; vendasValidas[i]; i++){
		printf("%s\n", vendasValidas[i]);
	}
}

int insereVendasValidas(){
	int i, j;
	char str[MAXBUFVENDAS];

	for(i=0, j=0; vendas[i]!=NULL; i++){
		if(eVendaValida(vendas[i])){
			vendasValidas[j] = (char *)malloc((strlen(str)+1)*sizeof(char));
			strcpy(vendasValidas[j], vendas[i]);
			j++;
		}
		else printf("ONE INVALID SALE %d -> %s tam:%ld\n", i, vendas[i], strlen(vendas[i]));
	}

	return 1;
}

int insereVendas(FILE *fpv){
	int i = 0;
	char str[MAXBUFVENDAS];

	while(fgets(str, MAXBUFVENDAS, fpv)){
		vendas[i] = (char *)malloc((strlen(str)+1)*sizeof(char));
		strtok(str, "\n\r");
		strcpy(vendas[i], str);
		i++;
		printf("%s\n", vendas[i-1]);
	}

	return 1;
}



int main(){

	FILE *fpv;

	fpv = fopen("Vendas_1MTeste.txt","r");

	if ( !fpv ){
		printf("I/O error");
		return 0;
	}

	insereVendas(fpv);

	insereVendasValidas();

	//imprimeVendasValidas();

	return 1;
}
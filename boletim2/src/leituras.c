#include "headers/leituras.h"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void le_ficheiros_dados(CClientes clientes){
	char str[MAXBUFCLI];
	char *buf = NULL;
	char *buf1 = NULL;
	
	/*FILE *fp = fopen("../teste/Clientes1.txt","r"); se este ficheiro estiver junto à makefile*/
	FILE *fp = fopen("../intocaveis/Clientes.txt","r"); /*se este ficheiro estiver junto à makefile*/

	while(fgets(str, MAXBUFCLI, fp)){
		strtok(str,"\r\n");

		buf = (char *) malloc((strlen(str))*sizeof(char));
		strcpy(buf, str);
		
		buf1 = (char *) malloc((strlen(str))*sizeof(char));
		strcpy(buf1, str);
		
		insere_cclientes(clientes, buf, buf1);
	}

	fclose(fp);



	
}
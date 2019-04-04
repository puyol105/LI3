#include "headers/lstrings.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>


#define FLUSH_STDIN() { int c; while((c = getchar()) != EOF && (c != '\r' || c != '\n')); }

struct lstrings{
	String *lista;
	int nresultados;
	int proximo;
	int tamanho;
};

LStrings novo_lstrings(){
	LStrings lstrings = (LStrings) malloc(sizeof(struct lstrings));
	lstrings->lista = (String*) malloc(INIT_TAMANHO * sizeof(char*));
	lstrings->tamanho = INIT_TAMANHO;
	lstrings->proximo = 0;
	lstrings->nresultados = LINE_P_PAG;
	return lstrings;
} 

int get_lstrings_tamanho(LStrings lstrings){
	return lstrings->tamanho;
}

int get_lstrings_proximo(LStrings lstrings){
	return lstrings->proximo;
}

int get_lstrings_nresultados(LStrings lstrings){
	return lstrings->nresultados;
}

String leLinha1(char buffer[], int tamanho, FILE* stream){	
	char* linha = fgets(buffer, tamanho, stream);
	
	if(linha != NULL){
		int i = strcspn(linha, "\r\n");	

		if(linha[i] == '\0') /* ficaram carateres no stdin */
			FLUSH_STDIN()
		else
			linha[i] = '\0'; /* remove o carater de newline, se este existir */
	}
	return linha;
}

LStrings insere_lstrings(LStrings lstrings, String string){
	String nova = NULL;

	if(lstrings->tamanho == lstrings->proximo){
		lstrings->lista = (String*) realloc(lstrings->lista, 2 * lstrings->tamanho * sizeof(char));
		lstrings->tamanho = 2 * lstrings->tamanho;
	}

	nova = (String) malloc((strlen(string)+1) * sizeof(char));
	strcpy(nova, string);
	lstrings->lista[lstrings->proximo] = nova;
	lstrings->proximo++;

	return lstrings;
}

Boolean imprime_lstrings(LStrings lstrings, int n){
	int r, pag, i, j, k=0;
	String input = (String) malloc(MAXOP * sizeof(char));
	Boolean flag = TRUE;

	pag = n / LINE_P_PAG + 1;

	for(i = 0; i < lstrings->proximo && flag == TRUE; i += lstrings->nresultados){
		for(j = i; j < i + lstrings->nresultados && j < lstrings->proximo; j++){
			puts(lstrings->lista[j]);
		}

		printf("\n[1]PROX   [2]ANT   [3]PRIM    [4]ULT    [5]SAIR    (PÁGINA %d de %d)\n", k, pag);
		printf("Nº produtos: %d\n", n);

		input = leLinha1(input, MAX_NAME_FILE, stdin);

		switch(input[0]) {

		   	case '1':
		   		k++;
		   		break; 
			
			case '2':
				if((i - 2*lstrings->nresultados) >=0){		
					i -= 2*lstrings->nresultados;
		    		k--;
		    	}
		    	else
		    		i -= lstrings->nresultados;
		    	break;

	    	case '3':
	    		i = 0;
	    		k = 0;
		    	break;

	    	case '4':
	    		i = lstrings->nresultados * (pag-2);
	    		k = pag;
		    	break;

		    case '5':
		    	flag = FALSE;
		    	break;	

		   	default :
		   	printf("não entrei em nenhum dos outros\n");
		   	break;
		}

		r = system(CLEAR);
		if(r)
			exit(EXIT_FAILURE);

	}


	return TRUE;
}
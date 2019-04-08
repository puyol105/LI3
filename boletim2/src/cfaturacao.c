#include "headers/cfaturacao.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>


struct cfaturacao{
	int nprodutos;
	AVL meses[NR_MESES];	
};

struct registos{
	Registo *array;
	int proximo;
	int tamanho;
};

struct registo{
	int quantidade;
	float preco;
};



typedef struct fatregtotal{
	int nregistos;
	float faturado;
}*FatRegTotal;


CFaturacao novo_cfaturacao(){
	int i;
	CFaturacao cfaturacao = (CFaturacao) malloc(sizeof(struct cfaturacao));
	cfaturacao->nprodutos = 0;
	for(i = 0; i < NR_MESES; i++)
		cfaturacao->meses[i] = nova_avl();
	return cfaturacao;
}

Registos novo_registos(){
	int i;
	Registos registos = (Registos) malloc(sizeof(struct registos));
	registos->array =  (Registo*) malloc(TAMARRAY * sizeof(struct registo));
	for(i = 0; i < TAMARRAY; i++)
		registos->array[i] = novo_registo();
	registos->tamanho = TAMARRAY;
	registos->proximo = 0;
	return registos;
}

FTSProduto novo_ftsproduto(){
	int i, j;
	/*[nr_promo][nr_filial]*/
	FTSProduto ftsproduto = (FTSProduto) malloc(NR_PROMOS * sizeof(Registos*));
	for(i = 0; i < NR_PROMOS; i++)
		ftsproduto[i] = (Registos*) malloc(NR_FILIAIS * sizeof(Registos));
	for(i = 0; i < NR_PROMOS; i++)
		for(j = 0; j < NR_FILIAIS; j++)
			ftsproduto[i][j] = NULL;
	return ftsproduto;

	/*
	TODO: CHECK THIS 
	FTSProduto ftsproduto = (FTSProduto) malloc(NR_PROMOS * NR_FILIAIS * sizeof(Registos));
	return ftsproduto;
	*/

}

Registo novo_registo(){
	Registo registo = (Registo) malloc(sizeof(struct registo));
	registo->quantidade = 0;
	registo->preco = 0;
	return registo;
}

Registo cria_registo(Quantidade quantidade, Preco preco){
	Registo registo = novo_registo();
	registo->quantidade = quantidade;
	registo->preco = preco;
	return registo;
}

Registos insere_registos(Registos registos, Registo registo){
	if(registos->tamanho == registos->proximo){
		registos->array = (Registo*) realloc(registos->array, 2 * registos->tamanho * sizeof(struct registo));
		registos->tamanho = 2 * registos->tamanho;
	}	
	registos->array[registos->proximo] = registo;
	registos->proximo++;
	return registos;
}

int get_nprodutos_cfaturacao(CFaturacao cfaturacao){
	return cfaturacao->nprodutos;
}

void free_registos(Registos registos){
	int i;
	for(i = 0; i < registos->proximo; i++)
		free_registo(registos->array[i]);
	free(registos->array);
	free(registos);
}

void free_registo(Registo registo){
	free(registo);
}

void insere_registoProduto_avl(CFaturacao faturacao, Venda venda){
	int i;
	Filial filial = get_filial_venda(venda);
	Mes mes = get_mes_venda(venda);
	Promo promo = get_promo_venda(venda);
	Quantidade quantidade = get_quantidade_venda(venda);
	Preco preco = get_preco_venda(venda);
	String str = get_produto_venda(venda);
	String produto = (char *) malloc((strlen(str) + 1)*sizeof(char));
	strcpy(produto, str);

	FTSProduto aux, fproduto = NULL;
	Registos registos = NULL;
	Registo registo = cria_registo(quantidade, preco);

 	for(i = 0; i < NR_MESES; i++){
 		if (NULL != procura_valor_avl(faturacao->meses[i], produto))
 			break;
 	}
 	
 	if(i == NR_MESES) faturacao->nprodutos++;

	if(NULL == (aux = procura_valor_avl(faturacao->meses[mes-1], produto))){
		fproduto = novo_ftsproduto();
		registos = novo_registos();
		registos = insere_registos(registos, registo);
		fproduto[promo][filial-1] = registos;
		insere_avl(faturacao->meses[mes-1], produto, fproduto);
	}
	else{
		if(NULL == aux[promo][filial-1]){ 
			registos = novo_registos();
			registos = insere_registos(registos, registo);
			aux[promo][filial-1] = registos;
		}
		else if(NULL != aux[promo][filial-1]){
			registos = insere_registos(aux[promo][filial-1], registo);
		}
	}


}

void imprime_cfaturacao_avls(CFaturacao faturacao){
	int i;
	for(i = 0; i < NR_MESES; i++)
		imprime_avl(faturacao->meses[i]);
}

int get_nregistos_ftsproduto(CFaturacao faturacao, Mes mes, String produto, Filial filial, Promo promo){
	int r = 0;

	FTSProduto ftsproduto = procura_valor_avl(faturacao->meses[mes-1], produto);

	if(ftsproduto == NULL)
		r = 0;
	else if (ftsproduto[promo][filial-1] == NULL)
		r = 0;
	else if (ftsproduto[promo][filial-1] != NULL)
		r = ftsproduto[promo][filial-1]->proximo; 	

	return r;

}

float get_faturado_ftsproduto(CFaturacao faturacao, Mes mes, String produto, Filial filial, Promo promo){
	int i; 
	float r = 0;

	FTSProduto ftsproduto = procura_valor_avl(faturacao->meses[mes-1], produto);

	if(ftsproduto == NULL)
		r = 0;
	else if (ftsproduto[promo][filial-1] == NULL)
		r = 0;
	else if (ftsproduto[promo][filial-1] != NULL){
		for(i = 0; i < ftsproduto[promo][filial-1]->proximo; i++)
			r = (float) ftsproduto[promo][filial-1]->array[i]->preco * ((float) ftsproduto[promo][filial-1]->array[i]->quantidade);		  	
	}

	return r;

}

AVL get_mes_avl(CFaturacao faturacao, int x){
	return faturacao->meses[x];
}


Boolean preenchido_filial_promo(FTSProduto ftsproduto, int i, int j){
	/*i -> promos; j -> filial*/
	if(ftsproduto[i][j] != NULL)
		return TRUE;
	else 
		return FALSE;
}


void get_totreg_totfat_meses(CFaturacao cfaturacao, int mesi, int mesf, int *totreg, float *totfat){
	FatRegTotal frt = (FatRegTotal) malloc(sizeof(struct fatregtotal));
	frt->nregistos = 0;
	frt->faturado = 0000000000000000.0000000000;

	for(; mesi<=mesf; mesi++)
		get_totreg_totfat_mes(cfaturacao->meses[mesi], frt);
	
	*totreg = frt->nregistos;
	*totfat = frt->faturado;

}
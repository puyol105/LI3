#include "headers/cfiliais.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct cfiliais{
	int nclientes;
	AVL filiais[NR_FILIAIS];	
};

struct qtprod{
	Quantidade quantidade;
};

typedef struct inteiro{
	int i;
}*Inteiro;

CFiliais novo_cfiliais(){
	int i;
	CFiliais cfiliais = (CFiliais) malloc(sizeof(struct cfiliais));
	cfiliais->nclientes = 0;
	for(i = 0; i<NR_FILIAIS; i++)
		cfiliais->filiais[i] = nova_avl();
	return cfiliais;
}

ProdsCliente novo_prodscliente(){
	int i, j;
	ProdsCliente prodscliente = (ProdsCliente) malloc(NR_PROMOS * sizeof(AVL*));
	for(i = 0; i < NR_PROMOS; i++)
		prodscliente[i] = (AVL*) malloc(NR_MESES * sizeof(AVL));
	for(i = 0; i < NR_PROMOS; i++)
		for(j = 0; j < NR_MESES; j++)
			prodscliente[i][j] = NULL;
	return prodscliente;
}

QTProd novo_qtprod(){
	QTProd qtprod = (QTProd) malloc(sizeof(struct qtprod));
	qtprod->quantidade = 0;
	return qtprod;
}

QTProd cria_qtprod(Quantidade quantidade){
	QTProd qtprod = novo_qtprod();
	qtprod->quantidade = quantidade;
	return qtprod;
}

void insere_registoCliente_avl(CFiliais cfiliais, Venda venda){
	int i;
	ProdsCliente prodscliente = NULL, aux = NULL;
	QTProd marc = NULL, qtprod = NULL;

	Filial filial = get_filial_venda(venda);
	Mes mes = get_mes_venda(venda);
	Promo promo = get_promo_venda(venda);
	Quantidade quantidade = get_quantidade_venda(venda);
	
	String str1 = get_cliente_venda(venda);
	String cliente = (String) malloc((strlen(str1) + 1)*sizeof(char));
	strcpy(cliente, str1);
	
	String str2 = get_produto_venda(venda);
	String produto = (String) malloc((strlen(str2) + 1)*sizeof(char));
	strcpy(produto, str2);

	for(i = 0; i < NR_FILIAIS; i++){
 		if (NULL != procura_valor_avl(cfiliais->filiais[i], cliente))
 			break;
 	}
 	
 	if(i == NR_FILIAIS) cfiliais->nclientes++;	

 	if(NULL == (aux = procura_valor_avl(cfiliais->filiais[filial-1], cliente))){
		prodscliente = novo_prodscliente();
		qtprod = cria_qtprod(quantidade);
		prodscliente[promo][mes-1] = nova_avl();
		insere_avl(prodscliente[promo][mes-1], produto, qtprod);
		insere_avl(cfiliais->filiais[filial-1], cliente, prodscliente);
	}	
	else{
		if(NULL == aux[promo][mes-1]){
			qtprod = cria_qtprod(quantidade);
			aux[promo][mes-1] = nova_avl();
			insere_avl(aux[promo][mes-1], produto, qtprod);
		}
		else if(NULL == (marc = procura_valor_avl(aux[promo][mes-1], produto))){
			qtprod = cria_qtprod(quantidade);
			insere_avl(aux[promo][mes-1], produto, qtprod);
		}
		else{
			marc->quantidade += quantidade;
		}
	}

}

int get_quantidade_comprada_cliente(CFiliais cfiliais, String cliente, Filial j, Mes i){
	int r = 0;
	ProdsCliente prodscliente = NULL; 
	Inteiro inteiro = (Inteiro) malloc(sizeof(struct inteiro));
	inteiro->i = 0;

	if(NULL !=(prodscliente = procura_valor_avl(cfiliais->filiais[j], cliente))){
		if(NULL != prodscliente[0][i]){
			soma_qtsprods_cliente(prodscliente[0][i], inteiro);

		}
		if(NULL != prodscliente[1][i]){
			soma_qtsprods_cliente(prodscliente[1][i], inteiro);
		}
	}

	r = inteiro->i;
	free(inteiro);
	return r;
}

int get_nclientes_cfiliais(CFiliais cfiliais){
	return cfiliais->nclientes;
}

AVL get_filial_avl(CFiliais cfiliais, int x){
	return cfiliais->filiais[x];
}

void imprime_cfiliais_avls(CFiliais cfiliais){
	int i;
	for(i = 0; i < NR_FILIAIS; i++)
		imprime_avl(cfiliais->filiais[i]);
}

AVL get_filial_promo_mes_avl(CFiliais cfiliais, String cliente, Filial filial, Promo promo, Mes mes){
	ProdsCliente pc = NULL;
	if(NULL != cfiliais->filiais[filial]){
		pc = procura_valor_avl(cfiliais->filiais[filial], cliente);
	}
	if(pc == NULL)
		return NULL;
	return pc[promo][mes]; 
}






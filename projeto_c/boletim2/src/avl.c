#include "headers/avl.h"

#include <glib.h>
#include <stdio.h>
#include <string.h>

#define TAMARRAY 1000

typedef struct arrstrs{
	String *array;
	int proximo;
	int tamanho;
}*ArrStrs;


typedef struct inteiro{
	int i;
}*Inteiro;

typedef struct fatregtotal{
	int nregistos;
	float faturado;
}*FatRegTotal;

typedef struct avlstrprm{
	AVL avl;
	String str;
	Promo promo;
}*AvlStrPrm;

/*Relativo ao cfiliais*/
typedef struct qtprod{
	Quantidade quantidade;
} *QTProd;

typedef AVL **ProdsCliente;

typedef struct qtprod *QTProd;
/*Relativo ao cfiliais*/


/*Relativo ao cfaturacao*/
typedef struct registo{
	int quantidade;
	float preco;
}*Registo;

typedef struct registos{
	Registo *array;
	int proximo;
	int tamanho;
}*Registos;

typedef Registos **FTSProduto;
/*Relativo ao cfaturacao*/



static int intcmp(IntKey n1, IntKey n2);
static gboolean imprime_todos(gpointer key, gpointer value, gpointer data);
static gboolean imprime_no_array(gpointer key, gpointer value, gpointer data);
static gboolean insere_avl_avl_iter(gpointer key, gpointer value, gpointer data);
static gboolean retira_comuns_avl_avl_iter(gpointer key, gpointer value, gpointer data);
static gboolean soma_qtsprods_cliente_iter(gpointer key, QTProd value, Inteiro data);
static gboolean get_totreg_totfat_mes_iter(gpointer key, FTSProduto ftsprodutos, FatRegTotal frt);
static gboolean get_clientes_produto_iter(gpointer key, ProdsCliente prdscliente, AvlStrPrm avlstrprm);
static gboolean imprime_todos_inteiros_iter(IntKey key, ArrStrs value, gpointer data);

static ArrStrs cria_arrstrs();
static ArrStrs insere_arrstrs(ArrStrs arrstrs, String string);
static gboolean prods_comprados_cliente_iter(Chave key, QTProd valor, AVL avl);
static gboolean convert_avl_avlheap_iter(Chave key, QTProd value, AVLHEAP data);
static gboolean imprime_array_todos_inteiros_iter(IntKey key, ArrStrs value, LStrings data);
static gboolean quantidades_produtos0_iter(Chave key, FTSProduto valor, AVL data);
static gboolean quantidades_produtos1_iter(Chave key, FTSProduto valor, AVL data);
static gboolean quantidades_produtos2_iter(Chave key, FTSProduto valor, AVL data);

/*
static gboolean insere_avl_avl_filial1_iter(gpointer key, gpointer value, gpointer data);
static gboolean insere_avl_avl_filial2_iter(gpointer key, gpointer value, gpointer data);
static gboolean insere_avl_avl_filial3_iter(gpointer key, gpointer value, gpointer data);
*/

void imprime_avl(AVL avl){
	g_tree_foreach((GTree *) avl, (GTraverseFunc)imprime_todos, NULL);
}

void insere_avl(AVL avl, Chave chave, Valor valor){
	g_tree_insert((GTree *) avl, (char*) chave, valor);
}

AVL nova_avl(){
	AVL avl; 
	avl = (AVL) g_tree_new((GCompareFunc) strcmp);
	return avl;
}

Valor procura_valor_avl(AVL avl, Chave chave){
	return (Valor) g_tree_lookup((GTree *) avl, (char *) chave);
}

Boolean procura_valor_avl_extended(AVL avl, Chave chave, Chave c, Valor v ){
	return (Boolean) g_tree_lookup_extended((GTree *) avl, (char *) chave, (gpointer*)&c, (gpointer*)&v);
}

Valor imprime_para_array(AVL avl, Valor valor){
	g_tree_foreach((GTree *) avl, (GTraverseFunc)imprime_no_array, valor);
	return valor;
}

void insere_avl_avl(AVL avl, Valor valor){
	g_tree_foreach((GTree *) avl, (GTraverseFunc)insere_avl_avl_iter, valor);
}

void soma_qtsprods_cliente(AVL avl, Valor valor){
	g_tree_foreach((GTree *) avl, (GTraverseFunc)soma_qtsprods_cliente_iter, (Inteiro) valor);
}

void get_totreg_totfat_mes(AVL avl, Valor valor){
	g_tree_foreach((GTree *) avl, (GTraverseFunc)get_totreg_totfat_mes_iter, (FatRegTotal) valor);	
}

void get_clientes_produto(AVL avl, Valor valor){
	g_tree_foreach((GTree *) avl, (GTraverseFunc)get_clientes_produto_iter, (AvlStrPrm) valor);	
}



void quantidades_produtos0(AVL avl, Valor valor){
	g_tree_foreach((GTree *) avl, (GTraverseFunc)quantidades_produtos0_iter, valor);
}

void quantidades_produtos1(AVL avl, Valor valor){
	g_tree_foreach((GTree *) avl, (GTraverseFunc)quantidades_produtos1_iter, valor);
}

void quantidades_produtos2(AVL avl, Valor valor){
	g_tree_foreach((GTree *) avl, (GTraverseFunc)quantidades_produtos2_iter, valor);
}

AVLHEAP nova_avlheap(){
	AVLHEAP avlheap; 
	avlheap = (AVLHEAP) g_tree_new((GCompareFunc) intcmp);
	return avlheap;
}

void insere_avlheap(AVLHEAP avlheap, int chave, Valor valor){
	int *intptr = (int*) malloc(sizeof(int));
	*intptr = chave;
	g_tree_insert((GTree *) avlheap, intptr, valor);
}

void imprime_avl_inteiros(AVLHEAP avlheap){
	g_tree_foreach((GTree *) avlheap, (GTraverseFunc)imprime_todos_inteiros_iter, NULL);
}

void prods_comprados_cliente(AVL avl, AVL valor){
	g_tree_foreach((GTree *) avl, (GTraverseFunc)prods_comprados_cliente_iter, valor);
}

void prods_mais_comprados_cliente(AVL avl, AVLHEAP avlheap){
	g_tree_foreach((GTree *) avl, (GTraverseFunc)convert_avl_avlheap_iter, avlheap);
}

Valor imprime_avl_todos_inteiros_para_array(AVL avl, Valor valor){
	g_tree_foreach((GTree *) avl, (GTraverseFunc)imprime_array_todos_inteiros_iter, valor);
	return valor;
}

void retira_comuns_avl_avl(AVL avl, Valor valor){
	g_tree_foreach((GTree *) avl, (GTraverseFunc)retira_comuns_avl_avl_iter, valor);
}



int get_nnodos(AVL avl){
	return g_tree_nnodes((GTree *) avl);
}

static gboolean quantidades_produtos0_iter(Chave key, FTSProduto valor, AVL data){
	QTProd qt = NULL;
	QTProd qtprod = (QTProd) malloc(sizeof(struct qtprod));
	qtprod->quantidade = 0;
	int i, k;
	for(i = 0; i < NR_PROMOS; i++)
		if(NULL != valor[i][0])
			for(k = 0; k < valor[i][0]->proximo; k++)
				qtprod->quantidade += valor[i][0]->array[k]->quantidade;
	if(NULL == (qt = g_tree_lookup((GTree*) data, key)))
		insere_avl(data, key, qtprod);
	else
		qt->quantidade += qtprod->quantidade;

	return FALSE;
}

static gboolean quantidades_produtos1_iter(Chave key, FTSProduto valor, AVL data){
	QTProd qt = NULL;
	QTProd qtprod = (QTProd) malloc(sizeof(struct qtprod));
	qtprod->quantidade = 0;
	int i, k;
	for(i = 0; i < NR_PROMOS; i++)
		if(NULL != valor[i][1])
			for(k = 0; k < valor[i][1]->proximo; k++)
				qtprod->quantidade += valor[i][1]->array[k]->quantidade;
	if(NULL == (qt = g_tree_lookup((GTree*) data, key)))
		insere_avl(data, key, qtprod);
	else
		qt->quantidade += qtprod->quantidade;

	return FALSE;
}

static gboolean quantidades_produtos2_iter(Chave key, FTSProduto valor, AVL data){
	QTProd qt = NULL;
	QTProd qtprod = (QTProd) malloc(sizeof(struct qtprod));
	qtprod->quantidade = 0;
	int i, k;
	for(i = 0; i < NR_PROMOS; i++)
		if(NULL != valor[i][2])
			for(k = 0; k < valor[i][2]->proximo; k++)
				qtprod->quantidade += valor[i][2]->array[k]->quantidade;
	if(NULL == (qt = g_tree_lookup((GTree*) data, key)))
		insere_avl(data, key, qtprod);
	else
		qt->quantidade += qtprod->quantidade;

	return FALSE;
}

static gboolean prods_comprados_cliente_iter(Chave key, QTProd valor, AVL avl){
	QTProd qt = NULL;
	QTProd qtprod = NULL;
	if(NULL == (qt = g_tree_lookup((GTree*) avl, key))){
		qtprod = (QTProd) malloc(sizeof(struct qtprod));
		qtprod->quantidade = valor->quantidade;
		insere_avl(avl, key, qtprod);
	}
	else{
		qt->quantidade += valor->quantidade;
	}
	return FALSE;
}


static gboolean convert_avl_avlheap_iter(Chave key, QTProd value, AVLHEAP data){
	ArrStrs qt = NULL;
	ArrStrs arrstrs = NULL;
	int *intptr = (int *) malloc(sizeof(int));
	*intptr = value->quantidade;
	if(NULL == (qt = g_tree_lookup((GTree*) data,  intptr))){
		arrstrs = cria_arrstrs();
		insere_arrstrs(arrstrs, key);
		insere_avlheap(data, value->quantidade, arrstrs);
	}
	else
		insere_arrstrs(qt, key);
	return FALSE;
}


static int intcmp(IntKey n1, IntKey n2){
	if(*n1 < *n2)
		return 1;
	if(*n1 > *n2)
		return -1;
	if(*n1 == *n2)
		return 0;
	return 0;
}

static gboolean imprime_array_todos_inteiros_iter(IntKey key, ArrStrs value, LStrings data){
	char str [MAXBUFVENDA];
	int i;
	for(i = 0; i < value->proximo; i++){	
		sprintf(str, "Quantidade: %d  Produto: %s", *key, value->array[i]);
		insere_lstrings(data, str);
	}
	return FALSE;
}

static gboolean imprime_todos_inteiros_iter(IntKey key, ArrStrs value, gpointer data){
	int i;
	if(data == NULL) i++; 
	for(i = 0; i < value->proximo; i++)	
		printf("%d, %s, %p\n",  *key, value->array[i], NULL);
	return FALSE;
}

static gboolean imprime_todos(gpointer key, gpointer value, gpointer data){
	printf("%s, %p, %p\n", (char*) key, value, data);
	return FALSE;
}

static gboolean imprime_no_array(gpointer key, gpointer value, gpointer data){
	int i; if(value == NULL) i++;
	data = insere_lstrings((LStrings) data, (String) key);
	return FALSE;
}

static gboolean insere_avl_avl_iter(gpointer key, gpointer value, gpointer data){ 
	insere_avl(data, (String) key, value);
	return FALSE;
}

static gboolean retira_comuns_avl_avl_iter(gpointer key, gpointer value, gpointer data){ 
	int i; if(value == NULL) i++;
	g_tree_remove(data, key);
	return FALSE;
}

static gboolean soma_qtsprods_cliente_iter(gpointer key, QTProd value, Inteiro data){
	int i; if(key == NULL) i++;
	data->i += (Quantidade) value->quantidade;
	return FALSE;
}

static gboolean get_totreg_totfat_mes_iter(gpointer key, FTSProduto ftsprodutos, FatRegTotal frt){
	int i, j, k;
	float s, t;  
	if(key != NULL)
		for(i = 0; i < NR_PROMOS; i++)
			for(j = 0; j < NR_FILIAIS; j++)
				if(NULL != ftsprodutos[i][j]){
					frt->nregistos += ftsprodutos[i][j]->proximo;
					for(k = 0; k < ftsprodutos[i][j]->proximo; k++){
						s = (float) ftsprodutos[i][j]->array[k]->quantidade;
						t = (float) ftsprodutos[i][j]->array[k]->preco;
						frt->faturado = frt->faturado + (s * t);
					}
				}
	return FALSE;
}

static gboolean get_clientes_produto_iter(gpointer key, ProdsCliente prdscliente, AvlStrPrm avlstrprm){
	int i;

	for(i = 0; i < NR_MESES; i++){
		if(NULL != prdscliente[avlstrprm->promo][i])	
			if(NULL != g_tree_lookup((GTree *) prdscliente[avlstrprm->promo][i], avlstrprm->str)){
				insere_avl(avlstrprm->avl, key, prdscliente);
				break;
			}
	}
	return FALSE;
}
 

static ArrStrs cria_arrstrs(){
	int i;
	ArrStrs arrstrs = (ArrStrs) malloc(sizeof(struct arrstrs));
	arrstrs->array =  (String*) malloc(TAMARRAY * sizeof(String));
	for(i = 0; i < TAMARRAY; i++){
		arrstrs->array[i] = NULL;
		/*arrstrs->array[i] = (String) malloc(MAXBUFPROD * sizeof(char));*/
	}
	arrstrs->tamanho = TAMARRAY;
	arrstrs->proximo = 0;
	return arrstrs;
}

static ArrStrs insere_arrstrs(ArrStrs arrstrs, String string){
	if(arrstrs->tamanho == arrstrs->proximo){
		arrstrs->array = (String*) realloc(arrstrs->array, 2 * arrstrs->tamanho * sizeof(String));
		arrstrs->tamanho = 2 * arrstrs->tamanho;
	}

	/*strcpy(arrstrs->array[registos->proximo], string);*/
	arrstrs->array[arrstrs->proximo] = string;
	arrstrs->proximo++;
	return arrstrs;
}

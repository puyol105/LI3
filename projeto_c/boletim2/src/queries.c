#include "headers/queries.h"

#include <string.h>
#include <stdio.h>
#include <glib.h>
#include <time.h>

typedef struct tresavls{
	AVL avls[4];
}*TRESAVLS;

typedef struct avlstrprm{
	AVL avl;
	String str;
	Promo promo;
}*AvlStrPrm;


static Boolean insere_avl_avl_filial1_iter(gpointer key, gpointer value, gpointer data);
static Boolean insere_avl_avl_filial2_iter(gpointer key, gpointer value, gpointer data);
static Boolean insere_avl_avl_filial3_iter(gpointer key, gpointer value, gpointer data);
static Boolean insere_all(gpointer key, gpointer value, gpointer data);
static Boolean get_comuns_tresavls_iter(gpointer key, gpointer value, gpointer data);

AVL get_tresavls_avl(TRESAVLS tresavls, int x){
	return tresavls->avls[x];
}

int query1(CFaturacao faturacao, CFiliais cfiliais, CClientes clientes, CProdutos produtos, char fv[], char fc[], char fp[]){
	int n = 0;
	
	clock_t start, end;	
	double cpu_time_used;
	start = clock();

	le_ficheiros_dados_clientes(clientes, fc);
  	/*imprime_cclientes(clientes);*/
  	le_ficheiros_dados_produtos(produtos, fp);
  	/*imprime_cprodutos(produtos);*/
  	n = le_ficheiros_dados_vendas(faturacao, cfiliais, clientes, produtos, fv);
  	/*imprime_cfaturacao_avls(faturacao);*/
  	/*imprime_cfiliais_avls(cfiliais);*/

	end = clock();
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("Tempo:%f\n", cpu_time_used );

  	printf("Número de produtos catalogados: %d\n", get_nprodutos(produtos));
  	printf("Número de clientes registados: %d\n", get_nclientes(clientes));
  	printf("Número de registos de venda: %d\n", n);

  	return n;
}

void query2(CProdutos produtos, char c){
	int n, i, j = c - 'A';
	LStrings lstrings = novo_lstrings();
	AVL avlaux, avlfinal = nova_avl();

	for(i = 0; i < NR_LETRAS; i++){
		avlaux = get_letras_avl(produtos, j, i);
		insere_avl_avl(avlaux, avlfinal);
	}

	n = get_nnodos(avlfinal);

	lstrings = imprime_para_array(avlfinal, lstrings);
	imprime_lstrings(lstrings, n);
}

void query3(CFaturacao cfaturacao, Mes mes, String produto, char c){
	int f1n, f2n, f3n, gn, f1p, f2p, f3p, gp;
	float t1n, t2n, t3n, tgn, t1p, t2p, t3p, tgp;

	f1n = get_nregistos_ftsproduto(cfaturacao, mes, produto, 1, 0);
	f2n = get_nregistos_ftsproduto(cfaturacao, mes, produto, 2, 0);
	f3n = get_nregistos_ftsproduto(cfaturacao, mes, produto, 3, 0);

	f1p = get_nregistos_ftsproduto(cfaturacao, mes, produto, 1, 1);
	f2p = get_nregistos_ftsproduto(cfaturacao, mes, produto, 2, 1);
	f3p = get_nregistos_ftsproduto(cfaturacao, mes, produto, 3, 1);
	
	t1n = get_faturado_ftsproduto(cfaturacao, mes, produto, 1, 0);
	t2n = get_faturado_ftsproduto(cfaturacao, mes, produto, 2, 0);
	t3n = get_faturado_ftsproduto(cfaturacao, mes, produto, 3, 0);

	t1p = get_faturado_ftsproduto(cfaturacao, mes, produto, 1, 1); 
	t2p = get_faturado_ftsproduto(cfaturacao, mes, produto, 2, 1);
	t3p = get_faturado_ftsproduto(cfaturacao, mes, produto, 3, 1);

	if(c == 'G' || c == 'g'){

		gn = f1n + f2n + f3n;
		gp = f1p + f2p + f3p;
		tgn = t1n + t2n + t3n;
		tgp = t1p + t2p + t3p;

		puts("\n\n-------Resultado Global-------");
		printf("\nVendas sem promoção (N): %d     Total faturado(N): %.2f\n", gn, tgn);
		printf("\nVendas com promoção (P): %d     Total faturado(N): %.2f\n", gp, tgp);

	}

	if(c == 'F' || c == 'f'){

		puts("\n\n-------Resultado Filial 3-------");
		printf("\nVendas sem promoção (N): %d     Total faturado(N): %.2f\n", f1n, t1n);
		printf("\nVendas com promoção (P): %d     Total faturado(N): %.2f\n", f1p, t1p);

		puts("\n\n-------Resultado Filial 2-------");
		printf("\nVendas sem promoção (N): %d     Total faturado(N): %.2f\n", f2n, t2n);
		printf("\nVendas com promoção (P): %d     Total faturado(N): %.2f\n", f2p, t2p);

		puts("\n\n-------Resultado Filial 3-------");
		printf("\nVendas sem promoção (N): %d     Total faturado(N): %.2f\n", f3n, t3n);
		printf("\nVendas com promoção (P): %d     Total faturado(N): %.2f\n", f3p, t3p);

	}



}

void query4(CFaturacao faturacao, CProdutos produtos, char c){
	int i, j, n = 0;
	AVL avlfaturacao = nova_avl();
	AVL avlaux = NULL;
	AVL avlprodutos = nova_avl();
	LStrings lstrings = novo_lstrings();



	if(c == 'G'){

		for(i = 0; i < NR_LETRAS; i++){
			for(j = 0; j < NR_LETRAS; j++){
				avlaux = get_letras_avl(produtos, i, j);
				insere_avl_avl(avlaux, avlprodutos);
			}
		}

		for(i = 0; i < NR_MESES; i++){
			avlaux = get_mes_avl(faturacao, i);
			insere_avl_avl(avlaux, avlfaturacao);
		}

		

	}
	else if(c == '1' || c == '2' || c == '3'){
		
		for(i = 0; i < NR_MESES; i++){
			avlaux = get_mes_avl(faturacao, i);

			if(c == '1')
				g_tree_foreach((GTree *) avlaux, (GTraverseFunc)insere_all, avlprodutos);
			if(c == '2'){
				g_tree_foreach((GTree *) avlaux, (GTraverseFunc)insere_all, avlprodutos);
			}
			if(c == '3'){
				g_tree_foreach((GTree *) avlaux, (GTraverseFunc)insere_all, avlprodutos);
			}			
			
		}


		for(i = 0; i < NR_MESES; i++){
			avlaux = get_mes_avl(faturacao, i);


			if(c == '1'){
				g_tree_foreach((GTree *) avlaux, (GTraverseFunc)insere_avl_avl_filial1_iter, avlfaturacao);
			}
			if(c == '2'){
				g_tree_foreach((GTree *) avlaux, (GTraverseFunc)insere_avl_avl_filial2_iter, avlfaturacao);
			}
			if(c == '3'){
				g_tree_foreach((GTree *) avlaux, (GTraverseFunc)insere_avl_avl_filial3_iter, avlfaturacao);
			}			
			
		}


	}


	retira_comuns_avl_avl(avlfaturacao, avlprodutos);
	
	n = get_nnodos(avlprodutos);
	lstrings = imprime_para_array(avlprodutos, lstrings);
	imprime_lstrings(lstrings, n);
}	


void query5(CFiliais cfiliais){
	int i, n;
	TRESAVLS tresavls = (TRESAVLS) malloc(sizeof(struct tresavls));
	tresavls->avls[3] = nova_avl();
	LStrings lstrings = novo_lstrings();	
	AVL avltodos = nova_avl();

	for(i = 0; i < NR_FILIAIS; i++){
		tresavls->avls[i] = nova_avl();
		insere_avl_avl(get_filial_avl(cfiliais, i), avltodos);
		tresavls->avls[i] = get_filial_avl(cfiliais, i);
	}

	g_tree_foreach((GTree *) avltodos, (GTraverseFunc)get_comuns_tresavls_iter, tresavls);

	n = get_nnodos(get_tresavls_avl(tresavls, 3));
	lstrings = imprime_para_array(get_tresavls_avl(tresavls, 3), lstrings);
	imprime_lstrings(lstrings, n);
}


void query6(CFaturacao cfaturacao, CFiliais cfiliais, CProdutos cprodutos, CClientes cclientes){
	clock_t start, end;	
	double cpu_time_used;
	start = clock();

	int nclientes = get_nclientes(cclientes) - get_nclientes_cfiliais(cfiliais);
	int nprodutos = get_nprodutos(cprodutos) - get_nprodutos_cfaturacao(cfaturacao);

	end = clock();
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("Tempo:%f\n", cpu_time_used );

	printf("Número de clientes que não fizeram compras: %d\n", nclientes);
	printf("Número de produtos que não foram comprados: %d\n", nprodutos);
}

void query7(CFiliais cfiliais, String cliente){
	int i, j, k = 1;
	int quantidades[NR_MESES][NR_FILIAIS];

	clock_t start, end;	
	double cpu_time_used;
	start = clock();

	for(i = 0; i < NR_MESES; i++)
		for(j = 0; j < NR_FILIAIS; j++)
			quantidades[i][j] = 0;

	for(i = 0; i < NR_MESES; i++){
		for(j = 0; j < NR_FILIAIS; j++){
			quantidades[i][j] = get_quantidade_comprada_cliente(cfiliais, cliente, j, i);
		}
	}
	puts("--------------------------------------------------");
	puts("|  Meses  |  Filial 1  |  Filial 2  |  Filial 3  |");
	puts("--------------------------------------------------");
	for(i = 0; i < NR_MESES; i++){
		printf("|%8d |", k);
		for(j = 0; j < NR_FILIAIS; j++){
			printf("  %8d  |", quantidades[i][j]);
		}
		puts("\n--------------------------------------------------");
		k++;
	}

	end = clock();
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("Tempo:%f\n", cpu_time_used );

}

void query8(CFaturacao cfaturacao, int mesi, int mesf){
	int totreg = 0;
	float totfat = 0;

	clock_t start, end;	
	double cpu_time_used;
	start = clock();

	get_totreg_totfat_meses(cfaturacao, mesi, mesf, &totreg, &totfat);	

	end = clock();
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("Tempo:%f\n", cpu_time_used );	

	printf("Total de registos: %d\n", totreg);
	printf("Total de faturado: %0.2f\n", totfat);
}


void query9(CFiliais cfiliais, String produto, Filial filial, Promo promo){
	int n = 0;

	clock_t start, end;	
	double cpu_time_used;
	start = clock();

	LStrings lstrings = novo_lstrings();
	AVL avlfilial = get_filial_avl(cfiliais, filial);
	AvlStrPrm asp = (AvlStrPrm) malloc(sizeof(struct avlstrprm));
	asp->avl = nova_avl();
	asp->str = produto;
	asp->promo = promo;

	get_clientes_produto(avlfilial, asp);

	end = clock();
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("Tempo:%f\n", cpu_time_used );	

	n = get_nnodos(asp->avl);
	lstrings = imprime_para_array(asp->avl, lstrings);
	imprime_lstrings(lstrings, n);
}

void query10(CFiliais cfiliais, String cliente, Mes mes){
	int i, j, n = 0;

	AVL aux = NULL;
	AVL qtdsprods = nova_avl();
	AVLHEAP avlheap = nova_avlheap();
	LStrings lstrings = novo_lstrings();

	clock_t start, end;	
	double cpu_time_used;
	start = clock();

	for(i = 0; i < NR_FILIAIS; i++)
		for(j = 0; j < NR_PROMOS; j++){
			aux = get_filial_promo_mes_avl(cfiliais, cliente, i, j, mes);
			if(NULL != aux)
				prods_comprados_cliente(aux, qtdsprods);
		}

	prods_mais_comprados_cliente(qtdsprods, avlheap);

	lstrings = imprime_avl_todos_inteiros_para_array(avlheap, lstrings);

	end = clock();
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("Tempo:%f\n", cpu_time_used );	

	n = get_nnodos(avlheap);

	if(n == 0)
		puts("Cliente sem produtos comprados neste mês.");

	imprime_lstrings(lstrings, n);

	/*imprime_avl(qtdsprods);*/


}


void query11(CFaturacao cfaturacao, int n, Filial filial){
	int i;
	AVL aux = NULL; 
	AVLHEAP avlheap = nova_avlheap();
	AVL avl = nova_avl();
	LStrings lstrings = novo_lstrings();

	clock_t start, end;	
	double cpu_time_used;
	start = clock();

	for(i = 0; i < NR_MESES; i++){
		aux = get_mes_avl(cfaturacao, i);
		if(filial == 0)
			quantidades_produtos0(aux, avl);
		if(filial == 1)	
			quantidades_produtos1(aux, avl);
		if(filial == 2)	
			quantidades_produtos2(aux, avl);
	}

	prods_mais_comprados_cliente(avl, avlheap);

	end = clock();
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("Tempo:%f\n", cpu_time_used );

	lstrings = imprime_avl_todos_inteiros_para_array(avlheap, lstrings);

	imprime_lstrings(lstrings, n);

}

void query12(){
	printf("%s\n", "1º: KM1884");
	printf("%s\n", "2º: PR1787");
	printf("%s\n", "3º: RN1057");
}

static Boolean insere_all(gpointer key, gpointer value, gpointer data){ 
	insere_avl(data, (String) key, value);
	return FALSE;
}

static Boolean insere_avl_avl_filial1_iter(gpointer key, gpointer value, gpointer data){ 
	if(TRUE == preenchido_filial_promo(value, 0, 0) && FALSE == preenchido_filial_promo(value, 1, 0))
		insere_avl(data, (String) key, value);
	return FALSE;
}

static Boolean insere_avl_avl_filial2_iter(gpointer key, gpointer value, gpointer data){ 
	if(TRUE == preenchido_filial_promo(value, 0, 1) && FALSE == preenchido_filial_promo(value, 1, 1))
		insere_avl(data, (String) key, value);
	return FALSE;
}

static Boolean insere_avl_avl_filial3_iter(gpointer key, gpointer value, gpointer data){ 
	if(TRUE == preenchido_filial_promo(value, 0, 2) && FALSE == preenchido_filial_promo(value, 1, 2))
		insere_avl(data, (String) key, value);
	return FALSE;
}

static Boolean get_comuns_tresavls_iter(gpointer key, gpointer value, gpointer data){
	if(NULL != procura_valor_avl((AVL) get_tresavls_avl(data, 0), key) && 
		NULL != procura_valor_avl((AVL) get_tresavls_avl(data, 1), key) &&
		NULL != procura_valor_avl((AVL) get_tresavls_avl(data, 2), key))
		insere_avl((AVL) get_tresavls_avl(data, 3), key, value);
	return FALSE;
}




/*


static Boolean insere_avl_avl_filial2_iter(void * key, void * value, void * data){ 
	if(TRUE == preenchido_filial_promo(value, 0, 1) && TRUE == preenchido_filial_promo(value, 1, 1))
		insere_avl(data, (String) key, value);
	return FALSE;
}

static Boolean insere_avl_avl_filial3_iter(void * key, void * value, void * data){ 
	if(TRUE == preenchido_filial_promo(value, 0, 2) && TRUE == preenchido_filial_promo(value, 1, 2))
		insere_avl(data, (String) key, value);
	return FALSE;
}*/
#include "headers/queries.h"

#include <string.h>
#include <stdio.h>

void query1(CFaturacao faturacao, CClientes clientes, CProdutos produtos, char fv[], char fc[], char fp[]){
	le_ficheiros_dados_clientes(clientes, fc);
  	/*imprime_cclientes(clientes);*/
  	le_ficheiros_dados_produtos(produtos, fp);
  	/*imprime_cprodutos(produtos);*/
  	le_ficheiros_dados_vendas(faturacao, clientes, produtos, fv);
  	/*imprime_cfaturacao_avls(faturacao);*/
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
		printf("\nVendas sem promoção (N): %d     Total faturado(N): %2.f\n", gn, tgn);
		printf("\nVendas com promoção (P): %d     Total faturado(N): %2.f\n", gp, tgp);

	}

	if(c == 'F' || c == 'f'){

		puts("\n\n-------Resultado Filial 3-------");
		printf("\nVendas sem promoção (N): %d     Total faturado(N): %2.f\n", f1n, t1n);
		printf("\nVendas com promoção (P): %d     Total faturado(N): %2.f\n", f1p, t1p);

		puts("\n\n-------Resultado Filial 2-------");
		printf("\nVendas sem promoção (N): %d     Total faturado(N): %2.f\n", f2n, t2n);
		printf("\nVendas com promoção (P): %d     Total faturado(N): %2.f\n", f2p, t2p);

		puts("\n\n-------Resultado Filial 3-------");
		printf("\nVendas sem promoção (N): %d     Total faturado(N): %2.f\n", f3n, t3n);
		printf("\nVendas com promoção (P): %d     Total faturado(N): %2.f\n", f3p, t3p);

	}



}
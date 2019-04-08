#ifndef _globais_h_
#define _globais_h_

typedef int Promo;
typedef char *String;
typedef int Boolean;
typedef int Quantidade;
typedef int Mes;
typedef float Preco;
typedef int Filial;

#ifdef _WIN32
	#define CLEAR "cls"
#else
	#define CLEAR "clear"
#endif


/*typedef FILE* Ficheiro;*/

/*Definição dos valores lógicos verdadeiro e falso.*/
#define FALSE 0
#define TRUE 1

#define LINE_P_PAG 32

/*Definição do número máximo de carateres lidos em cada linha do ficheiro 
  Clientes.txt.*/
#define MAXBUFCLI 14

/*Definição do número máximo de carateres lidos em cada linha do ficheiro 
  Produtos.txt.*/
#define MAXBUFPROD 14

#define MAXBUFVENDA 60

/*Definição do número máximo de campos de uma venda.*/
#define MAXCAMPOSVENDA 7

/*Definição do número máximo de carateres lidos na escolha da operação.*/
#define MAXOP 15

/*Definição do número máximo de carateres lidos na escolha do ficheiro.*/
#define MAX_NAME_FILE 100

/*Definição do número de meses existentes*/
#define NR_MESES 12

#define NR_PRODS 200000

/*Definição do número de promos (se é promoção ou não) de compra existentes*/
#define NR_PROMOS 2

/*Definição do número de filais existentes*/
#define NR_FILIAIS 3

/*Definição do número máximo de letras do abecedário*/
#define NR_LETRAS 26


#endif /* _globais_h_ */ 
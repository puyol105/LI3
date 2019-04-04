#include "headers/avl.h"

#include <glib.h>
#include <stdio.h>
#include <string.h>
#include "headers/cfaturacao.h"

static gboolean imprime_todos(gpointer key, gpointer value, gpointer data);
static gboolean imprime_no_array(gpointer key, gpointer value, gpointer data);
static gboolean insere_avl_avl_iter(gpointer key, gpointer value, gpointer data);
static gboolean comuns_avl_avl_iter(gpointer key, gpointer value, gpointer data);
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


/*
void foreach_avl(AVL avl, void (*f)(void *, void *, void *), Valor valor){
	g_tree_foreach((GTree *) avl, (GTraverseFunc)(*f), valor);
}*/

/*
void insere_avl_avl_filial1(AVL avl, Valor valor){
	g_tree_foreach((GTree *) avl, (GTraverseFunc)insere_avl_avl_filial1_iter, valor);
}
void insere_avl_avl_filial2(AVL avl, Valor valor){
	g_tree_foreach((GTree *) avl, (GTraverseFunc)insere_avl_avl_filial2_iter, valor);
}
void insere_avl_avl_filial3(AVL avl, Valor valor){
	g_tree_foreach((GTree *) avl, (GTraverseFunc)insere_avl_avl_filial3_iter, valor);
}*/

void comuns_avl_avl(AVL avl, Valor valor){
	g_tree_foreach((GTree *) avl, (GTraverseFunc)comuns_avl_avl_iter, valor);
}


int get_nnodos(AVL avl){
	return g_tree_nnodes((GTree *) avl);
}

static gboolean imprime_todos(gpointer key, gpointer value, gpointer data){
	printf("%s, %p, %p\n", (char*) key, value, data);
	return FALSE;
}

static gboolean imprime_no_array(gpointer key, gpointer value, gpointer data){
	int i;
	if(value == NULL)
		i++;
	data = insere_lstrings((LStrings) data, (String) key);
	return FALSE;
}

static gboolean insere_avl_avl_iter(gpointer key, gpointer value, gpointer data){ 
	insere_avl(data, (String) key, value);
	return FALSE;
}

static gboolean comuns_avl_avl_iter(gpointer key, gpointer value, gpointer data){ 
	int i;
	if(value == NULL)
		i++;
	g_tree_remove(data, key);
	return FALSE;
}

/*
static gboolean insere_avl_avl_filial1_iter(gpointer key, gpointer value, gpointer data){ 
	if(TRUE == preenchido_filial_promo(value, 0, 1) && TRUE == preenchido_filial_promo(value, 1, 1))
		insere_avl(data, (String) key, value);
	return FALSE;
}

static gboolean insere_avl_avl_filial2_iter(gpointer key, gpointer value, gpointer data){ 
	if(TRUE == preenchido_filial_promo(value, 0, 2) && TRUE == preenchido_filial_promo(value, 1, 2))
		insere_avl(data, (String) key, value);
	return FALSE;
}

static gboolean insere_avl_avl_filial3_iter(gpointer key, gpointer value, gpointer data){ 
	if(TRUE == preenchido_filial_promo(value, 0, 3) && TRUE == preenchido_filial_promo(value, 1, 3))
		insere_avl(data, (String) key, value);
	return FALSE;
}*/



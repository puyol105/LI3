#include "headers/avl.h"

#include <glib.h>
#include <stdio.h>

static gboolean iter_all(gpointer key, gpointer value, gpointer data);

AVL nova_avl(){
	AVL avl; 
	avl = (AVL) g_tree_new((GCompareFunc) strcmp);
	return avl;
}

void insere_avl(AVL avl, Chave chave, Valor valor){
	g_tree_insert((GTree *) avl, (char*) chave, (char*) valor);
}

void imprime_avl(AVL avl){
	g_tree_foreach((GTree *) avl, (GTraverseFunc)iter_all, NULL);
}

static gboolean iter_all(gpointer key, gpointer value, gpointer data){
	printf("%s, %s\n", (char*) key, (char*) value);
	return FALSE;
}
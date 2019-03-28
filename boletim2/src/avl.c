#include "headers/avl.h"

#include <glib.h>
#include <stdio.h>

static gboolean iter_all(gpointer key, gpointer value, gpointer data);

void imprime_avl(AVL avl){
	g_tree_foreach((GTree *) avl, (GTraverseFunc)iter_all, NULL);
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


static gboolean iter_all(gpointer key, gpointer value, gpointer data){
	printf("%s, %p, %p\n", (char*) key, value, data);
	return FALSE;
}
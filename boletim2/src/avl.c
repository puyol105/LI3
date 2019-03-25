#include "headers/avl.h"
#include "headers/globais.h"

#include <glib.h>
#include <stdio.h>

AVL init_avl(){
	AVL avl; 

	avl = (AVL) g_tree_new((GCompareFunc) strcmp);

	return avl;
}

//#include "headers/avl.h"
#include <glib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

#define MAXBUFCLI 14


gboolean iter_all(gpointer key, gpointer value, gpointer data) {
	printf("%s, %s\n", (char*) key, (char*) value);
	return FALSE;
}


int main(){

	clock_t start, end;
	double cpu_time_used;
	start = clock();

	char str[MAXBUFCLI];
	char *buf = NULL;
	char *buf1 = NULL;
	
	//FILE *fp = fp = fopen("../../teste/Clientes1.txt","r"); se este ficheiro estiver junto ao main.c
	FILE *fp = fp = fopen("../teste/Clientes1.txt","r"); //se estiver na usefull

	GTree* arv = g_tree_new((GCompareFunc) strcmp);

	while(fgets(str, MAXBUFCLI, fp)){
		strtok(str,"\r\n");
		buf = strdup(str);
		buf1 = strdup(str+1);
		//printf("%s\n", str+1);
		g_tree_insert(arv,buf1, buf);
		//g_tree_foreach(arv, (GTraverseFunc)iter_all, NULL);
		//printf("%d\n", g_tree_nnodes(arv));
	}

	fclose(fp);

	//printf("%p\n", g_tree_lookup(arv, 4891));

	g_tree_foreach(arv, (GTraverseFunc)iter_all, NULL);

	end = clock();
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("CPU Time:%f\n", cpu_time_used );

	return 0;
}


//gcc -Wall -o main main.c $(pkg-config --cflags --libs glib-2.0)

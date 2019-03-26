#ifndef _leituras_h_
#define _leituras_h_


#include "avl.h"
#include "cclientes.h"
#include "globais.h"

#include <glib.h>

gboolean iter_all(gpointer key, gpointer value, gpointer data);

void le_ficheiros_dados(CatClientes clientes);

#endif /* _leituras_h_ */ 
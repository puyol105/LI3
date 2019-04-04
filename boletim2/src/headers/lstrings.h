#ifndef _lstrings_h_
#define _lstrings_h_


#include "globais.h"


#define INIT_TAMANHO 10000

typedef struct lstrings *LStrings;

LStrings novo_lstrings();
LStrings insere_lstrings(LStrings lstrings, String string);
Boolean imprime_lstrings(LStrings lstrings, int n);
int get_lstrings_tamanho(LStrings lstrings);
int get_lstrings_proximo(LStrings lstrings);
int get_lstrings_nresultados(LStrings lstrings);
#endif /* _lstrings_h_ */ 
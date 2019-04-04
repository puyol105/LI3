CC = gcc 

CFLAGS = $(shell pkg-config --cflags glib-2.0) -ansi -Wunreachable-code -O2 -Wuninitialized -Wunused-parameter -Wall -Wextra

LIBS = $(shell pkg-config --libs glib-2.0)

OBJECTS = obj/avl.o obj/cliente.o obj/cclientes.o obj/cfaturacao.o obj/cprodutos.o obj/leituras.o obj/lstrings.o obj/main.o obj/produto.o obj/queries.o obj/venda.o

DOC = doc/Doxyfile

compile: $(OBJECTS)
	$(CC) $(CFLAGS) -o sgv $(OBJECTS) $(LIBS)

obj/%.o: src/%.c
	@mkdir -p obj
	$(CC) $(CFLAGS) -o $@ -c $<	

obj/main.o: src/headers/cclientes.h src/headers/cfaturacao.h src/headers/cprodutos.h src/headers/globais.h src/headers/leituras.h src/headers/queries.h src/headers/venda.h
obj/avl.o: src/headers/avl.h src/headers/globais.h src/headers/lstrings.h 
obj/cliente.o: src/headers/cliente.h src/headers/globais.h 
obj/cclientes.o: src/headers/avl.h src/headers/cliente.h src/headers/cclientes.h src/headers/globais.h
obj/leituras.o: src/headers/avl.h src/headers/cliente.h src/headers/cfaturacao.h src/headers/cclientes.h src/headers/cprodutos.h src/headers/globais.h src/headers/leituras.h src/headers/produto.h src/headers/venda.h
obj/cprodutos.o: src/headers/avl.h src/headers/globais.h src/headers/cprodutos.h src/headers/produto.h 
obj/produto.o: src/headers/produto.h src/headers/globais.h 
obj/venda.o: src/headers/cclientes.h src/headers/cliente.h src/headers/cprodutos.h src/headers/globais.h src/headers/produto.h
obj/cfaturacao.o: src/headers/avl.h src/headers/cfaturacao.h src/headers/globais.h src/headers/venda.h 
obj/queries.o: src/headers/cfaturacao.h src/headers/cclientes.h src/headers/cprodutos.h src/headers/leituras.h src/headers/lstrings.h src/headers/globais.h
obj/lstrings.o: src/headers/globais.h src/headers/lstrings.h 
#include "globais.h"

run: $(OBJECTS)
	$(CC) $(CFLAGS) -o sgv $(OBJECTS) $(LIBS)
	./sgv

clean:
	rm -f sgv
	rm -f debug 
	rm -f $(OBJECTS)

debug: $(OBJECTS)
	$(CC) $(OBJECTS) -g -o debug $(LIBS)
	gdb debug

.PHONY: doc
doc:$(OBJECTS)
		doxygen $(DOC)
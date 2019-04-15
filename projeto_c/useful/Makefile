CC = gcc 

CFLAGS = -ansi -Wunreachable-code -O2 -Wuninitialized -Wunused-parameter -Wall -Wextra 

LIBS = `pkg-config --cflags --libs glib-2.0`

OBJECTS = obj/main.o obj/avl.o obj/cclientes.o

DOC = doc/Doxyfile

compile: $(OBJECTS)
	$(CC) $(CFLAGS) -o sgv $(OBJECTS) $(LIBS)

obj/%.o: src/%.c
	@mkdir -p obj
	$(CC) $(CFLAGS) -o $@ -c $<	

obj/main.o: src/headers/globais.h src/headers/cclientes.h src/headers/leituras.h"
obj/avl.o: src/headers/avl.h src/headers/globais.h
obj/cclientes.o: src/headers/cclientes.h src/headers/avl.h src/headers/globais.h
obj/leituras.o: src/headers/leituras.h src/headers/avl.h src/headers/cclientes.h src/headers/globais.h
run: $(OBJECTS)
	$(CC) $(CFLAGS) -o sgv $(OBJECTS)
	./sgv

clean:
	rm -f sgv
	rm -f debug 
	rm -f $(OBJECTS)

debug: $(OBJECTS)
	$(CC) $(OBJECTS) -g -o debug
	gdb debug

.PHONY: doc
doc:$(OBJECTS)
		doxygen $(DOC)
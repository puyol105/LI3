CC = gcc
CFLAGS = -ansi -Wall -std=c11 -g `xml2-config --cflags --libs` 
LIBS = `pkg-config --libs libxml-2.0` `pkg-config --libs glib-2.0` `pkg-config --cflags --libs glib-2.0`

OBJECTS = obj/avl.o obj/cclientes.o

#$(INSTTOOL) -m 755 bin/doxytag    $(INSTALL)/bin

DOC = doc/Doxyfile


sgv:
	$(CC) $(CFLAGS) src/main.c src/cclientes.c src/avl.c -o sgv $(LIBS)

obj/%.o: src/%.c
	@mkdir -p obj
	$(CC) $(CFLAGS) -o $@ -c $<	

obj/avl.o: src/headers/avl.h src/headers/globais.h
obj/cclientes.o: src/headers/cclientes.h src/headers/globais.h src/headers/avl.h

clean:
	rm sgv

.PHONY: doc
doc:$(OBJECTS)
		doxygen $(DOC)


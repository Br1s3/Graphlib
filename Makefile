CC = gcc
RM = rm -rf

CFLAGS +=	\
-Wextra		\
-Wall   	\

.PHONY: all prog2 prog3 static dyn clean

all: static prog2 prog3

prog2: prog2.c
	gcc prog2.c -o prog2 $(CFLAGS)


prog3: libgraph.o
	gcc prog3.c libgraph.o -o prog3 $(CFLAGS)

libgraph.o:
	$(CC) -DLIBGRAPH_IMPLEMENTATION -x c -c libgraph.h




# Pour lancer le prog1 si pas "-Wl,-rpath=./"
# LD_LIBRARY_PATH="./" ./prog1
dyn: prog1.c | libgraph.so
	gcc prog1.c -o prog1 $(CFLAGS) -L. -lgraph -Wl,-rpath=./

static: prog1.c | libgraph.a
	$(CC) prog1.c -o prog1 -L. -lgraph $(CFLAGS)


libgraph.so: graph.c
	$(CC) $(CFLAGS) -fPIC -shared -o libgraph.so graph.c

libgraph.a: graph.c
	$(CC) $(CFLAGS) -c graph.c
	ar -cvq libgraph.a graph.o
	@ar -t libgraph.a


clean:
	$(RM) *.o
	$(RM) *.a
	$(RM) *.so
	$(RM) prog1
	$(RM) prog2
	$(RM) prog3

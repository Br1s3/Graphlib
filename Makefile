CC = gcc
RM = rm -rf

CFLAGS +=	\
-Wextra		\
-Wall   	\

.PHONY: clean static dyn

static: main.c | libgraph.a
	gcc main.c -o main -L. -lgraph $(CFLAGS)

libgraph.a: graph.c
	$(CC) $(CFLAGS) -c graph.c
	ar -cvq libgraph.a graph.o
	@ar -t libgraph.a


# Pour lancer le main si pas "-Wl,-rpath=./"
# LD_LIBRARY_PATH="./" ./main

dyn: main.c | libgraph.so
	gcc main.c -o main $(CFLAGS) -L. -lgraph -Wl,-rpath=./


libgraph.so: graph.c
	$(CC) $(CFLAGS) -fPIC -shared -o libgraph.so graph.c

clean:
	$(RM) *.o
	$(RM) *.a
	$(RM) *.so
	$(RM) main

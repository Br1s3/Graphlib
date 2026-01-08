CC = gcc
RM = rm -rf

CFLAGS +=	\
-Wextra		\
-Wall   	\


.PHONY: prog1 prog2 prog_dyn prog_static clean

prog1: prog.c
	$(CC) prog.c -o prog -DPROG1 $(CFLAGS)


prog2: libgraph.o
	$(CC) prog.c libgraph.o -o prog -DPROG2 $(CFLAGS)

libgraph.o:
	$(CC) -DLIBGRAPH_IMPLEMENTATION -x c -c libgraph.h


# Pour lancer le prog1 si pas "-Wl,-rpath=./"
# LD_LIBRARY_PATH="./" ./prog1
prog_dyn: prog.c | libgraph.so
	$(CC) prog.c -o prog -DPROG3 $(CFLAGS) -L. -lgraph -Wl,-rpath=./

libgraph.so: graph.c
	$(CC) $(CFLAGS) -fPIC -shared -o libgraph.so graph.c



prog_static: prog.c | libgraph.a
	$(CC) prog.c -o prog -L. -lgraph -DPROG3 $(CFLAGS)

libgraph.a: graph.c
	$(CC) $(CFLAGS) -c graph.c
	ar -cvq libgraph.a graph.o
	@ar -t libgraph.a


clean:
	$(RM) *.o
	$(RM) *.a
	$(RM) *.so
	$(RM) prog

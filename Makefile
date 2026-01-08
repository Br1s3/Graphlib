CC = gcc
RM = rm -rf

CFLAGS +=	\
-Wextra		\
-Wall   	\


.PHONY: prog1 prog2 prog_dyn prog_static clean

prog1: prog.c
	$(CC) prog.c -o prog -DPROG1 $(CFLAGS)



libgraph.o:
	$(CC) -DLIBGRAPH_IMPLEMENTATION -x c -c libgraph.h

prog2: libgraph.o
	$(CC) prog.c libgraph.o -o prog -DPROG2 $(CFLAGS)



# Pour lancer le prog1 si pas "-Wl,-rpath=./"
# LD_LIBRARY_PATH="./" ./prog1
libgraph.so: graph.c
	$(CC) $(CFLAGS) -fPIC -shared -o libgraph.so graph.c

prog_dyn: prog.c | libgraph.so
	$(CC) prog.c -o prog $(CFLAGS) -L. -lgraph -Wl,-rpath=./


libgraph.a: graph.c
	$(CC) $(CFLAGS) -c graph.c
	ar -cvq libgraph.a graph.o
	@ar -t libgraph.a

prog_static: prog.c | libgraph.a
	$(CC) prog.c -o prog -L. -lgraph $(CFLAGS)



clean:
	$(RM) *.o
	$(RM) *.a
	$(RM) *.so
	$(RM) prog

CC = gcc
RM = rm -rf
EXEC = animation raytracing triangle 3DSquare

CFLAGS +=	\
-Wextra		\
-Wall   	\
-lm   	        \


MODE ?= PROG1

.PHONY: header obj dynamic static clean

header:
	$(MAKE) --no-print-directory MODE=PROG1 $(EXEC)

obj: 
	$(MAKE) --no-print-directory MODE=PROG2 $(EXEC)

dynamic: 
	$(MAKE) --no-print-directory MODE=PROGDYN $(EXEC)

static: 
	$(MAKE) --no-print-directory MODE=PROGSTAT $(EXEC)

ifeq ($(MODE), PROG1)
%: %.c libgraph.h
	@echo Simple compilation of programs
	$(CC) $< -o $@ -D$(MODE) $(CFLAGS)
else ifeq ($(MODE), PROG2)
%: %.c libgraph.o
	@echo Compile with obj lib
	$(CC) $^ -o $@ -D$(MODE) $(CFLAGS)
else ifeq ($(MODE), PROGDYN)
%: %.c libgraph.so
	@echo Compile the dynamique library
	$(CC) $< -o $@ -D$(MODE) $(CFLAGS) -L. -lgraph -Wl,-rpath=./
else ifeq ($(MODE), PROGSTAT)
%: %.c libgraph.a
	@echo Compile the static library
	$(CC) $< -o $@ -L. -lgraph -D$(MODE) $(CFLAGS)
else
	@echo ERROR: Impossible mode
endif


libgraph.o: libgraph.h
	$(CC) -DLIBGRAPH_IMPLEMENTATION -x c -c $<

libgraph.so: graph.c
	$(CC) $(CFLAGS) -fPIC -shared -o $@ $<

graph.o: graph.c
	$(CC) $(CFLAGS) -c $<

libgraph.a: graph.o
	ar -cvq $@ $<
	@ar -t $@

clean:
	$(RM) *.o
	$(RM) *.a
	$(RM) *.so
	$(RM) $(EXEC)

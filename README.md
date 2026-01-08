# Graphlib

Short and simple static/shared library to draw shapes

## Ready to start

```console
$ make prog1
$ ./prog
$ make prog2
$ ./prog
$ make prog_static
$ ./prog
$ make prog_dyn
$ ./prog
```

Here is 3 ways to compile a same program:

> make prog1 will compile only the prog.c, everything is in the header file libgraph.h

> make prog2 will compile with libgraph object file and use the header file libgraph.h

> make prog_static will create a static librairy of graph and compile prog.c with

> make prog_dyn will create a dynamic librairy of graph and compile prog.c with

The prog.c program is just an exemple of use and it draw a triangle and move each point to the x and y axes step by step

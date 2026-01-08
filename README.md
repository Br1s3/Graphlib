# Graphlib

Short and simple static/shared library to draw shapes

## Ready to start

```console
$ make all
$ ./prog1
$ ./prog2
$ ./prog3
```
it will create 3 identical programs:
> prog1 is comile with the static or dynamic librairy of graph depanding of the argument pass through make
> prog2 is only compile with prog2.c, everything is in the header file libgraph.h
> prog3 is compile with libgraph object file and use the header file libgraph.h

if you want to use the dynamic lib instead of static:

```console
$ make static
$ ./prog1
```

The prog(n).c program is just an exemple of use and it draw a triangle and move each point to the x and y axes step by step

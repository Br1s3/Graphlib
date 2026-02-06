#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#if defined(PROG1)
#    define LIBGRAPH_IMPLEMENTATION
#    include "libgraph.h"
#elif defined(PROG2)
#    include "libgraph.h"
#else
#    include "graph.h"
#endif

# define HEIGHT	(7*9)
# define WIDTH	(10*16)


int main()
{
   char ** console = mem_alloc(HEIGHT, WIDTH);

   cons_clear(console, WIDTH, HEIGHT, '.');

   int ax = -20;
   int ay = 20;
   
   int bx = 0;
   int by = -20;
   
   int cx = 20;
   int cy = 20;


   for (int i = -20; i < 20; i++) {
       cons_clear(console, WIDTH, HEIGHT, '.');
       cons_triangle(console, WIDTH, HEIGHT, i, ay, bx, by, cx, cy, '#');
       cons_triangle(console, WIDTH, HEIGHT, i+1, ay-1, bx, by+1, cx-1, cy-1, '+');
       cons_rect(console, WIDTH, HEIGHT, 0, 0, 1, 1, '*');
       // print_cons(console, WIDTH, HEIGHT);
       print_cons_comp(console, WIDTH, HEIGHT);
       usleep(100000);
   }

   for (int i = -20; i < 20; i++) {
       cons_clear(console, WIDTH, HEIGHT, '.');
       cons_triangle(console, WIDTH, HEIGHT, ax, i, bx, by, cx, cy, '#');
       cons_triangle(console, WIDTH, HEIGHT, ax+1, i+1, bx, by+1, cx-1, cy-1, '+');
       cons_rect(console, WIDTH, HEIGHT, 0, 0, 1, 1, '*');
       // print_cons(console, WIDTH, HEIGHT);
       print_cons_comp(console, WIDTH, HEIGHT);
       usleep(100000);
   }

   for (int i = -20; i < 20; i++) {
       cons_clear(console, WIDTH, HEIGHT, '.');
       cons_triangle(console, WIDTH, HEIGHT, ax, ay, i, by, cx, cy, '#');
       cons_triangle(console, WIDTH, HEIGHT, ax+1, ay-1, i, by+1, cx-1, cy-1, '+');
       cons_rect(console, WIDTH, HEIGHT, 0, 0, 1, 1, '*');
       // print_cons(console, WIDTH, HEIGHT);
       print_cons_comp(console, WIDTH, HEIGHT);
       usleep(100000);
   }

   for (int i = -20; i < 20; i++) {
       cons_clear(console, WIDTH, HEIGHT, '.');
       cons_triangle(console, WIDTH, HEIGHT, ax, ay, bx, i, cx, cy, '#');
       if (i != 19)
	   cons_triangle(console, WIDTH, HEIGHT, ax+1, ay-1, bx, i+1, cx-1, cy-1, '+');
       cons_rect(console, WIDTH, HEIGHT, 0, 0, 1, 1, '*');
       // print_cons(console, WIDTH, HEIGHT);
       print_cons_comp(console, WIDTH, HEIGHT);
       usleep(100000);
   }

   for (int i = -20; i < 20; i++) {
       cons_clear(console, WIDTH, HEIGHT, '.');
       cons_triangle(console, WIDTH, HEIGHT, ax, ay, bx, by, i, cy, '#');
       cons_triangle(console, WIDTH, HEIGHT, ax+1, ay-1, bx, by+1, i-1, cy-1, '+');
       cons_rect(console, WIDTH, HEIGHT, 0, 0, 1, 1, '*');
       // print_cons(console, WIDTH, HEIGHT);
       print_cons_comp(console, WIDTH, HEIGHT);
       usleep(100000);
   }

   for (int i = -20; i < 20; i++) {
       cons_clear(console, WIDTH, HEIGHT, '.');
       cons_triangle(console, WIDTH, HEIGHT, ax, ay, bx, by, cx, i, '#');
       cons_triangle(console, WIDTH, HEIGHT, ax+1, ay-1, bx, by+1, cx-1, i-1, '+');
       cons_rect(console, WIDTH, HEIGHT, 0, 0, 1, 1, '*');
       // print_cons(console, WIDTH, HEIGHT);
       print_cons_comp(console, WIDTH, HEIGHT);
       usleep(100000);
   }

   mem_free(console, HEIGHT);
   return 0;
}

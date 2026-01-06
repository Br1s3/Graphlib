#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <time.h>
#include "graph.h"

#define HEIGHT	(10*9)
#define WIDTH	(15*16)

// #define WIDTH	3
// #define HEIGHT	4

#define xx 3

// const char canvas[5] = {' ', '.', '*', 'O', '#'};

#if xx==1
int main()
{
   char **console = mem_alloc(HEIGHT, WIDTH);

   int i, j = 1;
   for (i = -45; i < 45; i++, j++) {
      if (i<0) j = -i;
      cons_clear(console, WIDTH, HEIGHT, ' ');

      cons_rect(console, WIDTH, HEIGHT, -i*2, i, 10, 5, '#');
      cons_rect(console, WIDTH, HEIGHT, -i*2+1, i+1, 8, 3, '.');
      cons_cercle(console, WIDTH, HEIGHT, i, i, j, '#');
      cons_cercle(console, WIDTH, HEIGHT, i, i, j-1, '.');

      print_cons(console, WIDTH, HEIGHT);

      usleep(50000);
   }
   puts("tout c'est bien passé");

   mem_free(console, HEIGHT);
   return 0;
}
#elif xx==2
int main()
{
   char **console = mem_alloc(HEIGHT, WIDTH);
   // int i, j = 1;
   cons_clear(console, WIDTH, HEIGHT, ' ');
   cons_ligne(console, WIDTH, HEIGHT, 0, 0, 10, 0, 100, '#');
   cons_ligne(console, WIDTH, HEIGHT, 0, 0, 0, 10, 100, '#');
   cons_rect(console, WIDTH, HEIGHT, 0, 0, 1, 1, '*');
       
   print_cons(console, WIDTH, HEIGHT);
   mem_free(console, HEIGHT);

   return 0;
}
#else
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
       print_cons(console, WIDTH, HEIGHT);
       usleep(100000);
   }
   for (int i = -20; i < 20; i++) {
       cons_clear(console, WIDTH, HEIGHT, '.');
       cons_triangle(console, WIDTH, HEIGHT, ax, i, bx, by, cx, cy, '#');
       cons_triangle(console, WIDTH, HEIGHT, ax+1, i+1, bx, by+1, cx-1, cy-1, '+');
       cons_rect(console, WIDTH, HEIGHT, 0, 0, 1, 1, '*');
       print_cons(console, WIDTH, HEIGHT);
       usleep(100000);
   }
   for (int i = -20; i < 20; i++) {
       cons_clear(console, WIDTH, HEIGHT, '.');
       cons_triangle(console, WIDTH, HEIGHT, ax, ay, i, by, cx, cy, '#');
       cons_triangle(console, WIDTH, HEIGHT, ax+1, ay-1, i, by+1, cx-1, cy-1, '+');
       cons_rect(console, WIDTH, HEIGHT, 0, 0, 1, 1, '*');
       print_cons(console, WIDTH, HEIGHT);
       usleep(100000);
   }
   for (int i = -20; i < 20; i++) {
       cons_clear(console, WIDTH, HEIGHT, '.');
       cons_triangle(console, WIDTH, HEIGHT, ax, ay, bx, i, cx, cy, '#');
       if (i != 19)
	   cons_triangle(console, WIDTH, HEIGHT, ax+1, ay-1, bx, i+1, cx-1, cy-1, '+');
       cons_rect(console, WIDTH, HEIGHT, 0, 0, 1, 1, '*');
       print_cons(console, WIDTH, HEIGHT);
       usleep(100000);
   }
   for (int i = -20; i < 20; i++) {
       cons_clear(console, WIDTH, HEIGHT, '.');
       cons_triangle(console, WIDTH, HEIGHT, ax, ay, bx, by, i, cy, '#');
       cons_triangle(console, WIDTH, HEIGHT, ax+1, ay-1, bx, by+1, i-1, cy-1, '+');
       cons_rect(console, WIDTH, HEIGHT, 0, 0, 1, 1, '*');
       print_cons(console, WIDTH, HEIGHT);
       usleep(100000);
   }
   for (int i = -20; i < 20; i++) {
       cons_clear(console, WIDTH, HEIGHT, '.');
       cons_triangle(console, WIDTH, HEIGHT, ax, ay, bx, by, cx, i, '#');
       cons_triangle(console, WIDTH, HEIGHT, ax+1, ay-1, bx, by+1, cx-1, i-1, '+');
       cons_rect(console, WIDTH, HEIGHT, 0, 0, 1, 1, '*');
       print_cons(console, WIDTH, HEIGHT);
       usleep(100000);
   }

   mem_free(console, HEIGHT);
   return 0;
}
#endif

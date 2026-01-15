#include <stdio.h>
#include <stdlib.h>
// #include <time.h>
#include <unistd.h>
// #include <errno.h>
// #include <string.h>

#if defined(PROG1)
#    define LIBGRAPH_IMPLEMENTATION
#    include "libgraph.h"
#elif defined(PROG2)
#    include "libgraph.h"
#else
#    include "graph.h"
#endif


#define xx 4

#if xx==1
# define HEIGHT	(10*9)
# define WIDTH	(15*16)

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
# define HEIGHT	(10*9)
# define WIDTH	(15*16)

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
#elif xx==3
# define HEIGHT	(7*9)
# define WIDTH	(15*16)

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

#elif xx==4
# include <math.h>
# define HEIGHT	(7*9)
# define WIDTH	(15*16)

typedef struct {
    int x;
    int y;
} Vector2;


typedef struct {
    Vector2 pos;
    char color;
    int radius;
    int brighness;
} Corp;

int raytracing(Corp l, int l_len, double srcx, double srcy, Corp c)
{
    int j = 0;
    for (j = 0; j < l_len; j++) {
	Vector2 brighness_len = {
	    .x = l.pos.x + srcx*j,
	    .y = l.pos.y + srcy*j
	};
	if ((brighness_len.x - c.pos.x)*(brighness_len.x - c.pos.x) + (brighness_len.y - c.pos.y)*(brighness_len.y - c.pos.y) <= c.radius*c.radius) break;
    }
    return j;
}

int main()
{
    Corp light;
    light.pos.x = 0;
    light.pos.y = 0;
    light.color = '@';
    light.radius = 2;
    light.brighness = 70;

    Corp shadow1;
    shadow1.pos.x = 25;
    shadow1.pos.y = 0;
    shadow1.color = '$';
    shadow1.radius = 10;

    Corp shadow2;
    shadow2.pos.x = -25;
    shadow2.pos.y = 0;
    shadow2.color = '%';
    shadow2.radius = 10;

    char **console = mem_alloc(HEIGHT, WIDTH);

    for (double k = 0; k < 5*M_PI; k+=0.01) {
	cons_clear(console, WIDTH, HEIGHT, ' ');
	light.pos.y = sin(k)*(HEIGHT/2.5);

	for (double j = 0; j < 2*M_PI; j+=M_PI/50) {
	    int len = raytracing(light, light.brighness, cos(j), sin(j), shadow1);
	    if(raytracing(light, 1000, cos(j), sin(j), shadow2) < len)
	        len = raytracing(light, light.brighness, cos(j), sin(j), shadow2);
	    cons_ligne(console, WIDTH, HEIGHT, light.pos.x, light.pos.y, light.pos.x + cos(j)*(len), light.pos.y + sin(j)*(len), '.');
	}
	
	cons_cercle(console, WIDTH, HEIGHT, light.pos.x, light.pos.y, light.radius, light.color);	
	cons_cercle(console, WIDTH, HEIGHT, shadow1.pos.x, shadow1.pos.y, shadow1.radius, shadow1.color);
	cons_cercle(console, WIDTH, HEIGHT, shadow2.pos.x, shadow2.pos.y, shadow2.radius, shadow2.color);

	print_cons(console, WIDTH, HEIGHT);
	usleep(5000);
    }
    
    mem_free(console, HEIGHT);
    return 0;
}
#endif


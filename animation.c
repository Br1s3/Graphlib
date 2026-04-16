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

# define HEIGHT	(10*9)
# define WIDTH	(10*16)

int main()
{
   char **console = mem_alloc(HEIGHT, WIDTH);

   int i, j = 1;
   for (i = -45; i < 45; i++, j++) {
      if (i<0) j = -i;
      ConsoleClear(console, WIDTH, HEIGHT, ' ');

      PrintRectangle(console, WIDTH, HEIGHT, -i*2, i, 10, 5, '#');
      PrintRectangle(console, WIDTH, HEIGHT, -i*2+1, i+1, 8, 3, '.');
      PrintCircle(console, WIDTH, HEIGHT, i, i, j, '#');
      PrintCircle(console, WIDTH, HEIGHT, i, i, j-1, '.');

      // print_cons(console, WIDTH, HEIGHT);
      PrintConsoleSpace(console, WIDTH, HEIGHT);

      usleep(50000);
   }
   puts("tout c'est bien passé");

   mem_free(console, HEIGHT);
   return 0;
}

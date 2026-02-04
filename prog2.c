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
# define WIDTH	(15*16)


int main()
{
   char **console = mem_alloc(HEIGHT, WIDTH);
   // int i, j = 1;
   cons_clear(console, WIDTH, HEIGHT, ' ');
   cons_ligne(console, WIDTH, HEIGHT, 0, 0, 10, 0, '#');
   cons_ligne(console, WIDTH, HEIGHT, 0, 0, 0, 10, '#');
   cons_rect(console, WIDTH, HEIGHT, 0, 0, 1, 1, '*');
       
   print_cons(console, WIDTH, HEIGHT);
   mem_free(console, HEIGHT);

   return 0;
}

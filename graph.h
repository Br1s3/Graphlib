#ifndef CONS_H_INCLUED
#define CONS_H_INCLUED

#include <stdint.h>
// #define max(x, y) ((x)<(y) ? (y) : (x))
// #define min(x, y) ((x)>(y) ? (y) : (x))
#define MOVETO_LIBGRAPH(y, x) printf("\033[%d;%dH", (y), (x))
#define DEC_LIBGRAPH(x, y) (((x)*(width+1)) + (y))
#define ABS_GRAPHLIB(x) ((x) < 0 ? (-x) : (x))

#define ERRALLOC(x)                                                                          \
do                                                                                           \
{                                                                                            \
    if (x == NULL) {                                                                         \
        fprintf(stderr, "Erreur d'allocation : %s, ligne : %d\n", strerror(errno), __LINE__);\
        exit(EXIT_FAILURE);                                                                  \
    }                                                                                        \
} while(0)                                                                                   \


typedef struct
{
   int x, y;
}COORD;

typedef struct
{
   float x, y;
}COORDF;

char **mem_alloc(int H, int W);
void mem_free(char **ptr, int H);

void ConsoleClear(char **pixels, short width, short height, const char clear);

void PrintRectangle(char **pixels, short width, short height, int x, int y, int largeur, int hauteur, const char fd);
void PrintCircle(char **pixels, short width, short height, int x, int y, int radius, const char fd);
void PrintLine(char **pixels, const short width, const short height, int ax, int ay, int bx, int by, const char fd);
void PrintTriangle(char **pixels, short width, short height, int ax, int ay, int bx, int by, int cx, int cy, const char fd);

void PrintConsole(char **pixels, short width, short height);
void PrintConsoleSpace(char **pixels, short width, short height);


void ClearDrawing(uint8_t ***pixels, short width, short height, const uint32_t fd);

void DrawLine(uint8_t ***pixels, short width, short height, int ax, int ay, int bx, int by, const uint32_t fd);
void DrawCircle(uint8_t ***pixels, short width, short height, int x, int y, int radius, const uint32_t fd);


#endif //CONS_H_INCLUED

#ifndef GRAPH_H
#define GRAPH_H

#include "boolean.h"
#include "bangunan.h"

typedef int infotype;
typedef struct TList
{
    struct TLink *first, *last;
} Graph;

typedef struct TLink
{
    infotype V;
    struct TLink *prev, *next;
} Link;



/* *** Selektor *** */
/* G : Graph */
/* L : Link */
#define next(L) (L)->next
#define prev(L) (L)->prev
#define first(G) (G)->first
#define last(G) (G)->last

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */
/* *** Konstruktor membentuk Graph *** */
Graph AlokGraph();

Link AlokLink(infotype V);
/* mengembalikan node yang baru dialokasi, isinya adalah vertex dan pointer to NULL */

void addLink(Graph *list, Link *newlink);
/* menambah node ke suatu vertex setelah node dialokasi. */

#endif
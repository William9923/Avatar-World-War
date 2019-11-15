#include "graph.h"
#include <stdio.h>
#include <stdlib.h>

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */
/* *** Konstruktor membentuk Graph *** */

Graph AlokGraph();
/* mengembalikan true jika tidak ada node yang terhubung. */

Link AlokLink(infotype V);
/* mengembalikan node yang baru dialokasi, isinya adalah vertex dan pointer to NULL */

void addLink(Graph *G, Link *newlink)
/* menambah link ke suatu list. */

{
    next(newlink) = NULL;
    prev(newlink) = last(G);
    if (next(newlink)) prev(next(newlink)) = newlink;
                  else last(G) = newlink;
    if (prev(newlink)) next(prev(newlink)) = newlink;
                  else first(G) = newlink;
}

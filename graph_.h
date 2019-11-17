#include "boolean.h"
#include <stdlib.h>
#include <stdio.h>

#ifndef GRAPH_H
#define GRAPH_H

#define NilGraph NULL

typedef struct {
	int noBangunan;
} infotypeGraph;

typedef struct tNodeGraph* addrNode;
typedef struct tSuccNode* addrSuccNode;
typedef struct tNodeGraph {
	infotypeGraph IdBangunan;
	addrNode Next;
	addrSuccNode Trail;
} NodeGraph;

typedef struct tSuccNode
{
	addrNode Succ;
	addrSuccNode Next;
} SuccNode;

typedef struct 
{
	addrNode First;
} Graph;

/* Selektor */
#define FirstGraph(G) (G).First 
#define IdGraph(Pn) (Pn)->IdBangunan
#define TrailGraph(Pn) (Pn)->Trail
#define SuccGraph(Pn) (Pn)->Succ
#define NextGraph(Pn) (Pn)->Next 

/* Konstruktor */
void CreateGraph(infotypeGraph X, Graph* G);
/* membuat graph baru */
void InitGraph(Graph * G, char* source);
/* load graph dari external file */

/* Managemen memori */
addrNode AlokNodeGraph(infotypeGraph X);
/* mengembalikan hasil alokasi simpul */
void DeAlokNodeGraph(addrNode P);
/* mengembalikan simpul ke simpul */
addrSuccNode AlokSuccNode(addrNode Pn);
/* mengembalikan hasil alokasi succ*/
void DealokSuccNode(addrSuccNode P);
/* mengembalikan succ simpul ke sistem */

/* Operasi Graph */
boolean IsNodeEqual(addrNode P, infotypeGraph X);
/* mengembalikan apakah P memiliki ID X */
addrNode SearchNode(Graph G, infotypeGraph X);
/* mencari X pada G, return NilGraph bila tidak ada yang sama */
addrSuccNode SearchEdge(Graph G, infotypeGraph prec, infotypeGraph succ);
/* mencari succ dari prec pada G, return Nil jika tidak terdapat pada graph */
void InsertNode(Graph * G, infotypeGraph X, addrNode * Pn);
/* memasang X di akhir G */
void InsertEdge(Graph * G, infotypeGraph prec, infotypeGraph succ);
/*memasang succ ke akhir prec*/ 

infotypeGraph GetFirstSuccInfo(Graph G, infotypeGraph prec);
/* Mencari info succ simpul pertama dari node */

boolean IsConnected(Graph G, infotypeGraph prec, infotypeGraph succ);
/* Mengembalikan nilai kebenaran apakah suatu bangunan terkoneksi dengan bangunan lainnya */

#endif



















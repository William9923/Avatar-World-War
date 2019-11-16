#include"graph.h"
/* Konstruktor */
void CreateGraph(infotypeGraph X, Graph* G)
/* membuat graph baru */
{
	First(*G) = NilGraph;
	addrNode dummy;
	InsertNode(G,X,&dummy);

}

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
void InsertEdge(Graph * G, infotypeGraph prec, infotypeGraph succ);memasang succ ke akhir prec 

infotypeGraph GetFirstSuccInfo(Graph G, infotypeGraph prec);
/* Mencari info succ simpul pertama dari node */
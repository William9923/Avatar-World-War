#include"graph_.h"
/* Konstruktor */
void CreateGraph(infotypeGraph X, Graph* G)
/* membuat graph baru */
{
	FirstGraph(*G) = NilGraph;
	addrNode dummy;
	InsertNode(G,X,&dummy);

}

/* Managemen memori */
addrNode AlokNodeGraph(infotypeGraph X)
/* mengembalikan hasil alokasi simpul */
{
	addrNode P = (addrNode) malloc (sizeof(NodeGraph));
	if (P != NilGraph){
		IdGraph(P) = X;
		TrailGraph(P) = NilGraph;
		NextGraph(P) = NilGraph;
	}
	return P;
}
void DeAlokNodeGraph(addrNode P)
/* mengembalikan simpul ke simpul */
{
	free(P);
}
addrSuccNode AlokSuccNode(addrNode Pn)
/* mengembalikan hasil alokasi succ*/
{
	addrSuccNode P = (addrSuccNode) malloc (sizeof(SuccNode));
	if (P != NilGraph){
		SuccGraph(P) = Pn;
		NextGraph(P) = NilGraph;
	}
	return P;
}
void DealokSuccNode(addrSuccNode P)
/* mengembalikan succ simpul ke sistem */
{
	free(P);
}

/* Operasi Graph */
boolean IsNodeEqual(addrNode P, infotypeGraph X)
/* mengembalikan apakah P memiliki ID X */
{
	return (IdGraph(P).noBangunan == X.noBangunan);
}
addrNode SearchNode(Graph G, infotypeGraph X)
/* mencari X pada G, return NilGraph bila tidak ada yang sama */
{
	addrNode P = FirstGraph(G);
	while(P != NilGraph){
		if (IsNodeEqual(P,X)) return P;
		else P = NextGraph(P);
	}
	return P;
}
addrSuccNode SearchEdge(Graph G, infotypeGraph prec, infotypeGraph succ)
/* mencari succ dari prec pada G, return Nil jika tidak terdapat pada graph */
{
	addrNode Pn = SearchNode(G, prec);
	if (Pn == NilGraph) return NilGraph;
	addrSuccNode P = TrailGraph(Pn);
	while (P != NilGraph){
		if (IsNodeEqual(SuccGraph(P), succ)) return P;
		else P = NextGraph(P);
	}
	return P;
}
void InsertNode(Graph * G, infotypeGraph X, addrNode * Pn)
/* memasang X di akhir G */
{
	(*Pn) = AlokNodeGraph(X);
	addrNode P = FirstGraph(*G);
	if (P == NilGraph) FirstGraph(*G) = (*Pn);
	else {
		while (NextGraph(P) != NilGraph){
			P = NextGraph(P);
		}
		NextGraph(P) = (*Pn);
	}
}
void InsertEdge(Graph * G, infotypeGraph prec, infotypeGraph succ)
/*memasang succ ke akhir prec*/
{
	if (SearchEdge(*G, prec, succ) == NilGraph){
		addrNode Pn = SearchNode(*G,prec);
		if (Pn == NilGraph){
			InsertNode(G, prec, &Pn);
		}
		addrNode Ps = SearchNode(*G, succ);
		if (Ps == NilGraph){
			InsertNode(G, succ, &Ps);
		}
		addrSuccNode P = TrailGraph(Pn);
		if (P == NilGraph){
			TrailGraph(Pn) = AlokSuccNode(Ps);
		}
		else {
			while (NextGraph(P) != NilGraph){
				P = NextGraph(P);
			}
			NextGraph(P) = AlokSuccNode(Ps);
		}
	}
} 

infotypeGraph GetFirstSuccInfo(Graph G, infotypeGraph prec)
/* Mencari info succ simpul pertama dari node */
{
	infotypeGraph fal;
	// dummy value
	fal.noBangunan = -1;

	addrNode Pn = SearchNode(G, prec);
	if (Pn == NilGraph) return fal;

	addrSuccNode Ps = TrailGraph(Pn);
	if (Ps == NilGraph) return fal;

	return IdGraph(SuccGraph(Ps));
}
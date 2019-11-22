#include"./graph_.h"
#include"../array/array.c"
#include<stdlib.h>
#include<stdio.h>

int main() {
	Graph g;


	infotypeGraph a,b;

	a.noBangunan = 1;
	b.noBangunan = 2;

	infotypeGraph c;
	c.noBangunan = 3;

	infotypeGraph d;
	d.noBangunan = 4;

	CreateGraph(a, &g);
	addrNode P;

	// hubungan infotype 1
	InsertEdge(&g, a, b);
	InsertEdge(&g, a, c);

	// hubungan infotype 2
	InsertEdge(&g, b, a);
	InsertEdge(&g, b, c);

	InsertNode(&g, d, &P);



	/*Printing result*/
	addrNode P1 = FirstGraph(g);
	while(P1 != NilGraph){
		infotypeGraph Id1 = IdGraph(P1);
		addrSuccNode Ps = TrailGraph(P1);
		while (Ps != NilGraph) {
			infotypeGraph Id2 = IdGraph(SuccGraph(Ps));
			printf("%d %d\n", Id1.noBangunan, Id2.noBangunan);
			Ps = NextGraph(Ps);
		}
		P1 = NextGraph(P1);
	}

	if (IsConnected(g, b,b)){
		printf("%s\n", "Connected");
	} else {
		printf("%s\n", "Not connected");
	}
}
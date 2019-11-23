#include "saveload.c"
#include <stdio.h>


int main() {
    Pemain P1,P2,Pnow;
	StackUndo SU;
    PETA P;
    TabBangunan AllBangunan;
    Graph connectivity;
	List Netral;
	int turn=1;
	//Baca Konfigurasi Permainan
	printf("Reading Configuration File...\n");
    CreateEmptyList(&Netral);
    readkonfig(&P,&AllBangunan,&connectivity,&P1,&P2,&Netral);
    P1.nomor = 1;
	P2.nomor = 2;
	StartSkill(&((P1).Skill));StartSkill(&((P2).Skill));
	Pnow = P1;

    savefile(P1,P2,Pnow,SU,P,AllBangunan,connectivity,Netral,turn);
}
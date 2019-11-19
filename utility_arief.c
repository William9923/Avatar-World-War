#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"bangunan.h"
#include"point.h"
#include"state.h"
#include"array.h"
#include"matriks.h"
//#include "listbangunan.h"
#include "mesinkar.h"
#include "mesinkata.h"
//#include "skill.h"
#include"pemain.h"
#include"bangunan.c"
#include"point.c"
#include"state.c"
#include"array.c"
#include"matriks.c"
//#include "listbangunan.c"
#include "listlinier.c"
#include "mesinkar.c"
#include "mesinkata.c"
#include "readkonfigurasi.c"
//#include "skill.c"
#include"pemain.c"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"stackundo.c"
#include"utility_william.c"
#include"graph_.h"
#include"graph_.c"
#include<math.h>
#include"boolean.h"

void clrscr(){
	system("clear");
	// ini gw ganti dikit ya
}

void PemainNow(Pemain P1,Pemain P2,Pemain *P,boolean swapTurn,int turn){
	if(swapTurn){
		//genap jadi P1, ganjil P2
		if(turn%2==0){
			*P = P1;
		}
		else{
			*P = P2;
		}
	}
	else{
		//ganjil P1, genap P2
		if(turn%2==0){
			*P = P2;
		}
		else{
			*P = P1;
		}
	}
}

void ChangeTurnOrder(boolean *swapTurn){
	if(*swapTurn){
		*swapTurn = false;
	}
	else{
		*swapTurn = true;
	}
}

boolean IsEQPemain(Pemain P1, Pemain P2){
	boolean same = true;

	if ((P1.nomor != P2.nomor)){
		same = false;
	}
	return same;
}

int main() {
	//KAMUS
	Pemain P1,P2,Pnow;
	StackUndo SU;
    PETA P;
    TabBangunan AllBangunan;
    Graph connectivity;
	List Netral;
	int turn=1,nomor=1;
	boolean swapTurn = false;
	char CMD[9];
	CreateNewPlayer(&P1,nomor);
	nomor++;
	CreateNewPlayer(&P2,nomor);
	//Baca Konfigurasi Permainan
	printf("Reading Configuration File...\n");
    CreateEmptyList(&Netral);
    readkonfig(&P,&AllBangunan,&connectivity,&P1,&P2,&Netral);
    //aDD LIST b KE SI pEMAIN 1
	printf("Game Ready...\n");
	printf("Press Any Key To Continue..\n");
	clrscr();
	boolean stop = false;
    char *s;
	CreateEmptyStackUndo(&SU);
	while(!stop){
		//Validasi Command
		
		//Print Map
		PemainNow(P1,P2,&Pnow,swapTurn,turn);
		CetakPeta(P,P1,P2,AllBangunan);
		
		//Baca Command taruh disini...
		//...
		printf("Player %d\n",Pnow.nomor);
		PrintInfoLBangunan(AllBangunan,Pnow);
		//printskill
		printf("ENTER COMMAND: ");
		
		s = BacaInputUser();
		printf("\n");
		if(IsAttack(s)){
			if (IsEQPemain(Pnow, P1)) {
				ProsedurAttack(&AllBangunan, &P1, &P2,&Netral ,connectivity);
				SaveState(&SU,P1,P2,Netral,AllBangunan);
			} else {
				// pemain p2
				ProsedurAttack(&AllBangunan, &P2, &P1,&Netral ,connectivity);
				SaveState(&SU,P1,P2,Netral,AllBangunan);
			}
		}
		else if(IsLevelUp(s)){

		}
		else if(IsMove(s)){
			if (IsEQPemain(Pnow, P1)){
				ProsedurMove(&AllBangunan, &P1, connectivity);
				SaveState(&SU,P1,P2,Netral,AllBangunan);
			} else {
				// pemain p2
				ProsedurMove(&AllBangunan, &P2, connectivity);
				SaveState(&SU,P1,P2,Netral,AllBangunan);
			}
		}
		else if(IsSkill(s)){

		}
		else if(IsUndo(s)){
			LoadState(&SU,&P1,&P2,&Netral,&AllBangunan);
			continue;
			PemainNow(P1,P2,&Pnow,swapTurn,turn);
		}
		else if(IsEndTurn(s)){
			if (turn > 1){
				if (IsEQPemain(Pnow, P2)){
					NextTurnLBangunan(P1.b, &AllBangunan);
				} else {
					// P1 sekarang
					NextTurnLBangunan(P2.b, &AllBangunan);
				}
			}
			turn++;
			system("clear");
		}
		else if(IsSave(s)){

		}
		else{
			printf("Inputan tidak valid.\n");
		}
	}
}
//Revisi:
//Perbaiki StackUndo
//Penambahan MAP
//Pengubahan ADT Pemain
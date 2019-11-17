#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"bangunan.h"
#include"point.h"
#include"stack.h"
#include"state.h"
#include"array.h"
#include"matriks.h"
#include "listbangunan.h"
#include "mesinkar.h"
#include "mesinkata.h"
#include "readkonfigurasi.h"
#include "skill.h"
#include"pemain.h"
#include"bangunan.c"
#include"point.c"
#include"stack.c"
#include"state.c"
#include"array.c"
#include"matriks.c"
#include "listbangunan.c"
//#include "listlinier.c"
#include "mesinkar.c"
#include "mesinkata.c"
#include "readkonfigurasi.c"
#include "skill.c"
#include"pemain.c"
#include<stdio.h>
#include<stdlib.h>
#include"boolean.h"
#include<string.h>
#include"stackundo.h"

void clrscr(){
	system("@cls||clear");
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

int main() {
	//KAMUS
	Pemain P1,P2,Pnow;
	StackUndo SU;
	int turn=0,nomor=1;
	boolean swapTurn = false;
	char CMD[9];
	CreateNewPlayer(&P1,'r',nomor);
	nomor++;
	CreateNewPlayer(&P2,'b',nomor);
	//Baca Konfigurasi Permainan
	printf("Reading Configuration File...\n");
	readkonfig();
	printf("Game Ready...\n");
	printf("Press Any Key To Continue..");
	scanf("_");
	clrscr();
	boolean stop = false;
	while(!stop){
		//Validasi Command 
		//Yang dibawah semua buat else
		CreateEmptyStackUndo(&SU);
		//Print Map
		turn++;
		PemainNow(P1,P2,&Pnow,swapTurn,turn);
		//Cetak Peta

		//Baca Command taruh disini...
		//...
		printf("Player %d\n",Pnow.nomor);
		//PrintListBangunan
		
	}
}
//Revisi:
//Perbaiki StackUndo
//Penambahan MAP
//Pengubahan ADT Pemain
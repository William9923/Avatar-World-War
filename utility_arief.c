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
#include "skill.h"
#include"pemain.h"
#include"bangunan.c"
#include"point.c"
#include"state.c"
#include"array.c"
#include"matriks.c"
#include"skill.c"
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
#include"utility_felix.c"
#include"graph_.h"
#include"graph_.c"
#include<math.h>
#include"boolean.h"
#include"prosedur_skill.c"

boolean IsEQPemain(Pemain P1, Pemain P2){
	boolean same = true;

	if ((P1.nomor != P2.nomor)){
		same = false;
	}
	return same;
}


void NextPemain(Pemain P1,Pemain P2,Pemain *P){
	if(IsEQPemain(P1,*P)){
		*P = P2;
	}
	else{
		*P = P1;
	}
}

int main() {
	//KAMUS
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
	printf("Game Ready...\n");
	printf("Press Any Key To Continue..\n");
	clrscr();
	boolean stop = false;
	P1.nomor = 1;
	P2.nomor = 2;
	StartSkill(&((P1).Skill));StartSkill(&((P2).Skill));
	Pnow = P1;
	char * s;
	while(!stop){
		//Validasi Command
		//Print Map
		CreateEmptyStackUndo(&SU);
		int jatah=1;
		
		while(!stop && jatah!=0){
			printf("%s%d%s\n", "**************TURN ", turn , "**************");
			CetakPeta(P,P1,P2,AllBangunan);
			//Baca Command taruh disini...
			//...
			printf("Player %d\n",Pnow.nomor);
			//Ngerefresh isi Pnow setelah Undo
			if(Pnow.nomor==1){
				Pnow = P1;
			}
			else{
				Pnow = P2;
			}
			PrintInfoLBangunan(AllBangunan,Pnow);


			printf("%s", "Skill Available: ");
			if (IsEQPemain(P1,Pnow)){
				ShowSkill((P1.Skill));
			} else {
				ShowSkill((P2.Skill));
			}
			printf("\n");
			printf("ENTER COMMAND: ");
			s = BacaInputUser();
			printf("\n");
			if(IsAttack(s)){
				if (IsEQPemain(Pnow, P1)) {
					ProsedurAttack(&AllBangunan, &P1, &P2,&Netral ,connectivity,&SU, &((P1).Skill), &((P2).Skill));
				} else {
					// pemain p2
					ProsedurAttack(&AllBangunan, &P2, &P1,&Netral ,connectivity,&SU, &((P2).Skill), &((P1).Skill));
				}
				endgame(P1,P2,&stop);
			}
			else if(IsLevelUp(s)){
				if (IsEQPemain(Pnow, P1)) {
					ProsedurLevelUp(&AllBangunan,P1,P1,P2,Netral,&SU);	
				} else {
					// pemain p2
					ProsedurLevelUp(&AllBangunan,P2,P1,P2,Netral,&SU);
				}
			}
			else if(IsMove(s)){
				if (IsEQPemain(Pnow, P1)){
					ProsedurMove(&AllBangunan, &P1, connectivity,P1,P2,Netral,&SU);
				} else {
					// pemain p2
					ProsedurMove(&AllBangunan, &P2, connectivity,P1,P2,Netral,&SU);
				}
			}
			else if(IsSkill(s)){
				if (IsEQPemain(P1, Pnow)){
					PakeSkill (&((P1).Skill),&AllBangunan,&P1, &P2, &jatah,&SU);
				} else {
					PakeSkill (&((P2).Skill),&AllBangunan,&P2, &P1, &jatah,&SU);
				}
			}
			else if(IsUndo(s)){
				if(!IsEmptyStack(SU)){
					LoadState(&SU,&P1,&P2,&Netral,&AllBangunan);
				}
				else{
					printf("Tidak ada yang bisa di undo!.\n");
				}
			}
			else if(IsEndTurn(s)){
				if(jatah>1){
					if (IsEQPemain(Pnow, P1)){
						NextTurnLBangunan(P1.b, &AllBangunan);
						CheckAddIR(&((P1).Skill),&((P2).Skill),AllBangunan,P1,P2);
					} else {
						// P1 sekarang
						NextTurnLBangunan(P2.b, &AllBangunan);
						CheckAddIR(&((P2).Skill),&((P1).Skill),AllBangunan,P2,P1);
					}
				}
				else{
					if (IsEQPemain(Pnow, P2)){
						NextTurnLBangunan(P1.b, &AllBangunan);
						CheckAddIR(&((P2).Skill),&((P1).Skill),AllBangunan,P2,P1);
					} else {
						// P1 sekarang
						NextTurnLBangunan(P2.b, &AllBangunan);
						CheckAddIR(&((P1).Skill),&((P2).Skill),AllBangunan,P1,P2);
					}
				}
				turn++;
				jatah--;
				CreateEmptyStackUndo(&SU);
				system("clear");
			}
			else if(IsSave(s)){
				
			}
			else if(IsExit(s)) {
				stop = true;
			}
			else{
				printf("Inputan tidak valid.\n");
			}
		}
		NextPemain(P1,P2,&Pnow);
	}
}

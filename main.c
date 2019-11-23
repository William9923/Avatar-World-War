#include"include.h"

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
	CreateNewPlayer(&P1,1);	
	CreateNewPlayer(&P2,2);
    CreateEmptyList(&Netral);
    readkonfig(&P,&AllBangunan,&connectivity,&P1,&P2,&Netral);
	StartGame();
	clrscr();
	boolean stop = false;
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
				endgame(P1,P2,&stop,turn);
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
						P1.AttackUp=false;
					} else {
						// P1 sekarang
						NextTurnLBangunan(P2.b, &AllBangunan);
						CheckAddIR(&((P2).Skill),&((P1).Skill),AllBangunan,P2,P1);
						P2.AttackUp=false;
					}
				}
				else{
					if (IsEQPemain(Pnow, P2)){
						NextTurnLBangunan(P1.b, &AllBangunan);
						CheckAddIR(&((P2).Skill),&((P1).Skill),AllBangunan,P2,P1);
						P2.AttackUp=false;
					} else {
						// P1 sekarang
						NextTurnLBangunan(P2.b, &AllBangunan);
						CheckAddIR(&((P1).Skill),&((P2).Skill),AllBangunan,P1,P2);
						P1.AttackUp=false;
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




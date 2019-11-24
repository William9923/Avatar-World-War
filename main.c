#include"./include.h"

boolean IsEQPemain(Pemain P1, Pemain P2){
	/** Mengecek apakah P1 dan P2 adalah Pemain yang sama **/
	boolean same = true;

	if ((P1.nomor != P2.nomor)){
		same = false;
	}
	return same;
}


void NextPemain(Pemain P1,Pemain P2,Pemain *P){
	/** Berfungsi menentukan Pemain selanjutnya yang disimpan pada P **/
	if(IsEQPemain(P1,*P)){
		*P = P2;
	}
	else{
		*P = P1;
	}
}

void changecolor(Pemain Pnow, Pemain P1, Pemain P2){
	/** Berfungsi mengubah warna menyesuaikan siapa player sekarang, bila P1 maka merah dan P2 maka cyan selain itu green **/
	if (IsEQPemain(Pnow,P1)){
		red();
	} else if (IsEQPemain(Pnow,P2)) {
		cyan();
	} else {
		green();
	}
}

void cetakTurn(int turn,int space){
	/**berfungsi mencetak turn sekarang pada layar sebelum peta **/
	int halfspace = (space - 6) / 2;
	for (int i = 1; i <= 3; i++){
		printf("   ");
	}
	for (int i = 1; i <= space; i++){
		printf("═");
	}
	printf("\n");
	for (int i = 1; i <= 3; i++){
		printf("   ");
	}
	for (int i = 1; i <= halfspace; i++){
		printf(" ");
	}
	printf("TURN %d",turn);
	for (int i = 1; i <= halfspace; i++){
		printf(" ");
	}
	for (int i = 1; i <= 3; i++){
		printf("   ");
	}
	printf("\n");
	for (int i = 1; i <= 3; i++){
		printf("   ");
	}
	for (int i = 1; i <= space; i++){
		printf("═");
	}
	printf("\n");
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
	boolean newgame;
	char *path_file_konfig;
	char * s;
	int jatah;
	boolean menu =true;

	clrscr();//Membersihkan layar console
	printf("New Game or Load a saved game?\nType LOAD if you want to load a saved game.\nOtherwise type NEW.\n");
	green();
	
	normal();
	//Pengosongan variabel atau pengalokasian memory
	CreateNewPlayer(&P1,1);	
	CreateNewPlayer(&P2,2);
    CreateEmptyList(&Netral);
	CreateNewPlayer(&P1,1);	
	CreateNewPlayer(&P2,2);

	//Looping selama inputan tidak benar
	while(menu) {
		s = BacaInputUser();
		if (IsNew(s)) { //jika player memilih new
			clrscr();
			//Baca Konfigurasi Permainan
			printf("Reading Configuration File...\n");
			path_file_konfig = "file konfig.txt";
			readkonfig(path_file_konfig,&P,&AllBangunan,&connectivity,&P1,&P2,&Netral);
			newgame = true;
			StartSkill(&((P1).Skill));StartSkill(&((P2).Skill));
			Pnow = P1;
			menu=false;
		} else if(IsLoad(s)) { //jika player memilih load
			ProsedurLoad(&P1,&P2,&Pnow,&P,&AllBangunan,&connectivity,&Netral,&jatah);
			printf("Loading game from a saved file...\n");
			newgame = false;
			menu = false;
		} else {
			printf("Inputan tidak valid.\n");
		}
	}
	
	StartGame();//memulai game
	clrscr();
	clrscr();
	boolean stop = false;
	

	/* Desain game */
	int space = GetLastIdxBrs(P) * 5;

	//Looping selama game belum berakhir
	while(!stop){
		CreateEmptyStackUndo(&SU);//Pengosongan StackUndo setiap satu turn
		if (newgame) {
			jatah=1;
		} else {
			newgame = true;
		}
		
		//selama player masih memiliki jatah untuk bermain (turn) dan game belum berakhir
		while(!stop && jatah!=0){
			
			changecolor(Pnow,P1,P2);
			cetakTurn(turn,space);
			normal();
			CetakPeta(P,P1,P2,AllBangunan);
			yellow();
			printf("Player %d\n",Pnow.nomor);
			normal();
			//Ngerefresh isi Pnow setelah Undo
			if(Pnow.nomor==1){
				Pnow = P1;
			}
			else{
				Pnow = P2;
			}
			yellow();
			PrintInfoLBangunan(AllBangunan,Pnow);
			normal();
			yellow();
			printf("%s", "Skill Available: ");
			if (IsEQPemain(P1,Pnow)){
				ShowSkill((P1.Skill));
			} else {
				ShowSkill((P2.Skill));
			}
			printf("\n");
			CommandList();
			printf("ENTER COMMAND: ");
			normal();
			s = BacaInputUser();
			printf("\n");
			green();
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
				normal();
				turn++;
				jatah--;
				CreateEmptyStackUndo(&SU);
				system("clear");
			}
			else if(IsSave(s)){
				ProsedurSave(P1, P2, Pnow, P, AllBangunan, connectivity, Netral, jatah);
				clear_user_input();
			}
			else if(IsExit(s)) {
				stop = true;//game berakhir
			}
			else{
				printf("Inputan tidak valid.\n");
			}
		}
		NextPemain(P1,P2,&Pnow);
	}
}
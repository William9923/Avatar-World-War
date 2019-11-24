#include "./prosedur_skill.h"

/***************************************************************************************************************************************************
* Prosedur Skill                                                                                                                                   *
* Author : Kelompok Alstrukdat                                                                                                                     *
* Created at : 14 November 2019                                                                                                                    *
* Merupakan File Implementasi Skill pada Game ini                                                                                                  *
* Digunakan untuk pemenuhan kebutuhan fungsi - fungsi dalam game yang                                                                              *
* membutuhkan lebih dari 1 (satu) jenis ADT dan berhubungan dengan                                                                                 *
* penggunaan skill.                                                                                                                                *
*                                                                                                                                                  *
* SKILL yang terdapat pada FILE ini :                                                                                                              *
* 1. Instant Upgrade                                                                                                                               *
* 2. Extra Turn                                                                                                                                    *
* 3. Instant Reinforcement                                                                                                                         *
* 4. Barrage                                                                                                                                       *
*                                                                                                                                                  *
* Selain itu, di file ini juga banyak didefinisikan dan diimplementasikan fungsi - fungsi validator yang akan memvalidasi inputan user / pengguna  *
***************************************************************************************************************************************************/

void InstantUpgrade(TabBangunan * tab, Pemain p1){
	/* Implementasi Dari Instant Upgrade */
	address last=FirstL(p1.b);

    for (int i = 1; i <= NbElmtList(p1.b); i++){
		if (Level(ElmtArray((*tab), InfoL(last))) < 4) {
			Pasukan(ElmtArray((*tab), InfoL(last))) += M(ElmtArray((*tab), InfoL(last))) / 2;
			NaikLevel(&(ElmtArray((*tab), InfoL(last))));
		}
        last = NextL(last);
    }
}

void TambahPasukanB(Bangunan * bangunan, int n){
	/* Prosedur antara untuk menambah jumlah bangunan */
	Pasukan(*bangunan) += n;
}

void KurangPasukan(Bangunan * bangunan, int n){
	if ((Pasukan(*bangunan) - n) < 0){
		Pasukan(*bangunan) = 0;
	} else {
		Pasukan(*bangunan) -= n;
	}
}

void InstantReinforcement(TabBangunan * tab, Pemain p1) {
	/* Implementasi dari instant reinforcement */
	address last = FirstL(p1.b);
	int tambahanPasukan = 5;
	for (int i = 1; i <= NbElmtList(p1.b); i++){
		TambahPasukanB(&(ElmtArray((*tab), InfoL(last))),tambahanPasukan);
		last = NextL(last);
	}
}

void Barrage(TabBangunan * tab, Pemain * p1, Pemain * p2){
	/* Implementasi dari Barrage */
	address last = FirstL((*p2).b);
	int kurangPasukan = 10;
	for(int i = 1; i <= NbElmtList((*p2).b); i++){
		KurangPasukan(&(ElmtArray((*tab), InfoL(last))), kurangPasukan);
		last = NextL(last); // next element
	}
}

void ExtraTurn (int * n){
	/* Mengaktifkan skill ekstra turn */
	(*n) += 1;
}

void CriticalHit(Pemain *P){
	/* Mengaktifkan critical hit untuk satu orang pemain */
	(*P).CriticalHit = true;
}

void AttackUp(Pemain *P){
	/* Mengaktifkan skill attack up untuk pemain */
	(*P).AttackUp = true;
}

void Shield(Pemain *P){
	/* Mengaktifkan skill Shield untuk pemain tertentu */
	(*P).Shield = 2;
}

boolean IsObtainIR (TabBangunan tab, Pemain p1){
	/* Fungsi untuk melakukan pengecekan apakah pemain 
	   mendapatkan skill Instant Reinforcement atau tidak */
	address last = FirstL(p1.b);
	boolean checker = true;
	int i = 1;
	while (i <= NbElmtList(p1.b) && checker){
		if (Level(ElmtArray(tab, InfoL(last))) < 4){
			checker = false;
		}
		i++;
		last = NextL(last);
	}
	return checker;
}

boolean IsObtainBarrage(Pemain p2){
	/* Fungsi untuk melakukan pengecekan apakah seorang pemain mendapatkan skill Barrage atau tidak
	Notes : yang dibutuhkan untuk pengecekan hanyalah List bangunan musuh */
	return (NbElmtList(p2.b) == 10);
}
boolean IsObtainExtraTurn(TabBangunan tab, IdxTypeArray i, Pemain p2){
	/* Fungsi untuk melakukan pengecekan apakah seorang pemain mendapatkan skill Extra Turn 
	   Pengecekan dilakukan dengan mengecek apakah bangunan yang akan didapatkan berupa Fort atau tidak */
	return (Type(ElmtArray(tab, i)) == 'F');
}

boolean IsObtainShield(Pemain P){
	return NbElmtList(P.b)==2;	
}

boolean IsObtainAttackUp(Bangunan B,Pemain *P1,TabBangunan Tab){
	int counterTower=0;
	address Last= FirstL((*P1).b);
	for(int i=1;i<=NbElmtList((*P1).b);i++){
		if((ElmtArray(Tab,InfoL(Last)).type)=='T'){
			counterTower++;
		}
		Last = NextL(Last);
	}
	return (B.type=='T' && counterTower==3);
}

void CheckAddAttackUp(Bangunan B,Pemain *P1,TabBangunan Tab){
	if (IsObtainAttackUp(B,P1,Tab)){
		if (!IsFullQueue((*P1).Skill)){
			AddSkillQueue(&(*P1).Skill, 'D');
			printf("Player %d mendapatkan skill Attack Up\n", (*P1).nomor);
		} else {
			printf("Player %d mendapatkan skill Attack Up! Namun skill pouch sudah penuh\n", (*P1).nomor);
		}
	}
}

void CheckAddShield(Pemain *P2){
	if(IsObtainShield(*P2)){
		if (!IsFullQueue((*P2).Skill)){
			AddSkillQueue(&(*P2).Skill, 'B');
			printf("Player %d mendapatkan skill Shield\n", (*P2).nomor);
		} else {
			printf("Player %d mendapatkan skill Shield! Namun skill pouch sudah penuh\n",(*P2).nomor);
		}
	}
}

void CheckAddCriticalHit(Pemain *P){
	if (!IsFullQueue((*P).Skill)){
		AddSkillQueue(&(*P).Skill, 'E');
		printf("Player %d mendapatkan skill Critical Hit\n", (*P).nomor);
	} else {
		printf("Player %d mendapatkan skill Critical Hit! Namun skill pouch sudah penuh\n",(*P).nomor);
	}

}

void CheckAddExtraTurn(Queue * q1,TabBangunan tab, IdxTypeArray i, Pemain P1, Pemain P2){
	if (IsObtainExtraTurn(tab,i,P2)){
		if (!IsFullQueue(*q1)){
			AddSkillQueue(q1, 'C');
			printf("Player %d mendapatkan skill Extra Turn\n", P1.nomor);
		} else {
			printf("Player %d mendapatkan skill Extra Turn! Namun skill pouch sudah penuh\n", P1.nomor);
		}
	}
}

void CheckAddBarrage(Queue * q1,TabBangunan tab, Pemain p1, Pemain p2){
	if (IsObtainBarrage(p2)){
		if (!IsFullQueue(*q1)){
			AddSkillQueue(q1, 'G');
			printf("Player %d mendapatkan skill Barrage\n", p1.nomor);
		} else {
			printf("Player %d mendapatkan skill Barrage! Namun skill pouch sudah penuh\n", p1.nomor);
		}
	}
}

void CheckAddIR(Queue * q1, Queue * q2, TabBangunan tab, Pemain P1, Pemain P2){
	if (IsObtainIR (tab,P1)){
		if (!IsFullQueue(*q1)){
			AddSkillQueue(q1, 'F');
			printf("Player %d mendapatkan skill Instant Reinforcement\n", P1.nomor);
		} else {
			printf("Player %d mendapatkan skill Instant Reinforcement! Namun skill pouch sudah penuh\n", P1.nomor);
		}
	}
}
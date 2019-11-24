#define printInt(x) printf("%d", x)
#define printlnInt(x) printf("%d\n", x)
#define println(x) printf("%c\n", x)
#define print(x) printf("%c", x)
#define bacaInt(x) scanf("%d", &x)
#define bacaChar(x) scanf("%c", &c)
#define endline printf("\n")

#include "../Prosedur/prosedur_art.h"

/***************************************************************************************************************************************************
* Utility                                                                                                                                          *
* Author : Kelompok Alstrukdat                                                                                                                     *
* Created at : 13 November 2019                                                                                                                    *
* Merupakan File Utility dari Game ini                                                                                                             *
* Digunakan untuk pemenuhan kebutuhan fungsi - fungsi dalam game yang                                                                              *
* membutuhkan lebih dari 1 (satu) jenis ADT                                                                                                        *
* Selain itu, file ini juga berisi implementasi terhadap hampir seluruh jenis Prosedur yang dibutuhkan dalam game                                  *
*                                                                                                                                                  *
* Prosedur COMMAND yang terdapat di File ini :                                                                                                     *
* 1. ATTACK                                                                                                                                        *
* 2. MOVE                                                                                                                                          *
* 3. LEVEL_UP                                                                                                                                      *
*                                                                                                                                                  *
* Selain itu, di file ini juga banyak didefinisikan dan diimplementasikan fungsi - fungsi validator yang akan memvalidasi inputan user / pengguna  *
***************************************************************************************************************************************************/

void clrscr(){
	system("clear");
}

/* buat bersihin stream setelah save file */
void clear_user_input() {
  if (isatty(STDIN_FILENO)) {
    int fd = open(ttyname(STDIN_FILENO), O_RDONLY);
    ioctl(fd, TCFLSH, TCIFLUSH);
    close(fd);
  }
}


boolean IsAbleMove(Bangunan bangunanAwal, Bangunan bangunanTujuan, int n, Pemain P,TabBangunan Tab){
	/* Mengecek apakah pasukan suatu bangunan dapat dipindahkan ke bangunan tujuan*/
	/*
		Validasi didasari oleh :
			1. Apakah bangunan 1 terhubung dengan bangunan 2
	*/

	// cek keterhubungan
	// cek apakah kedua bangunan berasal dari pemilik yang sama
	// cek apakah jumlah pasukan yang dimasukkan valid

	// tambahin cek keterhubungan 2 bangunan
	if (!(haveBuildingB(P,bangunanAwal,Tab)) || !(haveBuildingB(P,bangunanTujuan,Tab))){
		return false;
	} 
	if (Pasukan(bangunanAwal) < n || n < 0){
		return false;
	}
	if (IsSudahMove(bangunanAwal)){
		return false;
	}
	return true;
}

void MoveB(IdxTypeArray i,IdxTypeArray j, int n, Pemain P,TabBangunan * tab){
	/*
	I.S. Bangunan Awal dan Bangunan Tujuan terdefinisi
		 Jumlah pasukan <= pasukan total di bangunanAwal
	F.S. Pasukan sebanyak n dipindahkan ke bangunanTujuan dari bangunan Awal
	Pemain d
	*/
	if (IsAbleMove(ElmtArray((*tab),i),(ElmtArray((*tab),j)),n, P,(*tab))) {
		Pasukan(ElmtArray((*tab),i)) -= n;
		Pasukan(ElmtArray((*tab),j)) += n;
		Move(ElmtArray((*tab),i)) = true;
		printf("%s\n", "Pasukan telah bermigrasi");
	} else {
		if (Pasukan(ElmtArray((*tab),i)) < n){
			printf("%s\n", "Jumlah pasukan anda kurang !");
		} else if(!(haveBuildingB(P,ElmtArray((*tab),i),(*tab))) || !(haveBuildingB(P,ElmtArray((*tab),j),(*tab)))) {
			printf("%s\n", "Bangunan tidak tersambung satu sama lain!");
		} else {
			printf("%s\n", "Jumlah pasukan tidak valid!");
		}
	}
}

boolean IsAbleSerang(Bangunan bangunanPe, Bangunan bangunanDe, int n){
	/*
		Mengecek apakah suatu bangunan dapat menyerang bangunan bertahan
		1. Cek apakah tersambung
		2. Cek apakah dia uda pernah nyerang
		3. Cek apakah jumlah penyerang tidak lebih dari jumlah total pasukan di bangunan tersebut
	*/

	// cek keterhubungan
	if (IsSudahSerang(bangunanPe)){
		// cek kondisi apakah sudah pernah menyerang atau belum
		printf("%s\n\n", "Pasukan lelah!. Bangunan ini telah menyerang di turn yang sama");
		return false;
	} 
	if (Pasukan(bangunanPe) < n){
		// cek apakah jumlah pasukan yang diinput valid atau tidak
		printf("%s\n\n", "Jumlah pasukan tidak mencukupi!");
		return false;
	}
	if (n < 0){
		printf("%s\n", "Jumlah pasukan tidak valid");
		return false;
	}
	return true;
}

boolean IsBangunanNetral(Bangunan b, Pemain p1, Pemain p2, TabBangunan tab){
	/* Melakukan pengecekan apakah suatu bangunan bersifat netral atau tidak */
	// cari indeks
	infotypeList i = SearchIdxBangunan(tab, b);
	if ((SearchList(p1.b,i) == Kosong) && (SearchList(p2.b,i) == Kosong)) return true;
	else return false;
}

void SerangB(IdxTypeArray i, IdxTypeArray j, int n, Pemain * P1, Pemain * P2, List * Netral, TabBangunan * tab, Queue * q1, Queue * q2){
	/*
	I.S. 2 Bangunan Terdefinisi
	F.S. bangunan 1 menyerang bangunan 2
	*/
	int x;
	boolean Temp = Pertahanan(ElmtArray((*tab),j));
	int TempPasukan = n;
	if (IsAbleSerang(ElmtArray((*tab),i), ElmtArray((*tab),j), n)){
		if((*P1).AttackUp==true){
			Pertahanan(ElmtArray((*tab),j))=false;
		}
		else if((*P1).CriticalHit==true){
			n*=2;
		}
		else if((*P2).Shield!=0){
			Pertahanan(ElmtArray((*tab),j))=true;
		}
		if (IsPindahPemilik(ElmtArray((*tab),j),n)){
			if (Pertahanan(ElmtArray((*tab),j))){
				x = ceil((4.0/3) * Pasukan(ElmtArray((*tab),j)));
				Pasukan(ElmtArray((*tab),j)) = n - x;
			} else {
				// tidak ada pertahanan
				Pasukan(ElmtArray((*tab),j)) = n - Pasukan(ElmtArray((*tab),j));
			}
			Pasukan(ElmtArray((*tab),i)) -= TempPasukan;
			// kalo dia bersifat netral
			if (IsBangunanNetral(ElmtArray((*tab),j), (*P1), (*P2), *tab)){
				InsVLastList(&((*P1).b),j);
				DelPList(Netral, j);
				CheckAddBarrage(q2 ,(*tab), (*P2), (*P1));
			} else{
				// kalo dia ternata punya orang
				MakeLevelOne(&(ElmtArray((*tab),j)));
				InsVLastList(&((*P1).b),j);
				DelPList(&((*P2).b), j);
				DelPList(&((*P2).b), j);
				CheckAddShield(P2);		
				CheckAddAttackUp((ElmtArray((*tab),j)),P1,*tab);
				CheckAddBarrage(q2 ,(*tab), (*P2), (*P1));
				CheckAddExtraTurn(q2,(*tab), j, (*P2), (*P1));
			} 
			printf("%s\n", "Bangunan menjadi milikmu");
		} else {
			if (Pertahanan(ElmtArray((*tab),j))) {
				x = (3/4.0) * n;
				Pasukan(ElmtArray((*tab),j)) -= x;
			} else {
				Pasukan(ElmtArray((*tab),j)) = Pasukan(ElmtArray((*tab),j)) - n;
			}
			Pasukan(ElmtArray((*tab),i)) -= TempPasukan;
			printf("%s\n", "Bangunan gagal direbut");
		}
	Serang(ElmtArray((*tab),i)) = true;
	Pertahanan(ElmtArray((*tab),j)) = Temp;
	if((*P2).Shield>0){
		(*P2).Shield--;
		if((*P2).Shield == 0 ){
			printf("\nShield musuh habis.\n");
		}
		else{
			printf("\nShield musuh tinggal %d turn lagi.\n",(*P2).Shield);
		}
	}
	(*P1).CriticalHit=false;
	}
}

void NextTurnLBangunan (List  L, TabBangunan * tab){
	address last;
	last = FirstL(L);
	infotypeList a;
	while(last != Kosong){
		a = InfoL(last);
		NextTurnBangunan(&(ElmtArray(*tab, a)));
		last = NextL(last);
	}
}


void NextTurnPemain(Pemain * P, TabBangunan * tab){
	/*
	I.S. Pemain terdefinisi,
		 Seluruh bangunan yang dimiliki pemain dalam keadaan turn sebelumnya
	F.S. Seluruh bangunan milik pemain memiliki kondisi yang terubah sesuai dengan 
		 ketentuan bangunan
	btw, buat perubahan yang terjadi taro disini aja
	*/
	NextTurnLBangunan((*P).b, tab);
	// ketentuan perubahan status pada turn berikutnya
}

void PrintInfoLBangunan(TabBangunan tab, Pemain p){
	address last = FirstL((p).b);
	int count = 0;
	while (last != Kosong){
		count++;
		printf("%d. ", count);
		CetakBangunanIndeks(tab, InfoL(last));
		last =  NextL(last);
	}
	endline;
}

void PrintInfoLBangunanSemua(TabBangunan tab){
	for (int i = 1; i <= NbElmt(tab); i++){
		CetakBangunanIndeks(tab, i);
	}
}

/* Print daftar bangunan bisa attack */
void PrintInfoLBangunanAttack(TabBangunan tab, Pemain p, IdxTypeArray j ,Graph g){
	int count = 0;
	for (IdxTypeArray i = 1; i <= NbElmt(tab); i++){
		if (i != j && IsConnected(g, j , i) && !haveBuildingB(p, ElmtArray(tab,i), tab)){
			count++;
			printf("%d. ", count);
			CetakBangunanIndeks(tab, i);
			endline;
		}
	}
}

/* Print daftar bangunan bisa move */
void PrintInfoLBangunanMove(TabBangunan tab, Pemain p, IdxTypeArray j, Graph g){
	int count = 0;
	for (IdxTypeArray i = 1; i <= NbElmt(tab); i++){
		if (i != j && IsConnected(g,j,i) && haveBuildingB(p, ElmtArray(tab, i), tab)){
			count++;
			printf("%d. ", count);
			CetakBangunanIndeks(tab,i);
			endline;
		}
	}
}	

/* Create an array containing the index of can be attacked bangunan */
void SemuaBangunanAttack(TabBangunan tab, Pemain p, IdxTypeArray j, Graph g, int * n){
	int b[NbElmt(tab)];
	int count = 0;
	for (IdxTypeArray i = 1; i <= NbElmt(tab); i++){
		if (i != j && IsConnected(g, j , i) && !haveBuildingB(p, ElmtArray(tab,i), tab)){
			b[count] = i;
			count++;
		}
	}
	*n = count;
}

int * getSemuaBangunanAttack(TabBangunan tab, Pemain p, IdxTypeArray j, Graph g, int n){
	static int a[600];
	int count = 0;
	for (IdxTypeArray i = 1; i <= NbElmt(tab); i++){
		if (i != j && IsConnected(g, j , i) && !haveBuildingB(p, ElmtArray(tab,i), tab)){
			a[count] = i;
			count++;
		}
	}
	return a;
}

/* Create an array containing the index of can be moved bangunan */
void SemuaBangunanMove(TabBangunan tab, Pemain p, IdxTypeArray j, Graph g, int * n){
	int b[NbElmt(tab)];
	int count = 0;
	for (IdxTypeArray i  = 1; i<= NbElmt(tab); i++){
		if (i != j && IsConnected(g,j,i) && haveBuildingB(p, ElmtArray(tab, i), tab)){
			b[count] = i;
			count++;
		}
	}
	*n = count;
}

int * getSemuaBangunanMove(TabBangunan tab, Pemain p, IdxTypeArray j, Graph g, int n){
	static int a[600];
	int count = 0;
	for (IdxTypeArray i = 1; i <= NbElmt(tab); i++){
		if (i != j && IsConnected(g, j, i) && haveBuildingB(p, ElmtArray(tab,i), tab)){
			if (i != j && IsConnected(g,j,i) && haveBuildingB(p, ElmtArray(tab,i), tab)){
				a[count] = i;
				count++;
			}
		}
	}
	return a;
}


/* Input User */
char * outputString() {
	char * s = malloc(sizeof (char) * CKata.Length);
	for (int i = 1; i <= CKata.Length; i++){
		s[i-1] = CKata.TabKata[i];
	}
	return s;
}


int pengubahAngka() {
	int sum = 0;
	for (int i = 1; i <= CKata.Length; i++){
		sum = sum * 10 + (CKata.TabKata[i] - '0');
	}
	return sum;
}

char * BacaInputUser(){
	STARTKATAIn();
	while(!EndKata){
		ADVKATAIn();
	}
	char * e = malloc(sizeof (int) * CKata.Length);
	free(e);
	char *d = malloc(sizeof(char)*CKata.Length);
	for (int i = 1; i <= CKata.Length;i++){
		d[i-1] = CKata.TabKata[i];
	}
	return d;
}

boolean IsNew(char s[]){
	char new[3];
	new[0] = 'N';
	new[1] = 'E';
	new[2] = 'W';

	int sizeof_new = sizeof(new) / sizeof(char);
	int sizeof_s;
	for(sizeof_s = 0; s[sizeof_s] != '\0'; ++sizeof_s);
	if (sizeof_s != sizeof_new) return false;
	else {
		for (int i = 0; i < sizeof_new; i++){
			if (s[i] != new[i]){
				return false;
			}
		}
	}
	return true;
}

boolean IsAttack (char s[]){
	char attack[6];
	attack[0] = 'A';
	attack[1] = 'T';
	attack[2] = 'T';
	attack[3] = 'A';
	attack[4] = 'C';
	attack[5] = 'K';

	int sizeof_attack = sizeof(attack) / sizeof(char);
	int sizeof_s;
	for(sizeof_s = 0; s[sizeof_s] != '\0'; ++sizeof_s);
	if (sizeof_s != sizeof_attack) return false;
	else {
		for (int i = 0; i < sizeof_attack; i++){
			if (s[i] != attack[i]){
				return false;
			}
		}
	}
	return true;
}

boolean IsLevelUp(char s[]){
	char levelUp[8];
	levelUp[0] = 'L';
	levelUp[1] = 'E';
	levelUp[2] = 'V';
	levelUp[3] = 'E';
	levelUp[4] = 'L';
	levelUp[5] = '_';
	levelUp[6] = 'U';
	levelUp[7] = 'P';

	int sizeof_levelUp = sizeof(levelUp) / sizeof(char);
int sizeof_s;
	for(sizeof_s = 0; s[sizeof_s] != '\0'; ++sizeof_s);
	if (sizeof_s != sizeof_levelUp) return false;
	else {
		for (int i = 0; i < sizeof_levelUp ;i++){
			if (s[i] != levelUp[i]){
				return false;
			}
		}
	}
	return true;
}

boolean IsMove(char s[]){
	char move[4];
	move[0] = 'M';
	move[1] = 'O';
	move[2] = 'V';
	move[3] = 'E';

	int sizeof_move = sizeof(move) / sizeof(char);
int sizeof_s;
	for(sizeof_s = 0; s[sizeof_s] != '\0'; ++sizeof_s);

	if (sizeof_s != sizeof_move) return false;
	else {
		for (int i = 0; i < sizeof_move; i++){
			if (s[i] != move[i]){
				return false;
			}
		}
	}
	return true;
}

boolean IsSkill(char s[]){
	char skill[5];
	skill[0] = 'S';
	skill[1] = 'K';
	skill[2] = 'I';
	skill[3] = 'L';
	skill[4] = 'L';

	int sizeof_skill = sizeof(skill) / sizeof(char);
	int sizeof_s;
	for(sizeof_s = 0; s[sizeof_s] != '\0'; ++sizeof_s);
	if (sizeof_s != sizeof_skill) return false;
	else {
		for (int i = 0; i < sizeof_skill; i++){
			if (s[i] != skill[i]){
				return false;
			}
		}
	}
	return true;
}

boolean IsUndo(char s[]){
	char undo[4];
	undo[0] = 'U';
	undo[1] = 'N';
	undo[2] = 'D';
	undo[3] = 'O';

	int sizeof_undo = sizeof(undo) / sizeof(char);
	int sizeof_s;
	for(sizeof_s = 0; s[sizeof_s] != '\0'; ++sizeof_s);
	if (sizeof_s != sizeof_undo) return false;
	else {
		for (int i = 0; i < sizeof_undo; i++){
			if (s[i] != undo[i]){
				return false;
			}
		}
	}
	return true;
}

boolean IsEndTurn (char s[]){
	char endTurn[8];
	endTurn[0] = 'E';
	endTurn[1] = 'N';
	endTurn[2] = 'D';
	endTurn[3] = '_';
	endTurn[4] = 'T';
	endTurn[5] = 'U';
	endTurn[6] = 'R';
	endTurn[7] = 'N';

	int sizeof_endTurn = sizeof(endTurn) / sizeof(char);
	int sizeof_s;
	for(sizeof_s = 0; s[sizeof_s] != '\0'; ++sizeof_s);	
		if (sizeof_s != sizeof_endTurn) return false;
	else {
		for (int i = 0; i < sizeof_endTurn; i++){
			if (s[i] != endTurn[i]){
				return false;
			}
		}
	}
	return true;
}

boolean IsSave (char s[]){
	char save[4];
	save[0] = 'S';
	save[1] = 'A';
	save[2] = 'V';
	save[3] = 'E';

	int sizeof_save = sizeof(save) / sizeof(char);
		int sizeof_s;
	for(sizeof_s = 0; s[sizeof_s] != '\0'; ++sizeof_s);
	if (sizeof_s != sizeof_save) return false;
	else {
		for (int i = 0; i < sizeof_save; i++){
			if (s[i] != save[i]){
				return false;
			}
		}
	}
	return true;
}

boolean IsLoad (char s[]){
	char load[4];
	load[0] = 'L';
	load[1] = 'O';
	load[2] = 'A';
	load[3] = 'D';

	int sizeof_load = sizeof(load) / sizeof(char);
		int sizeof_s;
	for(sizeof_s = 0; s[sizeof_s] != '\0'; ++sizeof_s);
	if (sizeof_s != sizeof_load) return false;
	else {
		for (int i = 0; i < sizeof_load; i++){
			if (s[i] != load[i]){
				return false;
			}
		}
	}
	return true;
}

boolean IsExit(char s[]){
	char exit[4];
	exit[0] = 'E';
	exit[1] = 'X';
	exit[2] = 'I';
	exit[3] = 'T';

	int sizeof_exit = sizeof(exit) / sizeof(char);
	int sizeof_s;
	for(sizeof_s = 0; s[sizeof_s] != '\0'; ++sizeof_s);
	if (sizeof_s != sizeof_exit) return false;
	else {
		for (int i = 0; i < sizeof_exit; i++){
			if (s[i] != exit[i]){
				return false;
			}
		}
	}
	return true;
}
//coba push
/*******************UNTUK SAVE DAN LOAD***************************/
void TulisPointkeFile (FILE *fp,Point P){
/* Nilai P ditulis ke layar dengan format "(X,Y)"
   tanpa spasi, enter, atau karakter lain di depan, belakang,
   atau di antaranya
   Output X dan Y harus dituliskan dalam bilangan riil dengan 2 angka di belakang koma.
*/
/* I.S. P terdefinisi */
/* F.S. P tertulis di layar dengan format "(X,Y)" */
    fprintf(fp,"%d %d",Absis(P),Ordinat(P));
}

void PrintInfoBangunankeFile(FILE *fp,Bangunan bangunan) {
	/*
		Melakukan pencetakan terhadap info bangunan dengan format
		<jenis_bangunan> <letak_bangunan> <jumlah_pasukan> lv. <level_bangunan>
	*/
	fprintf(fp,"%c ", Type(bangunan));

	TulisPointkeFile(fp,Letak(bangunan));
	fprintf(fp," ");

	fprintf(fp,"%d", Pasukan(bangunan));

	fprintf(fp," ");

	fprintf(fp,"%d", Level(bangunan)); 

    fprintf(fp, " ");

    fprintf(fp, "%d", Serang(bangunan));

    fprintf(fp, " ");

    fprintf(fp, "%d", Move(bangunan));

    fprintf(fp, " ");
}

void CetakBangunanDimilikikeFile (FILE *fp,TabBangunan T, Pemain P1, Pemain P2)
/* Proses: Mencetak ke layar bangunan yang dimiliki pemain */
/* I.S. Tabel T boleh kosong, tetapi tidak penuh */
/* F.S. Bangunan-bangunan milik pemain tercetak ke layar */
{
	// KAMUS
	IdxTypeArray i;
	// ALGORITMA
	for (i=GetFirstIdx(T);i<=GetLastIdx(T);i++)
	{
		PrintInfoBangunankeFile(fp,ElmtArray(T,i));
        if(haveBuildingKoordinat(P1,Absis(Letak(ElmtArray(T,i))),Ordinat(Letak(ElmtArray(T,i))),T)) {
            fprintf(fp, "1\n");
        }
        else if(haveBuildingKoordinat(P2,Absis(Letak(ElmtArray(T,i))),Ordinat(Letak(ElmtArray(T,i))),T)) {
            fprintf(fp, "2\n");
        }
        else{
            fprintf(fp, "0\n");
        }
	}
}

void PrintGraphkeFile(FILE *fp, Graph G,TabBangunan TB) {
    int i,j;

    for (i=1; i<=GetLastIdx(TB); i++) {
        for (j=1; j<=GetLastIdx(TB); j++) {
            if (j<GetLastIdx(TB)) {
                if (IsConnected(G,i,j)) {
                    fprintf(fp, "1 ");
                } else {
                    fprintf(fp, "0 ");
                }
            } else {
                if (IsConnected(G,i,j)) {
                    fprintf(fp, "1\n");
                } else {
                    fprintf(fp, "0\n");
                }
            }
        }
    }
}

void PrintSkillAktifkeFile (FILE *fp, Pemain P) {
    fprintf(fp, "%d ", P.AttackUp);
    fprintf(fp, "%d ", P.CriticalHit);
    fprintf(fp, "%d\n", P.Shield);
}

void PrintQueuekeFile(FILE *fp, Queue Q) {
    infotype X;
    if (IsEmptyQueue(Q)) {
        fprintf(fp,"x\n");
    } else {
        while (!IsEmptyQueue(Q)) {
            DelSkillQueue(&Q, &X);
            if (Head(Q) == Tail(Q)) {
                fprintf(fp, "%c\n", X);
            } else {
                fprintf(fp, "%c", X);
            }
        } 
    }
}

void PrintPemainkeFile(FILE *fp, Pemain P) {
    PrintQueuekeFile(fp, P.Skill);
    PrintSkillAktifkeFile(fp,P);
}

void savefile(char s[],Pemain P1, Pemain P2, Pemain Pnow, PETA P, TabBangunan TB, Graph connectivity, List Netral, int jatah) {
    FILE *fp;
    fp = fopen(s,"w");

    fprintf(fp,"%d %d\n", GetLastIdxBrs(P), GetLastIdxKol(P));
    fprintf(fp,"%d\n", GetLastIdx(TB));
	
	CetakBangunanDimilikikeFile(fp,TB,P1,P2);
    PrintGraphkeFile(fp,connectivity,TB);
    PrintPemainkeFile(fp,P1);
    PrintPemainkeFile(fp,P2);

    fprintf(fp, "%d %d`", Pnow.nomor, jatah);

    fclose(fp);
	clear_user_input();
}

void loadfile(char s[],Pemain *P1, Pemain *P2, Pemain *Pnow, PETA *P, TabBangunan *TB, Graph *connectivity, List *Netral, int *jatah) {
    //KAMUS LOKAL
    int PPeta, LPeta;
    int i,n;
    infotypeGraph bmatriks,kmatriks;
    int NBangunan;
    char typebangunan;
    Point letakbangunan;
    int letakx, letaky;
    int pasukan;
    Bangunan bangunan;
    int elist;
    
    //ALGORITMA

    STARTKATA(s);
    PPeta = pengubahAngka();

    /** menyimpan lebar peta (horizontal) ke dalam variabel LPeta **/
    ADVKATA();
    LPeta = pengubahAngka();

    /* membuat peta kosong seukuran PPeta x LPeta */
    MakePeta(PPeta,LPeta, P);

    /** menyimpan banyaknya bangunan ke dalam variabel NBangunan **/
    ADVKATA();

    NBangunan = pengubahAngka();

    /** membuat array kosong dengan ukuran NBangunan **/
    
    CreateEmptyArray(TB, NBangunan);

    /* membuat list kepemilikan bangunan tiap pemain dan bangunan netral */
    CreateEmptyList(&((*P1).b));
    CreateEmptyList(&((*P2).b));
    CreateEmptyList(Netral);

    /** looping untuk mengisi array bangunan dan listlinier dengan informasi yang dibaca dari file konfigurasi **/
    for (n=1; n <= NBangunan; n ++) {
        letakx=0;
        letaky=0;
        pasukan=0;
        ADVKATA();
        typebangunan = CKata.TabKata[1];

        ADVKATA();
        letakx = pengubahAngka();
       
        
        ADVKATA();
        letaky = pengubahAngka();

        letakbangunan = MakePoint(letakx,letaky);

        MakeBangunan(&bangunan, typebangunan, letakbangunan);

        ADVKATA();
        Pasukan(bangunan) = pengubahAngka();

        ADVKATA();
        Level(bangunan) = pengubahAngka();

        ADVKATA();
        if(CKata.TabKata[1] == '1') {
            Serang(bangunan) = true;
        } else {
            Serang(bangunan) = false;
        }

        ADVKATA();
        if(CKata.TabKata[1] == '1') {
            Move(bangunan) = true;
        } else {
            Move(bangunan) = false;
        }

        AddBangunan(TB,bangunan);

        ADVKATA();
        if (CKata.TabKata[1] == '1') {
            InsertLastList(&((*P1).b), AlokasiList(n));
        } else if (CKata.TabKata[1] == '2') {
            InsertLastList(&((*P2).b), AlokasiList(n));
        } else if (CKata.TabKata[1] == '0') {
            InsertLastList(Netral,AlokasiList(n));
        }
    }
        
    /* membuat peta jadi sesuai letak tiap bangunan */
    MakePetaJadi(P, *TB);

    /* mengisi graf yang merepresentasikan keterhubungan antar bangunan */
    bmatriks=1;
    kmatriks=1;
    CreateGraph(bmatriks,connectivity);
    for (n=1; n <= NBangunan * NBangunan; n++) {
        IgnoreBlank();
        if (CC == '1') {
            InsertEdge(connectivity,bmatriks,kmatriks);
        }
        ADV();
        if (kmatriks   < NBangunan) {
            kmatriks  ++;
        } else {
            kmatriks   = 1;
            bmatriks  ++;
        }
        IgnoreBlank();
    }

    
    CreateEmptyQueue(&((*P1).Skill));
    CreateEmptyQueue(&((*P2).Skill));
    
    //membaca informasi skill yang dimiliki
    ADVKATA();
    for (i=1; i<=CKata.Length; i++) {
		if(CKata.TabKata[i] !=  'x') {
        	AddSkillQueue(&((*P1).Skill), CKata.TabKata[i]);
		}
    }

    
    ADVKATA();
    (*P1).AttackUp = pengubahAngka();

    ADVKATA();
    (*P1).CriticalHit = pengubahAngka();

    ADVKATA();
    (*P1).Shield = pengubahAngka();
    

    ADVKATA();
    for (i=1; i<=CKata.Length; i++) {
        AddSkillQueue(&((*P2).Skill), CKata.TabKata[i]);
    }

    
    ADVKATA();
    (*P2).AttackUp = pengubahAngka();

    ADVKATA();
    (*P2).CriticalHit = pengubahAngka();

    ADVKATA();
    (*P2).Shield = pengubahAngka();
    

    ADVKATA();
    if (CKata.TabKata[1] == '1') {
        *Pnow = *P1;
    } else if (CKata.TabKata[1] == '2') {
        *Pnow = *P2;
    }
    
    ADVKATA();
    *jatah = pengubahAngka();
	IgnoreBlank();
	clear_user_input();
}
/*************************************************************************************/

void ProsedurAttack(TabBangunan * tab, Pemain * p1, Pemain * p2, List * Netral ,Graph g,StackUndo *SU, Queue * q1, Queue * q2){
	char * s;
	int * attackArr;
	IdxTypeArray a;
	int c,j,k; // c => Bangunan penyerang, j => Bangunan 
	int count_n;

	printf("%s\n", "Daftar Bangunan :");
	PrintInfoLBangunan((*tab), (*p1));

	count_n = NbElmtList((*p1).b);

	printf("%s", "Bangunan yang digunakan untuk menyerang: ");
	s = BacaInputUser();
	c = pengubahAngka();

	if (c <= count_n && c > 0) {
		address last;
		last = FirstL((*p1).b);
		for (int i = 1; i < c; i++){
			last = NextL(last);
		}
		a = InfoL(last);
		if (!IsSudahSerang(ElmtArray((*tab),a))) {
			int n;
			SemuaBangunanAttack((*tab), (*p1), a,g, &n);
			attackArr = getSemuaBangunanAttack((*tab), (*p1), a,g, n);
			if (n > 0){
				printf("%s\n", "Daftar bangunan yang dapat diserang:");
				for (int z = 0; z < n; z++){
					printf("%d. ", z+1);
					CetakBangunanIndeks((*tab),attackArr[z]);
				}
				endline;
				printf("%s", "Bangunan yang diserang: ");
				s = BacaInputUser();
				j = pengubahAngka();

				if (j <= n && j > 0) {
					printf("%s", "Jumlah pasukan: ");
					s = BacaInputUser();
					k = pengubahAngka();
					if((*p1).nomor==1){
						SaveState(SU,*p1,*p2,*Netral,*tab);
					}
					else{
						SaveState(SU,*p2,*p1,*Netral,*tab);
					}
					SerangB(a, attackArr[j - 1], k, p1, p2, Netral, tab, q1,q2);
				} else {
					do {
						printf("\n%s\n", "Masukan bangunan salah. Silahkan ulangi!");
						printf("%s", "Bangunan yang diserang: ");
						s = BacaInputUser();
						j = pengubahAngka();
					} while (j > n || j <= 0);
					printf("%s", "Jumlah pasukan: ");
					s = BacaInputUser();
					k = pengubahAngka();
					if((*p1).nomor==1){
						SaveState(SU,*p1,*p2,*Netral,*tab);
					}
					else{
						SaveState(SU,*p2,*p1,*Netral,*tab);
					}
					SerangB(a, attackArr[j - 1], k, p1, p2, Netral, tab, q1,q2);
				}
			} else {
				printf("%s\n", "Tidak ada bangunan yang dapat diserang.");	
			}
		} else {
			printf("%s\n\n", "Bangunan sudah menyerang di turn ini!");
		}
	} else {
		do {	
			printf("\n%s\n", "Masukan Bangunan tidak valid");
			printf("%s\n\n", "Silahkan diulangi");
			printf("%s\n", "Daftar Bangunan :");
			PrintInfoLBangunan((*tab), (*p1));
			printf("%s", "Bangunan yang digunakan untuk menyerang: ");
			s = BacaInputUser();
			c = pengubahAngka();			
		} while (c > count_n || c <= 0);
		address last;
		last = FirstL((*p1).b);
		for (int i = 1; i < c; i++){
			last = NextL(last);
		}
		a = InfoL(last);

		if (!IsSudahSerang(ElmtArray((*tab),a))) {
			int n;
			SemuaBangunanAttack((*tab), (*p1), a,g, &n);
			attackArr = getSemuaBangunanAttack((*tab), (*p1), a,g, n);
			if (n > 0){
				printf("%s\n", "Daftar bangunan yang dapat diserang:");
				for (int z = 0; z < n; z++){
					printf("%d. ", z+1);
					CetakBangunanIndeks((*tab),attackArr[z]);
				}
				endline;
				printf("%s", "Bangunan yang diserang: ");
				s = BacaInputUser();
				j = pengubahAngka();

				if (j <= n && j > 0) {
					printf("%s", "Jumlah pasukan: ");
					s = BacaInputUser();
					k = pengubahAngka();
					if((*p1).nomor==1){
						SaveState(SU,*p1,*p2,*Netral,*tab);
					}
					else{
						SaveState(SU,*p2,*p1,*Netral,*tab);
					}
					SerangB(a, attackArr[j - 1], k, p1, p2, Netral, tab, q1,q2);
					
				} else {
					do {
						printf("\n%s\n", "Masukan bangunan salah. Silahkan ulangi!");
						printf("%s\n", "Daftar bangunan yang dapat diserang:");
						
						for (int z = 0; z < n; z++){
							printf("%d. ", z+1);
							CetakBangunanIndeks((*tab),attackArr[z]);
						}

						printf("%s", "Bangunan yang diserang: ");
						s = BacaInputUser();
						j = pengubahAngka();
					} while (j > n || j <= 0);
					printf("%s", "Jumlah pasukan: ");
					s = BacaInputUser();
					k = pengubahAngka();
					if((*p1).nomor==1){
						SaveState(SU,*p1,*p2,*Netral,*tab);
					}
					else{
						SaveState(SU,*p2,*p1,*Netral,*tab);
					}
					SerangB(a, attackArr[j - 1], k, p1, p2, Netral, tab, q1,q2);
					
				}
			} else {
				printf("%s\n", "Tidak ada bangunan yang dapat diserang.");
			}
		} else {
			printf("%s\n\n", "Bangunan sudah menyerang di turn ini!");
		}
	}

}
void ProsedurMove (TabBangunan * tab, Pemain * p1,Graph g,Pemain P1,Pemain P2,List Netral,StackUndo *SU){
	char * s;
	int * moveArr;
	IdxTypeArray a;
	int c,j,k;
	int count_n;

	printf("%s\n", "Daftar Bangunan :");
	PrintInfoLBangunan((*tab), (*p1));

	count_n = NbElmtList((*p1).b);
	printf("%s", "Pilih Bangunan: ");
	s = BacaInputUser();
	c = pengubahAngka();
	
	if (c <= count_n && c > 0){
		address last;
		last = FirstL((*p1).b);
		for (int i = 1; i < c; i++){
			last = NextL(last);
		}
		a = InfoL(last);
		if (!IsSudahMove(ElmtArray((*tab),a))) {
			int n;
			SemuaBangunanMove((*tab), (*p1), a,g, &n);
			moveArr = getSemuaBangunanMove((*tab), (*p1), a,g, n);
			if (n > 0){
				printf("%s\n", "Daftar Bangunan terdekat");
				for (int z = 0; z < n; z++){
					printf("%d. ", z+1);
					CetakBangunanIndeks((*tab),moveArr[z]);
					endline;
				}
				printf("%s", "Bangunan yang akan menerima pasukan baru: ");
				s = BacaInputUser();
				j = pengubahAngka();

				if (j <= n && j > 0) {
					printf("%s", "Jumlah pasukan: ");
					s = BacaInputUser();
					k = pengubahAngka();
					SaveState(SU,P1,P2,Netral,*tab);
					MoveB(a,moveArr[j - 1], k, (*p1),tab);		
				} else {
					do {
						printf("\n%s\n", "Masukan Bangunan tidak valid");
						printf("%s\n", "Silahkan diulangi");
						printf("%s", "Bangunan yang akan menerima pasukan baru: ");
						s = BacaInputUser();
						j = pengubahAngka();
					} while(j > n || j <= 0);
						printf("%s", "Jumlah pasukan: ");
						s = BacaInputUser();
						k = pengubahAngka();
						SaveState(SU,P1,P2,Netral,*tab);
						MoveB(a,moveArr[j - 1], k, (*p1),tab);	
				}
			} else {
				printf("%s\n\n", "Tidak ada bangunan yang bisa menampung migrasi pasukan!");
			}
		} else {
			printf("%s\n", "Bangunan telah melakukan migrasi pasukan di turn ini.");
		}
	} else {
		do {
			printf("\n%s\n", "Masukan Bangunan tidak valid");
			printf("%s\n", "Silahkan diulangi");
			printf("%s\n", "Daftar Bangunan :");
            PrintInfoLBangunan((*tab), (*p1));
			printf("%s", "Pilih Bangunan: ");
			s = BacaInputUser();
			c = pengubahAngka();
		} while(c > count_n || c <= 0);
		address last;
		last = FirstL((*p1).b);
		for (int i = 1; i < c; i++){
			last = NextL(last);
		}
		a = InfoL(last);
		int n;
		SemuaBangunanMove((*tab), (*p1), a,g, &n);
		moveArr = getSemuaBangunanMove((*tab), (*p1), a,g, n);
		if (n > 0){
			printf("%s\n", "Daftar Bangunan terdekat");
			for (int z = 0; z < n; z++){
				printf("%d. ", z+1);
				CetakBangunanIndeks((*tab),moveArr[z]);
				endline;
			}
			printf("%s", "Bangunan yang akan menerima pasukan baru: ");
			s = BacaInputUser();
			j = pengubahAngka();

			if (j <= n && j > 0) {
				printf("%s", "Jumlah pasukan: ");
				s = BacaInputUser();
				k = pengubahAngka();
				SaveState(SU,P1,P2,Netral,*tab);
				MoveB(a,moveArr[j - 1], k, (*p1),tab);		
			} else {
				do {
					printf("\n%s\n", "Masukan Bangunan tidak valid");
					printf("%s\n", "Silahkan diulangi");
					printf("%s\n", "Daftar Bangunan terdekat");
					for (int z = 0; z < n; z++){
						printf("%d. ", z+1);
						CetakBangunanIndeks((*tab),moveArr[z]);
						endline;
					}
					printf("%s", "Bangunan yang akan menerima pasukan baru: ");
					s = BacaInputUser();
					j = pengubahAngka();
				} while(j > n || j <= 0);
					printf("%s", "Jumlah pasukan: ");
					s = BacaInputUser();
					k = pengubahAngka();
					SaveState(SU,P1,P2,Netral,*tab);
					MoveB(a,moveArr[j - 1], k, (*p1),tab);	
			}
		} else {
			printf("%s\n\n", "Tidak ada bangunan yang bisa menampung migrasi pasukan!");
		}
	}
}

/* Fungsi buat make skill */
void PakeSkill (Queue *Q,TabBangunan * tab,Pemain * p1, Pemain * p2, int * x,StackUndo *SU)
{
    char X;
    
    if (!IsEmptyQueue(*Q))
    {
        DelSkillQueue(Q,&X);
        if (X == 'A')
        {
            InstantUpgrade(tab, (*p1));
        }
        else if (X == 'B')
        {
            printf("Shield aktif\n");
			Shield(p1);
        }
        else if (X == 'C')
        {
            ExtraTurn(x);
			CheckAddCriticalHit(p2);
        }
        else if (X == 'D')
        {
            printf("Attack Up aktif\n");
			AttackUp(p1);
        }
        else if (X == 'E')
        {
            printf("Critical Hit aktif\n");
			CriticalHit(p1);
        }
        else if (X == 'F')
        {
            InstantReinforcement(tab,(*p1));
        }
        else if (X == 'G')
        {
            Barrage(tab,p1,p2);
        }
        // buat ngosongin
        CreateEmptyStackUndo(SU);
    }
    else 
    {	
        printf("Anda tidak memiliki skill\n");
    }

}

void ProsedurLevelUp (TabBangunan *tab, Pemain P1,Pemain P3,Pemain P2,List Netral,StackUndo *SU) {
     char * s;
 	int * levelArr;
 	IdxTypeArray a,b;
 	int c,j;
    int count_n;

 	printf("%s\n", "Daftar Bangunan :");
 	PrintInfoLBangunan((*tab), (P1));

    count_n = NbElmtList(P1.b);

 	printf("%s", "Bangunan yang akan di level up: ");
 	s = BacaInputUser();
    c = pengubahAngka();

    if (c <= count_n && c > 0){
        address last=FirstL(P1.b);
        for (int i = 1; i < c; i++){
            last = NextL(last);
        }
        a = InfoL(last);

        if(IsAbleNaikLevel(ElmtArray(*tab,a))) {
            SaveState(SU,P3,P2,Netral,*tab);
            if (Type(ElmtArray(*tab,a)) == 'C') {
                ElmtArray(*tab,a) = NaikLevelCastle(ElmtArray(*tab,a));
                printf("Level Castle-mu meningkat menjadi %d!\n",Level(ElmtArray(*tab,a)));
            } else if (Type(ElmtArray(*tab,a)) == 'F') {
                ElmtArray(*tab,a) = NaikLevelFort(ElmtArray(*tab,a));
                printf("Level Fort-mu meningkat menjadi %d!\n",Level(ElmtArray(*tab,a)));
            } else if (Type(ElmtArray(*tab,a)) == 'V') {
                ElmtArray(*tab,a) = NaikLevelVillage(ElmtArray(*tab,a));
                printf("Level Village-mu meningkat menjadi %d!\n",Level(ElmtArray(*tab,a)));
            } else {
                ElmtArray(*tab,a) = NaikLevelTower(ElmtArray(*tab,a));
                printf("Level Tower-mu meningkat menjadi %d!\n",Level(ElmtArray(*tab,a)));
            }
            
        } else {
            printf("Level: %d\n", Level(ElmtArray(*tab,a)));
            if (IsMaxLevel(ElmtArray(*tab,a))) {
				if (Type(ElmtArray(*tab,a)) == 'C') {
					printf("%s sudah berada pada level maksimum.\n", "Castle");
				} else if (Type(ElmtArray(*tab,a)) == 'F') {
					printf("%s sudah berada pada level maksimum.\n", "Fort");
				} else if (Type(ElmtArray(*tab,a)) == 'V') {
					printf("%s sudah berada pada level maksimum.\n", "Village");
				} else {
					printf("%s sudah berada pada level maksimum.\n", "Tower");
				}
			} else {
				if (Type(ElmtArray(*tab,a)) == 'C') {
					printf("Jumlah pasukan %s kurang untuk level up\n", "Castle");
				} else if (Type(ElmtArray(*tab,a)) == 'F') {
					printf("Jumlah pasukan %s kurang untuk level up\n", "Fort");
				} else if (Type(ElmtArray(*tab,a)) == 'V') {
					printf("Jumlah pasukan %s kurang untuk level up\n", "Village");
				} else {
					printf("Jumlah pasukan %s kurang untuk level up\n", "Tower");
				}
			}
        }
    } else {
        do {
            printf("\n%s\n", "Bangunan tidak tersedia");
            printf("%s\n\n", "Silahkan ulangi masukan");
            printf("%s\n", "Daftar Bangunan :");
            PrintInfoLBangunan((*tab), (P1));
            printf("%s", "Bangunan yang akan di level up: ");
            s = BacaInputUser();
            c = pengubahAngka();       
        } while (c > count_n || c <= 0);
        address last=FirstL(P1.b);
        for (int i = 1; i < c; i++){
            last = NextL(last);
        }
        a = InfoL(last);

        if(IsAbleNaikLevel(ElmtArray(*tab,a))) {
            SaveState(SU,P3,P2,Netral,*tab);
            if (Type(ElmtArray(*tab,a)) == 'C') {
                ElmtArray(*tab,a) = NaikLevelCastle(ElmtArray(*tab,a));
                printf("Level Castle-mu meningkat menjadi %d!\n",Level(ElmtArray(*tab,a)));
            } else if (Type(ElmtArray(*tab,a)) == 'F') {
                ElmtArray(*tab,a) = NaikLevelFort(ElmtArray(*tab,a));
                printf("Level Fort-mu meningkat menjadi %d!\n",Level(ElmtArray(*tab,a)));
            } else if (Type(ElmtArray(*tab,a)) == 'V') {
                ElmtArray(*tab,a) = NaikLevelVillage(ElmtArray(*tab,a));
                printf("Level Village-mu meningkat menjadi %d!\n",Level(ElmtArray(*tab,a)));
            } else {
                ElmtArray(*tab,a) = NaikLevelTower(ElmtArray(*tab,a));
                printf("Level Tower-mu meningkat menjadi %d!\n",Level(ElmtArray(*tab,a)));
            }
        } else {
			if (IsMaxLevel(ElmtArray(*tab,a))) {
				if (Type(ElmtArray(*tab,a)) == 'C') {
					printf("%s sudah berada pada level maksimum.\n", "Castle");
				} else if (Type(ElmtArray(*tab,a)) == 'F') {
					printf("%s sudah berada pada level maksimum.\n", "Fort");
				} else if (Type(ElmtArray(*tab,a)) == 'V') {
					printf("%s sudah berada pada level maksimum.\n", "Village");
				} else {
					printf("%s sudah berada pada level maksimum.\n", "Tower");
				}
			} else {
				if (Type(ElmtArray(*tab,a)) == 'C') {
					printf("Jumlah pasukan %s kurang untuk level up\n", "Castle");
				} else if (Type(ElmtArray(*tab,a)) == 'F') {
					printf("Jumlah pasukan %s kurang untuk level up\n", "Fort");
				} else if (Type(ElmtArray(*tab,a)) == 'V') {
					printf("Jumlah pasukan %s kurang untuk level up\n", "Village");
				} else {
					printf("Jumlah pasukan %s kurang untuk level up\n", "Tower");
				}
			}
        }
    }
}

void ProsedurSave(Pemain P1, Pemain P2, Pemain Pnow, PETA P, TabBangunan TB, Graph connectivity, List Netral, int jatah) {
	char *t;

	printf("Lokasi save file: ");
	t = BacaInputUser();
	printf("\n");
	savefile(t, P1, P2, Pnow, P, TB, connectivity, Netral, jatah);
	printf("Game berhasil disave!\n");
}

void ProsedurLoad(Pemain *P1, Pemain *P2, Pemain *Pnow, PETA *P, TabBangunan *TB, Graph *connectivity, List *Netral, int *jatah) {
	char *s;

	printf("Lokasi load file: ");
	s = BacaInputUser();
	printf("\n");
	loadfile(s, P1, P2, Pnow, P, TB, connectivity, Netral, jatah);
	printf("Game berhasil diload!\n");
}

void endgame(Pemain P1, Pemain P2, boolean *selesai, int turn) {
    if (IsEmptyList(P1.b)) {
        PWinArt (P2, turn);
        *selesai = true;
    } else if (IsEmptyList(P2.b)) {
        PWinArt (P1, turn);
        *selesai = true;
    }
}
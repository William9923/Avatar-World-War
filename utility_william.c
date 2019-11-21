#define printInt(x) printf("%d", x)
#define printlnInt(x) printf("%d\n", x)
#define println(x) printf("%c\n", x)
#define print(x) printf("%c", x)
#define bacaInt(x) scanf("%d", &x)
#define bacaChar(x) scanf("%c", &c)
#define endline printf("\n")

void clrscr(){
	system("clear");
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
	if (Pasukan(bangunanAwal) < n && n < 0){
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
	if (IsAbleSerang(ElmtArray((*tab),i), ElmtArray((*tab),j), n)){
		if (IsPindahPemilik(ElmtArray((*tab),j),n)){
			if (Pertahanan(ElmtArray((*tab),j))){
				x = ceil((4.0/3) * Pasukan(ElmtArray((*tab),j)));
				Pasukan(ElmtArray((*tab),j)) = n - x;
			} else {
				// tidak ada pertahanan
				Pasukan(ElmtArray((*tab),j)) = n - Pasukan(ElmtArray((*tab),j));
			}
			Pasukan(ElmtArray((*tab),i)) -= n;
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
			Pasukan(ElmtArray((*tab),i)) -= n;
			printf("%s\n", "Bangunan gagal direbut");
		}
	Serang(ElmtArray((*tab),i)) = true;
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
	char * s = malloc(sizeof (char) * CKata.Length);
	for (int i = 1; i <= CKata.Length;i++){
		s[i-1] = CKata.TabKata[i];
	}
	return s;
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
					SaveState(SU,*p1,*p2,*Netral,*tab);
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
					SaveState(SU,*p1,*p2,*Netral,*tab);
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
					SaveState(SU,*p1,*p2,*Netral,*tab);
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
					SaveState(SU,*p1,*p2,*Netral,*tab);
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
            printf("Shield");
        }
        else if (X == 'C')
        {
            ExtraTurn(x);
        }
        else if (X == 'D')
        {
            printf("Attack Up");
        }
        else if (X == 'E')
        {
            printf("Critical Hit");
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

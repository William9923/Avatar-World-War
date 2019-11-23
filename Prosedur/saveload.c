#include "../include.h"

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
    /*
    fprintf(fp, "%d ", P.AttackUp);
    fprintf(fp, "%d ", P.CriticalHit);
    fprintf(fp, "%d\n", P.Shield);
    */
}

void PrintQueuekeFile(FILE *fp, Queue Q) {
    infotype X;
    if (IsEmptyQueue(Q)) {
        fprintf(fp,"\n");
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
    int i;
    FILE *fp;
    fp = fopen(s,"w");
    
    fprintf(fp,"%d %d\n", GetLastIdxBrs(P), GetLastIdxKol(P));
    fprintf(fp, "%d\n", GetLastIdx(TB));
    CetakBangunanDimilikikeFile(fp,TB,P1,P2);
    PrintGraphkeFile(fp,connectivity,TB);
    PrintPemainkeFile(fp,P1);
    PrintPemainkeFile(fp,P2);

    fprintf(fp, "%d %d`", Pnow.nomor, jatah);

    fclose(fp);
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
    STARTLoad(s);
    ADVKATA();
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
        AddSkillQueue(&((*P1).Skill), CKata.TabKata[i]);
    }

    /*
    ADVKATA();
    *P1.AttackUp = pengubahAngka();

    ADVKATA();
    *P1.CriticalHit = pengubahAngka();

    ADVKATA();
    *P1.Shield = pengubahAngka();
    */

    ADVKATA();
    for (i=1; i<=CKata.Length; i++) {
        AddSkillQueue(&((*P2).Skill), CKata.TabKata[i]);
    }

    /*
    ADVKATA();
    *P2.AttackUp = pengubahAngka();

    ADVKATA();
    *P2.CriticalHit = pengubahAngka();

    ADVKATA();
    *P2.Shield = pengubahAngka();
    */

    ADVKATA();
    if (CKata.TabKata[1] == '1') {
        *Pnow = *P1;
    } else if (CKata.TabKata[1] == '2') {
        *Pnow = *P2;
    }
    
    ADVKATA();
    *jatah = pengubahAngka();
}
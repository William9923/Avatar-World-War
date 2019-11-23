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

    if(Serang(bangunan)) {
        fprintf(fp,"t");
    } else {
        fprintf(fp, "f");
    }

    fprintf(fp, " ");

    if(Move(bangunan)) {
        fprintf(fp,"t");
    } else {
        fprintf(fp, "f");
    }

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
    if (P.boolean1) {
        fprintf(fp, "t");
    } else {
        fprintf(fp, "f");
    }
    if (P.boolean2) {
        fprintf(fp, "t");
    } else {
        fprintf(fp, "f");
    }
    if (P.boolean2) {
        fprintf(fp, "t");
    } else {
        fprintf(fp, "f");
    }
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
                fprintf(fp, "%c ", X);
            }
        } 
    }
}

void PrintPemainkeFile(FILE *fp, Pemain P) {
    PrintQueuekeFile(fp, P.Skill);
    //PrintSkillAktifkeFile(fp,P.boolean);
}

void savefile(Pemain P1, Pemain P2, Pemain Pnow, StackUndo SU, PETA P, TabBangunan TB, Graph connectivity, List Netral, int jatah) {
    int i;
    FILE *fp;
    fp = fopen("save.txt","w");
    
    fprintf(fp,"%d %d\n", GetLastIdxBrs(P), GetLastIdxKol(P));
    fprintf(fp, "%d\n", GetLastIdx(TB));
    CetakBangunanDimilikikeFile(fp,TB,P1,P2);
    PrintGraphkeFile(fp,connectivity,TB);
    PrintPemainkeFile(fp,P1);
    PrintPemainkeFile(fp,P2);

    fprintf(fp, "%d %d\n", Pnow.nomor, jatah);

    fclose(fp);
}
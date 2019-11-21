#include "pemain.h"
#include "array.h"
#include "bangunan.h"
#include "boolean.h"
#include "graph_.h"
#include "listlinier.h"
#include "matriks.h"
#include "skill.h"
//#include "stackundo.h"
#include"bangunan.c"
#include"point.c"
#include"state.c"
#include"array.c"
#include"matriks.c"
#include"skill.c"
#include "listlinier.c"
#include "mesinkar.c"
#include "mesinkata.c"
#include "readkonfigurasi.c"
//#include "skill.c"
#include"pemain.c"
#include"stackundo.c"
#include"graph_.c"
#include<math.h>
#include"boolean.h"
#include"prosedur_skill.c"


#include <stdio.h>

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

	fprintf(fp,"%d\n", Level(bangunan)); 
}

void CetakBangunanDimilikikeFile (FILE *fp,TabBangunan T)
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

void PrintInfoListkeFile (FILE *fp,List L) {
	/* I.S. List mungkin kosong */
	/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
	/* Contoh : jika ada tiga elemen berkosongai 1, 20, 30 akan dicetak: [1,20,30] */
	/* Jika list kosong : menulis [] */
	/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
	if (!IsEmptyList(L)) {
		address Last;
		Last = FirstL(L);
		while (NextL(Last) != Kosong) {
            fprintf(fp,"%d ", InfoL(Last));
			Last = NextL(Last);
		}
		if (Last != Kosong) {
            fprintf(fp,"%d\n", InfoL(Last));
		}
	}
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
    PrintInfoListkeFile(fp,P.b);
    PrintQueuekeFile(fp, P.Skill);
}

void savefile(Pemain P1, Pemain P2, Pemain Pnow, StackUndo SU, PETA P, TabBangunan TB, Graph connectivity, List Netral, int turn) {
    int i;
    FILE *fp;
    fp = fopen("save.txt","w");
    
    fprintf(fp,"%d %d\n", GetLastIdxBrs(P), GetLastIdxKol(P));
    fprintf(fp, "%d\n", GetLastIdx(TB));
    CetakBangunanDimilikikeFile(fp,TB);
    PrintGraphkeFile(fp,connectivity,TB);
    PrintPemainkeFile(fp,P1);
    PrintPemainkeFile(fp,P2);
    PrintInfoListkeFile(fp,Netral);
    fprintf(fp, "%d", Pnow.nomor);

    fclose(fp);
}
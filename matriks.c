#include <stdio.h>
#include "boolean.h"
#include "bangunan.h"
#include "matriks.h"

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */
/* *** Konstruktor membentuk PETA *** */
void MakePeta (int NB, int NK, PETA * P) 
/* Membentuk sebuah PETA "kosong" yang siap diisi berukuran NB x NK */
/* I.S. NB dan NK adalah valid untuk memori peta yang dibuat */
/* F.S. Peta P sesuai dengan definisi di atas terbentuk */
{
	NBrsEff(*P) = NB;
	NKolEff(*P) = NK;
}

void MakePetaJadi(PETA *P, TabBangunan B)
/* Mengisi PETA dengan char */
/* I.S. PETA terdefinisi, bisa kosong */
/* F.S PETA terisi */
{
	int i, j, k;

	for (i=GetFirstIdxBrs(*P); i<=GetLastIdxBrs(*P); i++) {
		for (j=GetFirstIdxKol(*P); j<=GetLastIdxKol(*P); j++) {
			for (k=GetFirstIdx(B); k<=GetLastIdx(B); k++) {
				if (Absis(Letak(ElmtArray(B,k))) == i && Ordinat(Letak(ElmtArray(B,k))) == j) {
					ElmtMatriks(*P,i,j) = Type(ElmtArray(B,k));
				}
			}
		}
	}
}

/* *** Selektor: Untuk sebuah peta P yang terdefinisi: *** */
IdxTypeMatriks GetFirstIdxBrs (PETA P)
/* Mengirimkan indeks baris terkecil P */
{
	return BrsMin;
}
IdxTypeMatriks GetFirstIdxKol (PETA P)
/* Mengirimkan indeks kolom terkecil P */
{
	return KolMin;
}

IdxTypeMatriks GetLastIdxBrs (PETA P)
/* Mengirimkan indeks baris terbesar P */
{
	return NBrsEff(P);
}

IdxTypeMatriks GetLastIdxKol (PETA P)
/* Mengirimkan indeks kolom terbesar P */
{
	return NKolEff(P);
}

// PAKE MODUL WARNA 
/* ********** BACA/TULIS ********** */
void CetakPeta (PETA P)
/* I.S. P terdefinisi */
/* F.S. Elemen P dicetak ke layar per baris per kolom */
/* Proses: Mencetak nilai setiap elemen P ke layar dengan traversal per baris dan per kolom */
{
	int i,j;

	for (i=0; i<=GetLastIdxBrs(P)+1; i++) {
		for (j=0; j<=GetLastIdxKol(P)+1; j++) {
			if (i==0 || j == 0 || i == GetLastIdxBrs(P)+1 || j == GetLastIdxKol(P)+1) {
				printf("*");
			} else {
				if(ElmtMatriks(P,i,j) == 'C' || ElmtMatriks(P,i,j) == 'V' || ElmtMatriks(P,i,j) == 'T' || ElmtMatriks(P,i,j) == 'F') {
					printf("%c", ElmtMatriks(P,i,j));
				} else {
					printf(" ");
				}
			}
		}
		printf("\n");
	}
}
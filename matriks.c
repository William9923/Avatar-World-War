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
void CetakPeta (PETA P);
/* I.S. P terdefinisi */
/* F.S. Elemen P dicetak ke layar per baris per kolom */
/* Proses: Mencetak nilai setiap elemen P ke layar dengan traversal per baris dan per kolom */
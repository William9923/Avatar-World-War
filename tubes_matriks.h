#ifndef MATRIKS_H
#define MATRIKS_H

#include "boolean.h"

/* Ukuran minimum dan maksimum baris dan kolom */
#define BrsMin 1
#define BrsMax ?
#define KolMin 1
#define KolMax ?

typedef int indeks; /* indeks baris, kolom */
typedef ... ElType; // char (?)
typedef struct {
    ElType Mem[BrsMax+1][KolMax+1];
    int NBrsEff; /* ukuran baris yg terdefinisi */
    int NKolEff; /* ukuran kolom yg terdefinisi */
} PETA;

/* NBrsEff <= 1 dan NKolEff <= 1 */ -- salah
/* Indeks peta yang digunakan: [BrsMin..BrsMax][KolMin..KolMax] */
/* Memori peta yang dipakai selalu di "ujung kiri atas" */

/* *** Selektor *** */
#define NBrsEff(P) (P).NBrsEff
#define NKolEff(P) (P).NKolEff
#define Elmt(P,i,j) (P).Mem[(i)][(j)]

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */
/* *** Konstruktor membentuk PETA *** */
void MakePeta (int NB, int NK, PETA * P);
/* Membentuk sebuah PETA "kosong" yang siap diisi berukuran NB x NK di "ujung kiri" memori */
/* I.S. NB dan NK adalah valid untuk memori peta yang dibuat */
/* F.S. Peta P sesuai dengan definisi di atas terbentuk */

/* *** Selektor: Untuk sebuah peta P yang terdefinisi: *** */
indeks GetFirstIdxBrs (PETA P);
/* Mengirimkan indeks baris terkecil P */
indeks GetFirstIdxKol (PETA P);
/* Mengirimkan indeks kolom terkecil P */
indeks GetLastIdxBrs (PETA P);
/* Mengirimkan indeks baris terbesar P */
indeks GetLastIdxKol (PETA P);
/* Mengirimkan indeks kolom terbesar P */

/* ********** Operasi lain ********** */
int NBElmt (PETA P);
/* Mengirimkan banyaknya elemen P */

/* ********** BACA/TULIS ********** */

void CetakPeta (PETA P);
/* I.S. P terdefinisi */
/* F.S. Elemen P dicetak ke layar per baris per kolom */
/* Proses: Mencetak nilai setiap elemen P ke layar dengan traversal per baris dan per kolom */
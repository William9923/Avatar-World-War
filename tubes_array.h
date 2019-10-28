#ifndef ARRAYDIN_H
#define ARRAYDIN_H

#include "boolean.h"
#include "bangunan.h" // ganti namanya yg sesuai

/*  Kamus Umum */
#define IdxMin 1
/* Indeks minimum array */
#define IdxUndef -999
/* Indeks tak terdefinisi*/

/* Definisi elemen dan koleksi objek */
typedef int IdxType; // Tipe Indeks
typedef Bangunan ElType;  // Tipe Elemen Tabel
typedef struct
{
  ElType *TB; /* memori tempat penyimpan elemen */
  int Neff;   /* >=0, banyaknya elemen efektif */
  int MaxEl;  /* ukuran elemen */
} TabBangunan;

/* Indeks yang digunakan [IdxMin..MaxEl] */
/* Jika T adalah TabBangunan, cara deklarasi dan akses: */
/* Deklarasi : T : TabBangunan */
/* Maka cara akses:
   T.Neff  untuk mengetahui banyaknya elemen
   T.TB    untuk mengakses seluruh nilai elemen tabel
   T.TB[i] untuk mengakses elemen ke-i */
/* Definisi :
  Tabel kosong: T.Neff = 0
  Definisi elemen pertama : T.TB[i] dengan i=1
  Definisi elemen terakhir yang terdefinisi: T.TB[i] dengan i=T.Neff */
  
/* ********** SELEKTOR ********** */
#define Neff(T)   (T).Neff
#define TB(T)     (T).TB
#define Elmt(T,i) (T).TB[(i)]

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong  */
void MakeEmpty(TabBangunan *T, int maxel);
/* I.S. T sembarang, maxel > 0 */
/* F.S. Terbentuk tabel T kosong dengan kapasitas maxel + 1 */

void Dealokasi(TabBangunan *T);
/* I.S. T terdefinisi; */
/* F.S. TB(T) dikembalikan ke sistem, MaxEl(T)=0; Neff(T)=0 */

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int NbElmt(TabBangunan T);
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
/* *** Daya tampung container *** */
int MaxElement(TabBangunan T);
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
/* *** Selektor INDEKS *** */
IdxType GetFirstIdx(TabBangunan T);
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T pertama */
IdxType GetLastIdx(TabBangunan T);
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T terakhir */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmpty(TabBangunan T);
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
/* *** Test tabel penuh *** */
boolean IsFull(TabBangunan T);
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */

/* ********** SEARCHING ********** */
/* ***  Perhatian : Tabel boleh kosong!! *** */
IdxType SearchIdxBangunan (TabBangunan T, ElType X);
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X */
/* Jika tidak ada, mengirimkan IdxUndef */
/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong */
/* Memakai skema search TANPA boolean */

boolean SearchBangunan (TabBangunan T, ElType X);
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan true, jika tidak ada menghasilkan false */
/* Memakai Skema search DENGAN boolean */

/* ********** MENAMBAH ELEMEN ********** */
/* *** Menambahkan elemen terakhir *** */
void AddBangunan (TabBangunan * T, ElType X);
/* Proses: Menambahkan X sebagai elemen terakhir tabel */
/* I.S. Tabel T boleh kosong, tetapi tidak penuh */
/* F.S. X adalah elemen terakhir T yang baru */

/* ********** MENGHAPUS ELEMEN ********** */
void DelBangunan (TabBangunan * T, IdxType i, ElType * X);
/* Menghapus elemen ke-i tabel tanpa mengganggu kontiguitas */
/* I.S. Tabel tidak kosong, i adalah indeks efektif yang valid */
/* F.S. X adalah nilai elemen ke-i T sebelum penghapusan */
/*      Banyaknya elemen tabel berkurang satu */
/*      Tabel T mungkin menjadi kosong */
/* Proses : Geser elemen ke-i+1 s.d. elemen terakhir */
/*          Kurangi elemen efektif tabel */

void CetakBangunanDimiliki (TabBangunan T, int P);
/* Proses: Mencetak ke layar bangunan yang dimiliki pemain P */
/* I.S. Tabel T boleh kosong, tetapi tidak penuh */
/* F.S. Bangunan-bangunan milik pemain P tercetak ke layar */

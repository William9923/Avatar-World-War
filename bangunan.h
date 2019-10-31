/*
File : bangunan.h
Author : William
Topik : Tugas Besar Alstrukdat 1
*/

#ifndef BANGUNAN_H
#define BANGUNAN_H

#include "boolean.h"
#include "point.h"

typedef struct {
	char type; // T : Tower, C : Castle, F : Fort, V : Village
	int level; // 1 - 4
	int A; // nilai pertambahan pasukan
	int M; // maksimum penambahan pasukan
	boolean P; // true -> ada pertahanan, dan sebaliknya
	int pasukan; // pasukan awal
	POINT point;
	boolean serang; // apakah suatu bangunan telah menyerang di turn tersebut atau tidak
} Bangunan;

/* Notasi Akses : Selektor Bangunan*/
#define Type(B) (B).type 
#define Level(B) (B).level
#define A(B) (B).A 
#define TambahPasukan(B) (B).A
#define M(B) (B).M
#define Maksimum(B) (B).M
#define Pertahanan(B) (B).P 
#define Pasukan(B) (B).pasukan
#define Letak(B) (B).point
#define Serang(B) (B).serang


/* *** DEFINISI PROTOTIPE PRIMITIF *** */
/* *** Konstruktor membentuk Bangunan *** */
void MakeBangunan(Bangunan * bangunan, char type, Point point);
	/*
void MakeBangunan(Bangunan * bangunan, char type, int pemilik, Point point)
	I.S. : Bangunan sembarang
	F.S  : Bangunan terdefinisi
	*/



/* Fungsi - fungsi Primitif */
boolean IsAbleNaikLevel(Bangunan bangunan);
// memberikan informasi apakah suatu bangunan dapat naik level atau tidak


/* Fungsi - fungsi primitif terhadap naik level bangunan*/
Bangunan NaikLevelFort(Bangunan bangunan);

Bangunan NaikLevelTower(Bangunan bangunan);

Bangunan NaikLevelCastle(Bangunan bangunan);

Bangunan NaikLevelVillage(Bangunan bangunan);

void NaikLevel(Bangunan * bangunan);
/*
	I.S. Bangunan belum naik level
	F.S. Bangunan naik levelnya apabila "valid" untuk naik level
*/

/* Fungsi - fungsi primitif untuk Penyerangan*/
void Serang(Bangunan * bserang, Bangunan * bdiserang, int jPSerang);
/*
	I.S. Bangunan belum diserang
	F.S. Bangunan telah diserang
	Apabila Bangunan beralih kepemilikan, maka bangunan diserang akan berubah tempat listnya
*/

/* Fungsi - fungsi lainnya*/
boolean IsPindahPemilik(Bangunan bBertahan, int jumlahPenyerang);

boolean IsSudahSerang(Bangunan bangunan);

void TambahPasukan(Bangunan bangunan);
/*
	I.S. : Jumlah Pasukan belum ditambahkan
	F.S. : Jumlah Pasukan telah bertambah
*/

/* Cetak Info Bangunan*/
void PrintInfoBangunan(Bangunan bangunan);
/*
	Melakukan pencetakan terhadap info bangunan dengan format
	<jenis_bangunan> <letak_bangunan> <jumlah_pasukan> lv. <level_bangunan>
*/



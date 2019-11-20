/*
File : bangunan.h
Author : William
Topik : Tugas Besar Alstrukdat 1
*/

#ifndef BANGUNAN_H
#define BANGUNAN_H

#include "boolean.h"
#include "point.h"
#include "boolean.h"

typedef struct {
	char type; // T : Tower, C : Castle, F : Fort, V : Village
	int level; // 1 - 4
	int A; // nilai pertambahan pasukan
	int M; // maksimum penambahan pasukan
	boolean P; // true -> ada pertahanan, dan sebaliknya
	int pasukan; // pasukan awal
	Point letak;
	boolean serang; // apakah suatu bangunan telah menyerang di turn tersebut atau tidak
					// true -> uda serang, false -> belum serang
	boolean move; 	// apakah suatu bangunan telah melakukan migrasi pasukan di turn tersebut
					// true -> uda move. false -> belum melakukan move
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
#define Letak(B) (B).letak
#define Serang(B) (B).serang
#define Move(B) (B).move


/* *** DEFINISI PROTOTIPE PRIMITIF *** */
/* *** Konstruktor membentuk Bangunan *** */
void MakeBangunan(Bangunan * bangunan, char type, Point letak);
	/*
void MakeBangunan(Bangunan * bangunan, char type, int pemilik, Point Point)
	I.S. : Bangunan sembarang
	F.S  : Bangunan terdefinisi
	*/



/* Fungsi - fungsi Primitif */
boolean IsAbleNaikLevel(Bangunan bangunan);
// memberikan informasi apakah suatu bangunan dapat naik level atau tidak


/* Fungsi - fungsi primitif terhadap naik level bangunan*/
/*
	Kenaikan level tiap bangunan berbeda sesuai dengan jenisnya :
		1. Fort 
		2. Tower
		3. Castle
		4. Village
*/
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
// void Serang(Bangunan * bserang, Bangunan * bdiserang, int jPSerang);

// 	I.S. Bangunan belum diserang
// 	F.S. Bangunan telah diserang
// 	Apabila Bangunan beralih kepemilikan, maka bangunan diserang akan berubah tempat listnya




/* Fungsi - fungsi primitif lainnya*/
boolean IsPindahPemilik(Bangunan bBertahan, int jumlahPenyerang);
/*
	Fungsi yang melakukan pengecekan apakah suatu bangunan akan berpindah
	kepemilikan ketika suatu bangunan telah diserang
*/


boolean IsSudahSerang(Bangunan bangunan);
/*
	Dikarenakan setiap bangunan hanya boleh menyerang sekali, maka 
	dibentuk fungsi penanda apakah sudah serang di turn itu atau belum
*/

boolean IsSudahMove(Bangunan bangunan);
/*
	Dikarenakan setiap bangunan hanya boleh berpindah sekali dalam 1 turn, maka 
	dibentuk fungsi penanda apakah sudah pindah di turn itu atau belum
*/
Point letakBangunan(Bangunan bangunan);
/*
	Fungsi yang mengembalikan nilai Point letak dari 
*/

void PlusPasukan(Bangunan * bangunan);
/*
	I.S. : Jumlah Pasukan belum ditambahkan
	F.S. : Jumlah Pasukan telah bertambah
*/

void NextTurnBangunan(Bangunan * bangunan);
/*
	I.S. : Kondisi bangunan sebelum next turn
	F.S. : Kondisi bangunan setelah next turn

	Hanya digunakan untuk bangunan pemain tersebut saat baru memulai turnnya

	Kondisi bangunan setelah next turn sedikit berubah, seperti adanya pertambahan pasukan selama 
	belum melebihi batas atas jumlah maksimum pasukan, serta boolean boleh menyerangnya.
*/
/* Cetak Info Bangunan*/
void PrintInfoBangunan(Bangunan bangunan);
/*
	Melakukan pencetakan terhadap info bangunan dengan format
	<jenis_bangunan> <letak_bangunan> <jumlah_pasukan> lv. <level_bangunan>
*/

boolean EQBangunan(Bangunan b1, Bangunan b2);
/* Cek apakah kedua bangunan sama atau tidak */

#endif



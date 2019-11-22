
/* *** Definisi ABSTRACT DATA TYPE Point *** */
#ifndef Point_H
#define Point_H

#include "../boolean.h"
#include <math.h>

/*******************************************************************
* Point                                                            *
* Author : William                                                 *
* Created at : 04 November 2019                                    *
* Merupakan header file dari ADT Point                             *
* ADT Point digunakan untuk menandakan letak bangunan di peta game *
*******************************************************************/

typedef struct {
	int X; /* absis   */
	int Y; /* ordinat */
} Point;

/* *** Notasi Akses: Selektor Point *** */
#define Absis(P) (P).X
#define Ordinat(P) (P).Y

/* *** DEFINISI PROTOTIPE PRIMITIF *** */
/* *** Konstruktor membentuk Point *** */
Point MakePoint (int X, int Y);
/* Membentuk sebuah Point dari komponen-komponennya */

/* *** KELOMPOK Interaksi dengan I/O device, BACA/TULIS  *** */
void BacaPoint (Point * P);
/* Membaca nilai absis dan ordinat dari keyboard dan membentuk
   Point P berdasarkan dari nilai absis dan ordinat tersebut */
/* Komponen X dan Y dibaca dalam 1 baris, dipisahkan 1 buah spasi */
/* Contoh: 1 2
   akan membentuk Point <1,2> */
/* I.S. Sembarang */
/* F.S. P terdefinisi */
void TulisPoint (Point P);
/* Nilai P ditulis ke layar dengan format "(X,Y)"
   tanpa spasi, enter, atau karakter lain di depan, belakang,
   atau di antaranya
   Output X dan Y harus dituliskan dalam bilangan riil dengan 2 angka di belakang koma.
*/
/* I.S. P terdefinisi */
/* F.S. P tertulis di layar dengan format "(X,Y)" */

/* *** Kelompok operasi relasional terhadap Point *** */
boolean EQ (Point P1, Point P2);
/* Mengirimkan true jika P1 = P2 : absis dan ordinatnya sama */
boolean NEQ (Point P1, Point P2);
/* Mengirimkan true jika P1 tidak sama dengan P2 */

#endif

/* File: jam.h */
/* NIM : 13518138 */
/* Nama : William*/
/* Tanggal: 28 Agustus 2016 */
/* Topik : Modularitas Program */
/* Definisi ADT Point */
#include<stdio.h>
#include <math.h>
#include "boolean.h"
#include "point.h"

/* *** DEFINISI PROTOTIPE PRIMITIF *** */
/* *** Konstruktor membentuk Point *** */
Point MakePoint (int X, int Y){
/* Membentuk sebuah Point dari komponen-komponennya */
    Point p;

    Absis(p) = X;
    Ordinat(p) = Y;

    return p;
}

void BacaPoint (Point * P){
/* Membaca nilai absis dan ordinat dari keyboard dan membentuk
   Point P berdasarkan dari nilai absis dan ordinat tersebut */
/* Komponen X dan Y dibaca dalam 1 baris, dipisahkan 1 buah spasi */
/* Contoh: 1 2
   akan membentuk Point <1,2> */
/* I.S. Sembarang */
/* F.S. P terdefinisi */
    float x,y;
    scanf("%d %d", &x,&y);
    *P = MakePoint(x,y);
}

void TulisPoint (Point P){
/* Nilai P ditulis ke layar dengan format "(X,Y)"
   tanpa spasi, enter, atau karakter lain di depan, belakang,
   atau di antaranya
   Output X dan Y harus dituliskan dalam bilangan riil dengan 2 angka di belakang koma.
*/
/* I.S. P terdefinisi */
/* F.S. P tertulis di layar dengan format "(X,Y)" */
    printf("(%d,%d)",Absis(P),Ordinat(P));
}

/* *** Kelompok operasi relasional terhadap Point *** */
boolean EQ (Point P1, Point P2){
/* Mengirimkan true jika P1 = P2 : absis dan ordinatnya sama */
    return ((Absis(P1) == Absis(P2)) && (Ordinat(P1) == Ordinat(P2)));
}
boolean NEQ (Point P1, Point P2){
/* Mengirimkan true jika P1 tidak sama dengan P2 */
    return (!EQ(P1,P2));
}

#ifndef listbangunan_H
#define listbangunan_H

#include"bangunan.h"
#include<stddef.h>

#include "boolean.h"
#include "point.h"

#define Kosong NULL

typedef struct tElmtListB *elb;
typedef struct tElmtListB{
    Bangunan bangun;
    elb next;
} ElmtListB;

typedef struct {
    elb FirstB;
} ListB;



/* Definisi list : */
/* ListB kosong : FirstB(L) = Nil */
/* Setiap elemen dengan elb P dapat diacu Info(P), NextB(P) */
/* Elemen terakhir list : jika elbnya Last, maka NextB(Last)=Nil */

#define Bangunan(P) (P)->bangun
#define NextB(P) (P)->next
#define FirstB(L) ((L).FirstB)



/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmptyListB (ListB L);
/* Mengirim true jika list kosong */

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmptyListB (ListB *L);
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */

/****************** Manajemen Memori ******************/
elb AlokasiListB (Bangunan X);
/* Mengirimkan elb hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka elb tidak nil, dan misalnya */
/* menghasilkan P, maka Info(P)=X, NextB(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
void DealokasiListB (elb P);
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian elb P */

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
elb SearchListB (ListB L, Bangunan X);
/* Mencari apakah ada elemen list dengan Info(P)= X */
/* Jika ada, mengirimkan elb elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirstListB (ListB *L, Bangunan X);
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
void InsVLastListB (ListB *L, Bangunan X);
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirstBListB (ListB *L, Bangunan *X);
/* I.S. ListB L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
void DelVLastListB (ListB *L, Bangunan *X);
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirstListB (ListB *L, elb P);
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-elb P sebagai elemen pertama */
void InsertAfterListB (ListB *L, elb P, elb Prec);
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
void InsertLastListB (ListB *L, elb P);
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirstListB (ListB *L, elb *P);
/* I.S. ListB tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* FirstB element yg baru adalah suksesor elemen pertama yang lama */
void DelPListB (ListB *L, Bangunan X);
/* I.S. Sembarang */
/* F.S. Jika ada elemen list berelb P, dengan Info(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika ada lebih dari satu elemen list dengan Info bernilai X */
/* maka yang dihapus hanya elemen pertama dengan Info = X */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* ListB mungkin menjadi kosong karena penghapusan */
void DelLastListB (ListB *L, elb *P);
/* I.S. ListB tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen terakhir yg lama, */
/* jika ada */
void DelAfterListB (ListB *L, elb *Pdel, elb Prec);
/* I.S. ListB tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus NextB(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */

/****************** PROSES SEMUA ELEMEN LIST ******************/
//void PrintInfoListB (ListB L);
/* I.S. ListB mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
int NbElmtListB (ListB L);
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */

/****************** PROSES TERHADAP LIST ******************/
void Konkat1ListB (ListB *L1, ListB *L2, ListB *L3);
/* I.S. L1 dan L2 sembarang */
/* F.S. L1 dan L2 kosong, L3 adalah hasil konkatenasi L1 & L2 */
/* Konkatenasi dua buah list : L1 dan L2    */
/* menghasilkan L3 yang baru (dengan elemen list L1 dan L2) */
/* dan L1 serta L2 menjadi list kosong.*/
/* Tidak ada alokasi/dealokasi pada prosedur ini */

#endif

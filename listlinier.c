/* File : listlinier.h */
/* contoh ADT list berkait dengan representasi fisik pointer  */
/* Representasi address dengan pointer */
/* infotypeList adalah integer */
/*
Nama			: William
NIM 			: 13518138
Topik 			: Linear List
*/

#include"listlinier.h"
#include<stdlib.h>
#include<stdio.h>

#define printInt(x) printf("%d", x)
#define printlnInt(x) printf("%d\n", x)
#define println(x) printf("%c\n", x)
#define print(x) printf("%c", x)
#define bacaInt(x) scanf("%d", &x)
#define bacaChar(x) scanf("%c", &c)
#define loop1(bool1) while(bool1)
#define loop2(bool1,bool2) while(bool1 && bool2)
#define loop3(bool1,bool2,bool3) while(bool1 && bool2 & bool3)
#define forloop(S, i) for (int i = )
#define max(a, b) a>b?a:b
#define min(a, b) a<b?a:b
#define abs(a) a<0?-a:a
#define selisih(a, b) abs(a-b)
#define swap(a,b) {infotypeList tmp; tmp = b; b = a; a = tmp;}
#define endline printf("\n")

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmptyList (List L) {
	/* Mengirim true jika list kosong */
	return (First(L) == Nil);
}

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmptyList (List *L) {
	/* I.S. sembarang             */
	/* F.S. Terbentuk list kosong */
	First(*L) = Nil;
}

/****************** Manajemen Memori ******************/
address AlokasiList (infotypeList X) {
	/* Mengirimkan address hasil alokasi sebuah elemen */
	/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
	/* menghasilkan P, maka Info(P)=X, Next(P)=Nil */
	/* Jika alokasi gagal, mengirimkan Nil */
	address P;
	P = (address) malloc(sizeof(ElmtList));
	if (P != Nil) {
		Info(P) = X;
		Next(P) = Nil;
		return P;
	} else {
		return Nil;
	}
}

void DealokasiList (address *P) {
	/* I.S. P terdefinisi */
	/* F.S. P dikembalikan ke sistem */
	/* Melakukan dealokasi/pengembalian address P */
	free(*P);
}

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address SearchList (List L, infotypeList X) {
	/* Mencari apakah ada elemen list dengan Info(P)= X */
	/* Jika ada, mengirimkan address elemen tersebut. */
	/* Jika tidak ada, mengirimkan Nil */
	address P;
	if (!IsEmpty(L)) {
		P = First(L);
		boolean Found = false;
		loop2(!Found, P != Nil) {
			if (Info(P) == X) {
				Found = true;
			} else {
				P = Next(P);
			}
		}
		if (Found) {
			return P;
		} else {
			return Nil;
		}
	} else {
		return Nil;
	}
}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirstList (List *L, infotypeList X) {
	/* I.S. L mungkin kosong */
	/* F.S. Melakukan alokasi sebuah elemen dan */
	/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
	address P;
	P = Alokasi(X);
	if (P != Nil) {
		Next(P) = First(*L);
		First(*L) = P;
	}

}
void InsVLastList (List *L, infotypeList X) {
	/* I.S. L mungkin kosong */
	/* F.S. Melakukan alokasi sebuah elemen dan */
	/* menambahkan elemen list di akhir: elemen terakhir yang baru */
	/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

	address P, Last;
	P = Alokasi(X);
	if (P != Nil) {
		if (!IsEmpty(*L)) {
			Last = First(*L);
			while (Next(Last) != Nil) {
				Last = Next(Last);
			}
			InsertAfter(L, P, Last);
		} else {
			InsertFirst(L, P);
		}
	}
}

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirstList (List *L, infotypeList *X) {
	/* I.S. List L tidak kosong  */
	/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
	/*      dan alamat elemen pertama di-dealokasi */
	(*X) = Info(First(*L));
	address P;
	P = First(*L);
	First(*L) = Next(First(*L));
	Next(P) = Nil;
	Dealokasi(&P);
}
void DelVLastList (List *L, infotypeList *X) {
	/* I.S. list tidak kosong */
	/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
	/*      dan alamat elemen terakhir di-dealokasi */
	address Last, precLast;
	Last = First(*L);
	precLast = Nil;
	while (Next(Last) != Nil) {
		precLast = Last;
		Last = Next(Last);
	}
	(*X) = Info(Last);
	if (precLast == Nil) {
		First(*L) = Nil;
	} else {
		Next(precLast) = Nil;
	}
	Dealokasi(&Last);

}

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirstList (List *L, address P) {
	/* I.S. Sembarang, P sudah dialokasi  */
	/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
	if (IsEmpty(*L)) {
		Next(P) = Nil;
		First(*L) = P;
	} else {
		Next(P) = First(*L);
		First(*L) = P;
	}
}
void InsertAfterList (List *L, address P, address Prec) {
	/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
	/*      P sudah dialokasi  */
	/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
	Next(P) = Next(Prec);
	Next(Prec) = P;
}
void InsertLastList (List *L, address P) {
	/* I.S. Sembarang, P sudah dialokasi  */
	/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
	address Last;
	if (IsEmpty(*L)) {
		Next(P) = Nil;
		First(*L) = P;
	} else {
		Last = First(*L);
		while (Next(Last) != Nil) {
			Last = Next(Last);
		}
		Next(P) = Nil;
		Next(Last) = P;
	}
}

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirstList (List *L, address *P) {
	/* I.S. List tidak kosong */
	/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
	/*      Elemen list berkurang satu (mungkin menjadi kosong) */
	/* First element yg baru adalah suksesor elemen pertama yang lama */
	(*P) = First(*L);
	First(*L) = Next(First(*L));
	Next(*P) = Nil;
}
void DelPList (List *L, infotypeList X) {
	/* I.S. Sembarang */
	/* F.S. Jika ada elemen list beraddress P, dengan Info(P)=X  */
	/* Maka P dihapus dari list dan di-dealokasi */
	/* Jika ada lebih dari satu elemen list dengan Info bernilai X */
	/* maka yang dihapus hanya elemen pertama dengan Info = X */
	/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
	/* List mungkin menjadi kosong karena penghapusan */
	address P, Last;
	if (!IsEmpty(*L)) {
		if (Info(First(*L)) == X) {
			DelFirst(L, &P);
		} else {
			P = Search(*L, X);
			if (P != Nil) {
				Last = First(*L);
				if (Last != P) {
					loop1(Next(Last) != P) {
						Last = Next(Last);
					}
					Next(Last) = Next(P);
					Next(P) = Nil;
					Dealokasi(&P);
				}
			}
		}
	}
}
void DelLastList (List * L, address * P) {
	/* I.S. List tidak kosong */
	/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
	/*      Elemen list berkurang satu (mungkin menjadi kosong) */
	/* Last element baru adalah predesesor elemen terakhir yg lama, */
	/* jika ada */
	address precLast, Last;
	Last = First(*L);
	precLast = Nil;
	while (Next(Last) != Nil) {
		precLast = Last;
		Last = Next(Last);
	}
	(*P) = Last;
	if (precLast == Nil) {
		First(*L) = Nil;
	} else {
		Next(precLast) = Nil;
	}
}
void DelAfterList (List * L, address * Pdel, address Prec) {
	/* I.S. List tidak kosong. Prec adalah anggota list  */
	/* F.S. Menghapus Next(Prec): */
	/*      Pdel adalah alamat elemen list yang dihapus  */
	address Last;
	address place;
	boolean Found;
	(*Pdel) = Next(Prec);

	Last = First(*L);
	if (Last == Prec) {
		place = Next(Next(Prec));
		Next(Next(Prec)) = Nil;
		Next(Prec) = place;
	} else {
		Found = false;
		loop1(Last != Prec) {
			Last = Next(Last);
		}
		place = Next(Next(Last));
		Next(Next(Last)) = Nil;
		Next(Last) = place;
	}
}

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintInfoList (List L) {
	/* I.S. List mungkin kosong */
	/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
	/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
	/* Jika list kosong : menulis [] */
	/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
	print('[');
	if (!IsEmpty(L)) {
		address Last;
		Last = First(L);
		while (Next(Last) != Nil) {
			printInt(Info(Last));
			Last = Next(Last);
			print(',');
		}
		if (Last != Nil) {
			printInt(Info(Last));
		}
	}
	print(']');
}
int NbElmtList (List L) {
	/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
	int count = 0;
	if (!IsEmpty(L)) {
		address Last;
		Last = First(L);
		while (Last != Nil) {
			count += 1;
			Last = Next(Last);
		}
	}
	return count;
}

/*** Prekondisi untuk Max/Min/rata-rata : List tidak kosong ***/
infotypeList MaxList (List L) {
	/* Mengirimkan nilai Info(P) yang maksimum */
	infotypeList MAX;
	address Last;

	Last = First(L);
	MAX = Info(Last);
	while (Next(Last) != Nil) {
		Last = Next(Last);
		if (Info(Last) > MAX) {
			MAX = Info(Last);
		}
	}
	return MAX;
}
/****************** PROSES TERHADAP LIST ******************/
void Konkat1List (List * L1, List * L2, List * L3) {
	/* I.S. L1 dan L2 sembarang */
	/* F.S. L1 dan L2 kosong, L3 adalah hasil konkatenasi L1 & L2 */
	/* Konkatenasi dua buah list : L1 dan L2    */
	/* menghasilkan L3 yang baru (dengan elemen list L1 dan L2) */
	/* dan L1 serta L2 menjadi list kosong.*/
	/* Tidak ada alokasi/dealokasi pada prosedur ini */

	address Last;
	CreateEmpty(L3);
	if (IsEmpty(*L1)) {
		First(*L3) = First(*L2);
	} else {
		First(*L3) = First(*L1);
		Last = First(*L3);
		while (Next(Last) != Nil) {
			Last = Next(Last);
		}
		Next(Last) = First(*L2);
	}

	First(*L1) = Nil;
	First(*L2) = Nil;

}




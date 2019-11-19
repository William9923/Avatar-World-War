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
	return (FirstL(L) == Kosong);
}

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmptyList (List *L) {
	/* I.S. sembarang             */
	/* F.S. Terbentuk list kosong */
	FirstL(*L) = Kosong;
}

/****************** Manajemen Memori ******************/
address AlokasiList (infotypeList X) {
	/* Mengirimkan address hasil alokasi sebuah elemen */
	/* Jika alokasi berhasil, maka address tidak kosong, dan misalnya */
	/* menghasilkan P, maka Info(P)=X, Next(P)=Kosong */
	/* Jika alokasi gagal, mengirimkan Kosong */
	address P;
	P = (address) malloc(sizeof(ElmtList));
	if (P != Kosong) {
		InfoL(P) = X;
		NextL(P) = Kosong;
		return P;
	} else {
		return Kosong;
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
	/* Jika tidak ada, mengirimkan Kosong */
	printf("%s ", "Jancuk type");
	printlnInt(X);
	address P;
	if (!IsEmptyList(L)) {
		P = FirstL(L);
		boolean Found = false;
		loop2(!Found, P != Kosong) {
			if (InfoL(P) == X) {
				Found = true;
			} else {
				P = NextL(P);
			}
		}
		if (Found) {
			printf("%s\n", "Harusntya uda bener");
			return P;
		} else {
			return Kosong;
		}
	} else {
		return Kosong;
	}
}

/****************** PRIMITIF BERDASARKAN KOSONGAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirstList (List *L, infotypeList X) {
	/* I.S. L mungkin kosong */
	/* F.S. Melakukan alokasi sebuah elemen dan */
	/* menambahkan elemen pertama dengan kosongai X jika alokasi berhasil */
	address P;
	P = AlokasiList(X);
	if (P != Kosong) {
		NextL(P) = FirstL(*L);
		FirstL(*L) = P;
	}

}
void InsVLastList (List *L, infotypeList X) {
	/* I.S. L mungkin kosong */
	/* F.S. Melakukan alokasi sebuah elemen dan */
	/* menambahkan elemen list di akhir: elemen terakhir yang baru */
	/* berkosongai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

	address P, Last;
	P = AlokasiList(X);
	if (P != Kosong) {
		if (!IsEmptyList(*L)) {
			Last = FirstL(*L);
			while (NextL(Last) != Kosong) {
				Last = NextL(Last);
			}
			InsertAfterList(L, P, Last);
		} else {
			InsertFirstList(L, P);
		}
	}
}

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirstList (List *L, infotypeList *X) {
	/* I.S. List L tidak kosong  */
	/* F.S. Elemen pertama list dihapus: kosongai info disimpan pada X */
	/*      dan alamat elemen pertama di-dealokasi */
	(*X) = InfoL(FirstL(*L));
	address P;
	P = FirstL(*L);
	FirstL(*L) = NextL(FirstL(*L));
	NextL(P) = Kosong;
	DealokasiList(&P);
}
void DelVLastList (List *L, infotypeList *X) {
	/* I.S. list tidak kosong */
	/* F.S. Elemen terakhir list dihapus: kosongai info disimpan pada X */
	/*      dan alamat elemen terakhir di-dealokasi */
	address Last, precLast;
	Last = FirstL(*L);
	precLast = Kosong;
	while (NextL(Last) != Kosong) {
		precLast = Last;
		Last = NextL(Last);
	}
	(*X) = InfoL(Last);
	if (precLast == Kosong) {
		FirstL(*L) = Kosong;
	} else {
		NextL(precLast) = Kosong;
	}
	DealokasiList(&Last);

}

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirstList (List *L, address P) {
	/* I.S. Sembarang, P sudah dialokasi  */
	/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
	if (IsEmptyList(*L)) {
		NextL(P) = Kosong;
		FirstL(*L) = P;
	} else {
		NextL(P) = FirstL(*L);
		FirstL(*L) = P;
	}
}
void InsertAfterList (List *L, address P, address Prec) {
	/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
	/*      P sudah dialokasi  */
	/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
	NextL(P) = NextL(Prec);
	NextL(Prec) = P;
}
void InsertLastList (List *L, address P) {
	/* I.S. Sembarang, P sudah dialokasi  */
	/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
	address Last;
	if (IsEmptyList(*L)) {
		NextL(P) = Kosong;
		FirstL(*L) = P;
	} else {
		Last = FirstL(*L);
		while (NextL(Last) != Kosong) {
			Last = NextL(Last);
		}
		NextL(P) = Kosong;
		NextL(Last) = P;
	}
}

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirstList (List *L, address *P) {
	/* I.S. List tidak kosong */
	/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
	/*      Elemen list berkurang satu (mungkin menjadi kosong) */
	/* First element yg baru adalah suksesor elemen pertama yang lama */
	(*P) = FirstL(*L);
	FirstL(*L) = NextL(FirstL(*L));
	NextL(*P) = Kosong;
}
void DelPList (List *L, infotypeList X) {
	/* I.S. Sembarang */
	/* F.S. Jika ada elemen list beraddress P, dengan Info(P)=X  */
	/* Maka P dihapus dari list dan di-dealokasi */
	/* Jika ada lebih dari satu elemen list dengan Info berkosongai X */
	/* maka yang dihapus hanya elemen pertama dengan Info = X */
	/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
	/* List mungkin menjadi kosong karena penghapusan */
	address P, Last;
	if (!IsEmptyList(*L)) {
		if (InfoL(FirstL(*L)) == X) {
			DelFirstList(L, &P);
		} else {
			P = SearchList(*L, X);
			if (P != Kosong) {
				Last = FirstL(*L);
				if (Last != P) {
					loop1(NextL(Last) != P) {
						Last = NextL(Last);
					}
					NextL(Last) = NextL(P);
					NextL(P) = Kosong;
					DealokasiList(&P);
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
	Last = FirstL(*L);
	precLast = Kosong;
	while (NextL(Last) != Kosong) {
		precLast = Last;
		Last = NextL(Last);
	}
	(*P) = Last;
	if (precLast == Kosong) {
		FirstL(*L) = Kosong;
	} else {
		NextL(precLast) = Kosong;
	}
}
void DelAfterList (List * L, address * Pdel, address Prec) {
	/* I.S. List tidak kosong. Prec adalah anggota list  */
	/* F.S. Menghapus Next(Prec): */
	/*      Pdel adalah alamat elemen list yang dihapus  */
	address Last;
	address place;
	boolean Found;
	(*Pdel) = NextL(Prec);

	Last = FirstL(*L);
	if (Last == Prec) {
		place = NextL(NextL(Prec));
		NextL(NextL(Prec)) = Kosong;
		NextL(Prec) = place;
	} else {
		Found = false;
		loop1(Last != Prec) {
			Last = NextL(Last);
		}
		place = NextL(NextL(Last));
		NextL(NextL(Last)) = Kosong;
		NextL(Last) = place;
	}
}

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintInfoList (List L) {
	/* I.S. List mungkin kosong */
	/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
	/* Contoh : jika ada tiga elemen berkosongai 1, 20, 30 akan dicetak: [1,20,30] */
	/* Jika list kosong : menulis [] */
	/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
	print('[');
	if (!IsEmptyList(L)) {
		address Last;
		Last = FirstL(L);
		while (NextL(Last) != Kosong) {
			printInt(InfoL(Last));
			Last = NextL(Last);
			print(',');
		}
		if (Last != Kosong) {
			printInt(InfoL(Last));
		}
	}
	print(']');
}
int NbElmtList (List L) {
	/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
	int count = 0;
	if (!IsEmptyList(L)) {
		address Last;
		Last = FirstL(L);
		while (Last != Kosong) {
			count += 1;
			Last = NextL(Last);
		}
	}
	return count;
}

/*** Prekondisi untuk Max/Min/rata-rata : List tidak kosong ***/
infotypeList MaxList (List L) {
	/* Mengirimkan kosongai Info(P) yang maksimum */
	infotypeList MAX;
	address Last;

	Last = FirstL(L);
	MAX = InfoL(Last);
	while (NextL(Last) != Kosong) {
		Last = NextL(Last);
		if (InfoL(Last) > MAX) {
			MAX = InfoL(Last);
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
	CreateEmptyList(L3);
	if (IsEmptyList(*L1)) {
		FirstL(*L3) = FirstL(*L2);
	} else {
		FirstL(*L3) = FirstL(*L1);
		Last = FirstL(*L3);
		while (NextL(Last) != Kosong) {
			Last = NextL(Last);
		}
		NextL(Last) = FirstL(*L2);
	}

	FirstL(*L1) = Kosong;
	FirstL(*L2) = Kosong;

}

void KonkatDoang (List L1, List L2, List * L3){
	address Last;
	CreateEmptyList(L3);
	if (IsEmptyList(L1)) {
		FirstL(*L3) = FirstL(L2);
	} else {
		FirstL(*L3) = FirstL(L1);
		Last = FirstL(*L3);
		while (NextL(Last) != Kosong) {
			Last = NextL(Last);
		}
		NextL(Last) = FirstL(L2);
	}
}




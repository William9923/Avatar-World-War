/* File : listlinier.h */
/* contoh ADT list berkait dengan representasi fisik pointer  */
/* Representasi elb dengan pointer */
/* Bangunan adalah integer */
/*
Nama			: William
NIM 			: 13518138
Topik 			: Linear ListB
*/

#include"listbangunan.h"
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
#define endline printf("\n")

/* PROTOTYPE */


/****************** TEST LIST KOSONG ******************/
boolean IsEmptyListB (ListB L) {
	/* Mengirim true jika list kosong */
	return (FirstB(L) == Kosong);
}

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmptyListB (ListB *L) {
	/* I.S. sembarang             */
	/* F.S. Terbentuk list kosong */
	FirstB(*L) = Kosong;
}

/****************** Manajemen Memori ******************/
elb AlokasiListB (Bangunan X) {
	/* Mengirimkan elb hasil alokasi sebuah elemen */
	/* Jika alokasi berhasil, maka elb tidak nil, dan misalnya */
	/* menghasilkan P, maka Bangunan(P)=X, NextB(P)=Kosong */
	/* Jika alokasi gagal, mengirimkan Kosong */
	elb P;
	P = (elb) malloc(sizeof(ElmtListB));
	if (P != Kosong) {
		Bangunan(P) = X;
		NextB(P) = Kosong;
		return P;
	} else {
		return Kosong;
	}
}

void DealokasiListB (elb P) {
	/* I.S. P terdefinisi */
	/* F.S. P dikembalikan ke sistem */
	/* Melakukan dealokasi/pengembalian elb P */
	free(P);
}

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
elb SearchListB (ListB L, Bangunan X) {
	/* Mencari apakah ada elemen list dengan Bangunan(P)= X */
	/* Jika ada, mengirimkan elb elemen tersebut. */
	/* Jika tidak ada, mengirimkan Kosong */
	elb P;
	if (!IsEmptyListB(L)) {
		P = FirstB(L);
		boolean Found = false;
		loop2(!Found, P != Kosong) {
			if (EQBangunan(Bangunan(P),X)) {
				Found = true;
			} else {
				P = NextB(P);
			}
		}
		if (Found) {
			return P;
		} else {
			return Kosong;
		}
	} else {
		return Kosong;
	}
}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirstListB (ListB *L, Bangunan X) {
	/* I.S. L mungkin kosong */
	/* F.S. Melakukan alokasi sebuah elemen dan */
	/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
	elb P;
	P = AlokasiListB(X);
	if (P != Kosong) {
		NextB(P) = FirstB(*L);
		FirstB(*L) = P;
	}

}
void InsVLastListB (ListB *L, Bangunan X) {
	/* I.S. L mungkin kosong */
	/* F.S. Melakukan alokasi sebuah elemen dan */
	/* menambahkan elemen list di akhir: elemen terakhir yang baru */
	/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

	elb P, Last;
	P = AlokasiListB(X);
	if (P != Kosong) {
		if (!IsEmptyListB(*L)) {
			Last = FirstB(*L);
			while (NextB(Last) != Kosong) {
				Last = NextB(Last);
			}
			InsertAfterListB(L, P, Last);
		} else {
			InsertFirstListB(L, P);
		}
	}
}

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirstBListB (ListB *L, Bangunan *X) {
	/* I.S. ListB L tidak kosong  */
	/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
	/*      dan alamat elemen pertama di-dealokasi */
	(*X) = Bangunan(FirstB(*L));
	elb P;
	P = FirstB(*L);
	FirstB(*L) = NextB(FirstB(*L));
	NextB(P) = Kosong;
	DealokasiListB(P);
}
void DelVLastListB (ListB *L, Bangunan *X) {
	/* I.S. list tidak kosong */
	/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
	/*      dan alamat elemen terakhir di-dealokasi */
	elb Last, precLast;
	Last = FirstB(*L);
	precLast = Kosong;
	while (NextB(Last) != Kosong) {
		precLast = Last;
		Last = NextB(Last);
	}
	(*X) = Bangunan(Last);
	if (precLast == Kosong) {
		FirstB(*L) = Kosong;
	} else {
		NextB(precLast) = Kosong;
	}
	DealokasiListB(Last);

}

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirstListB (ListB *L, elb P) {
	/* I.S. Sembarang, P sudah dialokasi  */
	/* F.S. Menambahkan elemen ber-elb P sebagai elemen pertama */
	if (IsEmptyListB(*L)) {
		NextB(P) = Kosong;
		FirstB(*L) = P;
	} else {
		NextB(P) = FirstB(*L);
		FirstB(*L) = P;
	}
}
void InsertAfterListB (ListB *L, elb P, elb Prec) {
	/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
	/*      P sudah dialokasi  */
	/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
	NextB(P) = NextB(Prec);
	NextB(Prec) = P;
}
void InsertLastListB (ListB *L, elb P) {
	/* I.S. Sembarang, P sudah dialokasi  */
	/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
	elb Last;
	if (IsEmptyListB(*L)) {
		NextB(P) = Kosong;
		FirstB(*L) = P;
	} else {
		Last = FirstB(*L);
		while (NextB(Last) != Kosong) {
			Last = NextB(Last);
		}
		NextB(P) = Kosong;
		NextB(Last) = P;
	}
}

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirstListB (ListB *L, elb *P) {
	/* I.S. ListB tidak kosong */
	/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
	/*      Elemen list berkurang satu (mungkin menjadi kosong) */
	/* FirstB element yg baru adalah suksesor elemen pertama yang lama */
	(*P) = FirstB(*L);
	FirstB(*L) = NextB(FirstB(*L));
	NextB(*P) = Kosong;
}
void DelPListB (ListB *L, Bangunan X) {
	/* I.S. Sembarang */
	/* F.S. Jika ada elemen list berelb P, dengan Bangunan(P)=X  */
	/* Maka P dihapus dari list dan di-dealokasi */
	/* Jika ada lebih dari satu elemen list dengan Bangunan bernilai X */
	/* maka yang dihapus hanya elemen pertama dengan Bangunan = X */
	/* Jika tidak ada elemen list dengan Bangunan(P)=X, maka list tetap */
	/* ListB mungkin menjadi kosong karena penghapusan */
	elb P, Last;
	if (!IsEmptyListB(*L)) {
		if (EQBangunan(Bangunan(FirstB(*L)), X)) {
			DelFirstListB(L, &P);
		} else {
			P = SearchListB(*L, X);
			if (P != Kosong) {
				Last = FirstB(*L);
				if (Last != P) {
					loop1(NextB(Last) != P) {
						Last = NextB(Last);
					}
					NextB(Last) = NextB(P);
					NextB(P) = Kosong;
					DealokasiListB(P);
				}
			}
		}
	}
}
void DelLastListB (ListB * L, elb * P) {
	/* I.S. ListB tidak kosong */
	/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
	/*      Elemen list berkurang satu (mungkin menjadi kosong) */
	/* Last element baru adalah predesesor elemen terakhir yg lama, */
	/* jika ada */
	elb precLast, Last;
	Last = FirstB(*L);
	precLast = Kosong;
	while (NextB(Last) != Kosong) {
		precLast = Last;
		Last = NextB(Last);
	}
	(*P) = Last;
	if (precLast == Kosong) {
		FirstB(*L) = Kosong;
	} else {
		NextB(precLast) = Kosong;
	}
}
void DelAfterListB (ListB * L, elb * Pdel, elb Prec) {
	/* I.S. ListB tidak kosong. Prec adalah anggota list  */
	/* F.S. Menghapus NextB(Prec): */
	/*      Pdel adalah alamat elemen list yang dihapus  */
	elb Last;
	elb place;
	boolean Found;
	(*Pdel) = NextB(Prec);

	Last = FirstB(*L);
	if (Last == Prec) {
		place = NextB(NextB(Prec));
		NextB(NextB(Prec)) = Kosong;
		NextB(Prec) = place;
	} else {
		Found = false;
		loop1(Last != Prec) {
			Last = NextB(Last);
		}
		place = NextB(NextB(Last));
		NextB(NextB(Last)) = Kosong;
		NextB(Last) = place;
	}
}

/****************** PROSES SEMUA ELEMEN LIST ******************/
 void PrintBangunanListB (ListB L) {
 	/* I.S. ListB mungkin kosong */
 	/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
 	/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
 	/* Jika list kosong : menulis [] */
 	/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
	
	if(!IsEmptyListB(L)){
		elb Iterate = FirstB(L);
		for(int i=1;i<=NbElmtListB(L);i++){
			printf("%d. ",i);
			PrintInfoBangunan(Bangunan(Iterate));
			printf("\n");
			Iterate = NextB(Iterate);
		}
	}
 }

int NbElmtListB (ListB L) {
	/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
	int count = 0;
	if (!IsEmptyListB(L)) {
		elb Last;
		Last = FirstB(L);
		while (Last != Kosong) {
			count += 1;
			Last = NextB(Last);
		}
	}
	return count;
}

// /*** Prekondisi untuk Max/Min/rata-rata : ListB tidak kosong ***/
// Bangunan MaxListB (ListB L) {
// 	/* Mengirimkan nilai Bangunan(P) yang maksimum */
// 	Bangunan MAX;
// 	elb Last;

// 	Last = FirstB(L);
// 	MAX = Bangunan(Last);
// 	while (NextB(Last) != Kosong) {
// 		Last = NextB(Last);
// 		if (Bangunan(Last) > MAX) {
// 			MAX = Bangunan(Last);
// 		}
// 	}
// 	return MAX;
// }
/****************** PROSES TERHADAP LIST ******************/
void Konkat1ListB (ListB * L1, ListB * L2, ListB * L3) {
	/* I.S. L1 dan L2 sembarang */
	/* F.S. L1 dan L2 kosong, L3 adalah hasil konkatenasi L1 & L2 */
	/* Konkatenasi dua buah list : L1 dan L2    */
	/* menghasilkan L3 yang baru (dengan elemen list L1 dan L2) */
	/* dan L1 serta L2 menjadi list kosong.*/
	/* Tidak ada alokasi/dealokasi pada prosedur ini */

	elb Last;
	CreateEmptyListB(L3);
	if (IsEmptyListB(*L1)) {
		FirstB(*L3) = FirstB(*L2);
	} else {
		FirstB(*L3) = FirstB(*L1);
		Last = FirstB(*L3);
		while (NextB(Last) != Kosong) {
			Last = NextB(Last);
		}
		NextB(Last) = FirstB(*L2);
	}

	FirstB(*L1) = Kosong;
	FirstB(*L2) = Kosong;

}




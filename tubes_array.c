#include <stdio.h>
#include "boolean.h"
#include "bangunan.h"

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : membuat tabel kosong */
void CreateEmptyArray(TabBangunan *T, int maxel)
/* I.S. T sembarang, maxel > 0 */
/* F.S. Terbentuk tabel T kosong dengan kapasitas maxel + 1 */
{
	TB(*T) = (ElType *) malloc ((maxel+1)*sizeof(ElType));
	Neff(*T) = 0; 
	MaxEl(*T) = maxel;
}

void Dealokasi(TabBangunan *T)
/* I.S. T terdefinisi; */
/* F.S. TB(T) dikembalikan ke sistem, MaxEl(T)=0; Neff(T)=0 */
{
	MaxEl(*T) = 0;
	Neff(*T) = 0;
}

/* ********** SELEKTOR ********** */
/* *** Banyaknya elemen *** */
int NbElmt(TabBangunan T)
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
{
	if (Neff(T) != 0)
		{ return Neff(T); }
	else
		{ return 0; }
}
/* *** Daya tampung tabel *** */
int MaxElement(TabBangunan T)
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
{
	return MaxEl(T);
}

/* *** Selektor INDEKS *** */
IdxType GetFirstIdx(TabBangunan T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T pertama */
{
	return IdxMin;
}

IdxType GetLastIdx(TabBangunan T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T terakhir */
{
	return (IdxMin + Neff(T) - 1);
}

// GATAU INI PERLU GA???????
/* ********** TEST KOSONG/PENUH ********** */ 
/* *** Test tabel kosong *** */
boolean IsEmpty(TabBangunan T)
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
{
	return (Neff(T) == 0);
}
/* *** Test tabel penuh *** */
boolean IsFull(TabBangunan T)
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */
{
	return (Neff(T) == MaxEl(T));
}

/* ********** SEARCHING ********** */
IdxType SearchIdxBangunan (TabBangunan T, ElType X);
/* Mencari apakah terdapat elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X */
/* Jika tidak ada, mengirimkan IdxUndef */
/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong */
/* Memakai skema search tanpa boolean */
{
	// KAMUS 
	IdxType i;
	// ALGORITMA 
	i = IdxMin;
	while ((Neff(T)!=0) && (i<=Neff(T)) && (Elmt(T,i) != X))
	{
		i += 1;
	}
	if (Elmt(T,i) == X)
		{return i;}
	else 
		{return IdxUndef;}
}

boolean SearchBangunan (TabBangunan T, ElType X);
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan true, jika tidak ada menghasilkan false */
/* Memakai Skema search dengan boolean */
{
	// KAMUS 
	boolean Found;
	IdxType i;
	
	// ALGORITMA
	Found = false;
	i = IdxMin;
	while ((Neff(T)!=0) && (i<=Neff(T)) && !(Found))
	{
		if (Elmt(T,i) == X)
			{Found = true;}
		else 
			{ i += 1;}
	}
	if (Found)
		{return true;}
	else 
		{return false;}
}

/* ********** MENAMBAH ELEMEN ********** */
/* *** Menambahkan elemen terakhir *** */
void AddBangunan (TabBangunan * T, ElType X);
/* Proses: Menambahkan X sebagai elemen terakhir tabel */
/* I.S. Tabel T boleh kosong, tetapi tidak penuh */
/* F.S. X adalah elemen terakhir T yang baru */
{
	Elmt(*T,(Neff(*T)+1)) = X;
	Neff(*T) += 1;
}

/* ********** MENGHAPUS ELEMEN ********** */
void DelBangunan (TabBangunan * T, IdxType i, ElType * X)
/* Menghapus elemen ke-i tabel tanpa mengganggu kontiguitas */
/* I.S. Tabel tidak kosong, i adalah indeks efektif yang valid */
/* F.S. X adalah nilai elemen ke-i T sebelum penghapusan */
/*      Banyaknya elemen tabel berkurang satu */
/*      Tabel T mungkin menjadi kosong */
/* Proses : Geser elemen ke-i+1 s.d. elemen terakhir */
/*          Kurangi elemen efektif tabel */
{
	// KAMUS
	IdxType j;
	// ALGORITMA
	*X = Elmt(*T,i);
	for (j=i;j<=Neff(*T);j++)
	{
		Elmt(*T,j) = Elmt(*T,j+1);
	}
	Neff(*T) -= 1;
	
}


void CetakBangunanDimiliki (TabBangunan T)
/* Proses: Mencetak ke layar bangunan yang dimiliki pemain */
/* I.S. Tabel T boleh kosong, tetapi tidak penuh */
/* F.S. Bangunan-bangunan milik pemain tercetak ke layar */
{
	// KAMUS
	IdxType i;
	// ALGORITMA
	for (i=GetFirstIdx(T);i<=GetLastIdx(T);i++)
	{
		printf("%d. ",i);
		PrintInfoBangunan(Elmt(T,i));
		printf(" ");
		TulisPOINT(Letak(Elmt(T,i)));
		printf(" %d ",Pasukan(Elmt(T,i)));
		printf("lv. %d\n",Level(Elmt(T,i)));
		
	}
}

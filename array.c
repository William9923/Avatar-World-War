
#include <stdio.h>
#include "boolean.h"
#include "bangunan.h"
#include "array.h"
#include "point.h"
#include <stdlib.h>

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : membuat tabel kosong */
void CreateEmptyArray(TabBangunan *T, int maxel)
/* I.S. T sembarang, maxel > 0 */
/* F.S. Terbentuk tabel T kosong dengan kapasitas maxel + 1 */
{
	TB(*T) = (ElTypeArray *) malloc ((maxel+1)*sizeof(ElTypeArray));
	NeffArray(*T) = 0; 
	MaxElArray(*T) = maxel;
}

void Dealokasi(TabBangunan *T)
/* I.S. T terdefinisi; */
/* F.S. TB(T) dikembalikan ke sistem, MaxElArray(T)=0; NeffArray(T)=0 */
{
	MaxElArray(*T) = 0;
	NeffArray(*T) = 0;
}

/* ********** SELEKTOR ********** */
/* *** Banyaknya elemen *** */
int NbElmt(TabBangunan T)
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
{
	if (NeffArray(T) != 0)
		{ return NeffArray(T); }
	else
		{ return 0; }
}
/* *** Daya tampung tabel *** */
int MaxElement(TabBangunan T)
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
{
	return MaxElArray(T);
}

/* *** Selektor INDEKS *** */
IdxTypeArray GetFirstIdx(TabBangunan T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T pertama */
{
	return IdxMinArray;
}

IdxTypeArray GetLastIdx(TabBangunan T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T terakhir */
{
	return (IdxMinArray + NeffArray(T) - 1);
}

// GATAU INI PERLU GA???????
/* ********** TEST KOSONG/PENUH ********** */ 
/* *** Test tabel kosong *** */
boolean IsEmpty(TabBangunan T)
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
{
	return (NeffArray(T) == 0);
}
/* *** Test tabel penuh *** */
boolean IsFull(TabBangunan T)
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */
{
	return (NeffArray(T) == MaxElArray(T));
}

/* ********** SEARCHING ********** */
IdxTypeArray SearchIdxBangunan (TabBangunan T, ElTypeArray X)
/* Mencari apakah terdapat elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X */
/* Jika tidak ada, mengirimkan IdxUndefArray */
/* Menghasilkan indeks tak terdefinisi (IdxUndefArray) jika tabel T kosong */
/* Memakai skema search tanpa boolean */
{
	// KAMUS 
	IdxTypeArray i;
	// ALGORITMA 
	i = IdxMinArray;
	while (i<=NeffArray(T)){
		if(EQBangunan(X,ElmtArray(T,i))){
			return i;
		}
		else{
			i++;
		}
	}
	return IdxUndefArray;
}

boolean SearchBangunan (TabBangunan T, ElTypeArray X)
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan true, jika tidak ada menghasilkan false */
/* Memakai Skema search dengan boolean */
{
	// KAMUS 
	boolean Found;
	IdxTypeArray i;
	
	// ALGORITMA
	Found = false;
	i = IdxMinArray;
	while ((NeffArray(T)!=0) && (i<=NeffArray(T)) && !(Found))
	{
		if ((Absis(Letak(ElmtArray(T,i))) != Absis(Letak(X))) && (Ordinat(Letak(ElmtArray(T,i))) != Ordinat(Letak(X))))
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
void AddBangunan (TabBangunan * T, ElTypeArray X)
/* Proses: Menambahkan X sebagai elemen terakhir tabel */
/* I.S. Tabel T boleh kosong, tetapi tidak penuh */
/* F.S. X adalah elemen terakhir T yang baru */
{
	ElmtArray(*T,(NeffArray(*T)+1)) = X;
	NeffArray(*T) += 1;
}

/* ********** MENGHAPUS ELEMEN ********** */
void DelBangunan (TabBangunan * T, IdxTypeArray i, ElTypeArray * X)
/* Menghapus elemen ke-i tabel tanpa mengganggu kontiguitas */
/* I.S. Tabel tidak kosong, i adalah indeks efektif yang valid */
/* F.S. X adalah nilai elemen ke-i T sebelum penghapusan */
/*      Banyaknya elemen tabel berkurang satu */
/*      Tabel T mungkin menjadi kosong */
/* Proses : Geser elemen ke-i+1 s.d. elemen terakhir */
/*          Kurangi elemen efektif tabel */
{
	// KAMUS
	IdxTypeArray j;
	// ALGORITMA
	*X = ElmtArray(*T,i);
	for (j=i;j<=NeffArray(*T);j++)
	{
		ElmtArray(*T,j) = ElmtArray(*T,j+1);
	}
	NeffArray(*T) -= 1;
	
}


void CetakBangunanDimiliki (TabBangunan T)
/* Proses: Mencetak ke layar bangunan yang dimiliki pemain */
/* I.S. Tabel T boleh kosong, tetapi tidak penuh */
/* F.S. Bangunan-bangunan milik pemain tercetak ke layar */
{
	// KAMUS
	IdxTypeArray i;
	// ALGORITMA
	for (i=GetFirstIdx(T);i<=GetLastIdx(T);i++)
	{
		printf("%d. ",i);
		PrintInfoBangunan(ElmtArray(T,i));
	}
}

void CetakBangunanIndeks(TabBangunan tab, IdxTypeArray i){
	PrintInfoBangunan(ElmtArray(tab,i));
}

void CopyArray(TabBangunan tab1, TabBangunan * tab2){
	int x = NbElmt(tab1);
	CreateEmptyArray(tab2, x);

	for(int i = GetFirstIdx(tab1); i <= x; i++){
		ElmtArray((*tab2), i) = ElmtArray(tab1,i);
	}
}


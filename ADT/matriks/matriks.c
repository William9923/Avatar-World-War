#include <stdio.h>
#include "../boolean.h"
#include "../bangunan/bangunan.h"
#include "./matriks.h"
#include "../pcolor/pcolor.c"
#include "../pemain/pemain.h"
#include "../array/array.h"

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */
/* *** Konstruktor membentuk PETA *** */
void MakePeta (int NB, int NK, PETA * P) 
/* Membentuk sebuah PETA "kosong" yang siap diisi berukuran NB x NK */
/* I.S. NB dan NK adalah valid untuk memori peta yang dibuat */
/* F.S. Peta P sesuai dengan definisi di atas terbentuk */
{
	NBrsEff(*P) = NB;
	NKolEff(*P) = NK;
}

void MakePetaJadi(PETA *P, TabBangunan T)
/* Mengisi PETA dengan char menggunakan transversal */
/* I.S. PETA terdefinisi, bisa kosong */
/* F.S PETA terisi */
{
	int i;
	for (i=GetFirstIdx(T);i<=GetLastIdx(T);i++)
	{
		Bangunan A = ElmtArray(T,i);
		Point B = Letak(A);
		int X = Absis(B);
		int Y = Ordinat(B);
		ElmtMatriks(*P,X,Y) = Type(A);
	}
}

/* *** Selektor: Untuk sebuah peta P yang terdefinisi: *** */
IdxTypeMatriks GetFirstIdxBrs (PETA P)
/* Mengirimkan indeks baris terkecil P */
{
	return BrsMin;
}
IdxTypeMatriks GetFirstIdxKol (PETA P)
/* Mengirimkan indeks kolom terkecil P */
{
	return KolMin;
}

IdxTypeMatriks GetLastIdxBrs (PETA P)
/* Mengirimkan indeks baris terbesar P */
{
	return NBrsEff(P);
}

IdxTypeMatriks GetLastIdxKol (PETA P)
/* Mengirimkan indeks kolom terbesar P */
{
	return NKolEff(P);
}


// /* ********** BACA/TULIS ********** */
// void CetakPeta (PETA P,Pemain P1,Pemain P2,TabBangunan Tab)
// /* I.S. P terdefinisi */
// /* F.S. Elemen P dicetak ke layar per baris per kolom */
// /* Proses: Mencetak nilai setiap elemen P ke layar dengan traversal per baris dan per kolom */
// {
// 	int i,j;

// 	for (i=0; i<=GetLastIdxBrs(P)+1; i++) {
// 		for (j=0; j<=GetLastIdxKol(P)+1; j++) {
// 			if (i==0 || j == 0 || i == GetLastIdxBrs(P)+1 || j == GetLastIdxKol(P)+1) {
// 				printf("*");
// 			} else {
// 				if(ElmtMatriks(P,i,j) == 'C' || ElmtMatriks(P,i,j) == 'V' || ElmtMatriks(P,i,j) == 'T' || ElmtMatriks(P,i,j) == 'F') {
// 					if(haveBuildingKoordinat(P1,i,j,Tab)){
// 						print_red(ElmtMatriks(P,i,j));
// 					}
// 					else if(haveBuildingKoordinat(P2,i,j,Tab)){
// 						print_blue(ElmtMatriks(P,i,j));
// 					}
// 					else{
// 						printf("%c", ElmtMatriks(P,i,j));
// 					}
// 				} else {
// 					printf(" ");
// 				}
// 			}
// 		}
// 		printf("\n");
// 	}
// }

/* ********** BACA/TULIS ********** */
void CetakPeta (PETA P,Pemain P1,Pemain P2,TabBangunan Tab)
/* I.S. P terdefinisi */
/* F.S. Elemen P dicetak ke layar per baris per kolom */
/* Proses: Mencetak nilai setiap elemen P ke layar dengan traversal per baris dan per kolom */
{
	green();
	printf("   ╔");
	for (int i = 1; i <= GetLastIdxKol(P); i++){
		if (i == GetLastIdxKol(P)){
			printf("═══");
		} else {
			printf("═══╦");
		}
	}
	printf("╗");
	printf("\n");

	for(int i = 1; i <= GetLastIdxBrs(P); i++){
		normal();
		if ( i < 10){
			printf(" %d ",i);
		} else {
			printf("%d ", i);
		}
		green();
		for (int j = 1; j <= GetLastIdxKol(P); j++){
			green();
			printf("║");
			if(ElmtMatriks(P,i,j) == 'C' || ElmtMatriks(P,i,j) == 'V' || ElmtMatriks(P,i,j) == 'T' || ElmtMatriks(P,i,j) == 'F') {
				if(haveBuildingKoordinat(P1,i,j,Tab)){
					printf(" ");
					print_red(ElmtMatriks(P,i,j));
					printf(" ");
				}
				else if(haveBuildingKoordinat(P2,i,j,Tab)){
					printf(" ");
					print_blue(ElmtMatriks(P,i,j));
					printf(" ");
				}
				else{
					printf(" ");
					normal();
					printf("%c", ElmtMatriks(P,i,j));
					printf(" ");
				}
			} else {
				printf("   ");
			}
		}
		green();
		printf("║");
		printf("\n");
		if (i != GetLastIdxBrs(P)){
			printf("   ╠");
			for (int i = 1; i <= GetLastIdxKol(P); i++){
				green();
				if (i == GetLastIdxKol(P)){
					printf("═══");
				} else {
					printf("═══╬");
				}
			}
			green();
			printf("╣");
			printf("\n");
		}
	}
	printf("   ╚");
	for (int i = 1; i <= GetLastIdxKol(P); i++){
		green();
		if (i == GetLastIdxKol(P)){
			printf("═══");
		} else {
			printf("═══╩");
		}
	}
	green();
	printf("╝");
	printf("\n");
	printf("   ");
	for (int i = 1; i <= GetLastIdxKol(P); i++){
		normal();
		if ( i < 10){
			printf("  %d ",i);
		} else {
			printf(" %d ", i);
		}	
	}
	printf("\n");
	normal();
}
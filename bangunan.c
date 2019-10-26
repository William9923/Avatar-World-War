/*
File : bangunan.c
Author : William
Topik : Tugas Besar Alstrukdat 1
*/

#include "bangunan.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

/* *** DEFINISI PROTOTIPE PRIMITIF *** */
/* *** Konstruktor membentuk Bangunan *** */
void MakeBangunan(Bangunan * bangunan, char type, POINT point) {
	/*
	I.S. : Bangunan sembarang
	F.S  : Bangunan terdefinisi
	*/
	Level(*bangunan) = 1;
	Letak(*bangunan) = point;
	if (type == 'C') {
		Type(*(bangunan)) = 'C';
		A(*bangunan) = 10;
		M(*bangunan) = 40;
		U(*bangunan) = 40;
		Pasukan(*bangunan) = U(*bangunan);
		Pertahanan(*bangunan) = false;
	}
	else if (type == 'T') {
		Type(*(bangunan)) = 'T';
		A(*bangunan) = 5;
		M(*bangunan) = 20;
		U(*bangunan) = 30;
		Pasukan(*bangunan) = U(*bangunan);
		Pertahanan(*bangunan) = true;
	}
	else if (type == 'F') {
		Type(*(bangunan)) = 'F';
		A(*bangunan) = 10;
		M(*bangunan) = 20;
		U(*bangunan) = 80;
		Pasukan(*bangunan) = U(*bangunan);
		Pertahanan(*bangunan) = false;
	}
	else if (type == 'V') {
		Type(*(bangunan)) = 'V';
		A(*bangunan) = 5;
		M(*bangunan) = 20;
		U(*bangunan) = 20;
		Pasukan(*bangunan) = U(*bangunan);
		Pertahanan(*bangunan) = false;
	}
	Serang(*bangunan) = false;
	// else {
	// 	Type(*(bangunan)) = CharUndef
	// }
}

/* Fungsi - fungsi Primitif */
boolean IsAbleNaikLevel(Bangunan bangunan) {
// memberikan informasi apakah suatu bangunan dapat naik level atau tidak
// asumsi boleh nol
	if (Level(bangunan) < 4) return (Pasukan(bangunan) >= M(bangunan) / 2);
	else return false
	}

/* Fungsi - fungsi primitif terhadap naik level bangunan*/
Bangunan NaikLevelFort(Bangunan bangunan) {
	Bangunan newBangunan;
	newBangunan = bangunan;
	if (IsAbleNaikLevel(newBangunan)) {
		if (Level(newBangunan) == 1) {
			Pasukan(newBangunan) -= M(newBangunan) / 2;
			M(newBangunan) = 40;
			A(newBangunan) = 20;
			U(newBangunan) = -1;
		} else if (Level(newBangunan) == 2) {
			Pasukan(newBangunan) -= M(newBangunan) / 2;
			M(newBangunan) = 60;
			A(newBangunan) = 30;
			Pertahanan(newBangunan) = true;
		} else  if (Level(newBangunan) == 3) {
			Pasukan(newBangunan) -= M(newBangunan) / 2;
			M(newBangunan) = 80;
			A(newBangunan) = 40;
		}
		Level(newBangunan) += 1;
	}
	return newBangunan;
}

Bangunan NaikLevelTower(Bangunan bangunan) {
	Bangunan newBangunan;
	newBangunan = bangunan;
	if (IsAbleNaikLevel(newBangunan)) {
		if (Level(newBangunan) == 1) {
			Pasukan(newBangunan) -= M(newBangunan) / 2;
			M(newBangunan) = 30;
			A(newBangunan) = 10;
			U(newBangunan) = -1;
		} else if (Level(newBangunan) == 2) {
			Pasukan(newBangunan) -= M(newBangunan) / 2;
			M(newBangunan) = 40;
			A(newBangunan) = 20;
		} else if (Level(newBangunan) == 3) {
			Pasukan(newBangunan) -= M(newBangunan) / 2;
			M(newBangunan) = 50;
			A(newBangunan) = 30;
		}
		Level(newBangunan) += 1;
	}
	return newBangunan;
}

Bangunan NaikLevelCastle(Bangunan bangunan) {
	Bangunan newBangunan;
	newBangunan = bangunan;

	if (IsAbleNaikLevel(newBangunan)) {
		if (Level(newBangunan) == 1) {
			Pasukan(newBangunan) -= M(newBangunan) / 2;
			M(newBangunan) = 60;
			A(newBangunan) = 15;
			U(newBangunan) = -1;
		} else if (Level(newBangunan) == 2) {
			Pasukan(newBangunan) -= M(newBangunan) / 2;
			M(newBangunan) = 80;
			A(newBangunan) = 20;
		} else if (Level(newBangunan) == 3) {
			Pasukan(newBangunan) -= M(newBangunan) / 2;
			M(newBangunan) = 100;
			A(newBangunan) = 25;
		}
		Level(newBangunan) += 1;
	}
	return newBangunan;
}

Bangunan NaikLevelVillage(Bangunan bangunan) {
	Bangunan newBangunan;
	newBangunan = bangunan;

	if (IsAbleNaikLevel(newBangunan)) {
		if (Level(newBangunan) == 1) {
			Pasukan(newBangunan) -= M(newBangunan) / 2;
			M(newBangunan) = 30;
			A(newBangunan) = 10;
			U(newBangunan) = -1;
		} else if (Level(newBangunan) == 2) {
			Pasukan(newBangunan) -= M(newBangunan) / 2;
			M(newBangunan) = 40;
			A(newBangunan) = 15;
		} else if (Level(newBangunan) == 3) {
			Pasukan(newBangunan) -= M(newBangunan) / 2;
			M(newBangunan) = 50;
			A(newBangunan) = 20;
		}
		Level(newBangunan) += 1;
	}
	return newBangunan;
}

void NaikLevel(Bangunan * bangunan) {
	/*
		I.S. Bangunan akan naik level
		F.S. Bangunan naik levelnya apabila "valid" untuk naik level
	*/
	if (IsAbleNaikLevel(*bangunan)) {
		if (Type(*bangunan) == 'C') {
			(*bangunan) = NaikLevelCastle(*bangunan);
		} else if (Type(*bangunan) == 'T') {
			(*bangunan) = NaikLevelTower(*bangunan);
		} else if (Type(*bangunan) == 'F') {
			(*bangunan) = NaikLevelFort(*bangunan);
		} else { // village
			(*bangunan) = NaikLevelVillage(*bangunan);
		}
	}
}

/* Fungsi - fungsi primitif untuk Penyerangan*/
void Serang(Bangunan * bserang, Bangunan * bdiserang, int jPSerang);
/*
	I.S. Bangunan belum diserang
	F.S. Bangunan telah diserang
	Apabila Bangunan beralih kepemilikan, maka bangunan diserang akan berubah tempat listnya
*/

/* Fungsi - fungsi lainnya*/
boolean IsPindahPemilik(Bangunan bBertahan, int jumlahPenyerang) {
	float jumlahPenyerangDesimal;
	if (Pertahanan(bBertahan)) {
		jumlahPenyerangDesimal = (jumlahPenyerang * 3) / 4;
		return (Pasukan(bBertahan) < jumlahPenyerangDesimal);
	} else {
		return (Pasukan(bBertahan) <= jumlahPenyerang);
	}
}

boolean IsSudahSerang(Bangunan bangunan){
	return Serang(bangunan);
}

void TambahPasukan(Bangunan * bangunan) {
	/*
		I.S. : Jumlah Pasukan belum ditambahkan
		F.S. : Jumlah Pasukan telah bertambah
	*/
	if (Pasukan(*bangunan) < M(*bangunan)){
		Pasukan(*bangunan) += A(*bangunan);
	}
}
/* Cetak Info Bangunan*/
void PrintInfoBangunan(Bangunan bangunan) {
	/*
		Melakukan pencetakan terhadap info bangunan dengan format
		<jenis_bangunan> <letak_bangunan> <jumlah_pasukan> lv. <level_bangunan>
	*/
	if (Type(bangunan) == 'C'){
		printf("%s ", "Castle");
	} else if (Type(bangunan) == 'T'){
		printf("%s ", "Tower");
	} else if (Type(bangunan) == 'F'){
		printf("%s ", "Fort");
	} else if (Type(bangunan) == 'V'){
		printf("%s ", "Village");
	} 

	TulisPOINT(Letak(bangunan));
	printf(" ");

	printf("%d", Pasukan(bangunan));

	printf(" ");

	printf("lv. %d\n", Level(bangunan)); 
}

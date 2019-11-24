#include"./bangunan.h"
#include"./bangunan.c"
#include "../point/point.h"
#include"../point/point.c"
#include<stdlib.h>
#include<stdio.h>
/**********************************************************
*Bangunan                                                 *
*Author : William                                         *
*Created at : 26 Oktober 2019                             *
*File driver untuk ADT Bangunan                           *
*Digunakan untuk menguji fungsi - fungsi pada ADT Bangunan*
**********************************************************/
int main() {
	Bangunan bangunan1;
	Bangunan bangunan2;
	Point p1;
	Point p2;
	/* Membentuk letak absis dan ordinat dari letak bangunan */
	p1 = MakePoint(1,1);
	p2 = MakePoint(2,2);

	/* Uji coba membuat bangunan baru */
	MakeBangunan(&bangunan1, 'T' ,p1);
	MakeBangunan(&bangunan2, 'F', p2);

	if (IsAbleNaikLevel(bangunan1)){
		printf("%s\n", "Bangunan 1 dapat naik level");
	}
	if (IsAbleNaikLevel(bangunan2)){
		printf("%s\n", "Bangunan 2 dapat naik level");
	}

	printf("%s: %d\n", "Level Bangunan 1 saat ini",Level(bangunan1));
	printf("%s: %d\n", "Level Bangunan 2 saat ini",Level(bangunan2));
	/* Pengetesan prosedur naik level */
	NaikLevel(&bangunan1);
	NaikLevel(&bangunan2);
	printf("%s: %d\n", "Level Bangunan 1 setelah naik level ",Level(bangunan1));
	printf("%s: %d\n", "Level Bangunan 2 setelah naik level ",Level(bangunan2));

	/*Pengecekan terhadap fungsi boolean primitf */
	if (IsPindahPemilik(bangunan1, 100)){
		printf("%s\n", "Bangunan 1 akan berpindah pemilik jika diserang 100 pasukan dari lawan");
	} else {
		printf("%s\n", "Bangunan 1 tidak akan berpindah kepemilikan jika diserang oleh 100 pasukan musuh");
	}

	if (IsPindahPemilik(bangunan2, 5)){
		printf("%s\n", "Bangunan 2 akan berpindah pemilik jika diserang 5 pasukan dari lawan");
	} else {
		printf("%s\n", "Bangunan 2 tidak akan berpindah kepemilikan jika diserang oleh 5 pasukan musuh");
	}

	printf("%s: %d\n", "Pasukan bangunan 1 saat ini ",Pasukan(bangunan1));
	printf("%s: %d\n", "Pasukan bangunan 2 saat ini", Pasukan(bangunan2));

	PlusPasukan(&bangunan1);
	PlusPasukan(&bangunan2);

	printf("%s: %d\n", "Pasukan bangunan 1 setelah pertambahan pasukan ",Pasukan(bangunan1));
	printf("%s: %d\n", "Pasukan bangunan 2 setelah pertambahan pasukan", Pasukan(bangunan2));

	if(EQBangunan(bangunan1,bangunan2)){
		printf("%s\n", "Bangunan 1 dan Bangunan 2 sama");
	} else {
		printf("%s\n", "Bangunan 1 dan Bangunan 2 tidak sama");
	}

	printf("%s: %d\n","Level Bangunan saat ini ",Level(bangunan1));
	MakeLevelOne(&bangunan1);
	printf("%s: %d\n","Level Bangunan saat telah diambil musuh ",Level(bangunan1));
}
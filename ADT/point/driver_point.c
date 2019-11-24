#include"point.h"
#include"point.c"
/***************************************
* Point                                *
* Author : William                     *
* Created at : 04 November 2019        *
* Merupakan file driver dari ADT Point *
***************************************/
int main() {
	/* Pembuatan Point */
	Point p1;
	Point p2;

	/* Membuat Point */
	p1 = MakePoint(1,1);
	p2 = MakePoint(2,2);

	/* Daftar Point */
	printf("%s\n", "Daftar Point:");
	printf("%s :", "Titik pertama");
	TulisPoint(p1);
	printf("%s\n", "");
	printf("%s :", "Titik kedua");
	TulisPoint(p2);
	printf("%s\n", "");

	/* Pengecekan validitas letak titik*/
	if (EQ(p1,p2)){
		printf("%s\n", "Titik 1 dan titik 2 sama");
	} else {
		printf("%s\n", "Titik 1 dan titik 2 tidak sama");
	}

}
#include "../../include.h"


int main () {
	TabBangunan T;
//	PETA P;
//	Graph connectivity;
//	Pemain P1,P2;
//	List Netral;


	CreateEmptyArray(&T,200);
//	CreateEmptyList(&Netral);
//	readkonfig(&P,&T,&connectivity,&P1,&P2,&Netral);
//	Dealokasi(&T);
//	printf("%d\n",NeffArray(T));
//	printf("%d\n",MaxElArray(T));

	printf("%d\n",NbElmt(T));
	printf("%d\n",MaxElement(T));

//	printf("%d\n",GetFirstIdx(T));
//	printf("%d\n",GetLastIdx(T));

	if (IsEmpty(T))
	{printf("kosong\n");}
	else {printf("tidak kosong\n");}

	if (IsFull(T))
	{printf("penuh\n");}
	else {printf("tidak penuh\n");}

//	Bangunan X;
//	SearchIdxBangunan (T,X);

/*	if (SearchBangunan (T,X))
	{printf("ada\n");}
	else {printf("tidak ada\n");} */

//	AddBangunan (&T,X);

//	Bangunan Y;
//	IdxTypeArray i;
//	DelBangunan (&T, i, &Y)

//	CetakBangunanDimiliki (T);
//	CetakBangunanIndeks(T,i);

	TabBangunan TCopy;
	CopyArray(T, &TCopy);

	return 0;
}
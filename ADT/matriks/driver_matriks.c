#include "../../include.h"

int main () {
	
	PETA P;
	
	MakePeta(10,17,&P);

//	TabBangunan B;
//	MakePetaJadi(&P,B);

	printf("%d\n",NBrsEff(P));
	printf("%d\n",NKolEff(P));

	printf("%d\n",GetFirstIdxBrs(P));
	printf("%d\n",GetFirstIdxKol(P));
	printf("%d\n",GetLastIdxBrs(P));
	printf("%d\n",GetLastIdxKol(P));

//	Pemain P1,P2;
//	CetakPeta (P,P1,P2,B);
	
	return 0;
}
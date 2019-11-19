#include"pemain.h"
#include"bangunan.h"
#include"listlinier.h"
#include "array.h"

boolean haveBuilding(Pemain P){
/* Apakah player P punya bangunan */
    return !IsEmptyList(P.b);  
}

void CreateNewPlayer(Pemain *P,char Q,int nomor){
/* Fungsinya untuk membuat player baru di game, dengan ketentuan:
Warna(*P) = R atau B,ListBangunan kosong */
    CreateEmptyList(&((*P).b)); 
    (*P).nomor = nomor;
}

void ChangeOwner(Pemain *P,Bangunan b,Pemain *NewOwner, TabBangunan tab){
/* Untuk mengganti kepemilikan bangunan dari P ke NewOwner */
 	IdxTypeArray i = SearchIdxBangunan(tab,b);
    DelPList(&((*P).b),i);
    InsVLastList(&((*NewOwner).b),i);
}


boolean haveBuildingB(Pemain P,Bangunan a, TabBangunan tab){
 	IdxTypeArray i = SearchIdxBangunan(tab,a);
 	printf("%s: ", "Index Bangunan");
 	printf("%d\n", i);
 	if (SearchList(P.b,i) != NULL){
 		printf("%s\n", "TESTING");//coba push
 		printf("Nilai hasil search :%d\n", InfoL(SearchList(P.b,i)));
 	}
    return (SearchList(P.b,i) != NULL);
}

/*
TODO :
1. Ganti semua fungsi jadi fungsi yang ada di listlinier.c (sebenarnya ilangin aja si B nya dari fungsi wkwk)
2. Sama dia tuh sekarang makenya list linier yang isinya integer,
	namun mekanisme kek di ChangeOwner seharusnya sama
	( cuman mindahinnya beda, yang lama mindahin bangunan, sekarang cuman mindahin index)
3. Buat haveBuilding, nanti aku bikinin fungsi mapping, di utility, kalo ga kliatan chat aku aja yaa...
*/
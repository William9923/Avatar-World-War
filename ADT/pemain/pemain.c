#include"./pemain.h"
#include"../bangunan/bangunan.h"
#include"../list/listlinier.h"
#include "../array/array.h"

boolean haveBuilding(Pemain P){
/* Apakah player P punya bangunan */
    return !IsEmptyList(P.b);  
}

void CreateNewPlayer(Pemain *P,int nomor){
/* Fungsinya untuk membuat player baru di game, dengan ketentuan:
Warna(*P) = R atau B,ListBangunan kosong */
    CreateEmptyList(&((*P).b)); 
    (*P).nomor = nomor;
	CreateEmptyQueue(&(*P).Skill);
}

void ChangeOwner(Pemain *P,Bangunan b,Pemain *NewOwner, TabBangunan tab){
/* Untuk mengganti kepemilikan bangunan dari P ke NewOwner */
 	IdxTypeArray i = SearchIdxBangunan(tab,b);
    DelPList(&((*P).b),i);
    InsVLastList(&((*NewOwner).b),i);
}


boolean haveBuildingB(Pemain P,Bangunan a, TabBangunan tab){
 	IdxTypeArray i = SearchIdxBangunan(tab,a);
    return (SearchList(P.b,i) != NULL);
}

boolean haveBuildingKoordinat(Pemain P,int i,int j,TabBangunan Tab){
	List X = P.b;
	address last = FirstL(X);
	Bangunan b;
	while(last!=NULL){
		b = ElmtArray(Tab,InfoL(last));
		Point T;
		T = MakePoint(i,j);
		if(EQ(T,b.letak)){
			return true;
		}
		else{
			last=NextL(last);
		}
	}
	return false;
}

void CopyPemain(Pemain P,Pemain *Destination){
	CopyList(P.b,&((*Destination).b));
	(*Destination).Skill = P.Skill;
}

/*
TODO :
1. Ganti semua fungsi jadi fungsi yang ada di listlinier.c (sebenarnya ilangin aja si B nya dari fungsi wkwk)
2. Sama dia tuh sekarang makenya list linier yang isinya integer,
	namun mekanisme kek di ChangeOwner seharusnya sama
	( cuman mindahinnya beda, yang lama mindahin bangunan, sekarang cuman mindahin index)
3. Buat haveBuilding, nanti aku bikinin fungsi mapping, di utility, kalo ga kliatan chat aku aja yaa...
*/
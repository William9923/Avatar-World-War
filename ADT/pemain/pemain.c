#include"./pemain.h"
#include"../bangunan/bangunan.h"
#include"../list/listlinier.h"
#include "../array/array.h"
#include<stdlib.h>

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
	(*P).AttackUp = false;
	(*P).CriticalHit = false;
	(*P).Shield = 0;
}

void ChangeOwner(Pemain *P,Bangunan b,Pemain *NewOwner, TabBangunan tab){
/* Untuk mengganti kepemilikan bangunan dari P ke NewOwner */
 	IdxTypeArray i = SearchIdxBangunan(tab,b);
    DelPList(&((*P).b),i);
    InsVLastList(&((*NewOwner).b),i);
}


boolean haveBuildingB(Pemain P,Bangunan a, TabBangunan tab){
	/** Mengecek apakah P mempunyai a sebagai bangunannya **/
 	IdxTypeArray i = SearchIdxBangunan(tab,a);
    return (SearchList(P.b,i) != NULL);
}

boolean haveBuildingKoordinat(Pemain P,int i,int j,TabBangunan Tab){
	/** Mengecek apakah P mempunyai bangunan yang terletak pada koordinat (i,j) **/
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
	/** Mengcopy P ke Destination **/
	CopyList(P.b,&((*Destination).b));
	(*Destination).Skill = P.Skill;
	(*Destination).nomor = P.nomor;
}	
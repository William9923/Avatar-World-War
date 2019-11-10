#include"pemain.h"
#include"bangunan.h"
#include"listbangunan.h"

boolean haveBuilding(Pemain P){
/* Apakah player P punya bangunan */
    return !IsEmptyListB(P.b);  
}

void CreateNewPlayer(Pemain *P,char Q){
/* Fungsinya untuk membuat player baru di game, dengan ketentuan:
Warna(*P) = R atau B,ListBangunan kosong */
    CreateEmptyListB(&((*P).b)); 
    SetWarna(P,Q);
}

void ChangeOwner(Pemain *P, Bangunan a,Pemain *NewOwner){
/* Untuk mengganti kepemilikan bangunan dari P ke NewOwner */
    DelPListB(&((*P).b),a);
    InsVLastListB(&((*NewOwner).b),a);
}


boolean haveBuildingB(Pemain P,Bangunan a){
    return SearchListB(P.b,a);
}
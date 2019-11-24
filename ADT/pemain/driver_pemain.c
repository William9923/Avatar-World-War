#include"pemain.c"
#include"pemain.h"
#include"../bangunan/bangunan.c"
#include"../list/listlinier.c"
#include"../point/point.c"
#include"../queue/skill.c"
#include"../array/array.c"
int main(){
    Pemain P1;
    Pemain P2;
    CreateNewPlayer(&P1,1);
    if(!haveBuilding(P1)){
        printf("Kalau masuk sini berarti kosong dan benar\n");
    }
    CopyPemain(P1,&P2);
    if(P1.nomor==P2.nomor){
        printf("\nudah bener\n");
    }
    
    
}
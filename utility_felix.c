#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"bangunan.h"
#include"point.h"
#include"state.h"
#include"array.h"
#include"matriks.h"
//#include "listbangunan.h"
#include "mesinkar.h"
#include "mesinkata.h"
//#include "skill.h"
#include"pemain.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"graph_.h"
#include<math.h>
#include"boolean.h"

void ProsedurLevelUp (TabBangunan *tab, Pemain p1) {
 	char * s;
 	int * levelArr;
 	IdxTypeArray a,b;
 	int c,j;
    int count_n;

 	printf("%s\n", "Daftar Bangunan :");
 	PrintInfoLBangunan((*tab), (p1));

    count_n = NbElmtList(p1.b);

 	printf("%s", "Bangunan yang akan di level up: ");
 	s = BacaInputUser();
    c = pengubahAngka();

    if (c <= count_n){
        address last=FirstL(p1.b);
        for (int i = 1; i < c; i++){
            last = NextL(last);
        }
        a = InfoL(last);

        if(IsAbleNaikLevel(ElmtArray(*tab,a))) {
            if (Type(ElmtArray(*tab,a)) == 'C') {
                ElmtArray(*tab,a) = NaikLevelCastle(ElmtArray(*tab,a));
                printf("Level Castle-mu meningkat menjadi %d!\n",Level(ElmtArray(*tab,a)));
            } else if (Type(ElmtArray(*tab,a)) == 'F') {
                ElmtArray(*tab,a) = NaikLevelFort(ElmtArray(*tab,a));
                printf("Level Fort-mu meningkat menjadi %d!\n",Level(ElmtArray(*tab,a)));
            } else if (Type(ElmtArray(*tab,a)) == 'V') {
                ElmtArray(*tab,a) = NaikLevelVillage(ElmtArray(*tab,a));
                printf("Level Village-mu meningkat menjadi %d!\n",Level(ElmtArray(*tab,a)));
            } else {
                ElmtArray(*tab,a) = NaikLevelTower(ElmtArray(*tab,a));
                printf("Level Tower-mu meningkat menjadi %d!\n",Level(ElmtArray(*tab,a)));
            }
        } else {
            if (Type(ElmtArray(*tab,a)) == 'C') {
                printf("Jumlah pasukan %s kurang untuk level up\n", "Castle");
            } else if (Type(ElmtArray(*tab,a)) == 'F') {
                printf("Jumlah pasukan %s kurang untuk level up\n", "Fort");
            } else if (Type(ElmtArray(*tab,a)) == 'V') {
                printf("Jumlah pasukan %s kurang untuk level up\n", "Village");
            } else {
                printf("Jumlah pasukan %s kurang untuk level up\n", "Tower");
            }
        }
    } else {
        do {
            printf("\n%s\n", "Bangunan tidak tersedia");
            printf("%s\n\n", "Silahkan ulangi masukan");
            printf("%s\n", "Daftar Bangunan :");
            PrintInfoLBangunan((*tab), (p1));
            printf("%s", "Bangunan yang akan di level up: ");
            s = BacaInputUser();
            c = pengubahAngka();       
        } while (c > count_n);
        address last=FirstL(p1.b);
        for (int i = 1; i < c; i++){
            last = NextL(last);
        }
        a = InfoL(last);

        if(IsAbleNaikLevel(ElmtArray(*tab,a))) {
            if (Type(ElmtArray(*tab,a)) == 'C') {
                ElmtArray(*tab,a) = NaikLevelCastle(ElmtArray(*tab,a));
                printf("Level Castle-mu meningkat menjadi %d!\n",Level(ElmtArray(*tab,a)));
            } else if (Type(ElmtArray(*tab,a)) == 'F') {
                ElmtArray(*tab,a) = NaikLevelFort(ElmtArray(*tab,a));
                printf("Level Fort-mu meningkat menjadi %d!\n",Level(ElmtArray(*tab,a)));
            } else if (Type(ElmtArray(*tab,a)) == 'V') {
                ElmtArray(*tab,a) = NaikLevelVillage(ElmtArray(*tab,a));
                printf("Level Village-mu meningkat menjadi %d!\n",Level(ElmtArray(*tab,a)));
            } else {
                ElmtArray(*tab,a) = NaikLevelTower(ElmtArray(*tab,a));
                printf("Level Tower-mu meningkat menjadi %d!\n",Level(ElmtArray(*tab,a)));
            }
        } else {
            if (Type(ElmtArray(*tab,a)) == 'C') {
                printf("Jumlah pasukan %s kurang untuk level up\n", "Castle");
            } else if (Type(ElmtArray(*tab,a)) == 'F') {
                printf("Jumlah pasukan %s kurang untuk level up\n", "Fort");
            } else if (Type(ElmtArray(*tab,a)) == 'V') {
                printf("Jumlah pasukan %s kurang untuk level up\n", "Village");
            } else {
                printf("Jumlah pasukan %s kurang untuk level up\n", "Tower");
            }
        }
    }
}
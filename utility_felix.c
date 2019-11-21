// #include<stdio.h>
// #include<stdlib.h>
// #include<math.h>
// #include"bangunan.h"
// #include"point.h"
// #include"state.h"
// #include"array.h"
// #include"matriks.h"
// //#include "listbangunan.h"
// #include "mesinkar.h"
// #include "mesinkata.h"
// //#include "skill.h"
// #include"pemain.h"
// #include<stdio.h>
// #include<stdlib.h>
// #include<string.h>
// #include"graph_.h"
// #include<math.h>
// #include"boolean.h"

void ProsedurLevelUp (TabBangunan *tab, Pemain P1,Pemain P3,Pemain P2,List Netral,StackUndo *SU) {
     char * s;
 	int * levelArr;
 	IdxTypeArray a,b;
 	int c,j;
    int count_n;

 	printf("%s\n", "Daftar Bangunan :");
 	PrintInfoLBangunan((*tab), (P1));

    count_n = NbElmtList(P1.b);

 	printf("%s", "Bangunan yang akan di level up: ");
 	s = BacaInputUser();
    c = pengubahAngka();

    if (c <= count_n){
        address last=FirstL(P1.b);
        for (int i = 1; i < c; i++){
            last = NextL(last);
        }
        a = InfoL(last);

        if(IsAbleNaikLevel(ElmtArray(*tab,a))) {
            SaveState(SU,P3,P2,Netral,*tab);
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
            PrintInfoLBangunan((*tab), (P1));
            printf("%s", "Bangunan yang akan di level up: ");
            s = BacaInputUser();
            c = pengubahAngka();       
        } while (c > count_n);
        address last=FirstL(P1.b);
        for (int i = 1; i < c; i++){
            last = NextL(last);
        }
        a = InfoL(last);

        if(IsAbleNaikLevel(ElmtArray(*tab,a))) {
            SaveState(SU,P3,P2,Netral,*tab);
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
			if (IsMaxLevel(ElmtArray(*tab,a))) {
				if (Type(ElmtArray(*tab,a)) == 'C') {
					printf("%s sudah berada pada level maksimum.\n", "Castle");
				} else if (Type(ElmtArray(*tab,a)) == 'F') {
					printf("%s sudah berada pada level maksimum.\n", "Fort");
				} else if (Type(ElmtArray(*tab,a)) == 'V') {
					printf("%s sudah berada pada level maksimum.\n", "Village");
				} else {
					printf("%s sudah berada pada level maksimum.\n", "Tower");
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
}

void endgame(Pemain P1, Pemain P2, boolean *selesai) {
    if (IsEmptyList(P1.b)) {
        printf("P2 menang.\n");
        *selesai = true;
    } else if (IsEmptyList(P2.b)) {
        printf("P1 menang.\n");
        *selesai = true;
    }
}
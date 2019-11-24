#include <stdio.h>
#include "readkonfigurasi.c"
#include "../../ADT/mesinkata/mesinkar.c"
#include "../../ADT/mesinkata/mesinkata.c"
#include "../../ADT/array/array.c"
#include "../../ADT/graph/graph_.c"
#include "../../ADT/pemain/pemain.c"
#include "../../ADT/list/listlinier.c"
#include "../../ADT/bangunan/bangunan.c"
#include "../../ADT/point/point.c"
#include "../../ADT/matriks/matriks.c"

int main() {
    PETA P;
    TabBangunan B;
    Graph G;
    infotypeGraph X;
    infotypeGraph Y;
    int i,j;
    Pemain P1;
    Pemain P2;
    List Netral;
    char *path;

    path = "../../file konfig.txt";
    readkonfig(path,&P,&B,&G,&P1,&P2,&Netral);

    CetakBangunanDimiliki(B);

    printf("Tampilan Peta\n");
    CetakPeta(P,P1,P2,B);


    /*

    
    for (i=1; i <= 17; i++) {
        for (j=1; j <= 17; j++) {
            X=i;
            Y=j;
            if (IsConnected(G, X,Y)){
                printf("bangunan %d dan bangunan %d %s\n", X, Y,"Connected");
            } else {
                printf("bangunan %d dan bangunan %d %s\n",X,Y, "Not connected");
            }
        }
    }
    printf("bangunan pemain 1: ");
    PrintInfoList(P1.b);
    printf("\n");

    printf("bangunan pemain 2: ");
    PrintInfoList(P2.b);
    printf("\n");

    printf("bangunan netral: ");
    PrintInfoList(Netral);
    printf("\n");
    */
}
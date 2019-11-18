#include <stdio.h>
#include "readkonfigurasi.c"
#include "mesinkar.c"
#include "mesinkata.c"
#include "array.c"
#include "graph_.c"
#include "pemain.c"
#include "listlinier.c"
#include "bangunan.c"
#include "point.c"

int main() {
    int L, P;
    TabBangunan B;
    Graph G;
    infotypeGraph X;
    infotypeGraph Y;
    int i,j;
    Pemain P1;
    Pemain P2;
    List Netral;

    readkonfig(&P,&L,&B,&G,&P1,&P2,&Netral);

    printf("Panjang Peta: %d\n", P);
    printf("Lebar Peta: %d\n", L);
    CetakBangunanDimiliki(B);

    
    for (i=1; i <= 17; i++) {
        for (j=1; j <= 17; j++) {
            X.noBangunan=i;
            Y.noBangunan=j;
            if (IsConnected(G, X,Y)){
                printf("bangunan %d dan bangunan %d %s\n", X.noBangunan, Y.noBangunan,"Connected");
            } else {
                printf("bangunan %d dan bangunan %d %s\n",X.noBangunan,Y.noBangunan, "Not connected");
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
}
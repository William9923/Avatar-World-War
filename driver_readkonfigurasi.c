#include <stdio.h>
#include "readkonfigurasi.c"

int main() {
    int L, P;
    TabBangunan B;
    Graph G;
    infotypeGraph X;
    infotypeGraph Y;
    int i,j;

    readkonfig(&P,&L,&B,&G);

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
}
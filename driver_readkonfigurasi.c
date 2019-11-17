#include <stdio.h>
#include "readkonfigurasi.c"

int main() {
    int L, P;
    TabBangunan B;
    Graph G;

    readkonfig(&P,&L,&B,&G);

    printf("Panjang Peta: %d\n", P);
    printf("Lebar Peta: %d\n", L);
    CetakBangunanDimiliki(B);
}
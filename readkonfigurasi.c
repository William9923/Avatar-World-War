#include "mesinkata.h"
#include <stdio.h>
#include "array.h"
#include "graph_.h"
#include "pemain.h"
#include "listlinier.h"

void readkonfig(int *PPeta, int *LPeta, TabBangunan *ArrayBangunan, Graph *G, Pemain *P1, Pemain *P2, List *Netral) {
    int i,n;
    infotypeGraph bmatriks,kmatriks;
    int NBangunan;
    char typebangunan;
    Point letakbangunan;
    int letakx, letaky;
    Bangunan bangunan;

    /** menyimpan panjang peta (vertikal) ke dalam variabel PPeta **/
    STARTKATA();
    *PPeta = (CKata.TabKata[1] - '0') * 10 + (CKata.TabKata[2] - '0');
    //printf("%d\n", *PPeta);

    /** menyimpan lebar peta (horizontal) ke dalam variabel LPeta **/
    ADVKATA();
    *LPeta = (CKata.TabKata[1] - '0') * 10 + (CKata.TabKata[2] - '0');
    //printf("LPeta : %d\n", *LPeta);

    /** menyimpan banyaknya bangunan ke dalam variabel NBangunan **/

    ADVKATA();
    NBangunan=0;
    for (i=1; i <= CKata.Length; i++) {
        NBangunan = NBangunan * 10 + (CKata.TabKata[i] - '0');
    }
    //printf("Nbangunan : %d\n", NBangunan);

    /** membuat array kosong dengan ukuran NBangunan **/
    
    CreateEmptyArray(ArrayBangunan, NBangunan);
    /** looping untuk mengisi array bangunan dengan informasi yang dibaca dari file konfigurasi **/
    for (n=1; n <= NBangunan; n ++) {
        letakx=0;
        letaky=0;
        ADVKATA();
        typebangunan = CKata.TabKata[1];

        ADVKATA();
        for (i=1; i <= CKata.Length; i++) {
            letakx = letakx * 10 + (CKata.TabKata[i] - '0');
        }
        
        ADVKATA();
        for (i=1; i <= CKata.Length; i++) {
            letaky = letaky * 10 + (CKata.TabKata[i] - '0');
        }

        letakbangunan = MakePoint(letakx,letaky);

        MakeBangunan(&bangunan, typebangunan, letakbangunan);
        AddBangunan(ArrayBangunan,bangunan);
    }
    
    InsertLastList(&(*P1).b,AlokasiList(1));
    InsertLastList(&(*P2).b,AlokasiList(2));
    for(n=3;n<=NBangunan;n++){
        InsertLastList(Netral,AlokasiList(n));
    }
    
    bmatriks.noBangunan=1;
    kmatriks.noBangunan=1;
    CreateGraph(bmatriks,G);
    for (n=1; n <= NBangunan * NBangunan; n++) {
        IgnoreBlank();
        if (CC == '1') {
            InsertEdge(G,bmatriks,kmatriks);
        }
        ADV();
        if (kmatriks.noBangunan < NBangunan) {
            kmatriks.noBangunan++;
        } else {
            kmatriks.noBangunan = 1;
            bmatriks.noBangunan++;
        }
        IgnoreBlank();
    }
}
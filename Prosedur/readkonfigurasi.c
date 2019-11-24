#include "../ADT/mesinkata/mesinkata.h"
#include <stdio.h>
#include "../ADT/array/array.h"
#include "../ADT/graph/graph_.h"
#include "../ADT/pemain/pemain.h"
#include "../ADT/list/listlinier.h"
#include "../ADT/matriks/matriks.h"

/**********************************************************************************
* Prosedur Read Konfigurasi                                                       *
* Author : Kelompok Alstrukdat                                                    *
* Merupakan suatu prosedur untuk membaca file konfigurasi yang diberikan          *
* untuk mengatur seluruh konfigurasi game di awal pemainan                        *
* Prosedur ini memanfaatkan ADT ADT yang telah dibentuk sebelumnya untuk kemudian *
* menaruh informasi dari file konfigurasi ke File baru                            *
**********************************************************************************/

void readkonfig(char s[],PETA *P, TabBangunan *ArrayBangunan, Graph *G, Pemain *P1, Pemain *P2, List *Netral) {
    /* Inisialisasi nilai - nilai awal untuk data - data file konfigurasi */
    int PPeta, LPeta;
    int i,n;
    infotypeGraph bmatriks,kmatriks;
    int NBangunan;
    char typebangunan;
    Point letakbangunan;
    int letakx, letaky;
    Bangunan bangunan;

    /** menyimpan panjang peta (vertikal) ke dalam variabel PPeta **/
    STARTKATA(s);
    PPeta = (CKata.TabKata[1] - '0') * 10 + (CKata.TabKata[2] - '0');
    //printf("%d\n", *PPeta);

    /** menyimpan lebar peta (horizontal) ke dalam variabel LPeta **/
    ADVKATA();
    LPeta = (CKata.TabKata[1] - '0') * 10 + (CKata.TabKata[2] - '0');
    //printf("LPeta : %d\n", *LPeta);
    /* membuat peta kosong seukuran PPeta x LPeta */
    MakePeta(PPeta,LPeta, P);

    /** menyimpan banyaknya bangunan ke dalam variabel NBangunan **/

    ADVKATA();
    NBangunan=0;
    for (i=1; i <= CKata.Length; i++) {
        NBangunan = NBangunan * 10 + (CKata.TabKata[i] - '0');
    }

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
    /* membuat peta jadi sesuai letak tiap bangunan */
    MakePetaJadi(P, *ArrayBangunan);
    
    /* membuat list kepemilikan bangunan tiap pemain dan bangunan netral */
    CreateEmptyList(&((*P1).b));
    CreateEmptyList(&((*P2).b));
    CreateEmptyList(Netral);

    InsertLastList(&(*P1).b,AlokasiList(1));
    InsertLastList(&(*P2).b,AlokasiList(2));
    for(n=3;n<=NBangunan;n++){
        InsertLastList(Netral,AlokasiList(n));
    }
    
    /* mengisi graf yang merepresentasikan keterhubungan antar bangunan */
    bmatriks=1;
    kmatriks=1;
    CreateGraph(bmatriks,G);
    for (n=1; n <= NBangunan * NBangunan; n++) {
        IgnoreBlank();
        if (CC == '1') {
            InsertEdge(G,bmatriks,kmatriks);
        }
        ADV();
        if (kmatriks   < NBangunan) {
            kmatriks  ++;
        } else {
            kmatriks   = 1;
            bmatriks  ++;
        }
        IgnoreBlank();
    }
}
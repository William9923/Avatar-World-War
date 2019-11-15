#include "mesinkata.h"
#include <stdio.h>
#include "array.h"
#include "graph.h"

void readkonfig(int *PPeta, int *LPeta, int  *NBangunan, TabBangunan *ArrayBangunan, Graph *Graph) {
    int i,n;
    int banyakb;

    STARTKATA();
    *PPeta = (CKata.TabKata[1] - '0') * 10 + (CKata.TabKata[2] - '0');
    printf("%d\n", *PPeta);

    ADVKATA();
    for (i=1; i <= CKata.Length; i++) {
        printf("%c", CKata.TabKata[i]);
    }
    printf("\n");

    ADVKATA();
    for (i=1; i <= CKata.Length; i++) {
        printf("%c", CKata.TabKata[i]);
    }
    printf("\n");

    //jadiin fungsi String 2digit to Int
    banyakb = (CKata.TabKata[1] - '0') * 10 + (CKata.TabKata[2] - '0');

    printf("banyak bangunan = %d\n", banyakb);

    for (n=1; n <= banyakb * 3; n ++) {
        ADVKATA();
        for (i=1; i <= CKata.Length; i++) {
            printf("%c", CKata.TabKata[i]);
        }
        printf(" ");
        if (n % 3 == 0) {
            printf("\n");
        }
    }

    for (n=1; n <= banyakb * banyakb; n++) {
        IgnoreBlank();
        printf("%c ", CC);
        if (n % banyakb == 0) {
            printf("\n");
        }
        ADV();
        IgnoreBlank();
    }
}

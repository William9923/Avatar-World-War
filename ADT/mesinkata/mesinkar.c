/* File: mesinkar.c */
/* Implementasi Mesin Karakter */

#include "./mesinkar.h"
#include <stdio.h>

char CC;
boolean EOP;

static FILE * pita;
static int retval;

void START(char s[]) {
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   I.S. : sembarang
   F.S. : CC adalah karakter pertama pada pita. Jika CC != MARK maka EOP akan padam (false).
          Jika CC = MARK maka EOP akan menyala (true) */

    /* Algoritma */
    pita = fopen(s,"r");
    ADV();
}

void STARTIn() {
  /* Mesin siap dioperasikan. Dalam hal ini, pita yang akan 
  dibaca merupakan pita karakter via command line */
  pita = stdin;
  ADV();
}
void ADV() {
/* Pita dimajukan satu karakter.
   I.S. : Karakter pada jendela =
          CC, CC != MARK
   F.S. : CC adalah karakter berikutnya dari CC yang lama,
          CC mungkin = MARK.
          Jika  CC = MARK maka EOP akan menyala (true) */

    /* Algoritma */

    retval = fscanf(pita,"%c",&CC);

    EOP = (CC == MARK);
    if (EOP) {
       fclose(pita);
    }
}

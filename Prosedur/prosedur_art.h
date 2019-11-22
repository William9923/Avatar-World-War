#ifndef ART_H
#define ART_H


#include "pemain.h"
#include<stdio.h>


void StartGame();
/* I.S. sembarang
/* F.S. tercetak tampilan sebelum game dimulai */

void PWinArt (Pemain Pnow,int turn);
/* I.S. Pnow dan turn terdefinisi, Pnow merupakan pemain yang menang game */
/* F.S. tercetak tampilan player yang menang beserta turn di layar */

#endif
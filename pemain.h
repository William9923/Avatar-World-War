/* ADT Pemain */
/*
Seluruh algoritma yang berkaitan dengan pemain akan dibuat disini.
States dari seorang pemain terdiri dari:
1.List Bangunan yang dimiliki
2.Warna dari player
*/

#ifndef PEMAIN_H
#define PEMAIN_H

#include"boolean.h"
#include"bangunan.h"
#include"listlinier.h"
#include "array.h"
#include"skill.h"

typedef struct{
    /*QueueSkill Skill*/
    Queue Skill;
   List b;
   int nomor;
} Pemain;


boolean haveBuilding(Pemain P);
/* Apakah player P punya bangunan */

void CreateNewPlayer(Pemain *P,int nomor);
/* Fungsinya untuk membuat player baru di game, dengan ketentuan:
Warna(*P) = R atau B,ListBangunan kosong */

void ChangeOwner(Pemain *P,Bangunan b,Pemain *NewOwner, TabBangunan tab);
/* Untuk mengganti kepemilikan bangunan dari P ke NewOwner */

boolean haveBuildingB(Pemain P,Bangunan a, TabBangunan tab);
/* Menghasilkan nilai T/F apakah P punya Bangunan a */


boolean haveBuildingKoordinat(Pemain P,int i,int j,TabBangunan Tab);

void CopyPemain(Pemain P,Pemain *Destination);
#endif



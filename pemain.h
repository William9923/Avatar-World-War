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

typedef struct{
    /*QueueSkill Skill*/
   List b;
   char color;/*bisa R bisa B yang artinya Red/Blue*/
   int nomor;
} Pemain;


boolean haveBuilding(Pemain P);
/* Apakah player P punya bangunan */

void CreateNewPlayer(Pemain *P,char Q,int nomor);
/* Fungsinya untuk membuat player baru di game, dengan ketentuan:
Warna(*P) = R atau B,ListBangunan kosong */

void ChangeOwner(Pemain *P,Bangunan b,Pemain *NewOwner, TabBangunan tab);
/* Untuk mengganti kepemilikan bangunan dari P ke NewOwner */

boolean haveBuildingB(Pemain P,Bangunan a, TabBangunan tab);
/* Menghasilkan nilai T/F apakah P punya Bangunan a */

#endif



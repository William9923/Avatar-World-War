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
#include"listbangunan.h"

typedef struct{
    /*QueueSkill Skill*/
   ListB b;
   char color;/*bisa R bisa B yang artinya Red/Blue*/
   int nomor;
} Pemain;


boolean haveBuilding(Pemain P);
/* Apakah player P punya bangunan */

void CreateNewPlayer(Pemain *P,char Q,int nomor);
/* Fungsinya untuk membuat player baru di game, dengan ketentuan:
Warna(*P) = R atau B,ListBangunan kosong */

void ChangeOwner(Pemain *P,Bangunan b,Pemain *NewOwner);
/* Untuk mengganti kepemilikan bangunan dari P ke NewOwner */

boolean haveBuildingB(Pemain P,Bangunan a);
/* Menghasilkan nilai T/F apakah P punya Bangunan a */

#endif



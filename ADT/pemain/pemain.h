/* ADT Pemain */
/*
Seluruh algoritma yang berkaitan dengan pemain akan dibuat disini.
States dari seorang pemain terdiri dari:
1.List Bangunan yang dimiliki
2.Warna dari player
*/

#ifndef PEMAIN_H
#define PEMAIN_H

#include"../boolean.h"
#include"../bangunan/bangunan.h"
#include"../list/listlinier.h"
#include "../array/array.h"
#include"../queue/skill.h"

/************************************************************************************************************************************
* Prosedur Skill                                                                                                                    *
* Author : Kelompok Alstrukdat                                                                                                      *
* Created at : 06 November 2019                                                                                                     *
* Merupakan File Implementasi Pemain pada Game ini                                                                                  *
* Digunakan untuk pemenuhan kebutuhan fungsi - fungsi dalam game yang                                                               *
* membutuhkan lebih dari 1 (satu) jenis ADT dan berhubungan dengan                                                                  *
* penggunaan pemain.                                                                                                                *
* Selain itu, di file ini juga banyak didefinisikan dan diimplementasikan fungsi yang berkaitan dengan manipulasi properti pemain.  *
************************************************************************************************************************************/

typedef struct{
    /*QueueSkill Skill*/
    Queue Skill;
   List b;
   int nomor;
   boolean AttackUp;
   boolean CriticalHit;
   int Shield;
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



#include"../ADT/bangunan/bangunan.h"
#include"../ADT/array/array.h"
#include"../ADT/pemain/pemain.h"
#include "../ADT/list/listlinier.h"
#include "../ADT/boolean.h"

#ifndef SKILL_P
#define SKILL_P

/***************************************************************************************************************************************************
* Prosedur Skill                                                                                                                                   *
* Author : Kelompok Alstrukdat                                                                                                                     *
* Created at : 14 November 2019                                                                                                                    *
* Merupakan File Header Skill pada Game ini                                                                                                        *
* Digunakan untuk pemenuhan kebutuhan fungsi - fungsi dalam game yang                                                                              *
* membutuhkan lebih dari 1 (satu) jenis ADT dan berhubungan dengan                                                                                 *
* penggunaan skill.                                                                                                                                *
*                                                                                                                                                  *
* SKILL yang terdapat pada FILE ini :                                                                                                              *
* 1. Instant Upgrade                                                                                                                               *
* 2. Extra Turn                                                                                                                                    *
* 3. Instant Reinforcement                                                                                                                         *
* 4. Barrage                                                                                                                                       *
*                                                                                                                                                  *
* Selain itu, di file ini juga banyak didefinisikan dan diimplementasikan fungsi - fungsi validator yang akan memvalidasi inputan user / pengguna  *
***************************************************************************************************************************************************/

void InstantUpgrade(TabBangunan * tab, Pemain p1);
void TambahPasukanB(Bangunan * bangunan, int n);
void KurangPasukan(Bangunan * bangunan, int n);
void InstantReinforcement(TabBangunan * tab, Pemain p1);
void Barrage(TabBangunan * tab, Pemain * p1, Pemain * p2);
void ExtraTurn (int * n);
void CriticalHit(Pemain *P);
// buat Instant Upgrade, dilakukan hardcoding saat inisiasi game
boolean IsObtainIR (TabBangunan tab, Pemain p1);
boolean IsObtainBarrage(Pemain p2);
boolean IsObtainExtraTurn(TabBangunan tab, IdxTypeArray i, Pemain p2);

boolean IsObtainCriticalHit(int jatah);
boolean IsObtainShield(Pemain P);
boolean IsObtainAttackUp(Bangunan B,Pemain *P1,TabBangunan Tab);

void CheckAddExtraTurn(Queue * q1,TabBangunan tab, IdxTypeArray i, Pemain P1, Pemain P2);
void CheckAddBarrage(Queue * q1,TabBangunan tab, Pemain p1, Pemain p2);
void CheckAddIR(Queue * q1, Queue * q2, TabBangunan tab, Pemain P1, Pemain P2);
void CheckAddCriticalHit(Pemain P,int jatah,Pemain *P1,Pemain *P2);
void CheckAddShield(Pemain *P2);
void CheckAddAttackUp(Bangunan B,Pemain *P1,TabBangunan Tab);

#endif
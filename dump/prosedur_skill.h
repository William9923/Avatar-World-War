#include"bangunan.h"
#include"array.h"
#include"pemain.h"
#include "listlinier.h"
#include "boolean.h"

#ifndef SKILL_P
#define SKILL_P

void InstantUpgrade(TabBangunan * tab, Pemain p1);
void TambahPasukanB(Bangunan * bangunan, int n);
void KurangPasukan(Bangunan * bangunan, int n);
void InstantReinforcement(TabBangunan * tab, Pemain p1);
void Barrage(TabBangunan * tab, Pemain * p1, Pemain * p2);
void ExtraTurn (int * n);
// buat Instant Upgrade, dilakukan hardcoding saat inisiasi game
boolean IsObtainIR (TabBangunan tab, Pemain p1);
boolean IsObtainBarrage(Pemain p2);
boolean IsObtainExtraTurn(TabBangunan tab, IdxTypeArray i, Pemain p2);

void CheckAddExtraTurn(Queue * q1,TabBangunan tab, IdxTypeArray i, Pemain P1, Pemain P2);
void CheckAddBarrage(Queue * q1,TabBangunan tab, Pemain p1, Pemain p2);
void CheckAddIR(Queue * q1, Queue * q2, TabBangunan tab, Pemain P1, Pemain P2);

#endif
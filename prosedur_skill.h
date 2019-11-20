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
void Barrage(TabBangunan * tab, Pemain p1, Pemain p2);
void ExtraTurn (int * n);
// buat Instant Upgrade, dilakukan hardcoding saat inisiasi game
boolean IsObtainIR (TabBangunan tab, Pemain p1);
boolean IsObtainBarrage(TabBangunan tab, Pemain p2);
boolean IsExtraTurn(TabBangunan tab, IdxTypeArray i, Pemain p2)

#endif
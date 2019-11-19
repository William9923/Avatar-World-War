#include"stackundo.h"

boolean IsEmptyStack(StackUndo S){
    return Top(S)==0;
}
void CreateEmptyStackUndo(StackUndo *S){
    Top(*S) = 0;
}


void Push(StackUndo *S,states s){
    Top(*S)++;
    InfoTop(*S)=s;
}


void SaveState(StackUndo *S,Pemain P1,Pemain P2,List Netral,TabBangunan Bangunan){
    states q;
    StateP1(q) = P1;
    StateP2(q) = P2;
    StateNetral(q) = Netral;
    StateBangunan(q) = Bangunan;
    Push(S,q);
}


void Pop(StackUndo *S,states *q){
    *q = InfoTop(*S);
    Top(*S)--;
}

void LoadState(StackUndo *S,Pemain *P1,Pemain *P2,List *Netral,TabBangunan *Bangunan){
    states q;
    Pop(S,&q);
    *P1 = StateP1(q);
    *P2 = StateP2(q);
    *Netral = StateNetral(q);
    *Bangunan = StateBangunan(q);
}







#include"./stackundo.h"
#include"../list/listlinier.h"

boolean IsEmptyStack(StackUndo S){
    return Top(S)==0;
}
void CreateEmptyStackUndo(StackUndo *S){
    Top(*S) = 0;
}


void PushStack(StackUndo *S,states s){
    Top(*S)++;
    InfoTop(*S)=s;
}


void SaveState(StackUndo *S,Pemain P1,Pemain P2,List Netral,TabBangunan Bangunan){
    states q;
    CreateEmptyArray(&(StateBangunan(q)),NbElmt(Bangunan));
    CreateEmptyList(&(StateNetral(q)));
    CopyPemain(P1,&StateP1(q));
    CopyPemain(P2,&StateP2(q));
    CopyList(Netral,&(StateNetral(q)));
    CopyArray(Bangunan,&StateBangunan(q));
    PushStack(S,q);

}


void PopStack(StackUndo *S,states *q){
    *q = InfoTop(*S);
    Top(*S)--;
}

void LoadState(StackUndo *S,Pemain *P1,Pemain *P2,List *Netral,TabBangunan *Bangunan){
    states q;
    PopStack(S,&q);
    CopyPemain(StateP1(q),P1);
    CopyPemain(StateP2(q),P2);
    CopyList(StateNetral(q),Netral);
    CopyArray(StateBangunan(q),Bangunan);
}







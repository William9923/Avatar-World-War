#include"stackundo.h"

boolean IsEmptyStack(StackUndo S){
    return Top(S)==0;
}
void CreateEmptyStackUndo(StackUndo *S){
    Top(*S) = 0;
}


void Push(StackUndo *S,states s){
    if(IsEmptyStack(*S)){
        Top(*S)++;
        InfoTop(*S)=s;
    }
    else{
        Top(*S)++;
        InfoTop(*S)=s;
    }
}


void SaveState(StackUndo *S,Pemain P1,Pemain P2){
    states q;
    StateP1(q) = P1;
    StateP2(q) = P2;
    Push(S,q);
}

void Pop(StackUndo *S,states *q){
    *q = InfoTop(*S);
    Top(*S)--;
}

void Undo(states q,Pemain *P1,Pemain *P2){
    *P1 = StateP1(q);
    *P2 = StateP2(q);
}







#include"pemain.h"


#define Top(S) (S).TOP
#define InfoTop(S) (S).T[(S).TOP]
#define StateP1(Q) (Q).X
#define StateP2(Q) (Q).Y 

typedef struct {
    states T[101];
    int TOP;
} StackUndo;

typedef struct{
    Pemain X,Y;/*Pemain 1 dan Pemain 2*/
} states;

boolean IsEmptyStack(StackUndo S){
    return Top(S)==0;
}
void CreateEmpty(StackUndo *S){
    Top(*S) = 0;
}

void SaveState(StackUndo *S,Pemain P1,Pemain P2){
    states q;
    StateP1(q) = P1;
    StateP2(q) = P2;
    Push(S,q);
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

void Pop(StackUndo *S,states *q){
    *q = InfoTop(*S);
    Top(*S)--;
}

void Undo(states q,Pemain *P1,Pemain *P2){
    *P1 = StateP1(q);
    *P2 = StateP2(q);
}







#include"pemain.h"

#define Top(S) (S).TOP
#define InfoTop(S) (S).T[(S).TOP]
#define StateP1(Q) (Q).X
#define StateP2(Q) (Q).Y 

typedef struct{
    Pemain X,Y;/*Pemain 1 dan Pemain 2*/
} states;

typedef struct {
    states T[101];
    int TOP;
} StackUndo;

boolean IsEmptyStack(StackUndo S);
void CreateEmptyStackUndo(StackUndo *S);
void SaveState(StackUndo *S,Pemain P1,Pemain P2);
void Push(StackUndo *S,states s);
void Pop(StackUndo *S,states *q);
void Undo(states q,Pemain *P1,Pemain *P2);







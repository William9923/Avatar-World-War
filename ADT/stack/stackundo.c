#include"./stackundo.h"
#include"../list/listlinier.h"

boolean IsEmptyStack(StackUndo S){
    /** Mengecek apakah StackUndo kosong **/
    return Top(S)==0;
}
void CreateEmptyStackUndo(StackUndo *S){
    /** Membuat StackUndo kosong sesuai definisi yaitu Top = 0 **/
    Top(*S) = 0;
}


void PushStack(StackUndo *S,states s){
    /** Menyimpan states sebagai elemen dari StackUndo yaitu pada Top(*S) **/
    Top(*S)++;
    InfoTop(*S)=s;
}


void SaveState(StackUndo *S,Pemain P1,Pemain P2,List Netral,TabBangunan Bangunan){
    /** Menyimpan kondisi permainan sekarang ke dalam StackUndo **/
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
    /** Menghapus elemen teratas pada StackUndo kemudian menampung nilainya pada q **/
    *q = InfoTop(*S);
    Top(*S)--;
}

void LoadState(StackUndo *S,Pemain *P1,Pemain *P2,List *Netral,TabBangunan *Bangunan){
    /** Menghapus elemen teratas pada StackUndo kemudian mengassign semua nilainya kepada nilai di main sekarang **/
    states q;
    PopStack(S,&q);
    CopyPemain(StateP1(q),P1);
    CopyPemain(StateP2(q),P2);
    CopyList(StateNetral(q),Netral);
    CopyArray(StateBangunan(q),Bangunan);
}







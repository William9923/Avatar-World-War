#include"../array/array.c"
#include"../pemain/pemain.c"
#include"../bangunan/bangunan.c"
#include"../queue/skill.c"
#include"../point/point.c"
#include"../list/listlinier.h"
#include"../list/listlinier.c"
#include"./stackundo.c"

int main(){
    StackUndo S;
    CreateEmptyStackUndo(&S);
    if(IsEmptyStack(S)){
        printf("kosong dan bener\n");
    }
    
    return 0;
}
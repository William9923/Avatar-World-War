#include"bangunan.h"
#include<stddef.h>

typedef struct ElmtListBangunan *elb;
typedef struct tElmtListBangunan{
    Bangunan bangun;
    elb next;
} ElmtListBangunan;
typedef struct {
    elb First;
} ListBangunan;

void CreateEmptyListB(ListBangunan *b){
    (*b).First=NULL;
}

boolean IsEmptyListB(ListBangunan b){
    return b.First==NULL;
}


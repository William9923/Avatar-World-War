void CreateEmptyListB(ListBangunan *b){
    (*b).First=NULL;
}

boolean IsEmptyListB(ListBangunan b){
    return b.First==NULL;
}
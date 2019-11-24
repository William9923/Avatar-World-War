#include "../include.h"


int main () 
{
	Pemain P ;
	P.nomor = 2;
	int turn = 51;
	
    StartGame();
    PWinArt (P,turn);
    CommandList();
    return 0;
}

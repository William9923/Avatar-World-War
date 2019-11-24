
#include"../ADT/pemain/pemain.h"
#include<stdio.h>
#include "../Prosedur/prosedur_art.h"

void StartGame ()
/* I.S. sembarang
/* F.S. tercetak tampilan sebelum game dimulai */
{

char anykey;
 
printf("\n");
printf("    |>>>                                                      |>>> \n");
printf("    |                                                         |    \n");
printf("    *               WELCOME TO AVATAR: WORLD WAR              *    \n");
printf("  [ I ]                                                     [ I ]  \n");
printf("  [ F ]                   |>>>          |>>>                [ F ]  \n");
printf("  [   ]_ _ _              |             |              _ _ _[   ]  \n");
printf("  [   ]------|       {#########}   {#########}       |----- [   ]  \n");
printf("  [ I ]====/          |=======|     |=======|         /==== [ I ]  \n");
printf("  [ F ]    |           |     |_ _ _ _|     |           |    [ F ]  \n");
printf("  [___]    |_ _ _ _ _ _|     | X X X |     |_ _ _ _ _ _|    [___]  \n");
printf("   |   T   |A V A T A R|     |=======|     |  G A M E  |   U   |  \n");
printf("   |   A   |===========|     | + ^ + |     |===========|   D   |   \n");
printf("   |   N   |           |  A  |_______|  A  |           |   A   |    \n");
printf("   |   A   |           |  I  |||||||||  P  |           |   R   |    \n");
printf("   |   H   |           |  R  ||vvvvv||  I  |           |   A   |    \n");
printf("_-_|_______|-----------|_____||     ||_____|-----------|_______|_-_\n");
printf("  |_________|         |______||     ||______|         |_________|    \n");
printf(" |___________|-------|_______||_____||_______|-------|___________|   \n");
printf("\n");
printf("     *                 PRESS ANY KEY TO START                *    "); 
/* inspired from https://www.asciiart.eu/buildings-and-places/castles */
scanf("%c", &anykey);

}

void PWinArt (Pemain Pnow, int turn)
/* I.S. Pnow dan turn terdefinisi, Pnow merupakan pemain yang menang game */
/* F.S. tercetak tampilan player yang menang beserta turn di layar */
{
  
        printf("\n");
        printf("========Permainan telah selesai di turn %d!========\n",turn);
        printf("       ____________________________________ \n");
        printf("       |                                   | \n");
        printf("       |        **** P%d WIN !!! ****       | \n",Pnow.nomor);
        printf("       |___________________________________| \n");
        printf("\n");
}

void CommandList()
{
        char anykey;

        printf("AVAILABLE COMMAND: \n");
        printf("1. ATTACK\n");
        printf("2. MOVE\n");
        printf("3. SKILL\n");
        printf("4. LEVEL_UP\n");
        printf("5. UNDO\n");
        printf("6. END_TURN\n");
        printf("7. SAVE\n");
        printf("8. QUIT\n");
        printf("Press Any Key To Continue...");

        scanf("%c", &anykey);

}
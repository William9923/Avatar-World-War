#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>


void StartGame();
void P1WinArt (int turn);
void P2WinArt (int turn);

int main () 
{
    StartGame();
    P1WinArt (51);
    P2WinArt (51);
    return 0;
}
void StartGame ()
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
printf("     *                 PRESS ANY KEY TO START                *    \n"); 
/* inspired from https://www.asciiart.eu/buildings-and-places/castles */
scanf("%c", &anykey);

}

void P1WinArt (int turn)
{
  
        printf("\n");
        printf("========Permainan telah selesai di turn %d!========\n",turn);
        printf("       ____________________________________ \n");
        printf("       |                                   | \n");
        printf("       |        **** P1 WIN !!! ****       | \n");
        printf("       |___________________________________| \n");
        printf("\n");
}

void P2WinArt (int turn)
{
       printf("\n");
        printf("========Permainan telah selesai di turn %d!========\n",turn);
        printf("       ____________________________________ \n");
        printf("       |                                   | \n");
        printf("       |        **** P2 WIN !!! ****       | \n");
        printf("       |___________________________________| \n");
        printf("\n");
}
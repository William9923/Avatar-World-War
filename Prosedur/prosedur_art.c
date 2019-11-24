
#include"../ADT/pemain/pemain.h"
#include"../ADT/pcolor/pcolor.h"
#include<stdio.h>
#include "../Prosedur/prosedur_art.h"

void StartGame ()
/* I.S. sembarang
/* F.S. tercetak tampilan sebelum game dimulai */
{

char anykey;
green();
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
normal();
}

void PWinArt (Pemain Pnow, int turn)
/* I.S. Pnow dan turn terdefinisi, Pnow merupakan pemain yang menang game */
/* F.S. tercetak tampilan player yang menang beserta turn di layar */
{
		if (Pnow.nomor == 1){
			red();
		} else {
			blue();
		}
  
        printf("\n");
        printf("════════Permainan telah selesai di turn %d!════════\n",turn);
        printf("       ╔═══════════════════════════════════╗\n");
        printf("       ║                                   ║ \n");
        printf("       ║        **** P%d WIN !!! ****       ║ \n",Pnow.nomor);
        printf("       ╚═══════════════════════════════════╝ \n");
        printf("\n");
        normal();
}

void CommandList()
{
        char anykey;
        green();
        printf("╔═══════════════════════════════════════════════════════╗\n");
        printf("║AVAILABLE COMMAND:                                     ║\n");
        printf("║1. ATTACK    : menyerang bangunan lain                 ║\n");
        printf("║2. MOVE      : memindahkan prajurit ke bangunan lain   ║\n");
        printf("║3. SKILL     : menggunakan skill yang masih tersedia   ║\n");
        printf("║4. LEVEL_UP  : meningkatkan level bangunan             ║\n");
        printf("║5. UNDO      : kembali ke langkah sebelumnya           ║\n");
        printf("║6. END_TURN  : mengakhiri turn                         ║\n");
        printf("║7. SAVE      : save progress game saat ini             ║\n");
        printf("║8. EXIT      : keluar dari game                        ║\n");
        printf("╚═══════════════════════════════════════════════════════╝\n");
        normal();

}
#include "../../include.h"

int main() {
    Pemain P1,P2,Pnow;
	StackUndo SU;
    PETA P;
    TabBangunan AllBangunan;
    Graph connectivity;
	List Netral;
	int jatah=1;
    char *save;
    char *load;
    char *path_filekonfig;

    path_filekonfig = "../../file konfig.txt";
	//Baca Konfigurasi Permainan
	printf("Reading Configuration File...\n");
    CreateEmptyList(&Netral);
    readkonfig(path_filekonfig,&P,&AllBangunan,&connectivity,&P1,&P2,&Netral);
    P1.nomor = 1;
	P2.nomor = 2;
	StartSkill(&((P1).Skill));StartSkill(&((P2).Skill));
	Pnow = P1;

    ProsedurSave(P1,P2,Pnow,P,AllBangunan,connectivity,Netral,jatah);
    /*
    printf("ENTER path save: ");
    save = BacaInputUser();
    printf("\n");

    savefile(save,P1,P2,Pnow,P,AllBangunan,connectivity,Netral,jatah);
    */
    printf("ENTER path load: ");
    load = BacaInputUser();
    printf("\n");
    printf("%s\n", load);

    loadfile(load,&P1, &P2, &Pnow,&P, &AllBangunan, &connectivity, &Netral, &jatah);
    CetakBangunanDimiliki(AllBangunan);
    PrintInfoList(P1.b);
    printf("\n");
    PrintInfoList(P2.b);
    printf("\n");
    PrintInfoList(Netral);
    printf("\n");

    CetakPeta(P, P1, P2, AllBangunan);

    printf("P1\nattack up=%d\ncriticalhit = %d\nshield = %d\n", P1.AttackUp,P1.CriticalHit,P1.Shield);
    printf("P2\nattack up=%d\ncriticalhit = %d\nshield = %d\n", P2.AttackUp,P2.CriticalHit,P2.Shield);

    printf("skill P1 = ");
    ShowSkill(P1.Skill);
    printf("\n");
    printf("skill P2 = ");
    ShowSkill(P2.Skill);
    printf("\n");

    printf("Pnow = %d\n", Pnow.nomor);
    printf("jatah = %d\n", jatah);
    
}
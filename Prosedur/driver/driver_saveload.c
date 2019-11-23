#include "../saveload.c"


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
	//Baca Konfigurasi Permainan
	printf("Reading Configuration File...\n");
    CreateEmptyList(&Netral);
    readkonfig(&P,&AllBangunan,&connectivity,&P1,&P2,&Netral);
    P1.nomor = 1;
	P2.nomor = 2;
	StartSkill(&((P1).Skill));StartSkill(&((P2).Skill));
	Pnow = P1;

    
    printf("ENTER path save: ");
    save = BacaInputUser();
    printf("\n");
    printf("%s\n", save);

    savefile(save,P1,P2,Pnow,P,AllBangunan,connectivity,Netral,jatah);
    
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

    printf("skill P1 = ");
    ShowSkill(P1.Skill);
    printf("\n");
    printf("skill P2 = ");
    ShowSkill(P2.Skill);
    printf("\n");

    printf("Pnow = %d\n", Pnow.nomor);
    printf("jatah = %d\n", jatah);
}
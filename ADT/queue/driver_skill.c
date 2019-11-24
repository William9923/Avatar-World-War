#include "skill.c"

int main() {
    Queue Q;
    infotype del;

    CreateEmptyQueue(&Q);

    printf("IsEmpty Q : %d\n",IsEmptyQueue(Q));
    printf("isfull Q : %d\n",IsFullQueue(Q));
    printf("nbelmt Q : %d\n",NBElmtQueue(Q));

    AddSkillQueue(&Q, 'A');
    printf("Head = %c\n", InfoHead(Q));
    AddSkillQueue(&Q, 'B');
    printf("Head = %c\n", InfoHead(Q));
    DelSkillQueue(&Q, &del);
    printf("Head = %c\n", InfoHead(Q));
    printf("del = %c\n", del);

    DeAlokasiQueue(&Q);
    printf("setelah dealokasi dan alokasi lagi trus start skill\n");

    CreateEmptyQueue(&Q);
    StartSkill(&Q);
    printf("Head = %c\n", InfoHead(Q));
    printf("Kode A = ");
    KodeToSkill(InfoHead(Q));
    printf("\n");
    printf("peek = %c\n", Peek(Q));
    printf("Skill yang ada di Queue Sekarang = ");
    ShowSkill(Q);
    printf("\n");
}
#include <stdio.h>
#include "boolean.h"
#include "skill.h"

boolean IsEmptyQueue (Queue Q){
    return ((Head(Q)==0) && (Tail(Q)==0));
}
/* Mengirim true jika Q kosong: lihat definisi di atas */
boolean IsFullQueue (Queue Q){
    return ((Head(Q)==1) && (Tail(Q)==MaxEl(Q)));
}
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */
int NBElmtQueue (Queue Q){
    if (!IsEmpty(Q)){
        return (((Tail(Q) - Head(Q) + MaxEl(Q))% MaxEl(Q)) +1);
    }
    else{
        return 0;
    }
}
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */

/* *** Kreator *** */
void CreateEmptyQueue (Queue * Q, int Max){
    (*Q).T = (infotype *) malloc ((Max+1) * sizeof(infotype));
    if ((*Q).T != NULL) {
        MaxEl(*Q) = Max;
        Head(*Q) = 0;
        Tail(*Q) = 0;
    } 
    else /* alokasi gagal */ {
        MaxEl(*Q) = 0;
    }
}
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max+1 */
/* atau : jika alokasi gagal, Q kosong dg MaxEl=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */

/* *** Destruktor *** */
void DeAlokasiQueue(Queue * Q){
    MaxEl(*Q) = 0;
    free((*Q).T); 
}
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */

/* *** Primitif Add/Delete *** */
void AddSkillQueue(Queue * Q, infotype X){
    address i,j;
    boolean valid;
    valid = false;

    while (!valid){
        if (X == "Instant Upgrade" || X != "Shield" || X != "Extra Turn" || X != "Attack Up" || X != "Critical Hit" || X != "Instant Reinforcement" || X != "Barrage") {
            printf("Maaf, skill yang ingin ditambahkan tidak boleh dimasukkan.");
            scanf(" %c",&X);
        }
        else /* Q tidak kosong */ {
            if (Tail(*Q) == MaxEl(*Q)) { /* Geser elemen smp Head(Q)=1 */
                Tail(*Q) = 1;
                InfoTail(*Q) = X;
                valid = true;
            }
            else{
                Tail(*Q)++;
                InfoTail(*Q)=X;
                valid = true;
            }
        }
    }
}
/* Proses: Menambahkan X pada Q dengan aturan FIFO */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X menjadi TAIL yang baru, TAIL "maju" dengan mekanisme circular buffer */
void DelSkillQueue(Queue * Q, infotype * X){
    if (Head(*Q)==Tail(*Q)) { /* Set mjd queue kosong */
        *X = InfoHead(*Q);
        InfoHead(*Q)=0;
        Head(*Q)=0;
        Tail(*Q)=0;
    } 
    else if (Head(*Q) == MaxEl(*Q)){
            *X = InfoHead(*Q);
            InfoHead(*Q)=0;
            Head(*Q)=1;
    }
    else{
            *X = InfoHead(*Q);
            InfoHead(*Q)=0;
            Head(*Q)++;
    }   
}
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = 0ai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer; 
        Q mungkin kosong */
void startSkillQueue(Queue *Q){
    CreateEmpty(&Q,10);
    InfoHead(*Q) = "Instant Upgrade"; 
}



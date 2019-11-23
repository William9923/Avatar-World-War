#include "../boolean.h"
#include "./skill.h"
#include <stdio.h>
#include <stdlib.h>
#include"../../Prosedur/prosedur_skill.h"

/* ********* Prototype ********* */
boolean IsEmptyQueue (Queue Q)
/* Mengirim true jika Q kosong: lihat definisi di atas */
{
    return ((Head(Q)==Zero) && (Tail(Q)==Zero));
}

boolean IsFullQueue (Queue Q)
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxElQueue */
{
	return (NBElmtQueue(Q) == MaxElQueue(Q));
}

int NBElmtQueue (Queue Q)
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */
{
    if (IsEmptyQueue(Q)) {
        return Zero;
    } else {
        if (Tail(Q) >= Head(Q)) {
            return (Tail(Q) - Head(Q) + 1);
        } else {
            if (Head(Q) - Tail(Q) == 1) {
                return MaxElQueue(Q);
            } else {
                if (Head(Q) == MaxElQueue(Q)) {
                    return (Tail(Q) + 1);
                } else {
                    return (MaxElQueue(Q) - (Head(Q)-Tail(Q)) + 1);
                }
            }
        }
    }
}

/* *** Kreator *** */
void CreateEmptyQueue (Queue * Q)
{
    (*Q).T = (infotype *) malloc ((MaxQueue+1) * sizeof(infotype *));
    if ((*Q).T != NULL) {
        MaxElQueue(*Q) = MaxQueue;
        Head(*Q) = Zero;
        Tail(*Q) = Zero;
    } 
    else /* alokasi gagal */ {
        MaxElQueue(*Q) = 0;
    }
}

/* *** Destruktor *** */
void DeAlokasiQueue(Queue * Q)
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxElQueue(Q) diset 0 */
{
    MaxElQueue(*Q) = 0;
    free((*Q).T); 
}

void AddSkillQueue (Queue * Q, char X)
/* Proses: Menambahkan Y pada Q dengan aturan FIFO */
/* I.S. Q tidak kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. Y menjadi TAIL yang baru, TAIL "maju" dengan mekanisme circular buffer */
/* Skill yang tidak bisa ditambah adalah Instant Upgrade */
{
	if (!IsFullQueue(*Q))
	{
		if (IsEmptyQueue(*Q))
		{
			Head(*Q) = 1;
			Tail(*Q) = 1;
			InfoTail(*Q) = X;
		}
		else 
		{
			if (Tail(*Q) == MaxElQueue(*Q))
			{
				Tail(*Q) = 1;
				InfoTail(*Q) = X;
			}
			else 
			{
				Tail(*Q) += 1;
				InfoTail(*Q) = X;
			}
		}
	}  
}

void DelSkillQueue (Queue * Q, infotype * X)
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer; 
        Q mungkin kosong */
{
	if (!IsEmptyQueue(*Q))
	{
		*X = InfoHead(*Q);
		if ( NBElmtQueue(*Q) == 1) 
		{
			Head(*Q) = Zero;
			Tail(*Q) = Zero;
		}
		else 
		{
			if (Head(*Q) == MaxElQueue(*Q))
			{
				Head(*Q) = 1;	
			}
			else 
			{
				Head(*Q) += 1;
			}
		}
	}
}

void StartSkill(Queue *Q)
/* Proses : Memasukkan skill pertama IU ke dalam Queue yang sudah disiapkan*/
/* I.S. Q kosong*/
/* F.S Info(First(*Q)) = "Instant_Upgrade" dan NBElmtQueue = 1*/
{
    CreateEmptyQueue(Q);
    AddSkillQueue(Q,'A');

}

void KodeToSkill (char S)
/* I.S. Q terisi */
/* F.S Tercetak nama akronim skill dari kode yang diinput  */

{
    if (S == 'A') 
    {
        printf("IU");
    }
    else if (S == 'B')
    {
        printf("S");
    }
    else if (S == 'C')
    {
        printf("E");
    }
    else if (S == 'D')
    {
        printf("A");
    }
    else if (S == 'E')
    {
        printf("CH");
    }
    else if (S == 'F')
    {
        printf("IR");
    }
    else if (S == 'G')
    {
        printf("B");
    }

}

char Peek (Queue Q)
/* Mengecek nilai head dari Queue skill */
{
    if (!IsEmptyQueue(Q))
    {
        return InfoHead(Q);
    } else {
        // kosong
        return 'X';
    }
}

void ShowSkill(Queue Q)
/* Proses : Menampilkan akronim skill yang ada di head queue pada layar */
/* I.S. Q terisi, boleh kosong*/
/* F.S Menampilkan akronim skill ke layar, jika queue kosong menampilkan - */
{
    char place = Peek(Q);
    if (!IsEmptyQueue(Q)){
        KodeToSkill(place);
    }else {
        printf("-");
    }
}
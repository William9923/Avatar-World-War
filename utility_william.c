#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"bangunan.h"
#include"point.h"
#include"stack.h"
#include"state.h"
#include"array.h"
#include"matriks.h"
#include "listbangunan.h"
#include "mesinkar.h"
#include "mesinkata.h"
#include "readkonfigurasi.h"
//#include "skill.h"
#include"pemain.h"

#include"bangunan.c"
#include"point.c"
#include"stack.c"
#include"state.c"
#include"array.c"
#include"matriks.c"
#include "listbangunan.c"
//#include "listlinier.c"
#include "mesinkar.c"
#include "mesinkata.c"
#include "readkonfigurasi.c"
//#include "skill.c"
#include"pemain.c"
boolean IsAbleMove(Bangunan bangunanAwal, Bangunan bangunanTujuan, int n, Pemain P){
	/* Mengecek apakah pasukan suatu bangunan dapat dipindahkan ke bangunan tujuan*/
	/*
		Validasi didasari oleh :
			1. Apakah bangunan 1 terhubung dengan bangunan 2
	*/

	// cek keterhubungan
	// cek apakah kedua bangunan berasal dari pemilik yang sama
	// cek apakah jumlah pasukan yang dimasukkan valid

	// tambahin cek keterhubungan 2 bangunan
	if (!(haveBuildingB(P,bangunanAwal)) || !(haveBuildingB(P,bangunanTujuan))){
		return false;
	} 
	if (Pasukan(bangunanAwal) < n){
		return false;
	}
	return true;
}

void Move(Bangunan * bangunanAwal, Bangunan * bangunanTujuan, int n, Pemain P){
	/*
	I.S. Bangunan Awal dan Bangunan Tujuan terdefinisi
		 Jumlah pasukan <= pasukan total di bangunanAwal
	F.S. Pasukan sebanyak n dipindahkan ke bangunanTujuan dari bangunan Awal
	Pemain d
	*/
	if (IsAbleMove((*bangunanAwal),(*bangunanTujuan), n, P)){
		Pasukan(*bangunanAwal) -= n;
		Pasukan(*bangunanTujuan) += n;
	}

}

boolean IsAbleSerang(Bangunan bangunanPe, Bangunan bangunanDe, int n){
	/*
		Mengecek apakah suatu bangunan dapat menyerang bangunan bertahan
		1. Cek apakah tersambung
		2. Cek apakah dia uda pernah nyerang
		3. Cek apakah jumlah penyerang tidak lebih dari jumlah total pasukan di bangunan tersebut

	*/

	// cek keterhubungan
	if (IsSudahSerang(bangunanPe)){
		// cek kondisi apakah sudah pernah menyerang atau belum
		return false;
	} 
	if (Pasukan(bangunanPe) < n){
		// cek apakah jumlah pasukan yang diinput valid atau tidak
		return false;
	}
	return true;
}


void SerangB(Bangunan * bangunanPe, Bangunan * bangunanDe, int n, Pemain * P1, Pemain * P2){
	/*
	I.S. 2 Bangunan Terdefinisi
	F.S. bangunan 1 menyerang bangunan 2
	*/
	int x;
	if (IsAbleSerang((*bangunanPe), ((*bangunanDe)), n)){
		if (IsPindahPemilik((*bangunanDe),n)){
			if (Pertahanan(*bangunanDe)){
				x = ceil((4/3) * Pasukan(*bangunanDe));
				Pasukan(*bangunanDe) = n - x;
			} else {
				// tidak ada pertahanan
				Pasukan(*bangunanDe) = n - Pasukan(*bangunanDe);
			}
			Pasukan(*bangunanPe) -= n;
			ChangeOwner((P1), (*bangunanDe) , P2);

		} else {
			if (Pertahanan(*bangunanDe)){
				x = floor((3/4) * n);
				Pasukan(*bangunanDe) -= x;
			} else {
				Pasukan(*bangunanDe) = Pasukan(*bangunanDe) - n;
			}
			Pasukan(*bangunanPe) -= n;
		}
	}
}

void NextTurnPemain(Pemain * P){
	/*
	I.S. Pemain terdefinisi,
		 Seluruh bangunan yang dimiliki pemain dalam keadaan turn sebelumnya
	F.S. Seluruh bangunan milik pemain memiliki kondisi yang terubah sesuai dengan 
		 ketentuan bangunan
	btw, buat perubahan yang terjadi taro disini aja
	*/
	ListB listB;

	listB = (*P).b;

	NextTurnLBangunan(&listB);

	// ketentuan perubahan status pada turn berikutnya
}

void NextTurnLBangunan(ListB * L){
	/*
	Melakukan traversal ke seluruh bangunan pada list bangunan
	dan melakukan penambahan 
	*/
	elb bangunan;
	if (!IsEmpty(*L)){
		bangunan = FirstB(*L);
		while (bangunan != Nil){
			NextTurnBangunan(&bangunan);
			bangunan = NextB(bangunan);
		}
	}
}

/*
	Checker netral, 
	simple, kalo ga ada di list 2 pemain, bangunan netral
*/
boolean IsBangunanNetral(Bangunan b, Pemain p1, Pemain p2){
	/* Melakukan pengecekan apakah suatu bangunan bersifat netral atau tidak */
	
}





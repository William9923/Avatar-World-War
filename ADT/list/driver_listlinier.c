#include "listlinier.h"
#include "listlinier.c"

/*********************************************
* ListLinier                                 *
* Author : William                           *
* Created at : 01 November 2019              *
* Merupakan file driver dari ADT List Linier *
*********************************************/

int main() {
	List list1;
	int x1,x2;
	/*Pembuatan List Kosong*/
	CreateEmptyList(&list1);

	if (IsEmptyList(list1)){
		printf("%s\n", "List kosong");
	}

	InsVLastList(&list1, 5);

	if (SearchList(list1,5) != NULL){
		printf("%s\n", "Searching berhasil");
	}

	DelPList(&list1,5);
	if (SearchList(list1,5) == NULL){
		printf("%s\n", "Delete berhasil");
	}

	printf("%s : %d\n", "Jumlah elemen dalam list", NbElmtList(list1));

}
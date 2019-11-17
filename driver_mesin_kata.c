#include<stdio.h>
#include<stdlib.h>
#include"mesinkata.h"
#include"mesinkar.h"

#define printInt(x) printf("%d", x)
#define printlnInt(x) printf("%d\n", x)
#define println(x) printf("%c\n", x)
#define print(x) printf("%c", x)
#define bacaInt(x) scanf("%d", &x)
#define bacaChar(x) scanf("%c", &c)
#define endline printf("\n")

#define SIZE 100

char * outputString() {
	char * s = malloc(sizeof (char) * CKata.Length);
	for (int i = 1; i <= CKata.Length; i++){
		s[i-1] = CKata.TabKata[i];
	}
	return s;
}


int pengubahAngka() {
	int sum = 0;
	for (int i = 1; i <= CKata.Length; i++){
		sum = sum * 10 + (CKata.TabKata[i] - '0');
	}
	return sum;
}

char * BacaInputUser(){
	STARTKATAIn();
	while(!EndKata){
		ADVKATAIn();
	}
	char * s = malloc(sizeof (char) * CKata.Length);
	for (int i = 1; i <= CKata.Length;i++){
		s[i-1] = CKata.TabKata[i];
	}
	return s;
}


int main() {
	char * si;
	si = BacaInputUser();
	printf("%s\n", si);
	// kalo baca teks
	STARTKATAIn();
	while(!EndKata){
		for (int i = 1; i <= CKata.Length; i++){
			print(CKata.TabKata[i]);
		}
		endline;
		ADVKATAIn();
	}
		printf("%s\n", "debug");
	char s[CKata.Length];

	for (int i = 1; i <= CKata.Length;i++){
		s[i-1] = CKata.TabKata[i];
	}
	endline;
	printf("%s\n", "Testing");
	printf("%s\n", s);
	printf("%s\n", "End of testing");

	// kalo baca angka
	// coba operasi pengurangan 2 angka
	printf("%s\n", "debug");
	STARTKATAIn();
	int a,b;
	while(!EndKata){
		for (int i = 1; i <= CKata.Length; i++){
			print(CKata.TabKata[i]);
		}
		endline;
		a = pengubahAngka();
		ADVKATAIn();
	}
	print('a');
	print('=');
	printlnInt(a);
}

boolean IsAttack (char[] s){
	char attack[6];
	attack[0] = 'A';
	attack[1] = 'T';
	attack[2] = 'T';
	attack[3] = 'A';
	attack[4] = 'C';
	attack[5] = 'K';

	int sizeof_attack = sizeof(attack) / sizeof(char);
	int sizeof_s = sizeof(s) / sizeof(char);

	if (sizeof_s != sizeof_attack) return false;
	else {
		for (int i = 0; i < sizeof_attack; i++){
			if (s[i] != attack[i]){
				return false;
			}
		}
	}
	return true;
}

boolean IsLevelUp(char[] s){
	char levelUp[8];
	levelUp[0] = 'L';
	levelUp[1] = 'E';
	levelUp[2] = 'V';
	levelUp[3] = 'E';
	levelUp[4] = 'L';
	levelUp[5] = '_';
	levelUp[6] = 'U';
	levelUp[7] = 'P';

	int sizeof_levelUp = sizeof(levelUp) / sizeof(char);
	int sizeof_s = sizeof(s) / sizeof(char);

	if (sizeof_s != sizeof_levelUp) return false;
	else {
		for (int i = 0; i < sizeof_levelUp i++){
			if (s[i] != levelUp[i]){
				return false;
			}
		}
	}
	return true;
}

boolean IsMove(char[] s){
	char move[4];
	move[0] = 'M';
	move[1] = 'O';
	move[2] = 'V';
	move[3] = 'E';

	int sizeof_move = sizeof(move) / sizeof(char);
	int sizeof_s = sizeof(s) / sizeof(char);

	if (sizeof_s != sizeof_move) return false;
	else {
		for (int i = 0; i < sizeof_move; i++){
			if (s[i] != move[i]){
				return false;
			}
		}
	}
	return true;

}
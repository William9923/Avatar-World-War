#include <stdio.h>

void ChangeNilai(int * x){
	*x += 1;
}

int main() {
	int x = 6;
	ChangeNilai(&x);

	printf("%d\n", x);
}
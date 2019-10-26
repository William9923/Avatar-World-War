#include <stdio.h>

typedef struct{
	int x;
	int y;
}Point;


typedef struct{
	Point point1;
	Point point2;
} Tester;


int main(){
	Point p1; Point p2;
	Tester tester1;
	Tester tester2;

	p1.x = 1; p2.x = 2;
	p1.y = 5; p2.y = 6;

	tester1.point1 = p1;
	tester1.point2 = p2;

	tester2 = tester1;

	printf("%d",tester1.point1.x);
}
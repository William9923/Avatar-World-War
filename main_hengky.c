#include<stdio.h>
#include<stdlib.h>
#include "boolean.h"
#include "skill.h"


int main() {
	Queue Q;
	char C = 'A';


	StartSkill(&Q);
	AddSkillQueue(&Q,'B'); // ini buat menuhin queue
	AddSkillQueue(&Q,'C');
	AddSkillQueue(&Q,'D');
	AddSkillQueue(&Q,'E');
	AddSkillQueue(&Q,'F');
	AddSkillQueue(&Q,'G');
	AddSkillQueue(&Q,'B');
	AddSkillQueue(&Q,'C');
	AddSkillQueue(&Q,'D');
	


//	printf("%d\n",MaxElQueue(Q));
	
//	DelSkillQueue(&Q,&C);
	printf("%c\n",InfoHead(Q));
	printf("%c\n",InfoTail(Q));
	printf("%d\n",NBElmtQueue(Q));

	AddSkillQueue(&Q,'E'); // pesan kesalahan queue penuh
/*	if (IsEmptyQueue(Q))
	{
		printf("kosong\n");
	}
	else
	{
		printf("gak kosong\n");
	}

	if (IsFullQueue(Q))
	{
		printf("penuh\n");
	}
	else
	{
		printf("gak penuh\n");
	}
*/	
	return 0;
}
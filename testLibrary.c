#include <stdio.h>
#include "testLibrary.h"

void functionA(void)
{
	printf("In functionA\n");
}

char functionB(void)
{
	printf("In functionB\n");
	return 'A';
}

int functionC(int x, int y)
{
	printf("In functionC\n");
	printf("%d+%d=%d\n",x,y,x+y);
	return x+y;
}

void functionD(myADT* adt)
{
	printf("In functionD\n");
	printf("%d\n%d\n%c\n",adt->x,adt->y,adt->z);
}

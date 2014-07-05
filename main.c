#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "testLibrary.h"
#include "macro.h"
#include "randomInputs.h"

int main()
{
	FUZZTHIS(functionA, void, void)
	FUZZTHIS(functionB, char, void)
	FUZZTHIS(functionC, int, int, int)
	FUZZTHIS(functionD, void, myADT*)

	STARTFUZZLOOP
		DOFUZZING(functionA)
		DOFUZZING(functionB)
		DOFUZZING(functionC)
		DOFUZZING(functionD)
	ENDFUZZLOOP
	return 0;
}

void functionAFUZZ(void(*funcPtr)(void))
{
	printf("fuzzing func1\n");
	funcPtr();
}

void functionBFUZZ(char(*funcPtr)(void))
{
	printf("fuzzing func2\n");
	funcPtr();
}

void functionCFUZZ(int(*funcPtr)(int,int))
{
	int limit = 50;
	printf("fuzzing func3\n");
	funcPtr(getRandomInt()%limit,getRandomInt());
}

void functionDFUZZ(void(*funcPtr)(myADT*))
{
	myADT adt;
	adt.x=2;
	adt.y=5;
	adt.z='Z';

	printf("fuzzing func4\n");
	funcPtr(&adt);
}

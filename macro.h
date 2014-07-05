#ifndef MACRO_H
#define MACRO_H

typedef struct {
	int functionNumber;
	void* functionFuzzer;	
} function;

function* funcs;

static int counter = 0;
void resizeFunctionList()
{
	++counter;
	funcs = realloc(funcs, sizeof(function)*counter);
//	printf("%d\n",sizeof(function)*counter);	
}


#define FUZZTHIS(NAME, RET, ...) FUNCTIONTOFUZZDEFINITION(NAME, RET, __VA_ARGS__);\
				 FUZZFUNCTION(NAME, RET, __VA_ARGS__)\
				 INIT(NAME);\
				resizeFunctionList();\
				funcs[counter-1].functionNumber = counter;\
				funcs[counter-1].functionFuzzer=(void*)&NAME##func;

#define FUNCTIONTOFUZZDEFINITION(NAME, RET, ...) typedef struct {\
					RET(*funcPtr)(__VA_ARGS__);\
					void(*fuzz)(RET(*)(__VA_ARGS__));\
					}NAME ## _t

#define INIT(NAME) NAME##_t NAME##func;\
			NAME##func.funcPtr = NAME;\
			NAME##func.fuzz = NAME##FUZZ;
 
//TODO: Try and create a macro which will generate a default fuzz function.
//This may be difficult as funcPtr would need to be called with different arguments
//e.g. funcPtr(getRandomInt(), getRandomChar()) or funcPtr() depending on its arguments
#define FUZZFUNCTION(NAME, RET, ...) void NAME ## FUZZ(RET(*funcPtr)(__VA_ARGS__));

#define DOFUZZING(NAME) \
			case __COUNTER__:{\
				NAME##_t *p = f.functionFuzzer;\
				p->fuzz(p->funcPtr);\
			}\
			break;

#define STARTFUZZLOOP srand(time(NULL));\
			while(1){\
			function f = funcs[rand()%counter];\
			switch(f.functionNumber-1){


#define ENDFUZZLOOP }}
#endif

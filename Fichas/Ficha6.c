#include <stdio.h>
#include <stdlib.h>

#define Max 25
struct staticStack {
	int sp;
	int values [Max];
}STACK;
typedef struct staticStack *SStack;


// 1

// (a)
void SinitStack (SStack s){

    s->sp = 0;
}

// (b)
int SisEmpty (SStack s){

    return (s->sp == 0);
}

// (c)
int Spush (SStack s, int x){

    if(s->sp >= Max) return 1;

    s->values[s->sp] = x;
    s->sp++;
    return 0;
}

// (d)
int Spop (SStack s, int *x){

    if(!s->sp) return 1;

    *x = s->values[s->sp-1];
    s->sp--;

    return 0;
}

// (e)
int Stop (SStack s, int *x){

    if(!s->sp) return 1;

    *x = s->values[s->sp-1];
    return 0;
}



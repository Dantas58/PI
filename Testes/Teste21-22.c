#include <stdio.h>

// 1
void swap(int a[], int i, int j){

    int aux = a[i];
    a[i] = a[j];
    a[j] = aux;
}

int menor(int a[], int N){

    int i, min = a[0], r=0;
    for(i=0; i<N; i++) if(a[i]<min){min = a[i]; r=i;}

    return r;
}

int nesimo(int a[], int N, int i){

    int j;
    for(j=0; j<i; j++) swap(a+j, 0, menor(a+j, N-j));

    return(a[j-1]);
}


// 2
typedef struct LInt_nodo {
    int valor;
    struct LInt_nodo *prox;
} *LInt;

LInt removeMaiores(LInt l, int x){

    if(!l) return l;

    LInt copial = l;
    LInt ant = NULL;

    while(copial){

        if(copial->valor > x){
            if(!ant){
                l = l->prox;
                free(copial);
                copial = l;
            }
            else{
                ant->prox = copial->prox;
                LInt temp = copial;
                copial = copial->prox;
                free(temp);
            }
        }
        else{
            ant = copial;
            copial = copial->prox;
        }
    }
    return l;
}


// 3
typedef struct ABin_nodo {
    int valor;
    struct ABin_nodo *esq, *dir;
} *ABin;

LInt caminho(ABin a, int x){    // ficou confuso mas acho que funfa

    if(!a) return NULL; 

    ABin copia = a;
    LInt r = NULL;
    LInt l = NULL;

    while(copia && copia->valor!=x){

        if(!l){
            r = malloc(sizeof(LInt));
            r->valor = copia->valor;
            r->prox = NULL;
            l = r;
        }

        else{
            r->prox = malloc(sizeof(LInt));
            r = r->prox;
            r->valor = copia->valor;
            r->prox = NULL;
        }

        if(copia->valor > x) copia = copia->esq;
        else copia = copia->dir;
    }

    if(!copia) return NULL;

    r = malloc(sizeof(LInt));
    r->valor = x;
    r->prox = NULL;

    if(!l) return r;

    return l;
}

// 4
void inc(char s[]){ 

    int i = 0;
    for(i; s[i+1]; i++);
    int j = i;

    for(i; i>=0; i--){
            
        if(s[i] == '9') s[i] = '0';
        else {s[i]++; return;}
    }

    s[0] = '1';     // caso por exemplo 999 -> 1000
    s[j+1] = '0';
    s[j+2] = 0;
}


// 5
int sacos(int p[], int N, int C){   // nao sei mas acho que faz senso

    int i, total = 0;
    for(i=0; i<N; i++) total += p[i];

    if(total%C == 0) return (total/C);

    return (total/C + 1);
}


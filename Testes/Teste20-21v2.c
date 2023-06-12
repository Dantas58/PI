#include <stdio.h>


int sumhtpo (int n) {
    int r = 0;
    int i = 0;
    while (n != 1 && i < 100) {
        r += n;
        if (n%2 == 0) n = n/2; 
        else n = 1+(3*n);

        i++;
    }

    if(r < 100) return -1;

    return r;
}

int quantas (int v[], int N, int x){

    int i = 0;
    int cont = 0;
    for(; i<N; i++) if(v[i] == x) cont++;

    return cont;
}

int moda(int v[], int N, int *m){

    int i = 0;
    int cont = quantas(v, N, v[0]);
    int j;

    for(; i<N; i++){
        j = quantas(v, N, v[i]);
        if(j > cont){
            cont = j;
            *m = v[i];
        }
    }

    for(i = 0; i<N; i++){

        j = quantas(v, N, v[i]);
        if(j == cont && v[i] != *m) return 0;
    }

    return cont;
}

typedef struct LInt_nodo {
    int valor;
    struct LInt_nodo *prox;
} *LInt;

int procura (LInt *l, int x){

    if(!*l) return 0;

    LInt copial = *l;
    LInt ant = NULL;

    for(; copial; ant=copial, copial=copial->prox) if(copial->valor == x) break;

    if(!copial) return 0;
    if(!ant) return 1;

    if(copial->prox) ant->prox = copial->prox;
    else ant->prox = NULL;

    LInt node = malloc(sizeof(LInt));
    node->valor = x;
    node->prox = *l;

   *l = node;
    free(copial);

    return 1;
}


typedef struct nodo {
int valor;
struct nodo *pai, *esq, *dir;
} *ABin;

int freeAB(ABin a){

    if(!a) return 0;
    ABin esq = a->esq;
    ABin dir = a->dir;

    free(a);
    return (1 + freeAB(esq) + freeAB(dir));
}

void caminho(ABin a){

    if(!a->pai) return;
}
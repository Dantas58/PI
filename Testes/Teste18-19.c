#include <stdlib.h>

typedef struct lligada {
    int valor;
    struct lligada *prox;
} *LInt;

// PARTE A

// 1
int retiraNeg (int v[], int N){

    int i, j;
    for(i=0; i<N; i++)
        if(v[i]<0){
            for(j=i; j+1<N; j++) v[j] = v[j+1];
            N--;
            i--;
        }
    return N;
}

// 2
int difConsecutivos (char s[]){

    int i, cont = 1, max=1;

    for(i=0; s[i]; i++){
        if(s[i+1] && s[i]!=s[i+1]) cont++;

        else{
            if(cont > max) max = cont;
            cont = 1;
        }
    }
    return max;
}

// 3
int maximo (LInt l){

    if(!l) return -1;

    int r = l->valor;
    LInt copia = l->prox;
    for(; copia; copia=copia->prox) if(copia->valor > r) r = copia->valor;
    
    return r;
}

// 4
int removeAll (LInt *l, int x){

    if(!*l) return 0;

    LInt copia = *l, ant = NULL;
    int r = 0;

        while(copia){

        if(copia->valor==x){
            if(!ant){
                *l = (*l)->prox;
                r++;
                free(copia); 
                copia = *l;
            }
            else{
                ant->prox = copia->prox;
                free(copia);
                copia = ant;
                r++;
                copia = ant->prox;
            }
        }
         
        else{ant = copia; copia = copia->prox;}
    }
    return r;
}

// 5
LInt arrayToList (int v[], int N){

    if(N<=0) return NULL;

    LInt l = malloc(sizeof(LInt));
    l->valor = v[0];
    l->prox = arrayToList(v+1, N-1);

    return l;
}

// PARTE B

typedef struct nodo {
    int valor;
    struct nodo *esq, *dir;
} *ABin;

// 1
int minheapOK(ABin a) {
    if (!a) return 1; 

    ABin left = a->esq;
    ABin right = a->dir;

    if (left && left->valor < a->valor) return 0;

    if (right && right->valor < a->valor) return 0;

    return minheapOK(left) && minheapOK(right); 
}

// 2
int max (int x, int y){

    if(x>y) return x;
    else return y;
}
int maxHeap (ABin a){   // nao testei vou supor que dá

    if(!a) return 0;
    if(!a->esq && !a->dir) return a->valor;

    int left = maxHeap(a->esq);
    int right = maxHeap(a->dir);

    return(max(left, right));
}

// 3
void bubbleDown (ABin a){

    
}

void removeMin (ABin *a){

    if(!*a) return;

    ABin copiaDir = (*a)->dir;
    ABin copiaEsq = (*a)->esq;
    
}
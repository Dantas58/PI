#include <stdio.h>
#include <stdlib.h>


typedef struct lligada {
    int valor;
    struct lligada *prox;
} *LInt;



// 51
int length (LInt l){

    LInt aux = l;
    int r = 0;
    for(aux; aux; aux=aux->prox) r++;
    return r;
}


// 52
void freeL (LInt l){

    LInt aux = l;
    for(aux; aux; aux=aux->prox) free(aux);
}


// 53
void imprimeL (LInt l){

    LInt aux = l;
    for(aux; aux; aux=aux->prox){
        printf("%d \n", aux->valor);
    }
}


// 54
LInt reverseL (LInt l){

    LInt atual = l;
    LInt ant = NULL;
    LInt prox = NULL;

    for(; atual; atual = prox){
        prox = atual->prox;
        atual->prox = ant;
        ant = atual;
    }
    return ant;
}


// 55
void insertOrd (LInt *l, int x){

    LInt ant = NULL;
    LInt atual = *l;

    for (;atual && atual->valor < x; atual = atual->prox){
        ant = atual;
    }

    LInt new = malloc(sizeof(LInt));
    new->valor = x;
    new->prox = atual;

    if (ant == NULL) *l = new;
    else ant->prox = new;
}


// 56
int removeOneOrd (LInt *l, int x){

    LInt atual = *l;
    LInt ant = NULL;

    for(; atual && atual->valor!=x; atual = atual->prox) ant = atual;

    if(!atual) return 1;

    if(!ant){ant = atual; *l=atual->prox; free(ant);}
    else{ant->prox = atual->prox; free(atual);}

    return 0;
}


// 57
void merge (LInt *r, LInt a, LInt b){       

    if(!a){*r = b; return;}
    if(!b){*r = a; return;}

    LInt copiaa = a;
    LInt copiab = b;
    LInt ant = NULL;
    
    while(copiaa && copiab){

        LInt new = malloc(sizeof(LInt));

        if(copiaa->valor <= copiab->valor){
            new->valor = copiaa->valor;
            copiaa = copiaa->prox;
        }
        else{
            new->valor = copiab->valor;
            copiab = copiab->prox;
        }

        if(!ant) *r = new;
        else ant->prox = new;

        ant = new;
    }

    if(!copiaa) ant->prox = copiab;
    if(!copiab) ant->prox = copiaa;

}


// 58
void splitQS (LInt l, int x, LInt *mx, LInt *Mx){

    LInt copial = l;
    LInt antmen = NULL;
    LInt antmai = NULL;

    for(; copial; copial=copial->prox){

        LInt new = malloc(sizeof(LInt));
        if(copial->valor<x){
            if(!antmen){new->valor = copial->valor; *mx = new;}
            else{new->valor = copial->valor; antmen->prox = new;} 
            antmen = new;
        }
        else{
            if(!antmai){new->valor = copial->valor; *Mx = new;}
            else{new->valor = copial->valor; antmai->prox = new;} 
            antmai = new;            
        }
    }
}


// 59
LInt parteAmeio (LInt *l){

    int total = 0;
    LInt copial = *l;
    LInt ant = NULL;
    LInt r;

    for(; copial; copial=copial->prox) total++;

    total /= 2;

    for(total; total>0; total--){

        LInt new = malloc(sizeof(LInt));
        new->valor = (*l)->valor;
        if(!ant) r = new;
        else ant->prox = new;

        ant = new;
        *l = (*l)->prox;
    }
    return r;
}


// 60
int removeAll (LInt *l, int x){

    if(!l) return 0;

    int r = 0;
    LInt copial = *l;
    LInt ant = NULL;

    while(copial){
        if(copial->valor == x){
            if(!ant){*l=(*l)->prox; free(copial); copial=(*l); r++;}
            else{ant->prox = copial->prox; free(copial); copial=ant->prox; r++;}
        }
        else{ant = copial; copial=copial->prox;}
    }
    return r;
}


// 61
int removeDups (LInt *l){

    if(!l) return 0;
    int r = 0;
    LInt copial = *l;
    LInt aux;
    LInt ant;
    
    for(copial; copial->prox; copial=copial->prox){
        ant = copial;
        for(aux=copial->prox; aux; aux=aux->prox){
            if(aux->valor == copial->valor){
                ant->prox = aux->prox;
                free(aux);
                aux = ant;
                r++;
            }
            ant = aux;
        }
    }
    return r;
}


// 62
int removeMaiorL (LInt *l){

    if(!l) return -1;

    int max = 0;
    LInt copial = *l;
    LInt ant = NULL;

    for(; copial; copial=copial->prox) if(copial->valor > max) max = copial->valor;
    copial = *l;
    for(; copial; copial=copial->prox){
        if(copial->valor == max){
            if(!ant){*l=(*l)->prox; free(copial); return max;}
            else{ant->prox = copial->prox; free(copial); return max;}
        }
        ant = copial;
    }
}


// 63
void init (LInt *l){

    LInt copial = *l; LInt ant = NULL;
    
    for(; copial->prox; copial=copial->prox) ant = copial;
    free(copial);

    if(!ant) *l = NULL;
    else ant->prox = NULL;
}


// 64
void appendL (LInt *l, int x){  

    LInt node = malloc(sizeof(LInt));
    node->valor = x;
    node->prox = NULL;

    if(!*l){*l = node; return;}
    LInt copial = *l;

    for(; copial->prox; copial=copial->prox);
    copial->prox = node;
}


// 65
void concatL (LInt *a, LInt b){

    if(!*a){*a = b; return;}

    LInt copiaa = *a;

    for(; copiaa->prox; copiaa=copiaa->prox);
    copiaa->prox = b;
}


// 66
LInt cloneL (LInt l){   // confuso mas acho que funfa

    if(!l) return NULL;

    LInt copial = l->prox;
    LInt novo = malloc(sizeof(LInt));
    novo->valor = l->valor;
    novo->prox = NULL;
    LInt r = novo;

    for(; copial; copial=copial->prox){

        LInt prox = malloc(sizeof(LInt));
        prox->valor = copial->valor;
        prox->prox = NULL;
        novo->prox = prox;
        novo = novo->prox;
    }   

    return r;
}


// 67 
LInt cloneRev (LInt l){     // para depois

}


// 68
int maximo (LInt l){

    int max = l->valor;
    LInt copial = l->prox;

    for(; copial; copial=copial->prox) if(copial->valor > max) max = copial->valor;

    return max;
}


// 69
int take (int n, LInt *l){

    int N = n;
    LInt copial = *l; 

    for(N; N>1 && copial; N--) copial = copial->prox;

    if(!copial) return n-N;

    LInt aux = copial->prox;
    for(; aux; aux=aux->prox) free(aux);
    copial->prox = NULL;

    return n;
}


// 70
int drop (int n, LInt *l){

    if(!*l || n==0) return 0;

    int N = n;
    LInt ant = NULL;

    for(N; N>0 && *l; N--){

        ant = *l;
        *l = (*l)->prox;
        free(ant);
    }

    if(N) return n-N;

    return n;
}


// 71
LInt Nforward (LInt l, int N){

    if(!l) return NULL;

    LInt copial = l;
    int n;

    for(n=N; n>0; n--) copial = copial->prox;

    return copial;
}


// 72
int listToArray (LInt l, int v[], int N){

    int i;
    LInt copial = l;

    for(i=0; i<N && copial; i++){
        v[i] = copial->valor;
        copial=copial->prox;
    }
    return i;
}


// 73
LInt arrayToList (int v[], int N){

    if(!N) return NULL;

    int i;
    LInt l = malloc(sizeof(LInt));
    l->valor = v[0];
    l->prox = NULL;

    LInt aux = l;

    for(i=1; i<N; i++){
        aux->prox = malloc(sizeof(LInt));
        aux = aux->prox;
        aux->valor = v[i];
        aux->prox = NULL;
    }
    return l;
}

LInt arrayToList (int v[], int N){  // versão recursiva mais simples

    if(N<=0) return NULL;

    LInt l = malloc(sizeof(LInt));
    l->valor = v[0];
    l->prox = arrayToList(v+1, N-1);

    return l;
}

// 74
LInt somasAcL (LInt l){     // codeboard da erro mas acho que é isto

    if(!l) return l;

    int i = 0;
    LInt copial = l;

    for(; copial; copial=copial->prox){

        i += copial->valor;
        copial->valor = i;
    }
    return l;
}


// 75
void remreps (LInt l){

    if (!l) return;

    LInt copial = l;
    LInt aux = l->prox;

    while (aux){
        if (copial->valor == aux->valor){
            copial->prox = aux->prox;
            free(aux);
            aux = copial->prox;
        } 
        
        else {
            copial = aux;
            aux = aux->prox;
        }
    }
}


// 76   
LInt rotateL (LInt l){

    if(!l || !l->prox) return l;

    LInt copial = l;
    LInt aux = l;
    
    LInt node = malloc(sizeof(LInt));
    node->valor = l->valor;
    node->prox = NULL;


    for(; copial->prox; copial=copial->prox);
    
    copial->prox = node;
    //free(l)  big no no
    l = l->prox;
    free(aux);
    
    return l;
}


// 77
LInt parte (LInt l){

    
}


// ARVORES BINARIAS // 

typedef struct nodo {
    int valor;
    struct nodo *esq, *dir;
} *ABin;


// 78
int max (int x, int y){
    if(x>y) return x;
    return y;
}

int altura (ABin t){

    if(!t) return 0;

    return(1 + max(altura (t->esq), altura(t->dir)));
}


// 79
ABin cloneAB (ABin t){

    if(!t) return NULL;
    ABin nodo = malloc(sizeof(ABin));
    nodo->valor = t->valor;
    nodo->esq = cloneAB(t->esq);
    nodo->dir = cloneAB(t->dir);

    return nodo;
}


// 80
void mirror (ABin *t){

    if(!*t) return;

    ABin aux = (*t)->esq;
    (*t)->esq = (*t)->dir;
    (*t)->dir = aux;
    mirror(&(*t)->esq);
    mirror(&(*t)->dir);
}


// 81
void inorder (ABin t, LInt *l){ // estas sao tao chatas

}


// 82
void preorder (ABin t, LInt *l){

}


// 83
void posorder (ABin t, LInt *l){

}


// 84
int depth (ABin t, int x){

}


// 85
int freeAB (ABin t){

    if(!t) return 0;

    int r = 1 + freeAB(t->esq) + freeAB(t->dir);
    free(t);
    return(r);
}


// 86
int pruneAB (ABin *t, int l){

    int r;
    if(!*t) return 0;

    if(l==0){
        r = 1 + pruneAB(&(*t)->esq, l) + pruneAB(&(*t)->dir, l);
        free(*t);
    }
    else r = pruneAB(&(*t)->esq, l-1) + pruneAB(&(*t)->dir, l-1);

    return r;
}


// 87
int iguaisAB (ABin a, ABin b){

    if(!a && !b) return 1;
    if( (a && !b) || (!a && b) ) return 0;

    if(a->valor == b->valor) return (iguaisAB(a->esq, b->esq) && iguaisAB(a->dir, b->dir));

    return 0;
}


// 88 
LInt nivelL (ABin t, int n){

    
}


// 91
int somaSubarvore(ABin t) {
    if (!t) return 0;
    return t->valor + somaSubarvore(t->esq) + somaSubarvore(t->dir);
}

ABin somasAcA(ABin t) {
    
    if (!t) return t;
    
    ABin node = (ABin) malloc(sizeof(ABin));
    node->valor = somaSubarvore(t);
    node->esq = somasAcA(t->esq);
    node->dir = somasAcA(t->dir);

    return node;
}


// 92
int contaFolhas (ABin t){

    if(!t) return 0;

    if(!t->esq && !t->dir) return 1;

    return (contaFolhas(t->esq)+contaFolhas(t->dir));
}


// 93
ABin cloneMirror (ABin t){

    if(!t) return NULL;

    ABin new = malloc(sizeof(ABin));
    new->valor = t->valor;
    new->esq = cloneMirror(t->dir);
    new->dir = cloneMirror(t->esq);

    return new;
}


// 94
int addOrd (ABin *a, int x){ // admito derrota

    if(!*a) return 0;

    ABin copia = *a;

    
}


// 95
int lookupAB (ABin t, int x){

    if(!t) return 0;
    return(t->valor == x || lookupAB(t->esq, x) || lookupAB(t->dir, x));
}


// 96
int depthOrd (ABin t, int x){

    if(!t) return -1;

    ABin copiat = t;
    int cont = 1;
    while(copiat->valor != x){
        
        if(copiat->valor > x && copiat->esq){
            copiat = copiat->esq;
            cont++;
        }
        
        else if(copiat->dir){
            copiat = copiat->dir;
            cont++;
        }
        else return -1;
    }
    return cont;
}

// 97
int maiorAB (ABin t){

    if(!t) return 0;

    while(t->dir) t=t->dir;

    return t->valor;
}


// 98
void removeMaiorA (ABin *t){
    
    if(!*t) return;

    if(!(*t)->dir){*t = (*t)->esq; return;}

    ABin copiat = (*t)->dir;
    ABin ant = *t;
    while(copiat->dir){
        ant = copiat;
        copiat = copiat->dir;
    }

    ant->dir = copiat->esq;
}


// 99 
int quantos (ABin t){

    if(!t) return 0;
    return(1+quantos(t->esq)+quantos(t->dir));
}

int quantosMaiores (ABin t, int x){

    if(!t) return 0;
    
    if(t->valor > x) return(1+quantosMaiores(t->esq, x)+quantos(t->dir));
    else return(quantosMaiores(t->dir, x));
}


// 100



// 101
int menores (ABin t, int x){

    if(!t) return 1;
    //if(!t->esq) return 1;

    if(t->valor >= x) return 0;

    return (menores(t->esq, x) && menores(t->dir, x));
}

int maiores (ABin t, int x){

    if(!t) return 1;
    //if(!t->dir) return 1;

    if(t->valor <= x) return 0;

    return (maiores(t->esq, x) && maiores(t->dir, x));
}

int deProcura (ABin t){

    if(!t) return 1;

    ABin left = t->esq;
    ABin right = t->dir;
    
    if(menores(left, t->valor) && maiores(right, t->valor)) return (deProcura(t->esq) && deProcura(t->dir));

    return 0;
}


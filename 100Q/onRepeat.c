#include <stdio.h>
#include <stdlib.h>


typedef struct lligada {
    int valor;
    struct lligada *prox;
} *LInt;


int length (LInt l){

    int i = 0;
    for(; l; l = l->prox, i++);
    return i;
}

void freeL (LInt l){

    LInt aux = l;
    for(l = l->prox; l; l=l->prox){free(aux); aux = l;}
}

void imprimeL (LInt l){

    for(; l; l=l->prox) printf("%d\n", l->valor);
}

LInt reverseL (LInt l){
    
    if(!l) return NULL;

    LInt ant = NULL;
    LInt prox = NULL;
    
    for(; l; l=prox){

        prox = l->prox;
        l->prox = ant;
        ant = l;
    }
    return ant;
}

void insertOrd (LInt *l, int x){

    LInt copial = *l;
    LInt ant = NULL;

    for(; copial && copial->valor < x; ant=copial, copial=copial->prox);

    LInt aux = malloc(sizeof(LInt));
    aux->valor = x;
    aux->prox = copial;

    if(!ant) *l = aux;
    else ant->prox = aux;
}


int removeOneOrd (LInt *l, int x){

    if(!(*l)) return 1;

    LInt copial = *l; 
    LInt ant = NULL;

    for(; copial && copial->valor < x; ant = copial, copial=copial->prox);

    if(!copial || copial->valor != x) return 1;

    if(!ant) (*l) = copial->prox;
    else ant->prox = copial->prox; 

    free(copial);
    return 0;
}

void merge (LInt *r, LInt a, LInt b){

    if(!a){*r = b; return;}
    if(!b){*r = a; return;}

    LInt ant = NULL;

    while(a && b){

        LInt new = malloc(sizeof(LInt));

        if(a->valor < b->valor){
            new->valor = a->valor;
            a = a->prox;
        }
        else{
            new->valor = b->valor;
            b = b->prox;
        }

        if(!ant) *r = new;
        else ant->prox = new;

        ant = new;
    }

    if(!a) ant->prox = b;
    if(!b) ant->prox = a;
}

void splitQS (LInt l, int x, LInt *mx, LInt *Mx){

    if(!l) return;

    LInt antM = NULL;
    LInt antm = NULL;

    for(; l; l=l->prox){

        LInt new = malloc(sizeof(LInt));

        if(l->valor < x){
            new->valor = l->valor;
            if(!antm) *mx = new;
            else antm->prox = new;
            antm = new;
        }
        else{
            new->valor = l->valor;
            if(!antM) *Mx = new;
            else antM->prox = new;
            antM = new;
        }
    }
}

LInt parteAmeio (LInt *l){

    if(!*l) return NULL;

    LInt r = NULL;
    LInt copial = *l;

    int n = 0;
    for(; copial; copial=copial->prox) n++;

    int i = 0;
    LInt ant = NULL;

    for(; i<n/2; i++){

        LInt new = malloc(sizeof(LInt));

        new->valor = (*l)->valor;
        if(!ant) r = new;
        else ant->prox = new;

        ant = new;
        *l = (*l)->prox;
    }

    return r;
}

int removeAll (LInt *l, int x){

    if(!*l) return 0;
    int r = 0;
    LInt ant = NULL;
    LInt copial = *l;

    while(copial){

        if(copial->valor == x){
            if(!ant){
                (*l) = (*l)->prox;
                copial = *l;
                r++; 
            }
            else{
                ant->prox = copial->prox;
                copial = ant->prox;
                r++;
            }
        }

        else{ant = copial; copial = copial->prox;}
    }

    return r;
}


    int removeDups (LInt *l){

        if(!*l) return 0;

        LInt copial = *l;
        LInt ant = NULL;
        LInt comparator;

        for(; copial->prox; copial = copial->prox){

            ant = copial;
            comparator = copial->prox;

            for(; comparator; comparator = comparator->prox){

                if(comparator->valor == copial->valor){

                    ant->prox = comparator->prox;
                    free(comparator);
                    comparator = ant;
                }

                ant = comparator;
            }
        }

        return 1;
    }


int removeMaiorL (LInt *l){

    if(!*l) return 0;

    LInt copial = *l;
    int i = copial->valor;

    for(; copial; copial = copial->prox) if(copial->valor > i) i = copial->valor;

    LInt ant = NULL;
    copial = *l;

    for(; copial; copial=copial->prox){
        if(copial->valor == i){
            if(!ant) (*l) = (*l)->prox;
            else ant->prox = copial->prox;

            free(copial);
            return i;
        }
        ant = copial;
    }
    return 0;
}

void init (LInt *l){

    if(!*l) return;

    LInt copial = *l;
    LInt ant = NULL;

    for(; copial->prox; ant = copial, copial=copial->prox);
    free(copial);

    if(!ant){*l = NULL; return;}

    ant->prox = NULL;
}

void appendL (LInt *l, int x){

    LInt new = malloc(sizeof(LInt));
    new->valor = x;
    new->prox = NULL;

    if(!*l) {*l = new; return;}

    LInt copial = *l;
    for(; (*l)->prox; *l = (*l)->prox);

    (*l)->prox = new;
    *l = copial;
}

void concatL (LInt *a, LInt b){

    if(!*a){*a = b; return;}
    if(!b) return;

    LInt copia = *a;

    for(; copia->prox; copia=copia->prox);

    copia->prox = b;
}

LInt cloneL (LInt l){

    LInt r = l;
    return r;
}

int maximo (LInt l){

    if(!l) return -1;
    int r = l->valor;

    for(; l; l=l->prox) if(l->valor>r) r = l->valor;

    return r;
}

int take (int n, LInt *l){

    if(!*l) return 0;
    
    LInt copial = *l;
    int r = 0;
    for(; copial; copial=copial->prox) r++;

    if(r<n) return r;

    LInt ant = NULL;
    copial = *l;
    r = n;

    for(; n>0; ant = copial, copial = copial->prox, n--);

    ant->prox = NULL;

    while(copial){
        ant = copial;
        copial = copial->prox;
        free(ant);
    }
    return r;
}

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

LInt Nforward (LInt l, int N){

    if(!l) return NULL;

    for(; N>0; N--) l = l->prox;

    return l;
}

int listToArray (LInt l, int v[], int N){

    if(!l) return 0;
    
    int n = 0;
    for(; l && n<N; l=l->prox, n++) v[n] = l->valor;

    return n; 
}

LInt arrayToList (int v[], int N){

    if(!N) return NULL;

    LInt l = malloc(sizeof(LInt));
    l->valor = v[0];
    l->prox = NULL;

    LInt copial = l;

    int i = 1;
    for(; i<N; i++){

        LInt node = malloc(sizeof(LInt));
        node->valor = v[i];
        node->prox = NULL;
        copial->prox = node;
        copial = copial->prox;
    }
    
    return l;
}

LInt somasAcL (LInt l){


}


typedef struct nodo {
int valor;
struct nodo *esq, *dir;
} *ABin;

int altura (ABin t){

    if(!t) return 0;

    if(altura(t->esq) > altura(t->dir)) return 1+altura(t->esq);
    else return 1+(altura(t->dir));
}

ABin cloneAB (ABin t){

    if(!t) return NULL;

    ABin new = malloc(sizeof(ABin));
    new->valor = t->valor;
    new->esq = cloneAB(t->esq);
    new->dir = cloneAB(t->dir);

    return t;
}

void mirror (ABin *t){

    if(!*t) return;

    ABin aux = (*t)->esq;
    (*t)->esq = (*t)->dir;
    (*t)->dir = aux;

    mirror(&(*t)->esq);
    mirror(&(*t)->dir);
}

void inorder (ABin t, LInt *l){

    if(!t) return;

    inorder(t->esq, l);
    
    LInt node = malloc(sizeof(LInt));
    node->valor = t->valor;
    node->prox = NULL;

    if(!*l) *l = node;
    else{
        LInt aux = *l;
        for(; aux->prox; aux = aux->prox);
        aux->prox = node;
    }

    inorder(t->dir, l);
}

void preorder (ABin t, LInt *l){

    if(!t) return;
    
    LInt node = malloc(sizeof(LInt));
    node->valor = t->valor;
    node->prox = NULL;

    if(!*l) *l = node;
    else{
        LInt aux = *l;
        for(; aux->prox; aux = aux->prox);
        aux->prox = node;
    }

    preorder(t->esq, l);
    preorder(t->dir, l);
}

void posorder (ABin t, LInt *l){

    if(!t) return;
    
    posorder(t->esq, l);
    posorder(t->dir, l);

    LInt node = malloc(sizeof(LInt));
    node->valor = t->valor;
    node->prox = NULL;

    if(!*l) *l = node;
    else{
        LInt aux = *l;
        for(; aux->prox; aux = aux->prox);
        aux->prox = node;
    }
}

int depth(ABin t, int x) {

    if (!t) return -1;

    if (t->valor == x) return 1; 
    else {

        int leftDepth = depth(t->esq, x); 
        int rightDepth = depth(t->dir, x); 

        if (leftDepth == -1 && rightDepth == -1) return -1; 
        else if (leftDepth == -1) return rightDepth + 1;
        else if (rightDepth == -1) return leftDepth + 1; 
        else return (leftDepth < rightDepth) ? (leftDepth + 1) : (rightDepth + 1);  
        
    }
}

int freeAB (ABin t){

    if(!t) return 0;

    int x = freeAB(t->esq) + 1 + freeAB(t->dir);

    free(t);
    return x;
}


int pruneAB (ABin *t, int l){   // mudar a freeAB por causa dos argumentos

    if(!*t) return 0;
    if(!l) return freeAB(t);
    else return pruneAB(&(*t)->esq, l-1) + pruneAB(&(*t)->dir, l-1);

}

int iguaisAB (ABin a, ABin b){

    if(!a && !b) return 1;
    if(!a && b || a && !b) return -1; // 0 para dar na codeboard

    if(a->valor == b->valor) return (iguaisAB(a->esq, b->esq) && iguaisAB(a->dir, b->dir));

    return 0;
}

typedef struct lista {
    int valor;
    struct lista *prox;
} Nodo, *LInt;

LInt nivelL(ABin t, int n) {

    if (!t|| n < 1) return NULL;

    else if (n == 1) {

        LInt novo = malloc(sizeof(Nodo));
        novo->valor = t->valor;
        novo->prox = NULL;
        return novo;
        } 
        
        else {

        LInt esq = nivelL(t->esq, n - 1);
        LInt dir = nivelL(t->dir, n - 1);
        
        // Concatenar as listas da esquerda e direita
        LInt resultado = NULL;
        LInt temp = NULL;
        
        if (esq != NULL) {
            resultado = esq;
            temp = esq;
            
            while (temp->prox != NULL) temp = temp->prox;
            
            temp->prox = dir;
        } 
        
        else resultado = dir;
        
        return resultado;
    }
}

int nivelV(ABin a, int n, int v[]) {
    if (!a|| n <= 0) return 0;


    if (n == 1) {
        v[0] = a->valor;  
        return 1;  
    }

    int esquerda = nivelV(a->esq, n-1, v);  
    int direita = nivelV(a->dir, n-1, v + esquerda);  

    return esquerda + direita;
}

int dumpAbin (ABin t, int v[], int N){

}

int subArv (ABin t){

    if(!t) return 0;
    return t->valor + subArv(t->esq) + subArv(t->dir);
}

ABin somasAcA (ABin t){

    if(!t) return NULL;

    ABin new = malloc(sizeof(ABin));
    new->valor = subArv(t);
    new->dir = somasAcA(t->dir);
    new->esq = somasAcA(t->esq);

    return new;
}

int contaFolhas (ABin t){

    if(!t) return 0;

    if(!t->esq && !t->dir) return 1;

    return (contaFolhas(t->esq) + contaFolhas(t->dir));
}

ABin cloneMirror (ABin t){

    if(!t) return NULL;

    ABin new = malloc(sizeof(ABin));
    new->valor = t->valor;
    new->dir = cloneMirror(t->esq);
    new->esq = cloneMirror(t->dir);

    return new;
}

int addOrd (ABin *a, int x){

    ABin copia = *a;

    ABin node = malloc(sizeof(ABin));
    node->valor = x;
    node->esq = NULL;
    node->dir = NULL;

    if(!*a) {*a = node; return 0;}

    while(copia->esq || copia->dir){
        
        if(copia->valor == x) return 1;

        if(copia->valor > x && copia->esq) copia = copia->esq;
        else if(copia->valor < x && copia->dir) copia = copia->dir;
        else break;
    }

    if(copia->valor > x) copia->esq = node;
    else copia->dir = node;

    return 0;
}

int lookupAB (ABin a, int x){

    if(!a) return 0;

    while(a && a->valor != x){

        if(a->valor < x) a = a->dir;
        else a = a->esq;
    }

    if(!a) return 0;
    return 1;
}

int depthOrd (ABin a, int x){

    if(!a) return -1;

    int i = 1;
    while(a && a->valor != x){

        i++;
        if(a->valor < x) a = a->dir;
        else a = a->esq;
    }

    if(!a) return -1;

    return i;
}

int maiorAB (ABin t){

    if(!t) return -1;

    while(t->dir) t = t->dir;

    return t->valor;
}

void removeMaiorA (ABin *t){

    if(!*t) return;

    if(!(*t)->dir){*t = (*t)->esq; return;}

    ABin copia = *t;
    ABin last = (*t)->dir;

    for(; last->dir; copia = last, last = last->dir);

    copia->dir = last->esq;
    free(last);
}

int contaNodos (ABin t){

    if(!t) return 0;
    return (1 + contaNodos(t->dir) + contaNodos(t->esq));
}

int quantosMaiores (ABin a, int x){

    if(!a) return 0;

    if(a->valor > x) return(1 + quantosMaiores(a->esq, x) + contaNodos(a->dir));
    else return(quantosMaiores(a->dir, x));
}


void listToBTree (LInt l, ABin *a){


}

int deProcura (ABin a){

    if(!a) return 1;

    ABin esq = a->esq;
    ABin dir = a->dir;

    if(esq) if(esq->valor > a->valor) return 0;
    if(dir) if(dir->valor < a->valor) return 0;

    return (deProcura(esq) && deProcura(dir));
}
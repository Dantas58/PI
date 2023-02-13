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
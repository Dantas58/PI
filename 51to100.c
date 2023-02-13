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
#include<stdio.h>

int pesquisa (int a[], int N, int x){

    int i = 0;

    while(i<N && a[i] != x) i++;

    if(i == N) return -1;
    return i;
}

typedef struct LInt_nodo {
int valor;
struct LInt_nodo *prox;
} *LInt;

void roda (LInt *l){

    if(!*l || !(*l)->prox) return;

    LInt copia = *l;
    LInt ant = NULL;

    for(; copia->prox; ant = copia, copia = copia->prox);

    if(!ant) return;

    ant->prox = NULL;

    copia->prox = *l;
    *l = copia;
}


typedef struct ABin_nodo {
int valor;
struct ABin_nodo *esq, *dir;
} *ABin;


int nNodos (ABin a){

    if(!a) return 0;
    return(1+nNodos(a->esq)+nNodos(a->dir));
}

int apagaArvore (ABin a){

    if(!a) return 0;

    ABin esq = a->esq;
    ABin dir = a->dir;
    
    free(a);

    return(1+apagaArvore(esq)+apagaArvore(dir));
}


int apaga (ABin a, int n){

    if(!a || n == 0) return 0;
    if(n >= nNodos(a)) return apagaArvore(a);

    ABin copia = a;
    ABin aux = a;

    if(a->esq){
        while(aux->esq) {(copia) = aux; aux = aux->esq;}
            (copia)->esq = NULL;
            return nNodos(aux) + apaga(a, n-1);
    }

    else{
        while(aux->dir) {(copia) = aux; aux = aux->dir;}
        (copia)->dir = NULL;
        //free(aux);
        return nNodos(aux) + apaga(a, n-1);
    }
}

int pertence (ABin a, int x){

    if(!a) return 0;
    if(a->valor == x) return 1;
    return(pertence(a->esq, x) || pertence(a->dir, x));
}

int depth(ABin a, int x){

    if(pertence(a, x) == 0) return -1;

    int esq = 1 + depth(a->esq, x);
    int dir = 1 + depth(a->dir, x);

    if(esq<dir) return esq;
    else return dir;
}


void printList(LInt l) {
    while (l != NULL) {
        printf("%d ", l->valor);
        l = l->prox;
    }
    printf("\n");
}

void inOrderTraversal(ABin root) {
    if (root) {
        inOrderTraversal(root->esq);
        printf("%d ", root->valor);
        inOrderTraversal(root->dir);
    }
}
int main() {
    // Create a sample binary tree
    ABin root = malloc(sizeof(ABin));
    root->valor = 4;

    root->esq = malloc(sizeof(ABin));
    root->esq->valor = 2;

    root->dir = malloc(sizeof(ABin));
    root->dir->valor = 6;

    root->esq->esq = malloc(sizeof(ABin));
    root->esq->esq->valor = 1;
    root->esq->esq->esq = NULL;
    root->esq->esq->dir = NULL;

    root->esq->dir = malloc(sizeof(ABin));
    root->esq->dir->valor = 3;
    root->esq->dir->esq = NULL;
    root->esq->dir->dir = NULL;

    root->dir->esq = malloc(sizeof(ABin));
    root->dir->esq->valor = 5;
    root->dir->esq->esq = NULL;
    root->dir->esq->dir = NULL;

    root->dir->dir = malloc(sizeof(ABin));
    root->dir->dir->valor = 7;
    root->dir->dir->esq = NULL;
    root->dir->dir->dir = NULL;

    ABin copia = root;

    int x = 5;

    printf("Before deletion: ");
    inOrderTraversal(root);
    printf("\n");

    int deletedNodes = apaga(root, x);
    printf("Deleted nodes: %d\n", deletedNodes);

    printf("After deletion: ");
    inOrderTraversal(root);
    printf("\n");

    return 0;
}


/*
int main() {
    // Create a sample linked list
    LInt head = malloc(sizeof(LInt));
    head->valor = 1;

    LInt node2 = malloc(sizeof(LInt));
    node2->valor = 2;

    LInt node3 = malloc(sizeof(LInt));
    node3->valor = 3;

    LInt node4 = malloc(sizeof(LInt));
    node4->valor = 4;

    head->prox = node2;
    node2->prox = node3;
    node3->prox = node4;
    node4->prox = NULL;

 printf("Original list: ");
    printList(head);

    roda(&head);

    printf("Rotated list: ");
    printList(head);

    // Free memory
    while (head != NULL) {
        LInt temp = head;
        head = head->prox;
        free(temp);
    }

    return 0;
}
*/
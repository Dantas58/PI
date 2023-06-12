#include<stdio.h>

void swap (int v[], int x, int y){

    int aux = v[x];
    v[x] = v[y];
    v[y] = aux;
}

int menor (int v[], int N){

    int i;
    int min = v[0];
    int r;
    for(i=1; i<N; i++) if(v[i]<min){ min = v[i]; r = i;}

    return r;
}

int nesimo(int v[], int N, int i){

    int aux;

    for(i; i>0; i--){

        swap(v, menor(v, N), 0);
        aux = v[0];
        v = v+1;
        N--;
    }
    return aux;
}

typedef struct LInt_nodo {
    int valor;
    struct LInt_nodo *prox;
} *LInt;

LInt removeMaiores(LInt l, int x){

    if(!l) return NULL;

    LInt copia = l;
    LInt ant = NULL;

    for(; copia && copia->valor <= x; ant = copia, copia = copia->prox);

    if(!ant) return NULL;

    ant->prox = NULL;

    ant = copia;
    copia = copia->prox;
    for(; copia; ant = copia, copia=copia->prox) free(ant);

    return l;
}

typedef struct ABin_nodo {
int valor;
struct ABin_nodo *esq, *dir;
} *ABin;

LInt criaNodo (int x){

    LInt node = malloc(sizeof(LInt));
    node->valor = x;
    node->prox = NULL;

    return node;
}

LInt caminho(ABin a, int x){

    if(!a) return NULL;
    
    LInt lista = malloc(sizeof(LInt));
    lista->valor = a->valor;
    lista->prox = NULL;

    if(a->valor < x) a = a->dir;
    else a = a->esq;

    LInt r = lista;

    if(a->valor == x) return lista;

    while(a && a->valor != x){

        if(a->valor < x){

            LInt node = criaNodo(a->valor);
            lista->prox = node;
            lista = lista->prox;
            a = a->dir;
        }
        if(a->valor > x){

            LInt node = criaNodo(a->valor);
            lista->prox = node;
            lista = lista->prox;
            a = a->esq;
        }
    }

    if(!a) return NULL;
    else lista->prox = criaNodo(a->valor); 

    return r;
}

void inc(char s[]){

    int i = 0;
    while(s[i+1]) i++;  
    int l = i;

    while(i>=0 && s[i] == '9'){s[i] = '0'; i--;}

    if(i>=0) s[i] = s[i] + 1;

    else{
        s[0] = '1';
        s[l+1] = '0';
        s[l+2] = 0;
    } 
}

int sacos(int p[], int N, int C){

    
}


LInt createNode(int value) {
    LInt node = malloc(sizeof(LInt));
    node->valor = value;
    node->prox = NULL;
    return node;
}

void printList(LInt head) {
    LInt current = head;
    while (current != NULL) {
        printf("%d ", current->valor);
        current = current->prox;
    }
    printf("\n");
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
    LInt path = caminho(root, x);

    if (path == NULL) {
        printf("No path found to node with value %d\n", x);
    } else {
        printf("Path to node with value %d: ", x);
        while (path != NULL) {
            printf("%d ", path->valor);
            path = path->prox;
        }
        printf("\n");
    }

    // Free the memory allocated for the binary tree

    return 0;
}

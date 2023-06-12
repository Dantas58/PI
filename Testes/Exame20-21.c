#include<stdio.h>

void swap (int v[], int x, int y){

    int a = v[x];
    v[x] = v[y];
    v[y] = a;
}

int paresImpares (int v[], int N){

    int i = 0;
    int j = N-1;

    while(i<N && j>0){

        while(v[i] %2 == 0 && i<j) i++; 
        while(v[j] %2 != 0 && j>0) j--;

        if(v[j]%2==0){swap(v, j, i); j--;}

    }

    for(i=0; i<N && v[i]%2==0; i++);

    return i;
}

typedef struct lligada {
    int valor;
    struct lligada *prox;
} *LInt;

void merge (LInt *r, LInt a, LInt b){

    if(!a && b) {*r = b; return;}
    if(a && !b) {*r = a; return;}

    if(a->valor < b->valor) {*r = a; a = a->prox;}
    else {*r = b; b = b->prox;}

    LInt copia = *r;

    while(a && b){

        if(a->valor < b->valor) {copia->prox = a; a = a->prox; }
        else {copia->prox = b; b = b->prox;}

        copia = copia->prox;
    }

    if(!a) copia->prox = b; 
    if(!b) copia->prox = a;
}

void latino (int N, int m[N][N]){

    int i = 0;
    int j = 1;

    while(i<N) {m[0][i] = i+1; i++;}

    while(j<N){     
        i = 0;
        while(i<N){

            if(i == N-1) m[j][N-1] = m[j-1][0];
            //else if(m[j-1][i+1] == N) m[j][i] = 1;
            else m[j][i] = m[j-1][(i+1)];  
            //printf("%d\n", m[j][i]);
            i++;
        }
        j++;
    }
}


typedef struct nodo {
    int valor;
    struct nodo *pai, *esq, *dir;
} *ABin;


ABin next (ABin a){

    if(!a || !a->pai) return NULL;


}


typedef struct palavras {
    char *palavra;
    int nOcorr;
    struct palavras *esq, *dir;
} *Palavras;


int acrescentaPal (Palavras *p, char *pal){

    
}


int main() {
    int N = 4; // Example with N = 4
    int m[N][N];

    latino(N, m);

    // Print the resulting matrix
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }

    return 0;
}
// 1
int sumhtpo (int n) {

    int r = 0, i = 0;
    while (i<100){
        r += n;
        i++;
        if (n%2 == 0) n = n/2; else n = 1+(3*n);
    }
    return r;
}

// 2
int aparicoes(int v[], int N, int x){

    int i, cont=0;
    for(i=0; i<N; i++) if(v[i]==x) cont++;
    return cont;
}

int moda(int v[], int N, int *m){

    if(N<1) return 0;

    int i, max = 0;
    for(i=0; i<N; i++){
        int temp = aparicoes(v, N, v[i]);
        if(temp > max){max = temp; *m = v[i];}
    }

    int sec = 0;
    for(i=0; i<N; i++){
        if(v[i]!=*m){
            int temp = aparicoes(v, N, v[i]);
            if(temp == max) return 0;
        }
    }
    return max;
}

// 3
typedef struct LInt_nodo {
    int valor;
    struct LInt_nodo *prox;
} *LInt;


int procura (LInt *l, int x){

    if(!*l) return 0;

    LInt copial = *l;

    for(; copial && copial->valor != x; copial=copial->prox);

    if(!copial) return 0;

    int aux = (*l)->valor;
    (*l)->valor = x;
    copial->valor = aux;

    return 1;
}

// 4
typedef struct nodo {
    int valor;
    struct nodo *pai, *esq, *dir;
} *ABin;

int freeAB(ABin a){

    if(!a) return 0;

    int right = freeAB(a->dir);
    int left = freeAB(a->esq);
    free(a);

    return (1+right+left);
}

// 5
void caminho(ABin a){

    if(!a) return;

    ABin copia = a;
    int i = 0;
    for(; copia->pai; copia = copia->pai, i++);
    int *direcoes = malloc(i*sizeof(int));

    i = 0; copia = a;

    for(; copia->pai; copia = copia->pai){

        ABin paizin = copia->pai;
        if(copia == paizin->dir){
            direcoes[i] = 1;
            i++;
        }
        else{
            direcoes[i] = 0;
            i++;
        }
    }

    for(i-=1; i>=0; i--){
        if(direcoes[i]==1) printf("dir\n");
        else printf("esq\n");
    }

    free(direcoes);
}
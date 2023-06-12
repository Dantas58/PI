#include <stdio.h>
#include <stdlib.h>


// 2
void swapM (int *x, int *y){

    int aux = *x;
    *x = *y;
    *y = aux;
}

// 3
void swap (int v[], int i, int j){

    int aux = v[i];
    v[i] = v[j];
    v[j] = aux;
}

// 4
int soma (int v[], int N){

    int i, r = 0;
    for(i=0; i<N; i++) r += v[i];

    return r;
}

// 5
void inverteArray (int v[], int N){

    int i = 0;
    int j = N-1;
    for(i; i<j; i++, j--) swap(v, i, j);

}

void inverteArray2 (int v[], int N){

    int i = 0;
    int j = N-1;
    for(i; i<j; i++, j--) swapM(v+i, v+j);

}

// 6
int maximum (int v[], int N, int *m){

    if(N<1) return -1;
    *m = v[0];
    int i = 1;

    for(i; i<N; i++){
        if(v[i]>*m) *m = v[i];
    }
    return 0;
}

// 7
void quadrados (int v[], int N){    // cringe

    if(N<1) return;

    int i = -1;
    for(i; i<N-1; i++) v[i+1] = i*i+(2*i+1);
}

// 8

#include <stdio.h>
#include <stdlib.h>

typedef struct aluno {
    int numero;
    char nome[100];
    int miniT [6];
    float teste;
} Aluno;


// 1
int nota (Aluno a){     // ya nao sei o metodo de avaliação

    int mT = 0, i;
    for(i=0; i<6; i++) mT += a.miniT[i];

    return (int)(0.3*((float)mT) + 0.7*a.teste);
}

// 2
int procuraNum (int num, Aluno t[], int N){

    int i;
    for(i=0; i<N && t[i].numero<=num; i++) 
        if(t[i].numero == num){return i;}

    return -1;
}

// 3
int maiorInd (Aluno t[], int N){

    int i, max = 0, j;
    for(i=0; i<N; i++) if(t[i].numero > max){ max = t[i].numero; j=i;}

    return j;
}

void swap(Aluno t[], int x, int y){

    Aluno aux = t[x];
    t[x] = t[y];
    t[y] = aux;
}

void ordenaPorNum (Aluno t [], int N){  

    int i, j = N;
    for(i=0; i<N; i++){swap(t, maiorInd(t, j), j-1); j--;}
    
}

// 4
void criaIndPorNum (Aluno t [], int N, int ind[]){

}

// 5
void imprimeTurma (int ind[], Aluno t[], int N){

    int i, j;
    for(i=0; i<N; i++){

    printf("%s %d\n", t[ind[i]].nome, t[ind[i]].numero);
    for(j = 0; j<6; j++) printf("%d ", t[ind[i]].miniT[j]);
    printf("+ %lf\n", t[ind[i]].teste);
    }
}

// 6
int procuraNumII (int num, Aluno t[], int N, int ind[]){    // xd

    int i;

    for (i=0 ; i<N && t[ind[i]].numero <= num ; i++)
        if (t[ind[i]].numero == num) return ind[i];

    return -1;
    
}

// 7
void criaIndPorNome (Aluno t [], int N, int ind[]){     // nao me apetece faço depois


}
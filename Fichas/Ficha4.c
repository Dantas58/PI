#include <stdio.h>
#include <stdlib.h>


// 1
int contaVogais (char *s){

    int i, cont = 0;
    for(i=0; s[i]; i++)
        if(s[i] == 'A' ||s[i] == 'E' ||s[i] == 'I' ||s[i] == 'O' ||s[i] == 'U' ||
           s[i] == 'a' ||s[i] == 'e' ||s[i] == 'i' ||s[i] == 'o' ||s[i] == 'u' ) cont++;

    return cont;
}

// 2

int isVowel (char c){

    if(c == 'A' ||c == 'E' ||c == 'I' ||c == 'O' ||c == 'U' ||
        c == 'a' ||c == 'e' ||c == 'i' ||c == 'o' ||c == 'u' ) return 1;
    
    return 0;
}

int retiraVogaisRepCringe (char *s){    // dar malloc para o char *c e free no fim

    int i, aux, j=0, cont = 0;
    char *c;

    for(i=0; s[i]; i++){
        if(isVowel(s[i]) && s[i] == s[i+1]){
            for(aux = i+1; s[aux+1] == s[i]; aux++) cont++;
            cont++;
            i = aux;
        }
        c[j] = s[i];
        j++;
    }

    for(i=0; i<=j; i++) s[i] = c[i];
    //printf("%s\n", s);
    return cont;
}

int retiraVogaisRep (char *s){  // oops nao li o enunciado

    int i, j, cont = 0;

    for(i=0; s[i+1]; i++){
        if(isVowel(s[i]) && s[i] == s[i+1]){
            for(j = i+1; s[j]; j++) s[j] = s[j+1];
            cont++;
            i--;
        }
    }
    return cont;
}

// 3
int duplicaVogais (char *s){

    int i, j=0, cont=0;

    //for(i=0; s[i]; i++);
    //for(j=0; s[j]; j++) if(isVowel(s[j])) cont++;
    //char *c; // = malloc((i+cont)*sizeof(char)); nao entendo 

    char c[100] = {0};

    for(i=0; s[i]; i++){
        if(isVowel(s[i])){
            c[j] = c[j+1] = s[i];
            j += 2;
            cont++;
        }
        else{
            c[j] = s[i];
            j++;
        }
    }
    for(i=0; i<=j; i++) s[i] = c[i];
    //free(c);
    return cont;
}


// Arrays Ordenados

// 1
int ordenado (int v[], int N){

    for(N; v[N]>=v[N-1] && v[N-1]; N--);
    return (N==1);
}

// 2
void merge (int a[], int na, int b[], int nb, int r[]){

    int i, j, x=0;
    for(i=0, j=0; i<na && j<nb; x++){
        if(a[i]<b[j]){r[x] = a[i]; i++;}
        else{r[x] = b[j]; j++;}
    }

    if(j>=nb) for(i; i<na; i++) {r[x] = a[i]; x++;}
    if(i>=na) for(j; j<nb; j++) {r[x] = b[j]; x++;}
}

// 3
int partition (int v[], int N, int x){

    int i, cont = 0;
    int j;
    int aux[N];

    for(i=0; i<N; i++)
        if(v[i]<=x){
            aux[cont] = v[i]; 
            cont++;
        }
    
    j = cont;

    for(i=0; i<N; i++)
        if(v[i]>x){
            aux[j] = v[i];
            j++;
        }
    

    for(j = 0; j<N; j++) v[j] = aux[j];
    return cont;
}
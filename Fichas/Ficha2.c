#include <stdio.h>
#include <stdlib.h>

// 1
float multInt1 (int n, float m){

    float r = 0;
    for(n; n>0; n--) r *= m;

    return r;
}

// 2
float multInt2 (int n, float m){

    float r = 0;

    for(n; n>0; n/=2, m*=2){
        if(n%2!=0) r+=m; //count++;
    }
    return r;
}

// 3
int mdc1 (int a, int b){

    if(b==a) return a;
    int x = a;

    for(x; x>0; x--) if(a%x == 0 && b%x == 0) return x;

    return -1;
}

// 4
int mdc2 (int a, int b){

    if(b==a) return a;
    // int i = 0;

    while(a>0 && b>0){      // a!=b para menos 1 iteraçao e só return a
        if(a>b) a -= b;
        else b -= a;
        //i++;
    }

    if(!a) return b;
    else return a;
}

// 5
int mdc2 (int a, int b){

    if(b==a) return a;
    // int i = 0;

    while(a!=b){
        if(a>b) a %= b;
        else b %= a;
        //i++;
    }

    return a;
}

// 6
int fib1 (int n){

    if(n<2) return n;

    return(fib1(n-1) + fib(n-2));
}

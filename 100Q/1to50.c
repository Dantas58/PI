

// 7
char *mystrcat (char s1[], char s2[]){

    int i;
    for(i = 0; s1[i]!='\0'; i++);
    int j = 0;
    for(j; s2[j]!='\0'; j++){
        s1[i] = s2[j];
        i++;
    }
    s1[i] = '\0';

    return s1;
}


// 8
char *mystrcpy (char *dest, char source[]){

    int i;
    for(i = 0; source[i]!='\0'; i++) dest[i] = source[i];
    dest[i] = '\0';

    return dest;
}


// 9
int mystrcmp (char s1[], char s2[]){

    int i;
    for(i = 0; s1[i]!='\0'; i++){
        if(s1[i]>s2[i]) return 1;
        else if(s1[i]<s2[i]) return -1;
    }

    if(s2[i]) return -1;

    return 0;
}


// 10
char *mystrstr (char s1[], char s2[]){

    int i, j, c;
    
    if(s2[0] == '\0') return s1;
    
    for(i = 0; s1[i]!='\0';i++){

        for(j = 0, c=i; s2[j]!='\0'; j++, c++) if(s1[c]!=s2[j]) break;

        if(s2[j] == '\0') return s1+i;
    }
    return NULL;
}


// 11
void strrev (char s[]){

    int i, l, j, aux;
    for(l=0; s[l]!='\0'; l++);

    for(i=0, j=l-1; i<=(l-1)/2; i++, j--){
        aux = s[i];
        s[i] = s[j];
        s[j] = aux;
    }
}


// 12

void strnoV (char s[]){

    int i = 0;
    for(i; s[i]!='\0'; i++){
        if(s[i] == 'a'||s[i] == 'e'||s[i] == 'i'||s[i] == 'o'||s[i] == 'u'||
           s[i] == 'A'||s[i] == 'E'||s[i] == 'I'||s[i] == 'O'||s[i] == 'U'){
            int j;
            for(j = i; s[j]!='\0'; j++) s[j] = s[j+1];
            i--;
        }
    }
}


// 13

int quantas (char t[], int n){

    int i = 0;
    for(i; t[i]!=' ' && t[i]!='\0'; i++);

    return i>n;
}

void truncW (char t[], int n){

    int i; 
    for(i=0; t[i]!='\0'; i++){
        if(quantas(t+i, n)){
            int j; 
            for(j=i+n; t[j]!='\0'; j++) t[j] = t[j+1];
            i--;
        }
    }
}


// 14
char charMaisfreq (char s[]){

    if(!s) return 0;

    int i, j, cont, max = 0;
    char r = s[0];

    for(i = 0; s[i]!='\0'; i++){
        cont = 0;

        for(j = 0; s[j]!='\0'; j++){
            if(s[j] == s[i]) cont++;
        }

        if(cont>max){max = cont; r = s[i];}
    }
    return r;
}

// 15
int iguaisConsecutivos (char s[]){

    int i, j, cont, max = 0;

    for(i=0; s[i]; i++){ 
        cont = 1;
        for(j=i; s[j] == s[j+1]; j++) cont++;
        if(cont>max) max = cont;
    }
    return max;
}


// 16
int difConsecutivos (char s[]){  // ?

    int i, j, cont, max = 0;

    for(i=0; s[i]; i++){ 
        cont = 1;
        for(j=i; s[j] != s[j+1] && s[j]; j++) cont++;
        if(cont>max) max = cont;
    }
    return max;
}


// 17
int maiorPrefixo (char s1 [], char s2 []){

    int i;
    for(i = 0; s1[i] && s2[i]; i++) if(s1[i]!=s2[i]) break;

    return i;
}


// 18
int maiorSufixo (char s1 [], char s2 []){

    int i,j;

    for(i = 0; s1[i]; i++);
    i--;
    for(j = 0; s2[j]; j++);
    j--;

    int cont = 0;
    for(i, j; i>=0 && j>=0; i--, j--){
        if(s1[i]==s2[j]) cont++;
        else break;
    }
    return cont;
}


// 19
int sufPref (char s1[], char s2[]) {
    int ans = 0, i, j = 0;
    for(i = 0; s1[i]; i++) {
        if(s1[i] == s2[j++]) ans++;     // vai procurando ate serem iguais e caso deixem de ser 
        else ans = j = 0;               // da reset para 0 
    }
    return ans;
}


// 20
int contaPal (char s[]){

    int i, r=0;
    for(i = 0; s[i]; i++){
        if(s[i]!=' ' && s[i]!='\n'){
            r++; 
            for(i; s[i+1]!=' ' && s[i+1]; i++);
        }
    }
    return r;
}


// 21
int contaVogais (char s[]){

    int i = 0;
    int r = 0;
    for(i; s[i]; i++){
        if(s[i] == 'a'||s[i] == 'e'||s[i] == 'i'||s[i] == 'o'||s[i] == 'u'||
           s[i] == 'A'||s[i] == 'E'||s[i] == 'I'||s[i] == 'O'||s[i] == 'U') r++;
    }
    return r;
}


// 22
int contida (char a[], char b[]){

    int i,j;
    for(i=0; a[i]; i++){
        for(j=0; b[j]; j++) if(b[j] == a[i]) break;

        if(!b[j]) return 0;
    }
    return 1;
}


// 23
int palindorome (char s[]){ // ?
    
    int i=0, j;

    for(j = 0; s[j+1]; j++);
    
    for(i,j; i<(j/2)+1; i++, j--){
        if(s[i]!=s[j]) return 0;
    }
    return 1;
}


// 24
int remRep (char x[]){

    int i, j;
    for(i = 0; x[i]; i++){
        if(x[i+1]==x[i]){
            for(j=i; x[j]; j++) x[j] = x[j+1];
            i--;
        }
    }
    for(j = 0; x[j]; j++);
    return j;
}


// 25
int limpaEspacos (char t[]){

    int i, j;
    for(i = 0; t[i]; i++){
        if(t[i]==' ' && t[i+1]==' '){
            for(j=i; t[j]; j++) t[j] = t[j+1];
            i--;
        }
    }
    for(j=0; t[j]; j++);
    return j;
}


// 26
void insere (int v[], int N, int x){

    int i;
    for(i=0; i<N && v[i]<x; i++);

    int l = N;
    for(l; l>i; l--) v[l] = v[l-1];

    v[i] = x;
}


// 27
void merge (int r [], int a[], int b[], int na, int nb){

    int i, j, x=0;
    for(i=0, j=0; i<na && j<nb; x++){
        if(a[i]<b[j]){r[x] = a[i]; i++;}
        else{r[x] = b[j]; j++;}
    }

    if(j>=nb) for(i; i<na; i++) {r[x] = a[i]; x++;}
    if(i>=na) for(j; j<nb; j++) {r[x] = b[j]; x++;}
}


// 28
int crescente (int a[], int i, int j){

    for(i; i<j; i++) if(a[i]>a[i+1]) return 0;

    return 1;
}


// 29
int retiraNeg (int v[], int N){

    int i,j;

    for(i=0; i<N; i++){
        if(v[i]<0){
            for(j=i; j<N; j++)v[j] = v[j+1];
            N--; i--;
        }
    }
    return N;
}


// 30
int menosFreq (int v[], int N){

    int i, j, cont, max=__INT_MAX__, r;
    for(i=0; i<N; i++){
        cont = 0;
        for(j=0; j<N; j++) if(v[j] == v[i]) cont++;
        if(cont<max){max = cont; r=v[i];}
    }
    return r;
}


// 31
int maisFreq (int v[], int N){  // mesmo a pedir para dar copy paste da anterior
    int i, j, cont, max=0, r;
    for(i=0; i<N; i++){
        cont = 0;
        for(j=0; j<N; j++) if(v[j] == v[i]) cont++;
        if(cont>max){max = cont; r=v[i];}
    }
    return r;
}


// 32
int maxCresc (int v[], int N){

    int i, cont=1, max=0;
    for(i = 0; i<N; i++){
        if(v[i]>v[i+1]){
            if(cont>max) max=cont;
            cont = 0;
        }
        cont++;
    }
    return max;
}


// 33
int elimRep (int v[], int n){

    int i, j, k;
    for(i=0; i<n; i++){
        for(j=i+1; j<n; j++){
            if(v[j]==v[i]){
                for(k=j; k<n; k++) v[k] = v[k+1];
                n--;
                j--;
            }
         }
    }
    return n;
}


// 34
int elimRepOrd (int v[], int n){    // a de cima da igual mas o objetivo é ser mais eficiente (?)

    int i;                          // standby
    for(i=0; i<n; i++){

    }
}


// 35
int comunsOrd (int a[], int na, int b[], int nb){   // ficou confuso

    int i, j=0, r=0;
    for(i=0; i<na; i++){
            int k = j;
            for(j; j<nb; j++){
                if(b[j]==a[i]){r++; j++; break;}
            }
            if(j==nb) j=k;                          // se nao encontrar volta ao valor inicial
         }
    return r;
}   


// 36
int comuns (int a[], int na, int b[], int nb){

    int i,j,r=0;
    for(i=0;i<na;i++){
        for(j=0;j<nb;j++){
            if(a[i]==b[j]){
                r++;
                break;
            }
        }
    }
    return r;
}


// 37
int minInd (int v[], int n){

    int i, min = 0;

    for(i=1; i<n; i++) if(v[i]<v[min]) min = i;

    return min;
}


// 38
void somasAc (int v[], int Ac [], int N){

    int i, j, x=0;
    for(i=0; i<N; i++){
        for(j=0; j<=i; j++) x+=v[j];

        Ac[i] = x;
        x=0;
    }
}


// 39
int triSup (int N, float m [N][N]){

    int i, j;

    for (i=0 ; i<N ; i++)
        for (j=i+1 ; j<N ; j++)
            if (m[i][i] == 0 || m[j][i] != 0) return 0;

    return 1;
}


// 40
void transposta (int N, float m [N][N]){

    int i,j;
    for(i=0; i<N; i++){
        for(j=i+1; j<N; j++){
            int aux = m[i][j];
            m[i][j] = m[j][i];
            m[j][i] = aux;
        }
    }
}


// 41
void addTo (int N, int M, int a [N][M], int b[N][M]){

    int i, j;
    for(i=0; i<N; i++)
        for(j=0; j<M; j++)
            a[i][j] += b[i][j];
}


// 42
int unionSet (int N, int v1[N], int v2[N], int r[N]){

    int i;
    for(i=0; i<N; i++) if(v1[i] || v2[i]) r[i] = 1;

    return 1;
}


// 43
int intersectSet (int N, int v1[N], int v2[N], int r[N]){

    int i;
    for(i=0; i<N; i++) r[i] = (v1[i]&&v2[i]);

    return 1;
}


// 44
int intersectMSet (int N, int v1[N], int v2[N], int r[N]){

    int i;
    for(i=0; i<N; i++){
        if(v1[i] && v2[i]){
            if(v1[i]<v2[i]) r[i] = v1[i];
            else r[i] = v2[i];
        }    
    }
    return 1;
}


// 45
int unionMSet (int N, int v1[N], int v2[N], int r[N]){

    int i;
    for(i=0; i<N; i++){
        if(v1[i] || v2[i]){
            if(v1[i]<v2[i]) r[i] = v2[i];
            else r[i] = v1[i];
        }    
    }
    return 1;
}


// 46
int cardinalMSet (int N, int v[N]){

    int i, r=0;
    for(i=0; i<N; i++) r += v[i];

    return r;
}


// 47 
typedef enum movimento {Norte, Oeste, Sul, Este} Movimento;
typedef struct posicao {
    int x, y;
} Posicao;

Posicao posFinal (Posicao inicial, Movimento mov[], int N){

    int i;
    Posicao final = inicial;
    for(i=0; i<N; i++){
        if(mov[i] == Norte) final.y++;
        else if(mov[i] == Sul) final.y--;
        else if(mov[i] == Este) final.x++;
        else if(mov[i] == Oeste) final.x--;
    }
    return final;
}


// 48
int caminho (Posicao inicial, Posicao final, Movimento mov[], int N){

    int i=0;
    Posicao aux = inicial;
    
    while(i<=N && (final.x!=aux.x || final.y!=aux.y)){

        if(aux.y > final.y){aux.y--; mov[i]=Sul; i++;}
        else if(aux.y<final.y){aux.y++; mov[i]=Norte; i++;}

        if(aux.x > final.x){aux.x--; mov[i]=Oeste; i++;}
        else if(aux.x<final.x){aux.x++; mov[i]=Este; i++;}
    }

    if(i>N) return -1;

    return i;
}


// 49
int maisCentral (Posicao pos[], int N){

    int i, j;
    int min = __INT_MAX__;
    int r = -1;
    for(i=0; i<N; i++){
        j = abs(pos[i].x) + abs(pos[i].y);
        if(j < min){min = j; r = i;}
    }
    return r;
}


// 50
int vizinhos (Posicao p, Posicao pos[], int N){ // nao funfatings nao sei porque

    int i, r = 0;
    for(i=0; i<N; i++){
        if(( (abs(p.x - pos[i].x)==1 && abs(p.y - pos[i].y)==0) || (abs(p.x - pos[i].x)==0 && abs(p.y - pos[i].y)==1)) 
        && (p.x!=pos[i].x && p.y!=pos[i].y)) r++;
    }
    return r;
}
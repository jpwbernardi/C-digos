/*
S: P - V[i] + C[0]                                                     , se n == N e i == M
   min(P - V[i] + C[0], C[i])                                          , se n == N
   P - V[i] + C[0] + S(1, n + 1)                                       , se i == M
   min(P - V[i] + C[0] + PD(1, n + 1), C[i] + PD(i + 1, n + 1);        , caso contrario
*/

#include <stdio.h>
#include <algorithm>
using namespace std;

#define INF 112345678
#define MAX 2012

int N, I, M, P;
int S[MAX][MAX];
int V[MAX], C[MAX];
int T[MAX][MAX]; //Guarda trocas

/* Recursivo
int PD(int i, int n){
    if(S[i][n] != INF) return S[i][n];
    if(i == M && n == N) return S[i][n] = P - V[i] + C[0];
    if(n == N) return S[i][n] = min(P - V[i] + C[0], C[i]);
    if(i == M) return S[i][n] = P - V[i] + C[0] + PD(1, n + 1);
    return S[i][n] = min(P - V[i] + C[0] + PD(1, n + 1), C[i] + PD(i + 1, n + 1));
} */

void PD(){
    int n, i;
    for(n = N; n >= 1; n--)
        for(i = M; i >= 0; i--)
            if(n == N && i == M){ T[i][n] = 1; S[i][n] = P - V[i] + C[0]; }
            else if(n == N && P - V[i] + C[0] <= C[i]){ T[i][n] = 1; S[i][n] = P - V[i] + C[0]; }
            else if(n == N) { T[i][n] = 0; S[i][n] = C[i]; }
            else if(i == M) { T[i][n] = 1; S[i][n] = P - V[i] + C[0] + S[1][n + 1]; }
            else if(P - V[i] + C[0] + S[1][n + 1] <= C[i] + S[i + 1][n + 1]){ T[i][n] = 1; S[i][n] = P - V[i] + C[0] + S[1][n + 1]; }
            else { T[i][n] = 0; S[i][n] = C[i] + S[i + 1][n + 1]; }
}

int main(void){
    int i, n, first;
    while(scanf("%d %d %d %d", &N, &I, &M, &P) != EOF){
        for(i = 0; i < M; i++) scanf("%d", &C[i]);
        for(i = 1; i <= M; i++) scanf("%d", &V[i]);
        PD();
        printf("%d\n", S[I][1]);
        for (i = I, first = n = 1; n <= N; i = T[i][n] ? 1 : i + 1, n++) {
          if (T[i][n]) {
            if (first) first = 0;
            else printf(" ");
            printf("%d", n);
          }
        }
        if (first) printf("0");
        printf("\n");
    }
    return 0;
}

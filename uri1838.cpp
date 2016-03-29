/*
S:  0                                                     , se t == 3600 || n == N
    S(n + 1, t)                                           , se in[n] < t
    max(S(n + 1, f[n]) + (f[n] - in[n]), pd(n + 1, t))    , cc
*/

#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define MAX 1123
#define INICIO 0
#define FIM 1

int N;
int R[MAX][2];
int S[MAX][3612];

int cmp(const void *a, const void *b){
    return ((int *)a)[INICIO] - ((int *)b)[INICIO];
}

int pd(int n, int t){
    if(t == 3600 || n == N) return 0;
    if(S[n][t] != -1) return S[n][t];
    if(R[n][INICIO] < t) return S[n][t] = pd(n + 1, t);
    return S[n][t] = max(pd(n + 1, R[n][FIM]) + (R[n][FIM] - R[n][INICIO]), pd(n + 1, t));
}


int main(void){
    scanf("%d", &N);
    memset(S, -1, sizeof(S));
    for(int i = 0; i < N; i++) scanf("%d %d", &R[i][INICIO], &R[i][FIM]);
    qsort(R, N, sizeof(int) * 2, &cmp);
    // for(int i = 0; i < N; i++){
    //     printf("%d\n", R[i][INICIO]);
    // }
    printf("%d\n", pd(0, 1));
    return 0;
}

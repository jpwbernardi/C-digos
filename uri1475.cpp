#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
using namespace std;

#define MAX 1123
#define INF 1123456789

int N, C, T1, T2, inicio;
int F[MAX * 2];
long long S[MAX * 2], resp;


int prox(int i, int T){
    int a = i, b = inicio + N, m;
    while(a < b){
        m = (a + b) / 2;
        if(F[m] <= F[i] + T) a = m + 1;
        else b = m;
    }
    return a;
}

long long pd(int i){
    if(S[i] != -1) return S[i];
    if(i - inicio >= N) return 0;
    return S[i] = min(pd(prox(i, T1)) + T1, pd(prox(i, T2)) + T2);
}

int cmp(const void *a, const void *b){
    return *(int *)a - *(int *)b;
}

int main(void){
    int i;
    while(scanf("%d %d %d %d", &N, &C, &T1, &T2) != EOF){
        resp = INF;
        for(i = 0; i < N; i++){
            scanf("%d", &F[i]);
            F[i + N] = F[i] + C;
        }
        qsort(F, N * 2, sizeof(int), &cmp);
        for(inicio = 0; inicio < N; inicio++){
            memset(S, -1, sizeof(S));
            resp = min(resp, pd(inicio));
        }
        printf("%lld\n", resp);
    }
    return 0;
}

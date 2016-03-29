/*
S: 1                                    , se k == 0
   0                                    , se r == 0
   S(r - 1, k)                          , se k < dG[r]
   S(r - 1, k) || S(r - 1, k - dG[r])   , cc;
*/

#include<stdio.h>
#include<string.h>

#define MAX 112

int K, R;
int dG[MAX];
int S[(MAX * MAX) / 2][MAX];

int pd(int k, int r){
    if(k == 0) return 1;
    if(r == 0) return 0;
    if(S[k][r] != -1) return S[k][r];
    if(dG[r] > k) return S[k][r] = pd(k, r - 1);
    return S[k][r] = pd(k, r - 1) || pd(k - dG[r], r - 1);
}

int main(void){
    int i, u, v;
    while(scanf("%d %d", &R, &K) != EOF){
        memset(dG, 0, sizeof(dG));
        memset(S, -1, sizeof(S));
        for(i = 0; i < K; i++){
            scanf("%d %d", &u, &v);
            dG[u]++; dG[v]++;
        }
        printf("%s\n", pd(K, R) ? "S" : "N");
    }
    return 0;
}

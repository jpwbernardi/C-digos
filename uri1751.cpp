//Somamos o peso do caminho total para passar por todos os amigos e subtraimos aquele que vai "mais fundo" e.e

#include <stdio.h>
#include <string.h>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

#define MAX 112345
typedef pair< int, int > ii;

int N, F;
int ret, soma;
int f[MAX];
vector< ii > LG[MAX];

int dfs(int u, int deep){
    int v, p, i, flag = f[u], fl;
    if(flag) ret = max(ret, deep);
    for(i = 0; i < (int)LG[u].size(); i++){
        v = LG[u][i].first; p = LG[u][i].second;
        if((fl = dfs(v, deep + p))){ soma += p; flag |= fl; }
    }
    return flag;
}

int main(void){
    int u, v, p, i;
    scanf("%d %d", &N, &F);
    memset(f, 0, sizeof(f));
    for(i = 1; i < N; i++){
        scanf("%d %d %d", &u, &v, &p);
        LG[u].push_back(ii(v, p));
    }
    while(F--){ scanf("%d", &u); f[u] = 1; }
    soma = ret = 0;
    dfs(1, 0);
    printf("%d\n", soma - ret);
    return 0;
}

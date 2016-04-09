#include <stdio.h>
#include <string.h>

#define MAX 1123

int N, M, count;
char nota[MAX], vis[MAX];
int LG[MAX][MAX], dG[MAX];

void dfs(int u){
    int i, v;
    vis[u] = 1;
    if(nota[u] == 'B') count++;
    for(i = 0; i < dG[u]; i++){
        v = LG[u][i];
        if(!vis[v]) dfs(v);
    }
}

int main(void){
    int u, v, flag, i;
    while(scanf("%d %d", &N, &M) != EOF){
        for(i = 0; i < N; i++) scanf(" %c", &nota[i]);
        memset(dG, 0, sizeof(dG));
        memset(vis, 0, sizeof(vis));
        while(M--){
            scanf("%d %d", &u, &v); u--; v--;
            LG[u][dG[u]++] = v; LG[v][dG[v]++] = u;
        }
        for(flag = i = 0; i < N; i++)
            if(!vis[i]) { count = 0; dfs(i); flag |= (count & 1); }
        printf("%s\n", flag ? "N" : "Y");
    }
    return 0;
}

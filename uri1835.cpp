#include <stdio.h>
#include <string.h>

#define MAX 1123

int N, M, T, caso;
int u, v, resp;
int LG[MAX][MAX], dG[MAX];
char ok[MAX];

void dfs(int u){
    ok[u] = 1;
    for(int i = 0; i < dG[u]; i++)
        if(!ok[LG[u][i]]) dfs(LG[u][i]);
}

int main(void){
    scanf("%d", &T); caso = 1;
    while(T--){
        resp = -1;
        memset(dG, 0, sizeof(dG));
        memset(ok, 0, sizeof(ok));
        scanf("%d %d", &N, &M);
        while(M--){
            scanf("%d %d", &u, &v);
            LG[u][dG[u]++] = v; LG[v][dG[v]++] = u;
        }
        // for(int i = 1; i <= N; i++){
        //     printf("\n%d: ", i);
        //     for(int j = 0; j < dG[i]; j++){
        //         printf("%d, ", LG[i][j]);
        //     }
        // }
        for(int i = 1; i <= N; i++)
            if(!ok[i]) { resp++; dfs(i); }
        printf("Caso #%d: ", caso++);
        if(resp) printf("ainda falta(m) %d estrada(s)\n", resp);
        else printf("a promessa foi cumprida\n");
    }
    return 0;
}

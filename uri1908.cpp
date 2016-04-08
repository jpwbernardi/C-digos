#include <stdio.h>
#include <string.h>

#define MAX 11234
#define INF 112345678

int N, K, L;
char AG[MAX][MAX];
int LG[MAX][MAX], dG[MAX], dist[MAX], fila[MAX];

int bfs(int s, int t) {
    int inic, fim, u, i, v;
    for (u = 0; u < N; u++) dist[u] = INF;
    fila[inic = fim = 0] = s; dist[s] = 0;
    while (inic <= fim) {
        u = fila[inic++];
        for (i = 0; i < dG[u]; i++) {
            v = LG[u][i];
            if (dist[v] == INF) {
                dist[v] = dist[u] + 1;
                fila[++fim] = v;
            }}}
    return dist[t];
}

int main(void){
    int u, v, i, j, L[MAX], tL, topo;
    scanf("%d %d", &N, &K);
    memset(dG, 0, sizeof(dG));
    memset(AG, 0, sizeof(AG));
    while(K--){
        scanf("%d", &tL);
        for(i = 0; i < tL; i++) scanf("%d", &L[i]);
        for(i = 0; i < tL; i++)
            for(j = i + 1; j < tL; j++) {
                u = L[i] - 1; v = L[j] - 1;
                if(!AG[u][v]) {
                    LG[u][dG[u]++] = v; LG[v][dG[v]++] = u;
                    AG[u][v] = 1; AG[v][u] = 1;
                  }}}
    printf("%d\n", bfs(0, N - 1));
    // for(i = 1; i <= N; i++){
    //     printf("%d: ", i);
    //     for(j = 0; j < dG[i]; j++)
    //         printf("[%d]", LG[i][j]);
    //     printf("\n");
    // }
    return 0;
}

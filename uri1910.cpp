#include <stdio.h>
#include <string.h>

#define MAX 112345
#define INF 112345678
#define verifica(x) (x > 0 && x <= 100000 && dist[x] == INF && !proibidos[x])

int O, D, K;
char proibidos[MAX];
int dist[MAX], fila[MAX];


int main(void) {
    int tmp, i, inicio, fim, u, v;
    while (scanf("%d %d %d", &O, &D, &K), O) {
        for(i = 0; i < MAX; i++) dist[i] = INF;
        memset(proibidos, 0, sizeof(proibidos));
        while (K--) { scanf("%d", &tmp); proibidos[tmp] = 1; }
        fila[dist[O] = inicio = fim = 0] = O;
        while (inicio <= fim) {
            u = fila[inicio++];
            if(u == D) break;
            v = u + 1;
            if(v > 0 && v <= 100000 && dist[v] == INF && !proibidos[v]) { fila[++fim] = v; dist[v] = dist[u] + 1; }
            v = u - 1;
            if(v > 0 && v <= 100000 && dist[v] == INF && !proibidos[v]) { fila[++fim] = v; dist[v] = dist[u] + 1; }
            v = u * 2;
            if(v > 0 && v <= 100000 && dist[v] == INF && !proibidos[v]) { fila[++fim] = v; dist[v] = dist[u] + 1; }
            v = u * 3;
            if(v > 0 && v <= 100000 && dist[v] == INF && !proibidos[v]) { fila[++fim] = v; dist[v] = dist[u] + 1; }
            v = u / 2;
            if(!(u % 2) && v > 0 && v <= 100000 && dist[v] == INF && !proibidos[v]) { fila[++fim] = v; dist[v] = dist[u] + 1; }
        }
        printf("%d\n", dist[D] == INF ? -1 : dist[D]);
    }
    return 0;
}

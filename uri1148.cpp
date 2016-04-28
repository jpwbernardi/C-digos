#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

#define MAX 512
#define INF 112345678

typedef pair< int, int > ii;

int N, E, K;
int AG[MAX][MAX], LG[MAX][MAX], dG[MAX], dist[MAX];

void dijkstra(int s, int T) {
  int u, i, v, ok[MAX], peso;
  priority_queue< ii, vector<ii>, greater<ii> > Q;
  memset(ok, 0, sizeof(ok));
  for (u = 0; u < MAX; u++) dist[u] = INF;
  dist[s] = 0; Q.push(ii(0, s));
  while (!Q.empty()) {
    // printf("u: %d\n", u);
    u = Q.top().second; Q.pop();
    if (ok[u]) continue; ok[u] = 1;
    for (i = 0; i < dG[u]; i++) {
      v = LG[u][i]; peso = AG[u][v];
      if (dist[v] > dist[u] + peso) {
        dist[v] = dist[u] + peso;
        Q.push(ii(dist[v], v));
      }}}}

int main(void) {
  int u, v, c;
  while (scanf("%d %d", &N, &E), N){
    memset(AG, 0, sizeof(AG)); memset(dG, 0, sizeof(dG));
    while (E--) {
      scanf("%d %d %d", &u, &v, &c); u--; v--;
      AG[u][v] = c; LG[u][dG[u]++] = v;
      if(AG[v][u]) AG[u][v] = AG[v][u] = 0;
    }
    scanf("%d", &K);
    while (K--) {
      scanf("%d %d", &u, &v); u--; v--;
      dijkstra(u, v);
      if(dist[v] == INF) printf("Nao e possivel entregar a carta\n");
      else printf("%d\n", dist[v]);
    }
    printf("\n");
  }
  return 0;
}

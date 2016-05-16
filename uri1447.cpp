#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <utility>
#include <queue>
using namespace std;

#define MAX 112
#define INF (1 << 30)

typedef pair<int, int> ii;

int N, M;
int D, K;
int LG[MAX][MAX], AG[MAX][MAX], AR[MAX][MAX], dist[MAX];
int d[MAX], ok[MAX], pai[MAX];

int dijkstra(int s, int t) {
  int c;
  int u, v, i;
  memset(ok, 0, sizeof(ok));
  memset(pai, -1, sizeof(pai));
  for (u = 0; u < N; u++) dist[u] = INF;
  priority_queue<ii, vector<ii>, greater<ii> > Q;
  Q.push(ii(0, s)); dist[s] = 0;
  while (!Q.empty()) {
    u = Q.top().second; Q.pop();
    if (u == t) return dist[u];
    if (ok[u]) continue; ok[u] = 1;
    for (i = 0; i < d[u]; i++) {
      v = LG[u][i]; c = AG[u][v];
      if (AR[u][v] && dist[v] > dist[u] + c) {
        dist[v] = dist[u] + c; pai[v] = u;
        Q.push(ii(dist[v], v));
      }}}
  return -1;
}

int ffek(int s, int t) {
  int f, u, delta, flag = 1;
  for (f = 0; flag && dijkstra(s, t) != -1; f += delta) {
    for (delta = K, u = t; u != s; u = pai[u])
      delta = min(delta, AR[pai[u]][u]);
    D -= delta;
    if (D <= 0) { delta = (delta + D); flag = 0; }
    for (u = t; u != s; u = pai[u])
      { AR[pai[u]][u] -= delta; AR[u][pai[u]] += delta; }
  }
  return !flag;
}

int custo() {
  int u, i, v, tot = 0;
  for (u = 0; u < N; u++)
    for (i = 0; i < d[u]; i++) {
      v = LG[u][i];
      if (AR[u][v] < K) tot += (K - AR[u][v]) * AG[u][v];
    }
  return tot;
}


int main(void) {
  int u, v, p, caso = 0, i;
  while (scanf("%d %d", &N, &M) != EOF) {
    caso++; memset(d, 0, sizeof(d));
    while (M--) {
      scanf("%d %d %d", &u, &v, &p); u--; v--;
      LG[u][d[u]++] = v; AG[u][v] = p;
      LG[v][d[v]++] = u; AG[v][u] = p;
    }
    scanf("%d %d", &D, &K);
    for (u = 0; u < N; u++)
      for (i = 0; i < d[u]; i++)
        { v = LG[u][i]; AR[u][v] = K; }
    printf("Instancia %d\n", caso);
    if(ffek(0, N - 1)) printf("%d\n\n", custo());
    else printf("impossivel\n\n");
  }
  return 0;
}

#include <stdio.h>
#include <string.h>
#include <queue>
#include <vector>
#include <utility>
using namespace std;

#define MAX 512
#define INF 112345678

typedef pair< int, int > ii;
typedef pair< int, ii > iii;

int N, M;
int s, t;
int dist[MAX];
int LG[MAX][MAX], dG[MAX], AG[MAX][MAX], pais[MAX][MAX], dp[MAX];

void dijkstra() {
  int u, i, v, ok[MAX], peso, p, d;
  priority_queue< iii, vector<iii>, greater<iii> > Q;
  memset(ok, 0, sizeof(ok));
  memset(dp, 0, sizeof(dp));
  for (u = 0; u < MAX; u++) dist[u] = INF;
  dist[s] = 0; Q.push(iii(0, ii(s, -1)));
  while (!Q.empty()) {
    u = Q.top().second.first; p = Q.top().second.second;
    d = Q.top().first; Q.pop();
    if(d == dist[u]) pais[u][dp[u]++] = p; //Coloco o pai do vértice no vetor dos pais
    if (ok[u]) continue; ok[u] = 1;
    for (i = 0; i < dG[u]; i++) {
      v = LG[u][i]; peso = AG[u][v];
      if (peso && dist[v] >= dist[u] + peso) {
        dist[v] = dist[u] + peso;
        Q.push(iii(dist[v], ii(v, u)));
      }}}}

void tiraCaminhos(int t) {
  int v;
  for (dp[t]--; dp[t] >= 0; dp[t]--)
    if ((v = pais[t][dp[t]]) != -1) {
      AG[v][t] = 0; tiraCaminhos(v);
    }
}

int main(void) {
  int u, v, p;
  while (scanf("%d %d", &N, &M), N) {
    scanf("%d %d", &s, &t);
    memset(dG, 0, sizeof(dG));
    while (M--) {
      scanf("%d %d %d", &u, &v, &p);
      LG[u][dG[u]++] = v; AG[u][v] = p;
    }
    dijkstra();
    tiraCaminhos(t);
    dijkstra();
    printf("%d\n", dist[t] == INF ? -1 : dist[t]);
  }
  return 0;
}

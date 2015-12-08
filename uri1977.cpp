#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <vector>
#include <utility>
#include <queue>
#include <map>
#include <string>
using namespace std;

#define MAX 112
#define INF 112345678

typedef pair<int, int> ii;
typedef pair<int, ii> pi;

int X, N, V;
int dist[MAX][12];
int AG[MAX][MAX], LG[MAX][MAX], dG[MAX];

int mmin(int a, int b){
  return a < b ? a : b;
}

void dijkstra(int s) {
  int u, i, v, ok[MAX][12], peso, estado;
  priority_queue< pi, vector<pi>, greater<pi> > Q;
  memset(ok, 0, sizeof(ok));
  for (u = 0; u < MAX; u++)
    for(i = 0; i < 12; i++) dist[u][i] = INF;

  dist[s][0] = 0; Q.push(pi(0, ii(s, 0)));
  while (!Q.empty()) {
    u = Q.top().second.first;
    estado = Q.top().second.second;
    Q.pop();
    if (ok[u][estado]) continue;
    ok[u][estado] = 1;
    for (i = 0; i < dG[u] && estado < V; i++) {
      v = LG[u][i]; peso = AG[u][v];
      if (dist[v][estado + 1] > dist[u][estado] + peso) {
        dist[v][estado + 1] = dist[u][estado] + peso;
        Q.push(pi(dist[v][estado + 1], ii(v, estado + 1)));
      }}}}

int main(void){
  int peso, s, t, i, cont, u, v;
  int h, m, min, tempo;
  char cstr1[1123], cstr2[1123];
  scanf("%d %d %d", &X, &N, &V);
  while(X || N || V){
    cont = 0; h = 17; min = m = X > 30 ? 50 : 30;
    map<string, int> M;
    memset(dG, 0, sizeof(dG));
    for(i = 0; i < N; i++){
      scanf(" %s %s %d", cstr1, cstr2, &peso);
      string str1(cstr1), str2(cstr2);
      if(M.find(str1) == M.end()) M[str1] = cont++;
      if(M.find(str2) == M.end()) M[str2] = cont++;
      u = M[str1]; v = M[str2];
      AG[u][v] = peso;
      LG[u][dG[u]++] = v;
    }
    s = M["varzea"];
    t = M["alto"];
    dijkstra(s);
    for(tempo = INF, i = 0; i < 12; i++)
      tempo = mmin(dist[t][i], tempo);
    m += tempo;
    h += m / 60;
    m %= 60;
    h %= 24;
    printf("%.2d:%.2d\n", h, m);
    if(min + tempo > 60) printf("Ira se atrasar\n");
    else printf("Nao ira se atrasar\n");
    scanf("%d %d %d", &X, &N, &V);
  }
  return 0;
}

#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

#define MAX 312
#define INF 112345678

int T, m, n;
int s, t;
long long  A[MAX], B[MAX];
int LG[MAX][MAX], dG[MAX], AG[MAX][MAX], cam[MAX], tcam;;

int bfs(void) {
  int fila[MAX], inic, fim, dist[MAX], p[MAX], u, i, v, garg = INF;
  for (u = 0; u < MAX; u++) dist[u] = INF;
  dist[s] = 0; fila[inic = fim = 0] = s;
  while (inic <= fim) {
    u = fila[inic++];
    for (i = 0; i < dG[u]; i++) {
      v = LG[u][i];
      if (dist[v] == INF && AG[u][v] > 0) {
        dist[v] = dist[u] + 1; p[v] = u; fila[++fim] = v;
        if (v == t) { inic = fim + 1; break; }
      }}}
  if (dist[t] == INF) return 0;
  tcam = dist[t] + 1;
  for (i = dist[t]; i > 0; i--) {
    cam[i] = v; v = p[v];
    garg = min(garg, AG[v][cam[i]]);
  }
  cam[0] = s;
  return garg;
}

int ffek(void) {
  int f = 0, garg, i, u, v;
  while ((garg = bfs())) {
    for (i = 0; i <= tcam - 2; i++) {
      u = cam[i]; v = cam[i + 1];
      AG[u][v] -= garg; AG[v][u] += garg;
    }
    f += garg;
  }
  return f;
}

void montagrafo(){
  int i, u, v, j;
  memset(dG, 0, sizeof(dG));
  memset(AG, 0, sizeof(AG));
  for(i = 1; i <= n; i++){
    u = i;
    LG[s][dG[s]++] = u; AG[s][u] = 1;
    LG[u][dG[u]++] = s;
    for(j = 1; j <= m; j++){
      v = j + 100; LG[v][dG[v]++] = t;
      AG[v][t] = 1;
      if((!A[i] && !B[j]) || (A[i] != 0 && (B[j] == 0 || B[j] % A[i] == 0))){
        LG[u][dG[u]++] = v; AG[u][v] = 1;
        LG[v][dG[v]++] = u;
      }}}}

int main(void){
  int i, j, caso;
  t = 205; s = 0;
  scanf("%d", &T);
  for(caso = 1; caso <= T; caso++){
    scanf("%d", &n);
    for(i = 1; i <= n; i++)
      scanf("%lld", &A[i]);
    scanf("%d", &m);
    for(i = 1; i <= m; i++)
      scanf("%lld", &B[i]);
    montagrafo();
    printf("Case %d: %d\n", caso, ffek());
  }
  return 0;
}

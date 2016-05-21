#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

#define S 0
#define T 1
#define MAX 312
#define INF 112345678
#define LAST 2 * N + 2 + 1

int N, Q, q[MAX];
int LG[MAX][MAX], d[MAX], AG[MAX][MAX], AR[MAX][MAX];
int dist[MAX], fila[MAX], inic, fim, pai[MAX];

int bfs(int s, int t) {
  int u, i, v;
  for (u = 0; u < LAST; u++) dist[u] = INF;
  dist[s] = 0; fila[inic = fim = 0] = s;
  while (inic <= fim) {
    u = fila[inic++];
    if (u == t) return 1;
    for (i = 0; i < d[u]; i++) {
      v = LG[u][i];
      if (AR[u][v] && dist[v] == INF)
        { pai[v] = u; dist[v] = dist[u] + 1; fila[++fim] = v; }
    }}
  return 0;
}

int ffek(int s, int t) {
  int f, delta, u;
  for (f = 0; bfs(s, t); f += delta) {
    for (delta = INF, u = t; u != s; u = pai[u])
      delta = min(delta, AR[pai[u]][u]);
    for (u = t; u != s; u = pai[u])
      { AR[pai[u]][u] -= delta; AR[u][pai[u]] += delta; }
  }
  return f;
}

void montaaresta(int u, int v, int c) {
  LG[u][d[u]++] = v; AG[u][v] = c; AR[u][v] = c;
  LG[v][d[v]++] = u; AG[v][u] = 0; AR[v][u] = 0;
}

//Pais [2 ... 2 + N)  Grupos [2 + N ... 2 + 2 * N]
int main(void) {
  int B, i, j, v, fluxo;
  scanf("%d %d", &N, &Q);
  memset(d, 0, sizeof(d));
  montaaresta(N + 2, T, 0);
  for (i = 2; i < 2 + N; i++) {
    scanf("%d", &B);
    montaaresta(S, i, 1); montaaresta(N + 1 + i, T, 0);
    if (B < N) montaaresta(i, N + 2, INF);
    while (B--) {
      scanf("%d", &j);
      montaaresta(i, N + 2 + j, INF);
    }
  }
  while (Q--) {
    scanf("%d", &B);
    for (i = 0; i < B; i++)
      { scanf("%d", &q[i]); AR[q[i] + N + 2][T] = 1; }
    fluxo = ffek(S, T);
    if (fluxo ==  B)
      for (AR[N + 2][T] = INF, i = 0; i < B; i++)
        AR[q[i] + N + 2][T] = INF;
    fluxo += ffek(S, T);
    printf("%c\n", fluxo == N ? 'Y' : 'N');
    for (i = 0; i < LAST; i++)
      for (j = 0; j < d[i]; j++) { v = LG[i][j]; AR[i][v] = AG[i][v]; }
  }
  return 0;
}

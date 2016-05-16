#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

#define INF 112345678
#define MAXI 123
#define MAXG 11234

int N, n, nc;
char grid[MAXI][MAXI];
int linha[MAXI][MAXI], coluna[MAXI][MAXI];
int LG[MAXG][MAXG], d[MAXG], vis[MAXG], match[MAXG];

int aug(int u) {
  int i, v;
  if (vis[u]) return 0;
  vis[u] = 1;
  for (i = 0; i < d[u]; i++) {
    v = LG[u][i];
    if (match[v] == -1 || aug(match[v]))
      { match[v] = u; return 1; }
  }
  return 0;
}

void montagrafo(){
  int u, i, j, k;
  memset(d, 0, sizeof(d));
  memset(coluna, -1, sizeof(coluna));
  memset(linha, -1, sizeof(linha));
  for (n = 0, i = 0; i < N; i++) {
    for (j = 0; j < N; j++) {
      if (grid[i][j] == 'X' || coluna[i][j] != -1) continue;
      for (k = i; k < N && grid[k][j] == '.'; k++) coluna[k][j] = n;
      n++;
    }}
  for (nc = n, i = 0; i < N; i++) {
    for (j = 0; j < N; j++) {
      if (grid[i][j] == 'X') continue;
      while (j < N && grid[i][j] == '.') {
        linha[i][j] = n; u = coluna[i][j++];
        if (u == -1 || n == -1) continue;
        LG[u][d[u]++] = n;
      }
      n++;
    }}}

int main(void) {
  int resp, u;
  while (scanf("%d\n", &N) != EOF) {
    for (int i = 0; i < N; i++) fgets(grid[i], MAXI, stdin);
    montagrafo();
    //    printagrafo();
    memset(match, -1, sizeof(match));
    for (resp = u = 0; u < nc; u++)
      { memset(vis, 0, sizeof(vis)); resp += aug(u); }
    printf("%d\n", resp);
  }
  return 0;
}

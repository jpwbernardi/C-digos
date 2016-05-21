#include <stdio.h>
#include <string.h>

#define MAX 112345

int dist[MAX], fila[MAX], ini, fim;

int inv(int u) {
  int ret = 0;
  while (u)
    { ret *= 10; ret += u % 10; u /= 10; }
  return ret;
}

int bfs(int s, int t) {
  int u, v;
  memset(dist, -1, sizeof(dist));
  dist[s] = 0; fila[ini = fim = 0] = s;
  while (ini <= fim) {
    u = fila[ini++];
    if (u == t) return dist[u];
    if (dist[u + 1] == -1)
      { fila[++fim] = u + 1; dist[u + 1] = dist[u] + 1; }
    if (dist[v = inv(u)] == -1)
      { fila[++fim] = v; dist[v] = dist[u] + 1; }
  }
  return -1;
}

int main(void) {
  int T, s, t;
  scanf("%d", &T);
  while (T--) {
    scanf("%d %d", &s, &t);
    printf("%d\n", bfs(s, t));
  }
  return 0;
}

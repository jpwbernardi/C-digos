#include <stdio.h>

#define MAX 1123

struct ponto {
  int x, y;
  ponto() {}
  ponto(int _x, int _y) : x(_x), y(_y) {}
};

int N, M;
char AG[MAX][MAX];
ponto fila[MAX * MAX];
int dist[MAX][MAX], ini, fim;

int dx[] = { 1, -1,  0, 0};
int dy[] = { 0,  0, -1, 1};

void bfs(ponto s) {
  int i;
  ponto u, v;
  fila[ini = fim = 0] = s; dist[s.x][s.y] = 0;
  while (ini <= fim) {
    u = fila[ini++];
    for (i = 0; i < 4; i++) {
      v = ponto(u.x + dx[i], u.y + dy[i]);
      if (v.x >= 0 && v.x < N && v.y >= 0 && v.y < M &&
          AG[v.x][v.y] == '.')
        { fila[++fim] = v; AG[v.x][v.y] = 'o'; }
    }}}


int main(void) {
  int resp = 0, i, j;
  scanf("%d %d\n", &N, &M);
  for (i = 0; i < N; i++)
    fgets(AG[i], MAX, stdin);
  for (i = 0; i < N; i++)
    for (j = 0; j < M; j++)
      if (AG[i][j] == '.')
        { bfs(ponto(i, j)); resp++; }
  printf("%d\n", resp);
}

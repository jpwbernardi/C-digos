#include <stdio.h>

#define MAX 12
#define N 5

struct ponto {
  int x, y;
  ponto() {}
  ponto(int _x, int _y) : x(_x), y(_y) {}
};

int AG[MAX][MAX], ini, fim;;
ponto fila[MAX * MAX];

int dx[] = { 1, -1,  0, 0};
int dy[] = { 0,  0, -1, 1};

void bfs(ponto s) {
  int i;
  ponto u, v;
  fila[ini = fim = 0] = s;
  while (ini <= fim) {
    u = fila[ini++];
    for (i = 0; i < 4; i++) {
      v = ponto(u.x + dx[i], u.y + dy[i]);
      if (v.x >= 0 && v.x < N && v.y >= 0 && v.y < N &&
          AG[v.x][v.y] == 0)
        { fila[++fim] = v; AG[v.x][v.y] = 1; }
    }}}


int main(void) {
  int i, j, T;
  scanf("%d\n", &T);
  while (T--) {
    for (i = 0; i < 5; i++)
      for (j = 0; j < 5; j++)
        scanf("%d", &AG[i][j]);
    bfs(ponto(0, 0));
    printf("%s\n", AG[4][4] == 0 ? "ROBBERS" : "COPS");
  }
}

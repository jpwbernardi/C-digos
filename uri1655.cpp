#include <stdio.h>
#include <string.h>

#define MAX 1123
#define EPS 1e-9
#define igualDouble(x,y) (fabs ((x) - (y)) < EPS)
#define menorIgualDouble(x,y) ((x) < (y) || igualDouble(x,y))
#define maiorIgualDouble(x,y) ((x) > (y) || igualDouble(x,y))

int N, M;
double AG[MAX][MAX];

void fwarshall() {
  for(int w = 0; w < N; w++)
    for(int u = 0; u < N; u++)
      for(int v = 0; v < N; v++)
        if(AG[u][v] < AG[u][w] * AG[w][v])
          AG[u][v] = AG[u][w] * AG[w][v];
}


int main(void) {
  int u, v, p;
  while (scanf("%d", &N), N) {
    scanf("%d", &M);
    memset(AG, 0, sizeof(AG));
    while (M--) {
      scanf("%d %d %d", &u, &v, &p); u--; v--;
      AG[u][v] = AG[v][u] = (p / 100.0);
    }
    fwarshall();
    printf("%lf percent\n", AG[0][N - 1] * 100);
  }
  return 0;
}

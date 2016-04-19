#include <stdio.h>
#include <string.h>
#include <vector>
#include <utility>
#include <queue>
#include <math.h>
using namespace std;

#define MAX 512
#define INF 1123456789

typedef pair<int, int> ii;
typedef vector<ii> vii;
struct ponto{ int x, y; ponto(){} ponto(int _x, int _y) : x(_x), y(_y) {}};

int C, N;
int distmin[MAX], vis[MAX];
ponto V[MAX];

int distsq(int i, int j) {
  int dx = V[i].x - V[j].x, dy = V[i].y - V[j].y;
  return dx * dx + dy * dy;
}

int minDist(){
  int i, ret = -1;
  for(i = 0; i < N; i++)
    if((ret == -1 && !vis[i]) || (ret != -1 && distmin[ret] >= distmin[i] && !vis[i]))
      ret = i;
  return ret;
}

double prim() {
  int u, i, c;
  double custo = 0;
  memset(vis, 0, sizeof(vis));
  distmin[0] = 0;
  while ((u = minDist()) != -1) {
    custo += sqrt(distmin[u]); vis[u] = 1;
    for (i = 0; i < N; i++) {
      c = distsq(u, i);
      if (!vis[i] && c < distmin[i]) distmin[i] = c;
    }}
  return custo;
}

int main(void){
  int x, y, i;
  scanf("%d", &C);
  while(C--){
    scanf("%d", &N);
    for(i = 0; i < N; i++){
      scanf("%d %d", &x, &y);
      V[i] = ponto(x, y);
      distmin[i] = INF;
    }
    printf("%.2lf\n", prim() / 100);
  }
  return 0;
}

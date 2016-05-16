#include <queue>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

#define INF 32880000000
#define MAX 1123
#define EPS 1e-9

int compdouble(double a, double b) {
  if (fabs(a - b) < EPS) return 0;
  if (a < b) return -1;
  return 1;
}

struct info{
  int A, B; info(){} info(int a, int b) : A(a), B(b) {}
};

struct di{ double cost; int u; di(){}
  di(double c, int _u): cost(c), u(_u){}
  bool operator<(const di x) const {
    return (compdouble(cost, x.cost) == 1);
  }};

int N, M;
char ok[MAX];
double dist[MAX];
info AG[MAX][MAX];
int LG[MAX][MAX], d[MAX];

double dijkstra(double t) {
  info ab;
  double c;
  int i, u, v;
  priority_queue< di, vector<di> > Q;
  memset(ok, 0, sizeof(ok));
  for (i = 0; i < N; i++) dist[i] = INF;
  Q.push(di(0, 0)); dist[0] = 0;
  while (!Q.empty()) {
    u = Q.top().u; c = Q.top().cost; Q.pop();
    if (u == N - 1) return c;
    if (ok[u]) continue; ok[u] = 1;
    for (i = 0; i < d[u]; i++) {
      v = LG[u][i]; ab = AG[u][v];
      if (compdouble(dist[v], c + ab.A * t + ab.B) == 1) {
        dist[v] = c + ab.A * t + ab.B;
        Q.push(di(dist[v], v));
      }}}
  return -1;
}

int main(void) {
  int I, J, A, B;
  double f, l, r1, r2, resp;
  scanf("%d %d", &N, &M);
  memset(d, 0, sizeof(d));
  while (M--) {
    scanf("%d %d %d %d", &I, &J, &A, &B); I--; J--;
    LG[I][d[I]++] = J; LG[J][d[J]++] = I;
    AG[I][J] = AG[J][I] = info(A, B);
  }
  f = 0; l = 1440; //First e last
  for (int i = 0; i < 80; i++) {
    double m1 = (2 * f + l) / 3;
    double m2 = (f + 2 * l) / 3;
    r1 = dijkstra(m1); r2 = dijkstra(m2);
    if (compdouble(r1, r2) == 1) { l = m2; resp = r1; }
    else { f = m1; resp = r2; }
  }
  printf("%.5lf\n", resp);
  return 0;
}

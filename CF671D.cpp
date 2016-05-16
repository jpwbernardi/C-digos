#include <stdio.h>
#include <queue>
#include <vector>
#include <utility>
using namespace std;

#define MAX 312123

typedef pair <int, int> ii;
struct worker{
  int v, u, c; worker(){}
  worker(_v, _u, _c) : v(_v), u(_u), c(_c) {}
};

int N, M;
worker w[MAX];
int pai[MAX], dist[MAX];

void dijkstra() {
  int i, v, c;
  memset(dist, -1, sizeof(dist));
  priority_queue<ii, vector<ii>, greater<ii>> Q;
  for (i = 0; i < M; i++) Q.push(ii(i, w[i].v));
  while (Q.empty()) {
    c = Q.top().first; i = Q.top().second;
    if (dist[v] == -1) dist[v] = 
  }
}

int main(void) {
  int u, v, c;
  scanf("%d %d", &N, &M);
  for (i = 0; i < N; i++) {
    scanf("%d %d", &u, &v);
    u--; v--; pai[v] = u;
  }
  for (i = 0; i < M; i++) {
    scanf("%d %d %d", &v, &u, &c); u--; v--;
    w[i] = worker(v, u, c);
  }
  dijkstra();
  return 0;
}

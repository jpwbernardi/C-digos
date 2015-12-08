#include <stdio.h>
#include <string.h>
#include <vector>
#include <utility>
#include <queue>
#include <map>
#include <string>
using namespace std;

#define MAX 21234
#define INF 112345678

typedef pair<int, int> ii;
typedef pair<int, ii> pi;
typedef vector<ii> vii;

int V, E;
int dist[MAX][2], ok[MAX][2];

int dijkstra(vector<vii> &LG, int s) {
  int u, i, v, peso, par;
  priority_queue< pi, vector<pi>, greater<pi> > Q;
  memset(ok, 0, sizeof(ok));
  for (u = 0; u < V; u++){ dist[u][0] = INF; dist[u][1] = INF; }
  dist[s][0] = 0; Q.push(pi(0, ii(s, 0)));
  while (!Q.empty()) {
    u = Q.top().second.first; par = Q.top().second.second;
    if(u == V - 1 && !par) return Q.top().first;
    // printf("%d %d\n", u, par);
    Q.pop();
    if (ok[u][par]) continue;
    ok[u][par] = 1;
    for (i = 0; i < (int)LG[u].size(); i++) {
      v = LG[u][i].first; peso = LG[u][i].second;
      if (dist[v][!par] > dist[u][par] + peso) {
        dist[v][!par] = dist[u][par] + peso;
        Q.push(pi(dist[v][!par], ii(v, !par)));
      }}}
  return -1;
}


int main(void){
  int u, v, p;
  scanf("%d %d", &V, &E);
  vector<vii> LG(V);
  while(E--){
    scanf("%d %d %d", &u, &v, &p);
    u--; v--;
    LG[u].push_back(ii(v, p));
    LG[v].push_back(ii(u, p));
  }
  printf("%d\n", dijkstra(LG, 0));
  return 0;
}

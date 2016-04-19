#include <stdio.h>
#include <string.h>
#include <vector>
#include <utility>
#include<queue>
using namespace std;

#define MAX 11234

typedef pair<int, int> ii;
typedef vector<ii> vii;

int N;
int vis[MAX];

long long prim(int s, vector<vii> &LG) {
  int u, i, v, c;
  long long custo = 0;
  priority_queue< ii, vector<ii>, greater<ii> > Q;
  Q.push(ii(0, s));
  while (!Q.empty()) {
    u = Q.top().second;
    if (!vis[u]) custo += Q.top().first;
    Q.pop(); vis[u] = 1;
    for (i = 0; i < (int)LG[u].size(); i++) {
      v = LG[u][i].second; c = LG[u][i].first;
      if (!vis[v]) Q.push(ii(c, v));
    }}
  return custo;
}

int main(void){
  int u, k, v, c, familias = 0;
  long long custoTot = 0;
  scanf("%d", &N);
  vector<vii> LG(N);
  for(u = 0; u < N - 1; u++){
    scanf("%d", &k);
    while(k--){
      scanf("%d %d", &v, &c); v--;
      LG[u].push_back(ii(c, v));
      LG[v].push_back(ii(c, u));
    }}
  memset(vis, 0, sizeof(vis));
  for(u = 0; u < N; u++){
    if(!vis[u]) { custoTot += prim(u, LG); familias++; }
  }
  printf("%d %lld\n", familias, custoTot);
  return 0;
}

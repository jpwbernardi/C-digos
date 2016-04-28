#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

#define MAX 112
#define MAXL 112
#define MAXK 13
#define INF 112345678

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

//A: vilas
//B: castelos
//M: ruas
//L: a distancia máxima coberta pela bota
//K: o numero máximo de vezes que a bota pode ser usada
int A, B, M, L, K;
int LG[MAX][MAX], dG[MAX], AG[MAX][MAX], AG2[MAX][MAX];
int ok[MAX][MAXK], dist[MAX][MAXK];

int menorDist(){
  int u, menor = INF;
  for(u = 0; u <= K; u++)
    menor = min(menor, dist[0][u]);
  return menor;
}

void fwarshall() {
  for(int w = 0; w < A; w++)
    for(int u = 0; u < A + B; u++)
      for(int v = 0; v < A + B; v++)
        if(AG[u][v] > AG[u][w] + AG[w][v])
          AG[u][v] = AG[u][w] + AG[w][v];
}

void dijkstra(int s) {
  int u, i, v, k;
  priority_queue< iii, vector<iii>, greater<iii> > Q;
  memset(ok, 0, sizeof(ok));
  for (u = 0; u < MAX; u++)
      for(v = 0; v < MAXK; v++) dist[u][v] = INF;
  dist[s][K] = 0; Q.push(iii(0, ii(s,  K)));
  while (!Q.empty()) {
    u = Q.top().second.first;
    k = Q.top().second.second;
    Q.pop();
    if (ok[u][k]) continue; ok[u][k] = 1;
    for(v = 0 ; v < A + B ; v++)
      if(AG[u][v] <= L && k && dist[v][k - 1] > dist[u][k]) {
        dist[v][k - 1] = dist[u][k];
        Q.push(iii(dist[v][k - 1], ii(v, k - 1)));
      }
    //Verifico se é melhor ir caminhando
    for(i = 0; i < dG[u]; i++){
      v = LG[u][i];
      if(dist[v][k] > dist[u][k] + AG2[u][v]) {
        dist[v][k] = dist[u][k] + AG2[u][v];
        Q.push(iii(dist[v][k], ii(v, k)));
      }}}}


int main(void) {
  int T, u, v, p;
  scanf("%d", &T);
  while(T--) {
    scanf("%d %d %d %d %d", &A, &B, &M, &L, &K);
    memset(dG, 0, sizeof(dG));
    for(u = 0; u < MAX ; u++)
      for(v = 0; v < MAX; v++) AG[u][v] = INF;
    while (M--) {
      scanf("%d %d %d", &u, &v, &p); u--; v--;
      LG[u][dG[u]++] = v; LG[v][dG[v]++] = u;
      AG2[u][v] = AG2[v][u] = AG[u][v] = AG[v][u] = p;
    }
    fwarshall();
    dijkstra(A + B - 1);
    printf("%d\n", menorDist());
  }
  return 0;
}

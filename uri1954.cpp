#include <set>
#include <vector>
#include <utility>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

#define MAX 112345
#define PRIMO 1000000007

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long ll;

int n, Ncomp, s, t;
//S é nossa pilha para o tarjan
int ordem[MAX], ciclo[MAX], comp[MAX], _ordem, S[MAX], topo, emS[MAX];
int vis[MAX], pi[MAX], tpi, posPi[MAX], qtdCam[MAX];

void tarjan(int u, vector<vi> &LG) {
  int i, v;
  //Define ordem e ciclo para vértice incial
  ordem[u] = ciclo[u] = _ordem++;
  //Coloca na pilha e marca que está lá
  S[topo++] = u; emS[u] = 1;
  for (i = 0; i < (int)LG[u].size(); i++) {
    v = LG[u][i];
    //Se não visitei o vértice ainda...
    if (!ordem[v]) tarjan(v, LG);
    //Se o vértice v já está na pilha, tento diminuir o ciclo de s
    if (emS[v]) ciclo[u] = min(ciclo[u], ciclo[v]);
  }
  //Verifico se ordem é igual a ciclo
  if (ordem[u] == ciclo[u]) {
    //Desempilho todos os vértices até encontrar s. Esses vértices formam uma componente fortemente conexa(??)
    do { v = S[--topo]; emS[v] = 0; comp[v] = Ncomp; } while (v != u);
    Ncomp++;
  }}

void dfs(int u, vector<vi> &LDAG) {
  int i, v;
  vis[u] = 1;
  for (i = 0; i < (int)LDAG[u].size(); i++) {
    v = LDAG[u][i];
    if (!vis[v]) dfs(v, LDAG);
  }
  pi[tpi] = u;
  posPi[u] = tpi--;
}

void pd(vector<vi> &LDAG, int s, int t){
  int u, i, j, v;
  s = comp[s]; t = comp[t];
  memset(qtdCam, 0, sizeof(qtdCam));
  memset(vis, 0, sizeof(vis));
  qtdCam[s] = 1;
  for(i = posPi[s]; i < posPi[t]; i++){
    u = pi[i];
    for(j = 0; j < (int)LDAG[u].size(); j++){
      v = LDAG[u][j];
      if (!vis[v]) { qtdCam[v] = (qtdCam[v] + qtdCam[u]) % PRIMO; vis[v] = 1; }
    }
    for(j = 0; j < (int)LDAG[u].size(); j++){ v = LDAG[u][j]; vis[v] = 0; }
  }}

int main(void){
  int m, u, v, i;
  scanf("%d %d %d %d", &n, &m, &s, &t);
  vector<vi> LG(n); s--; t--;
  while (m--) {
    scanf("%d %d", &u, &v); u--; v--;
    LG[u].push_back(v);
  }
  //Executa tarjan para cada vértice, descobrindo os componentes fortemente conexos
  memset(ordem, 0, sizeof(ordem)); memset(ciclo, 0, sizeof(ciclo)); memset(emS, 0, sizeof(emS));
  for (_ordem = 1, topo = Ncomp = u = 0; u < n; u++)
    if (!ordem[u]) tarjan(u, LG);
  //Faz um DAG a partir dos componentes descobertos procurando se existe arestas entre componentes distintos
  vector<vi> LDAG(Ncomp);
  for (u = 0; u < n; u++)
    for (i = 0; i < (int)LG[u].size(); i++) {
      v = LG[u][i];
      //Se pertencem a componentes diferentes e não foi criado a aresta entre esses componentes ainda
      if (comp[u] != comp[v]) LDAG[comp[u]].push_back(comp[v]);
    }

  //Toposort
  memset(vis, 0, sizeof(vis));
  for (tpi = Ncomp - 1, u = 0; u < Ncomp; u++)
    if (!vis[u]) dfs(u, LDAG);

  pd(LDAG, s, t);
  printf("%d\n", qtdCam[comp[t]]);
  return 0;
}

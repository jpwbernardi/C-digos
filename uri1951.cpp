#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 112
#define MAX1 MAX * MAX * 3

int Ncomp;
int I, N, O, K;
char memo[MAX1];
int LG[MAX1][MAX], dG[MAX1];
int ordem[MAX1], ciclo[MAX1], comp[MAX1], _ordem, S[MAX1], topo, emS[MAX1];


//Retorna 1 se não chegou no fim, 0 cc;
int dfs(int u){
  int flag = 1;
  if(u >= I + N) return 0;
  if(memo[u] != -1) return memo[u];
  for(int i = 0; i < dG[u]; i++)
    flag &= dfs(LG[u][i]);
  return memo[u] = flag;
}

void tarjan(int u) {
  int i, v;
  ordem[u] = ciclo[u] = _ordem++;
  S[topo++] = u; emS[u] = 1;
  for (i = 0; i < dG[u]; i++) {
    v = LG[u][i];
    if (!ordem[v]) tarjan(v);
    if (emS[v]) ciclo[u] = min(ciclo[u], ciclo[v]);
  }
  if (ordem[u] == ciclo[u]) {
    do { v = S[--topo]; emS[v] = 0; comp[v] = Ncomp; } while (v != u);
    Ncomp++;
  }}

int main(void){
  int u, v;
  char erro = 0;
  memset(dG, 0, sizeof(dG));
  memset(ordem, 0, sizeof(ordem)); memset(ciclo, 0, sizeof(ciclo)); memset(emS, 0, sizeof(emS));
  scanf("%d %d %d", &I, &N, &O);
  for (v = I; v < I + N; v++){
    scanf("%d", &K);
    while(K--){ scanf("%d", &u); u--; LG[u][dG[u]++] = v; }
  }
  for(v = I + N; v < I + N + O; v++){ scanf("%d", &u); u--; LG[u][dG[u]++] = v; }
  // for(u = 0; u < I + N + O; u++){
  //   printf("%d: ", u);
  //   for(v = 0; v < dG[u]; v++)
  //     printf("%d, ", LG[u][v]);
  //   printf("\n");
  // }
  for(Ncomp = u = 0; u < I + N + O; u++)
    if(!ordem[u]) tarjan(u);

  erro = !(Ncomp == I + N + O);
  memset(memo, -1, sizeof(memo));
  for(u = 0; !erro && u < I + N; u++)
    erro |= dfs(u);

  printf("%s\n", !erro ? "o.o" : "u.u");
  return 0;
}

#include <stdio.h>
#include<stdio.h>
#include<string.h>
#include<vector>
#include<utility>
#include<algorithm>
#include<set>
using namespace std;

#define MAX 1123


char AG[MAX][MAX], ponte;
int N, M, Ncomp, cordem;
int LG[MAX][MAX], dG[MAX];
int LC[MAX][MAX], dC[MAX]; //Grafo das componentes
int ordem[MAX], ciclo[MAX], comp[MAX], _ordem, S[MAX], topo, emS[MAX], pai[MAX];

void tarjan(int u) {
  int i, v;
  //Define ordem e ciclo para vértice incial
  ordem[u] = ciclo[u] = _ordem++;
  //Coloca na pilha e marca que está lá
  S[topo++] = u; emS[u] = 1;
  for (i = 0; i < dG[u]; i++) {
    v = LG[u][i];
    //Se não visitei o vértice ainda...
    if (!ordem[v]) tarjan(v);
    //Se o vértice v já está na pilha, tento diminuir o ciclo de s
    if (emS[v]) ciclo[u] = min(ciclo[u], ciclo[v]);
  }
  //Verifico se ordem é igual a ciclo
  if (ordem[u] == ciclo[u]) {
    //Desempilho todos os vértices até encontrar s. Esses vértices formam uma componente fortemente conexa(??)
    do { v = S[--topo]; emS[v] = 0; comp[v] = Ncomp; } while (v != u);
    Ncomp++;
  }}

void dfs(int u, int r) {
  int i, v;
  ordem[u] = ciclo[u] = cordem++;
  for (i = 0; i < dC[u]; i++) {
    v = LC[u][i];
    if (!ordem[v]) {
      pai[v] = u; dfs(v, r);
      if (ciclo[v] > ordem[u]) ponte = 1;
      ciclo[u] = min(ciclo[u], ciclo[v]);
    } else if (v != pai[u]) ciclo[u] = min(ciclo[u], ordem[v]);
  }}

int main(void){
  int u, v, t, i, j;
  while(scanf("%d %d", &N, &M) != EOF){
    // printf(">>>>>>>>>>>>>\n");
    memset(dG, 0, sizeof(dG)); memset(dC, 0, sizeof(dC)); memset(AG, 0, sizeof(AG));
    scanf("%d %d %d", &u, &v, &t);
    while(--M){
      scanf("%d %d %d", &u, &v, &t);
      u--; v--;
      LG[u][dG[u]++] = v;
      if(t == 2) LG[v][dG[v]++] = u;
    }
    //Executa tarjan para cada vértice, descobrindo os componentes fortemente conexos
    memset(ordem, 0, sizeof(ordem)); memset(ciclo, 0, sizeof(ciclo)); memset(emS, 0, sizeof(emS));
    for (_ordem = 1, topo = Ncomp = u = 0; u < N; u++){
      if (!ordem[u]) tarjan(u);
      // printf(">%d\n", u); }
    }
    // printf(">>Ncomp: %d\n", Ncomp);
    if(Ncomp == 1) { printf("-\n"); continue; }

    //Monta grafo das componentes
    for (u = 0; u < N; u++)
      for (i = 0; i < dG[u]; i++) {
        v = LG[u][i];
        //Se pertencem a componentes diferentes e não foi criado a aresta entre esses componentes ainda
        if (comp[u] != comp[v]) {
          LC[comp[u]][dC[comp[u]]++] = comp[v];
          LC[comp[v]][dC[comp[v]]++] = comp[u];
        }}

    // for(i = 0; i < Ncomp; i++){
    //   printf("%d: ", i);
    //   for(j = 0; j < dC[i]; j++){
    //     printf("%d, ", LC[i][j]);
    //   }
    //   printf("\n");
    // }

    memset(ordem, 0, sizeof(ordem)); memset(ciclo, 0, sizeof(ciclo));
    memset(pai, -1, sizeof(pai)); cordem = 1;

    dfs(0, 0);
    for(u = 1; u < Ncomp; u++)
      if(!ordem[u]) break;

    for(ponte = i = 0; i < Ncomp; i++)
      if(dC[i] == 1) ponte = 1;
    if(u < Ncomp)
      printf("*\n");
    else if(ponte)
      printf("2\n");
    else
      printf("1\n");
  }
  return 0;
}

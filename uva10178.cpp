#include <stdio.h>
#include <string.h>
#define MAX 300

int LG[MAX][MAX], dG[MAX], nE, nV;
int existe[MAX], AG[MAX][MAX];
bool vis[MAX];

void dfs(int u){
  if(vis[u]) return;
  vis[u] = true; nV++;
  for(int i = 0; i < dG[u]; i++){
    int v = LG[u][i]; nE++;
    if(!vis[v]) dfs(v);
  }}

int main(void){
  int V, E, i, f;
  int u, v, n;
  char a, b;
  while(scanf("%d %d", &V, &E) != EOF){
    getchar();
    memset(dG, 0, sizeof(dG)); memset(vis, 0, sizeof(vis));
    memset(existe, 0, sizeof(existe));
    for(n = 1, i = 0; i < E; i++){
      scanf("%c %c", &a, &b); getchar();
      u = a; v = b;
      if(!existe[(int)a]) existe[(int)a] = n++;
      if(!existe[(int)b]) existe[(int)b] = n++;
      u = existe[(int)a]; v = existe[(int)b];
      LG[u][dG[u]++] = v; LG[v][dG[v]++] = u;
    }
    f = 1;
    for(i = 1; i <= V; i++){
      if(!vis[i]){
        nE = nV = 0; dfs(i);
        f += 1 + (nE / 2) - nV;
      }}
    printf("%d\n", f);
  }
  return 0;
}

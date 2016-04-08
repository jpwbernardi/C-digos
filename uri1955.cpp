#include <stdio.h>
#include <string.h>

#define MAX 1123

int N, flag;
int AG[MAX][MAX], vis[MAX];

void dfs(int u, int p) {
  int i;
  vis[u] = p;
  for (i = 0; i < N; i++) {
    if (!AG[u][i]) continue;
    if (!vis[i]) dfs(i, (p & 1) + 1);
    else if (vis[i] == vis[u]) flag = 0;
  }}

int main(void){
    int tmp, u, i, j;
    scanf("%d", &N);
    for(i = 0; i < N; i++)
        for (j = 0; j < N; scanf("%d", &tmp), AG[i][j] = !tmp, j++);
    memset(vis, 0, sizeof(vis));
    for (flag = u = 1; flag && u < N; u++)
        if (!vis[u]) dfs(u, 1);
    printf("%s\n", flag ? "Bazinga!" : "Fail!");
    return 0;
}

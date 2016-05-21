#include <stdio.h>
#include <string.h>

#define MAX 31

int N, M;
int LG[MAX][MAX], dG[MAX];
int cmp[MAX], r;

void dfs(int s) {
  int i, v;
  cmp[s] = r;
  for (i = 0; i < dG[s]; i++) {
    v = LG[s][i];
    if (!cmp[v]) dfs(v);
  }
}

int main(void) {
  int T, i, j, caso;
  int u, v; char cu, cv;
  scanf("%d\n", &T);
  for (caso = 1; caso <= T; caso++) {
    memset(dG, 0, sizeof(dG));
    scanf("%d %d\n", &N, &M);
    while (M--) {
      scanf("%c %c\n", &cu, &cv);
      u = cu - 'a'; v = cv - 'a';
      LG[u][dG[u]++] = v;
      LG[v][dG[v]++] = u;
    }
    memset(cmp, 0, sizeof(cmp));
    printf("Case #%d:\n", caso);
    for (r = i = 0; i < N; i++) {
      if (cmp[i]) continue;
      r++; dfs(i);
      for (j = 0; j < N; j++)
        if (cmp[j] == r) printf("%c,", j + 'a');
      printf("\n");
    }
    printf("%d connected components\n\n", r);
  }
  return 0;
}

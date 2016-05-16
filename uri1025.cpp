#include <stdio.h>
#include <stdlib.h>

#define MAX 1123456

int N, Q;
int v[MAX];

int cmp(const void *a, const void *b) {
  return *(int *)a - *(int *)b;
}

int buscabin(int chave) {
  int p = 0, u = N, m = 1;
  while (p < u)
    if (v[m = (p + u) / 2] >= chave) u = m;
    else p = m + 1;
  return v[p] == chave ? p : -1;
}

int main(void) {
  int i, pos, caso = 1;
  while (scanf("%d %d", &N, &Q), N) {
    for (i = 0; i < N; i++) scanf("%d", &v[i]);
    qsort(v, N, sizeof(int), &cmp);
    printf("CASE# %d:\n", caso++);
    while (Q--) {
      scanf("%d", &i);
      if ((pos = buscabin(i)) != -1)
        printf("%d found at %d\n", i, pos + 1);
      else printf("%d not found\n", i);
    }}
  return 0;
}

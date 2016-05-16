#include <stdio.h>
#include <string.h>

char alf[30];

int main(void) {
  int N, resp = 0, i;
  scanf("%d\n", &N);
  if (N > 26) { printf("-1\n"); return 0; }
  memset(alf, 0, sizeof(alf));
  for (i = 0; i < N; i++)
    if(++alf[getchar() - 'a'] > 1) resp++;
  printf("%d\n", resp);
  return 0;
}

#include <stdio.h>

#define MAX 1123

int N, K;
int a[MAX], b[MAX];

int consigo(int qtd) {
  int k = K, i;
  for (i = 0; i < N; i++)
    if(b[i] < a[i] * qtd)
      k -= (a[i] * qtd - b[i]);
  return k < 0 ? 0 : 1;
}
int main(void) {
  int min, max, meio, i;
  scanf("%d %d", &N, &K);
  for (i = 0; i < N; i++) scanf("%d", &a[i]);
  for (i = 0; i < N; i++) scanf("%d", &b[i]);
  min = 0; max = 2000;
  while (min < max) {
    //    printf("%d %d\n", min, max);
    meio = (min + max) / 2;
    if (consigo(meio)) min = meio + 1;
    else max = meio;
  }
  printf("%d\n", min == 0 || min == 2000 ? min : min - 1);
  return 0;
}

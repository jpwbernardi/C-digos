
#include <stdio.h>

long long qtd[113];

int main(void) {
  int N, i;
  for (qtd[1] = 1, i = 2; i <= 100; i++)
    qtd[i] = i * i + qtd[i - 1];
  while (scanf("%d", &N), N)
    printf("%lld\n", qtd[N]);
  return 0;
}

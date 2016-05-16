#include <stdio.h>

#define MAX 112345

typedef long long ll;

ll N, K;
ll a[MAX], b[MAX];

int consigo(ll qtd) {
  ll k = K; int i;
  for (i = 0; i < N && k >= 0; i++)
    if(b[i] < a[i] * qtd)
      k -= (a[i] * qtd - b[i]);
  return k < 0 ? 0 : 1;
}
int main(void) {
  int i;
  ll min, max, meio;
  scanf("%lld %lld", &N, &K);
  for (i = 0; i < N; i++) scanf("%lld", &a[i]);
  for (i = 0; i < N; i++) scanf("%lld", &b[i]);
  min = 0; max = 2000000000;
  while (min < max) {
    //    printf("%d %d\n", min, max);
    meio = (min + max) / 2;
    if (consigo(meio)) min = meio + 1;
    else max = meio;
  }
  printf("%lld\n", min == 0 || min == 2000000000 ? min : min - 1);
  return 0;
}

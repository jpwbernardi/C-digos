#include <stdio.h>
#define NUM 2000000011

typedef long long ll;

ll expb(ll n, int k){
  if(k == 0) return 1;
  if(k == 1) return n;
  if(k & 1) return (n * expb(n, k - 1)) % NUM;
  return (expb(n, k / 2) * expb(n, k / 2)) % NUM;
}

int main(void){
  int N, n, i;
  scanf("%d", &N);
  for(i = 1; i <= N; i++){
    scanf("%d", &n);
    printf("Case #%d: ", i);
    if(n == 1 || n == 2) printf("1\n");
    else printf("%lld\n", expb(n, n - 2) % NUM);
  }
  return 0;
}

#include <stdio.h>
#include <string.h>

#define MAX 1123
#define P 1000000007

typedef unsigned long long ull;

char str[MAX];
int alf[30];

ull expbin(ull n, int k) {
  if (k == 0) return 1;
  if (k == 1) return n;
  if (k & 1) return (n * expbin(n, k - 1)) % P;
  ull n1 = expbin(n, k / 2);
  return (n1 * n1) % P;
}

ull inv(ull n) {
  return expbin(n, P - 2);
}

int main(void) {
  int n, i;
  ull num, den;
  while (fgets(str, MAX, stdin) != NULL) {
    memset(alf, 0, sizeof(alf));
    n = strlen(str) - 1; num = 1; den = 1;
    while (n) num = (n-- * num) % P;
    for (i = 0; str[i] != '\n'; i++)
      alf[str[i] - 'A']++;
    for (i = 0; i < 30; i++)
      while (alf[i] >= 2) den = (den * alf[i]--) % P;
    printf("%llu\n", (num * inv(den)) % P);
  }
  return 0;
}

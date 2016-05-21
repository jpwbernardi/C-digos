#include <stdio.h>

#define MAX 55
#define P 1000000007

typedef unsigned long long ull;
struct ponto { int x, y; ponto() {}
  ponto(int _x, int _y): x(_x), y(_y) {} };

char grid[MAX][MAX];

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

ull comb(ponto a, ponto b) {
  int i, j;
  ull nom = 1, den = 1;
  ull brancos = 0, pretos = 0, tot = 0;
  for (i = a.x; i <= b.x; i++)
    for (j = a.y; j <= b.y; j++)
      if (grid[i][j] == '.') brancos++;
      else pretos++;
  tot = brancos + pretos;
  while (tot > 1) nom = (tot-- * nom) % P;
  while (brancos > 1) den = (brancos-- * den) % P;
  while (pretos > 1) den = (pretos-- * den) % P;
  return (nom * inv(den)) % P;
}

int main(void) {
  int N, M, i;
  ponto a, b;
  scanf("%d %d\n", &N, &M);
  for (i = 0; i < N; i++) fgets(grid[i], MAX, stdin);
  while (scanf("%d %d %d %d", &a.x, &a.y, &b.x, &b.y) != EOF) {
    a.x--; a.y--; b.x--; b.y--;
    //printf("%d %d\n", a.x, a.y);
    printf("%llu\n", comb(a, b) - 1);
  }
  return 0;
}

#include <stdio.h>

#define MAX 16
#define MAXJ 35123
//força atual / força máxima
struct lutador { int fa, fm; lutador() {}
  lutador(int _f) : fa(_f), fm(_f) {} };

int vit[MAXJ][MAX], dV[MAXJ];
int N, K, pilha[MAXJ], tp;
lutador lut[MAXJ];

int exp(int n, int k) {
  int a;
  if(k == 0) return 1;
  if(k == 1) return n;
  if(k & 1) return n * exp(n, k - 1);
  a = exp(n, k / 2);
  return  a * a;
}

int sumula() {
  int i, j1, j2;
  while (!tp) {
    i = tp;
    while (i) {
      j1 = pilha[i]; j2 = pilha[i - 1];
      if(lut[j2].
    }
  }
}

int main(void) {
  int T, totJ, gan, f;
  scanf("%d", &T);
  while (T--) {
    scanf("%d %d", &N, &K);
    totJ = exp(2, N); tp = -1;
    for (i = 0; i < totJ; i++) {
      scanf("%d", &f);
      lut[i] = lutador(f);
      pilha[++tp] = i;
    }
    gan = simula();
    printaVit(gan);
  }
  return 0;
}

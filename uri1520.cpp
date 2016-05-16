#include <stdio.h>
#include <stdlib.h>

#define MAX 11234

int N, ini, fim;
int v[MAX];

int cmp(const void *a, const void *b) {
  return *(int *)a - *(int *)b;
}

int buscaBin(int chave) {
  int i = 0, f = fim, m;
  while (i < f) {
    m = (i + f) / 2;
    if(v[m] >= chave) f = m;
    else if(v[m] < chave) i = m + 1;
  }
  return v[i] == chave ? i : -1;
}

int descobreFim() {
  int i;
  for (i = ini; i < fim && v[i] == v[ini]; i++);
  return i - 1;
}

int main(void) {
  int X, Y, i;
  while (scanf("%d", &N) != EOF) {
    for (fim = i = 0; i < N; i++)
      for(scanf("%d %d", &X, &Y); X <= Y; X++)
        v[fim++] = X;
    qsort(v, fim, sizeof(int), &cmp);
    scanf("%d", &X);
    if((ini = buscaBin(X)) != -1) {
      Y = descobreFim();
      printf("%d found from %d to %d\n", X, ini, Y);
    } else printf("%d not found\n", X);
  }
  return 0;
}

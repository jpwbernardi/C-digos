#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;

#define MAX 112345
#define EPS 1e-4
#define igualDouble(x,y) (fabs ((x) - (y)) < EPS)
#define menorIgualDouble(x,y) ((x) < (y) || igualDouble(x,y))

int N, A;
int v[MAX], maior;

double area(double x) {
  double soma = 0;
  for (int i = 0; i < N; i++)
    soma += v[i] - x > 0 ? v[i] - x : 0;
  return soma;
}

double buscabinaria(int chave) {
  int i = 0;
  double p = 0, u = maior, m, a;
  while (i++ < 50) {
    m = (p + u) / 2; a = area(m);
    if (a > chave) p = m;
    else if (a < chave) u = m;
  }
  return igualDouble(area(m), chave) ? m : -1;
}

int main(void) {
  int i;
  double resp;
  while (scanf("%d %d", &N, &A), N) {
    for(maior = i = 0; i < N; i++) {
      scanf("%d", &v[i]);
      maior = max(maior, v[i]);
    }
    resp = buscabinaria(A);
    if (igualDouble(resp, 0)) printf(":D\n");
    else if(resp > 0) printf("%.4lf\n", resp);
    else printf("-.-\n");
  }
  return 0;
}

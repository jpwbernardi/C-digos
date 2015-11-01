#include <stdio.h>
#include <math.h>

#define MAX 1123

typedef struct{ int x, y; }ponto;
typedef long long ll;

int V;
ll v;
ponto p[MAX];

ll abs(ll num){
  if(num < 0) return -num;
  return num;
}

//Para calcular quantos pontos existem entre as cordenadas
ll euclides(ll a, ll b){
   if(b == 0) return a;
   if(a % b == 0 || a == 0) return b;
   return euclides(b, a % b);
}

//Retorna o dobro da área
ll area2(){
  ll result = 0.0, x1, y1, x2, y2;
  for (int i = 0; i < V; i++) {
    x1 = p[i].x; x2 = p[i + 1].x;
    y1 = p[i].y; y2 = p[i + 1].y;
    result += (x1 * y2 - x2 * y1);
    v += euclides(abs(x2 - x1), abs(y2 - y1));
  }
  return abs(result);
}

int main(void){
  int i;
  while(scanf("%d", &V), V){
    for(i = 0; i < V; i++) scanf("%d %d", &p[i].x, &p[i].y);
    p[i] = p[0]; v = 0;
    printf("%lld\n", (area2() - v + 2) >> 1);
  }
}

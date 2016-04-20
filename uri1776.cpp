#include <stdio.h>
#define MAX 1123456789
#define MAX1 321234


int primos[MAX1], tp;

void crivo(){
  int i, j, flag;
  primos[tp = 0] = 2;
  for(i = 3; i * i < MAX; i++){
    for(flag = 1, j = 0; flag && j < tp && primos[j] * primos[j] <= i; j++)
      if(i % primos[j] == 0) flag = 0;
    if(flag) primos[++tp] = i;
  }}


long long fatoraEVerifica(int N){
  int i, cont;
  long long ret = N;
  for(i = 0; i <= tp; i++){
    cont = 0;
    while(N % primos[i] == 0){
      N /= primos[i];
      cont++;
    }
    if(cont % 2) ret *= primos[i];
  }
  //Se N != 1, significa que o valor que sobrou é um primo
  if(N != 1) ret *= N;
  return ret;
}

int main(void){
  int T, N, casos;
  crivo();
  // for(int i = 0; i < 100; i++)
  //   printf("[%d]", primos[i]);
  scanf("%d", &T);
  for(casos = 1; casos <= T; casos++){
    scanf("%d", &N);
    printf("Caso #%d: %lld\n", casos, fatoraEVerifica(N));
  }

  return 0;
}

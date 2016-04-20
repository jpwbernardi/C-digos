#include <stdio.h>

#define MAX 1123456

int primos[MAX], tp;

void crivo(){
  int flag, i, j;
  primos[tp = 0] = 2;
  for(i = 3; i < MAX; i++){
    flag = 0;
    for(j = 0; !flag && j <= tp && primos[j] * primos[j] <= i; j++)
      flag |= !(i % primos[j]);
    if(!flag) primos[++tp] = i;
  }}

int fat(int N){
  int i = 0, ret = 0;
  for(i = 0; N != 1; i++){
    if(N % primos[i] == 0){
      ret++;
      while(N % primos[i] == 0) N /= primos[i];
    }}
  return ret;
}

int main(void){
  int N;
  crivo();
  while(scanf("%d", &N), N)
    printf("%d : %d\n", N, fat(N));
  return 0;
}

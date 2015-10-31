#include <stdio.h>
#include <string.h>

#define MAX 1000000012

int v[10];
long long cre, dec, num;
long long pilha[1123], topo = -1;
bool vis[MAX];

void limpavis(){
  while(topo >= 0){
    vis[pilha[topo--]] = 0;
  }}

void separa(){
  if(num == 0) v[0]++;
  while(num){ v[num % 10]++; num /= 10; }
}

void montacre(){
  int i, j;
  cre = 0;
  for(i = 0; i < 10; i++){
    for(j = 0; j < v[i]; j++){
      cre *= 10; cre += i;
    }}}

void montadec(){
  int i;
  dec = 0;
  for(i = 9; i >= 0; i--)
    while(v[i]){ dec *= 10; dec += i; v[i]--; }
}

int main(void){
  int chain;
  memset(v, 0, sizeof(v)); memset(vis, 0, sizeof(vis));
  while(scanf("%lld", &num), num){
    chain = 0; limpavis();
    printf("Original number was %lld\n", num);
    while(!vis[num]){
      vis[num] = true; pilha[++topo] = num;
      separa(); montacre(); montadec(); chain++;
      printf("%lld - %lld = %lld\n", dec, cre, (num = dec - cre));
    }
    printf("Chain length %d\n\n", chain);
  }
  return 0;
}

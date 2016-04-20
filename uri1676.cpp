#include <stdio.h>
#include <string.h>

#define MAX 51234

char pflag[MAX];
int N, primos[MAX], tp;

void crivo(){
  int i, j, cont;
  memset(pflag, 0, sizeof(pflag));
  for(i = 2; i < MAX; i++){
    if(pflag[i]) continue;
    for(cont = 0, j = i + 1; j < MAX; j++){
      if(!pflag[j]) cont++;
      if(cont == i) { pflag[j] = 1; cont = 0; }
    }}}

void monta(){
  int i;
  for(tp = -1, i = 2; i < MAX; i++){
    if(!pflag[i]) primos[++tp] = i;
  }}

int main(void){
  crivo(); monta();
  while(scanf("%d", &N), N)
    printf("%d\n", primos[N - 1]);
}

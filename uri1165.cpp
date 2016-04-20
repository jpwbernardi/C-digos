#include <stdio.h>
#include <string.h>

#define MAX 11234567

char pflag[MAX];

void crivo(){
  int i, j;
  memset(pflag, 0, sizeof(pflag));
  pflag[0] = pflag[1] = 1;
  for(i = 2 ; i * i < MAX; i++)
    for(j = i * 2; !pflag[i] && j < MAX; j += i)
      pflag[j] = 1;
}

int main(void){
  int N, X;
  scanf("%d", &N);
  crivo();
  while(N--){
    scanf("%d", &X);
    printf("%d %seh primo\n", X, pflag[X] ? "nao " : "");
  }
  return 0;
}

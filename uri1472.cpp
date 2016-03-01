#include <stdio.h>
#include <string.h>

int N;
int X[112345];

int main(void){
  int i, j, k, dist, cmp, resp;
  while(scanf("%d", &N) != EOF){
    for(i = 0; i < N; i++){
      scanf("%d", &dist);
      X[i] = i == 0 ? dist : dist + X[i - 1];
    }
    j = k = 0; resp = 0;
    cmp = X[N - 1] / 3;
    if(X[N - 1] % 3){ printf("0\n"); continue; }
    for(i = 0; X[i] + 2 * cmp <= X[N - 1] ; i++){
      for(; X[j] < X[i] + cmp; j++);
      for(; X[k] < X[i] + 2 * cmp; k++);

      if(X[j] == X[i] + cmp && X[k] == X[i] + 2 * cmp)
        resp++;
    }
    printf("%d\n", resp);
  }
  return 0;
}

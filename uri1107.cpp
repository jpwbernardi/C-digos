#include <stdio.h>

int main(void){
  int A, C;
  int h, resp;
  while(scanf("%d %d", &A, &C), A){
    resp = 0;
    while(C--){
      scanf("%d", &h);
      if(h < A) resp += (A - h);
      A = h;
    }
    printf("%d\n", resp);
  }
  return 0;
}

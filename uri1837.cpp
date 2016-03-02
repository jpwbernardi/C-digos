#include <stdio.h>
#include <math.h>

int main(void){
  int a, b, q, r;
  scanf("%d %d", &a, &b);
  for(r = 0; r <= 1000; r++){
    q = (a - r) / b;
    if( a == b * q + r) break;
  }

  printf("%d %d\n", q, r);

  return 0;
}

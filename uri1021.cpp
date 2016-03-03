#include <stdio.h>

int main(void){
  int p, m, i;
  int vp[6] = {100, 50, 20, 10, 5, 2}, vm[6] = {100, 50, 25, 10, 05, 1};
  int rp[6] = {0, 0, 0, 0, 0, 0}, rm[6] = {0, 0, 0, 0, 0, 0};
  scanf("%d.%d", &p, &m);
  m += (p % 2) * 100;
  for(i = 0; i < 6; i++){
    rm[i] = m / vm[i]; rp[i] = p / vp[i];
    m %= vm[i]; p %= vp[i];
  }
  printf("NOTAS:\n");
  for(i = 0; i < 6; i++)
    printf("%d nota(s) de R$ %d.00\n", rp[i], vp[i]);
  printf("MOEDAS:\n");
  for(i = 0; i < 6; i++)
    printf("%d moeda(s) de R$ %.2lf\n", rm[i], vm[i] / 100.0);
  return 0;
}

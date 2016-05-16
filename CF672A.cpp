#include <stdio.h>

#define MAX 3 * 1123

char str[MAX];

void monta() {
  int i;
  str[0] = '\0';
  for (i = 1; i < 1000; i++)
    sprintf(str, "%s%d", str, i);
}

int main(void) {
  int N;
  monta();
  scanf("%d", &N);
  printf("%c\n", str[N - 1]);
  return 0;
}

#include <stdio.h>
#include <string.h>

#define MAX 1123456

int N;
char seq[40][MAX];

void montaseq() {
  int i, j, top = 0, cont, tam;
  char atual;
  seq[0][0] = '3'; seq[0][1] = '\0';
  for (i = 1, top = 0; i < 40; i++) {
    tam = strlen(seq[i - 1]);
    for (cont = j = 0; j < tam;) {
      atual = seq[i - 1][j];
      while(seq[i - 1][j++] == atual) cont++;
      seq[i][top++] = cont + '0';
      seq[i][top++] = atual;
      printf("%c%c", seq[i][top - 2], seq[i][top - 1]);
    }
    printf("\n");
    seq[i][top] = '\0';
  }}

int main(void) {
  int i;
  montaseq();
  for (i = 0; i < 5; i++) printf("%s\n", seq[i]);
  printf("---------\n");
  while (scanf("%d", &N) != EOF)
    printf("%s\n", seq[N - 1]);
  return 0;
}

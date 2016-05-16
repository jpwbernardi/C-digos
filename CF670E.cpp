#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 512123

int N, M, p, top;
char bracket[MAX], stack[MAX];
int posstack[MAX];
int pos[MAX], left[MAX], right[MAX];

void push(char c, int pos) {
  stack[top] = c;
  posstack[top++] = pos;
}

void magicpop() {
  int i, j;
  if (top <= 1) return;
  if (stack[top - 1] != stack[top - 2]) {
    i = posstack[top - 1]; j = posstack[top - 2];
    pos[i] = j; pos[j] = i; //I fecha em J e J fecha em I
    top -= 2;
  }
}

void monta() {
  int i = 0; top = 0;
  do {
    push(bracket[i], i);
    i++; magicpop();
  } while (top > 0 || i < N);
  for (i = 0; i < N; i++) {
    right[i] = i + 1 < N ? i + 1 : -1;
    left[i] = i - 1;
  }
}

int main(void) {
  int ini, fim, tmp;
  scanf("%d %d %d\n", &N, &M, &p); p--;
  scanf("%s\n", bracket); monta();
  while (M--) {
    switch (getchar()) {
    case 'R': p = right[p]; break;
    case 'L': p = left[p]; break;
    case 'D':
      ini = p; fim = pos[p];
      if (ini > fim) { tmp = fim; fim = ini; ini = tmp; }
      if (right[fim] != -1) left[right[fim]] = left[ini];
      if (left[ini] != -1) right[left[ini]] = right[fim];
      if (right[fim] == -1 && left[ini] == -1) { p = -1; break; }
      else if (right[fim] == -1) p = left[ini];
      else p = right[fim];
    }}
  while (p != -1 && left[p] != -1) p = left[p];
  while (p != -1) { printf("%c", bracket[p]); p = right[p]; }
  printf("\n");
  return 0;
}

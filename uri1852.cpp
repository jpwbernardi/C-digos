#include <stdio.h>
#include <string.h>
#include <map>
#include <vector>
#include <string>
using namespace std;

#define MAX 512

int N;
map<string, int> M;
char child[MAX][123], wolf[MAX][123];
int childprefer[MAX][MAX], wolfprefer[MAX][MAX];
int marc[MAX], marw[MAX], proposed[MAX][MAX];

void stablemarriage() {
  int c, c1, w, i, change;
  memset(marc, -1, sizeof(marc)); memset(marw, -1, sizeof(marw));
  memset(proposed, 0, sizeof(proposed));
  do {
    change = 0;
    for (c = 0; c < N; c++)
      //Se a criança não tem par, procuro o primeiro lobo para quem ela não propos
      for (i = 0; marc[c] == -1 && i < N; i++) {
        w = childprefer[c][i];
        if (proposed[c][w]) continue; proposed[c][w] = 1;
        //Se não está casado, caso
        if (marw[w] == -1) {
          marc[c] = w; marw[w] = c;
          change = 1;
        } else { //Caso contrário, verifico se não é melhor eu mudar o casamento
          c1 = marw[w];
          if (wolfprefer[w][c] < wolfprefer[w][c1]) {
            marc[c1] = -1; marc[c] = w; marw[w] = c;
            change = 1;
          }}}
  } while (change);
}

int main(void) {
  int i, j, w, c;
  char name[MAX];
  scanf("%d\n", &N);
  for (i = 0; i < N; i++) {
    scanf("%s", child[i]);
    c = M[child[i]] = i;
    for (j = 0; j < N; j++) {
      scanf("%s", name);
      if (M.find(name) == M.end())
        { strcpy(wolf[j], name); M[name] = j; }
      w = M[name];
      childprefer[c][j] = w;
    }}
  for (i = 0; i < N; i++) {
    scanf("%s", name);
    w = M[name];
    for (j = 0; j < N; j++) {
      scanf("%s", name);
      c = M[name];
      wolfprefer[w][c] = j;
    }}
  stablemarriage();
  for (i = 0; i < N; i++)
    printf("%s %s\n", child[i], wolf[marc[i]]);
  return 0;
}

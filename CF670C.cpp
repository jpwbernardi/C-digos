#include <stdio.h>
#include <map>
using namespace std;
#define MAX 212123

int movies[MAX];
map<int, int> M;

int main(void) {
  int n, m, lang, sub, i;
  int feliz, felizinho, resp;
  scanf("%d", &n);
  for (i = 0; i < n; i++) { scanf("%d", &lang); M[lang]++; }
  scanf("%d", &m);
  for (i = 0; i < m; i++) scanf("%d", &movies[i]);
  scanf("%d", &sub); resp = 0;
  feliz = M[movies[0]]; felizinho = M[sub];
  for (i = 1; i < m; i++) {
    scanf("%d", &sub);
    if (M[movies[i]] > feliz ||
        (M[movies[i]] == feliz && M[sub] > felizinho))
      { feliz = M[movies[i]]; felizinho = M[sub]; resp = i; }
  }
  printf("%d\n", resp + 1);
  return 0;
}

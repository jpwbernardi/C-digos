#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <vector>
#include <utility>
#include <queue>
using namespace std;

#define MAX 112345
#define MAXS 512345

struct aresta { int u, v, c; aresta() {}
  aresta(int _u, int _v, int _c) : u(_u), v(_v), c(_c) {} };

typedef pair<int, int> ii;
typedef vector< int > vi;

int N, M, S;
aresta E[MAX];
char ok[MAXS];
ii consultas[MAXS];
int pai[MAX], rk[MAX], resp[MAXS];

void Make(int x) { pai[x] = x; rk[x] = 0; }
int Find(int x) { return pai[x] == x ? x : (pai[x] = Find(pai[x])); }
void Union(int _x, int _y, int valor, vector<vi> &indices) {
  int i, k;
  int x = Find(_x), y = Find(_y);
  if (x == y) return;
  if (rk[y] > rk[x]) return Union(y, x, valor, indices);
  if (rk[x] == rk[y]) rk[x]++;
  pai[y] = x;
  for (i = 0; i < (int)indices[y].size(); i++) {
    k = indices[y][i];
    if((consultas[k].first == x ||
        consultas[k].second == x) && !ok[k]) {
      ok[k] = 1; resp[k] = valor;
    } else if (!ok[k]) {
      indices[x].push_back(k);
      if (consultas[k].first == y) consultas[k].first = x;
      else consultas[k].second = x;
    }}}

void kruskal(vector<vi> &indices) {
  int u, v, i;
  for (i = 0; i < M; i++) {
    u = E[i].u; v = E[i].v;
    if (Find(u) != Find(v))
      Union(u, v, E[i].c, indices);
  }}

int cmp(const void *a, const void *b) {
  aresta *e = (aresta *)a, *f = (aresta *)b;
  return f->c - e->c;
}

int main(void) {
  int s, t, u, v, p, m, i;
  while (scanf("%d %d %d", &N, &M, &S) != EOF) {
    for (i = 0; i < N; i++) Make(i);
    for (m = 0; m < M; m++) {
      scanf("%d %d %d", &u, &v, &p); u--; v--;
      E[m] = aresta(u, v, p);
    }
    qsort(E, M, sizeof(aresta), &cmp);
    vector<vi> indices(N);
    memset(ok, 0, sizeof(ok));
    for (i = 0; i < S; i++) {
      scanf("%d %d", &s, &t); s--; t--;
      consultas[i] = ii(s, t);
      indices[s].push_back(i); indices[t].push_back(i);
    }
    kruskal(indices);
    for (i = 0; i < S; i++) printf("%d\n", resp[i]);
  }
  return 0;
}

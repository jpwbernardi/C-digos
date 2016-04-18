#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

#define MAX 112
#define INF 1123456789

int LG[3*MAX*MAX][MAX], dg[3*MAX*MAX], en, mei, sai;
int d[3*MAX*MAX], low[3*MAX*MAX], seen[3*MAX*MAX], st[3*MAX*MAX], comp[3*MAX*MAX];
int sn, ncomp, tempo, S[3*MAX*MAX], svis[3*MAX*MAX];

void tarjan(int u) {
  int i, v;
  st[sn++] = u; seen[u] = 1;
  d[u] = low[u] = tempo++;
  for (i = 0; i < dg[u]; i++) {
    v = LG[u][i];
    if (!seen[v]) { tarjan(v); low[u] = min(low[u], low[v]); }
    else { low[u] = min(low[u], d[v]); }
  }
  if (d[u] == low[u]) {
    do { v = st[--sn]; d[v] = INF; } while (v != u);
    ncomp++;
    }}

int dfs(int u, int flag) {
  int i, ret = 0;
  if (S[u] != -1) return S[u];
  if (u >= en + mei) {
    if (flag) svis[u] = S[u] = 1;
    return ret = 1;
  }
  for (i = 0; i < dg[u]; i++) {
    ret |= dfs(LG[u][i], flag);
  }
  return S[u] = ret;
}

int main(void) {
  int i, k, a, valido;
  scanf("%d %d %d", &en, &mei, &sai);
  memset(dg, 0, sizeof(dg));
  for (i = 0; i < mei; i++) {
    scanf("%d", &k);
    while (k--) {
      scanf("%d", &a); a--;
      LG[a][dg[a]++] = en + i;
    }}
  for (i = 0; i < sai; i++) {
    scanf("%d", &a); a--;
    LG[a][dg[a]++] = en + mei + i;
  }
  memset(d, 0, sizeof(d)); memset(low, 0, sizeof(low));
  memset(seen, 0, sizeof(seen));
  for (tempo = 1, sn = ncomp = i = 0; i < en + mei + sai; i++)
    if (!d[i]) tarjan(i);
  valido = (ncomp == en + mei + sai);
  memset(S, -1, sizeof(S)); memset(svis, 0, sizeof(svis));
  for (i = 0; valido && i < en + mei; i++){
    S[i] = dfs(i, !(i < en));
    valido &= S[i];
  }
  for (i = en + mei; valido && i < sai; i++)
    valido &= svis[i];
  printf("%s\n", valido ? "o.o" : "u.u");
  return 0;
}

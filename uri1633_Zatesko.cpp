#include<stdio.h>
#include<stdlib.h>
#include<utility>
#include<vector>
#include<queue>
using namespace std;

#define MAX 112345

typedef struct { int t, c; } proc;
typedef pair<int, int> ii;

proc P[MAX];

int cmp(const void *a, const void *b) {
  proc *p1 = (proc *)a, *p2 = (proc *)b;
  return p1->t - p2->t;
}

int main(void) {
  int n, i, t;
  long long resp;
  while (scanf("%d", &n) != EOF) {
    priority_queue< ii, vector<ii>, greater<ii> > Q;
    for (i = 0; i < n; i++) scanf("%d %d", &P[i].t, &P[i].c);
    qsort(P, n, sizeof(proc), &cmp);
    i = 0; t = 1; resp = 0;
    while (i < n || !Q.empty()) {
      while (i < n && P[i].t <= t) {
        Q.push(ii(P[i].c, P[i].t)); i++;
      }
      if (!Q.empty()) {
        resp += t - Q.top().second; t += Q.top().first; Q.pop();
      } else if (i < n) { t = P[i].t; }
    }
    printf("%lld\n", resp);
  }
  return 0;
}

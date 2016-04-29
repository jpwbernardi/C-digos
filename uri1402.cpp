#include <stdio.h>
#include <math.h>
#include <string.h>
#include <algorithm>
using namespace std;

#define MAX 1123
#define INF 112345678
#define HOR 0
#define VER 1
#define sqr(x) ((x) * (x))
struct point { int x, y;
  point() { x = y = 0.0; }
  point(int _x, int _y) : x(_x), y(_y){}
};
struct seg{ point a, b; char dir; seg(){}
  seg(int _x, int _y, int l) : a(_x, _y) {
    if(l >= 0) { b.x = _x + l; b.y = _y; dir = HOR; }
    else { l = -l; b.x = _x; b.y = _y + l; dir = VER; }
  }};

seg V[MAX];
int N, AG[MAX][MAX], vis[MAX], distmin[MAX], pai[MAX];

double dist(point p1, point p2) {
  return (p1.x - p2.x) * (p1.x - p2.x)
    + (p1.y - p2.y) * (p1.y - p2.y);
}

int intersec(point k, point l, point m, point n) {
  if(l.x < m.x || k.x > n.x || k.y > n.y || l.y < m.y) return 0;
  return 1;
}

int dist2hor(seg r, seg s) {
  if(intersec(r.a, r.b, s.a, s.b)) return 0;
  if(r.a.y == s.a.y) return sqr(min(min(abs(r.a.x - s.a.x), abs(r.a.x - s.b.x)),
                                    min(abs(r.b.x - s.a.x), abs(r.b.x - s.b.x))));
  if((r.a.x <= s.a.x && r.b.x >= s.a.x) || (r.a.x <= s.b.x && r.b.x >= s.b.x) ||
     (s.a.x <= r.a.x && s.b.x >= r.a.x) || (s.b.x <= r.b.x && s.b.x >= r.a.x))
    return sqr(abs(r.a.y - s.a.y));
  return min(min(dist(r.a, s.a), dist(r.a, s.b)),
             min(dist(r.b, s.a), dist(r.b, s.b)));
}

int dist2ver(seg r, seg s) {
  if(intersec(r.a, r.b, s.a, s.b)) return 0;
  if((r.a.y <= s.a.y && r.b.y >= s.a.y) || (r.a.y <= s.b.y && r.b.y >= s.b.y) ||
     (s.a.y <= r.a.y && s.b.y >= r.a.y) || (s.b.y <= r.b.y && s.b.y >= r.a.y))
    return sqr(abs(r.a.x - s.a.x));
  return min(min(dist(r.a, s.a), dist(r.a, s.b)),
             min(dist(r.b, s.a), dist(r.b, s.b)));
}

int dist2(seg r, seg s) {
  if(r.dir == s.dir && r.dir == HOR) return dist2hor(r, s);
  if(r.dir == s.dir && r.dir == VER) return dist2ver(r, s);
  if(r.dir == VER) return dist2(s, r);
  //r.dir == hor && s.dir = vert
  if(r.a.x <= s.a.x && r.b.x >= s.a.x && (r.a.y <= s.b.y && r.a.y >= s.a.y)) return 0;
  if(r.a.x <= s.a.x && r.b.x >= s.a.x)
    return sqr(min(abs(r.a.y - s.a.y), abs(r.a.y - s.b.y)));
  if(r.a.y >= s.a.y && r.a.y <= s.b.y)
    return sqr(min(abs(r.a.x - s.a.x), abs(r.b.x - s.a.x)));
  return min(min(dist(r.a, s.a), dist(r.a, s.b)),
             min(dist(r.b, s.a), dist(r.b, s.b)));
}

int minDist(){
  int i, ret = -1;
  for(i = 0; i < N; i++)
    if((ret == -1 && !vis[i]) || (ret != -1 && distmin[ret] >= distmin[i] && !vis[i]))
      ret = i;
  return ret;
}

void prim() {
  int u, i, c, c1, c2;
  memset(vis, 0, sizeof(vis));
  for(i = 0; i < N; i++) distmin[i] = INF;
  distmin[0] = 0;
  while ((u = minDist()) != -1) {
    vis[u] = 1;
    for (i = 0; i < N; i++) {
      c = dist2(V[u], V[i]);
      if (!vis[i] && c < distmin[i]){ distmin[i] = c; pai[i] = u; }
    }}}

int main(void) {
  int x, y, l, i, resp;
  while (scanf("%d", &N), N) {
    for (i = 0; i < N; i++) {
      scanf("%d %d %d", &x, &y, &l);
      seg u(x, y, l); V[i] = u;
    }
    resp = 0; prim();
    for (i = 1; i != 0; i = pai[i])
      resp = max(distmin[i], resp);
    printf("%.2lf\n", sqrt(resp));
  }
  return 0;
}

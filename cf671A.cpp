#include <stdio.h>
#include <queue>
#include <vector>
#include <math.h>
#include <utility>
using namespace std;

#define EPS 1e-8
#define MAX 112456
#define sq(x) (x) * (x)
#define menorigual(x, y) fabs((x) - (y)) < EPS || (x) < (y) ? 1 : 0;

struct ponto { int x, y; ponto() {}
  ponto(int _x, int  _y): x(_x), y(_y) {} };
typedef pair<int, int> ii;

int N;
ponto a, b, t;
ponto lixo[MAX];

long double dist(ponto a, ponto b) {
  return sqrt(sq(a.x - b.x) + sq(a.y - b.y));
}

long double calcdist() {
  long double ret = 0;
  int fa = 0, fb = 0, i, sa = 0, sb = 0;
  for (i = 0; i < N; i++)
    ret += 2 * dist(lixo[i], t);
  for (i = 0; i < N; i++) {
    if (ret - dist(lixo[fa], t) + dist(lixo[fa], a) >
        ret - dist(lixo[i], t) + dist(lixo[i], a)) fa = i;
    if (ret - dist(lixo[fb], t) + dist(lixo[fb], b) >
        ret - dist(lixo[i], t) + dist(lixo[i], b)) fb = i;
  }
  for (i = 0; i < N; i++) {
    if (ret - dist(lixo[sa], t) + dist(lixo[sa], a) >
        ret - dist(lixo[i], t) + dist(lixo[i], a) && i != fa) sa = i;
    if (ret - dist(lixo[sb], t) + dist(lixo[sb], b) >
        ret - dist(lixo[i], t) + dist(lixo[i], b) && i != fb) sb = i;
  }
  if (mina != minb) {
    if (ret - dist(lixo[mina], t) + dist(lixo[mina], a) >
        ret - dist(lixo[minb], t) + dist(lixo[minb], b)) {
      ret += -dist(lixo[mina], t) + dist(lixo[mina], a);
      if (ret > ret - dist(lixo[minb], t) + dist(lixo[minb], b))
      ret += -dist(lixo[minb], t) + dist(lixo[minb], b);
    } else {
      ret += -dist(lixo[minb], t) + dist(lixo[minb], b);
      if (ret > ret - dist(lixo[mina], t) + dist(lixo[mina], a))
        ret += -dist(lixo[mina], t) + dist(lixo[mina], a);
    }
  } else {

  }
  printf("%Lf\n", ret);
  printf("A> %d %Lf %Lf\n", mina, dist(lixo[mina], a), dist(lixo[mina], t));
  printf("B> %d %Lf %Lf\n", minb, dist(lixo[minb], b), dist(lixo[minb], t));
  return ret;
}

int main(void) {
  int i;
  scanf("%d %d %d %d %d %d", &a.x, &a.y, &b.x, &b.y, &t.x, &t.y);
  scanf("%d", &N);
  for (i = 0; i < N; i++) scanf("%d %d", &lixo[i].x, &lixo[i].y);
  printf("%.12Lf\n", calcdist());
  return 0;
}

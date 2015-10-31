#include <stdio.h>
#include <math.h>
#include <string.h>
#include <algorithm>
using namespace std;

#define INFTO 112345678
#define MAX 20
#define MAX2 1123456

int N;
int x[MAX], y[MAX];
double dist[MAX][MAX];
double s[MAX2];
bool vis[MAX2];

double pd(int mask){
  //Já foram feitas todas as escolhas
  if(mask == (1 << N)  - 1) return 0;
  if(vis[mask]) return s[mask];

  int i, j;
  double ret;
  //Escolho o primeiro que não foi escolhido ('livre')
  for(i = 0; i < N; i++)
    if(!(mask & (1 << i))) break;

  //Marco como escolhido
  mask |= (1 << i);
  //Escolho um par
  for(ret = INFTO, j = 0; j < N; j++){
    //Se o j não foi escolhido ainda...
    if(!(mask & (1 << j)))
      ret = min(ret, pd(mask | (1 << j)) + dist[i][j]);
  }
  vis[mask] = true;
  return s[mask] = ret;
}

void calculaDist(){
  int i, j;
  double x_, y_;
  for(i = 0; i < N; i++)
    for(j = 0; j < N; j++){
      x_ = x[i] - x[j]; y_ = y[i] - y[j];
      dist[i][j] = sqrt(x_ * x_ + y_ * y_);
    }
}

int main(void){
  int i, caso = 0;
  char lixo[30];
  while(scanf("%d ", &N), N){
    N *= 2; caso++; memset(vis, 0, sizeof(vis));
    for(i = 0; i < N; i++) scanf("%s %d %d ", lixo, &x[i], &y[i]);
    calculaDist();
    printf("Case %d: %.2lf\n", caso, pd(0));
  }
  return 0;
}

#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

#define MAX 1123
#define CRIVO 11234567

char P;
bool pri[CRIVO], vis[MAX][MAX][6];
int L, C, K, S[MAX][MAX][6], M[MAX][MAX];

void crivo(){
  int i, j;
	memset(pri, false, sizeof(pri));
	pri[0] = true; pri[1] = true;
    for(i = 2; i * i < CRIVO ; i++)
      if(!pri[i])
			   for(j = i * i ; j < CRIVO; j += i)
				       pri[j] = true;
}

int pd(int i, int j, int k){
  int x, y;
  if(vis[i][j][k]) return S[i][j][k];
  y = x = 0;
  if(P == 'N'){
    //Considerando a vantagem do primo:
    if(i != 0 && !pri[M[i][j]] && k < K) x = max(pd(i - 1, j, k + 1), x);
    if(j != C - 1 && !pri[M[i][j]] && k < K) x = max(pd(i, j + 1, k + 1), x);
    //Não usando o primo:
    if(i != 0 && M[i][j] > M[i - 1][j]) y = max(pd(i - 1, j, k), y);
    if(j != C - 1 && M[i][j] > M[i][j + 1]) y = max(pd(i, j + 1, k), y);

  }else{
    //Considerando a vantagem do primo:
    if(i != L - 1 && !pri[M[i][j]] && k < K) x = max(pd(i + 1, j, k + 1), x);
    if(j != 0 && !pri[M[i][j]] && k < K) x = max(pd(i, j - 1, k + 1), x);
    //Não usando o primo:
    if(i != L - 1 && M[i][j] > M[i + 1][j]) y = max(pd(i + 1, j, k), y);
    if(j != 0 && M[i][j] > M[i][j - 1]) y = max(pd(i, j - 1, k), y);
  }
  vis[i][j][k] = true;
  return S[i][j][k] = max(x, y) + 1;
}

int main(void){
  int resp, i, j;
  crivo();
  while(scanf("%d %d %d\n", &L, &C, &K), L){
    P = getchar();
    resp = 0; memset(vis, false, sizeof(vis));
    for(i = 0; i < L; i++)
      for(j = 0; j < C; j++)
        scanf("%d", &M[i][j]);
    for(i = 0; i < L; i++){
      for(j = 0; j < C; j++){
        if(!vis[i][j][0]){
          pd(i, j, 0);
          if(S[i][j][0] > resp) resp = S[i][j][0];
        }
        //printf("[%d]", S[i][j][0]);
      }
      //printf("\n");
    }
    printf("%d\n", resp);
  }
  return 0;
}

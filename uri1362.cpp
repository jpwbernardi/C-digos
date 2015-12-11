#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

#define MAX 312
#define INF 112345678

int s, t;
int T, N, M;
char A[2][5];
int B[MAX][2];
int LG[MAX][MAX], dG[MAX], AG[MAX][MAX], cam[MAX], tcam;;

int bfs(void) {
  int fila[MAX], inic, fim, dist[MAX], p[MAX], u, i, v, garg = INF;
  for (u = 0; u < MAX; u++) dist[u] = INF;
  dist[s] = 0; fila[inic = fim = 0] = s;
  while (inic <= fim) {
    u = fila[inic++];
    for (i = 0; i < dG[u]; i++) {
      v = LG[u][i];
      if (dist[v] == INF && AG[u][v] > 0) {
        dist[v] = dist[u] + 1; p[v] = u; fila[++fim] = v;
        if (v == t) { inic = fim + 1; break; }
      }}}
  if (dist[t] == INF) return 0;
  tcam = dist[t] + 1;
  for (i = dist[t]; i > 0; i--) {
    cam[i] = v; v = p[v];
    garg = min(garg, AG[v][cam[i]]);
  }
  cam[0] = s;
  return garg;
}

int ffek(void) {
  int f = 0, garg, i, u, v;
  while ((garg = bfs())) {
    for (i = 0; i <= tcam - 2; i++) {
      u = cam[i]; v = cam[i + 1];
      AG[u][v] -= garg; AG[v][u] += garg;
    }
    f += garg;
  }
  return f;
}

void montagrafo(){
  int i, v, j;
  memset(dG, 0, sizeof(dG));
  memset(AG, 0, sizeof(AG));
  for(i = 1; i <= 6; i++){
    LG[s][dG[s]++] = i; AG[s][i] = N / 6;
    LG[i][dG[i]++] = s;
    for(j = 0; j < M; j++){
      v = j + 10;
      if(!AG[v][t]){
        LG[v][dG[v]++] = t;  AG[v][t] = 1;
      }
      if(B[j][0] == i || B[j][1] == i){
        LG[i][dG[i]++] = v; AG[i][v] = 1;
        LG[v][dG[v]++] = i;
      }}}}

void printagrafo(){
  int i, j;
  for(i = 0; i < MAX; i++){
    if(dG[i] != 0){
      printf("%d: {", i);
      for(j = 0; j < dG[i]; j++){
        printf("%s %d", !j ? "" : ",", LG[i][j]);
      }
      printf("}\n");
    }}}

int main(void){
  int i;
  t = 100; s = 0;
  scanf("%d", &T);
  while(T--){
    scanf("%d %d\n", &N, &M);
    // xxl = N / 6; xl = xxl * 2; l = xxl * 3; m = xxl * 4; s = xxl * 5; xs = xxl * 6;
    for(i = 0; i < M; i++){
      scanf("%s %s\n", A[0], A[1]);
      if(!strcmp(A[0], "XXL")) B[i][0] = 1;
      else if(!strcmp(A[0], "XL")) B[i][0] = 2;
      else if(!strcmp(A[0], "L")) B[i][0] = 3;
      else if(!strcmp(A[0], "M")) B[i][0] = 4;
      else if(!strcmp(A[0], "S")) B[i][0] = 5;
      else if(!strcmp(A[0], "XS")) B[i][0] = 6;

      if(!strcmp(A[1], "XXL")) B[i][1] = 1;
      else if(!strcmp(A[1], "XL")) B[i][1] = 2;
      else if(!strcmp(A[1], "L")) B[i][1] = 3;
      else if(!strcmp(A[1], "M")) B[i][1] = 4;
      else if(!strcmp(A[1], "S")) B[i][1] = 5;
      else if(!strcmp(A[1], "XS")) B[i][1] = 6;
    }
    montagrafo();
    // printagrafo();
    printf("%s\n", ffek() == M ? "YES" : "NO");
  }
  return 0;
}

#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

#define MAX 1123

int s[MAX][MAX];
char txt[MAX];

int pd(int l, int r){
  if(s[l][r]) return s[l][r];
  if(l == r) return 1;
  if(l + 1 == r) return s[l][r] = (txt[l] == txt[r] ? 2 : 1);
  if(txt[l] == txt[r]) return s[l][r] = 2 + pd(l + 1, r - 1);
  else return s[l][r] = max(pd(l, r - 1), pd(l + 1, r));
}

int main(void){
  int N;
  scanf("%d", &N); getchar();
  while(N--){
    fgets(txt, 1123, stdin); memset(s, 0, sizeof(s));
    if(strlen(txt) == 1){ printf("0\n"); continue; }
    printf("%d\n", pd(0, strlen(txt) - 2));
  }
  return 0;
}

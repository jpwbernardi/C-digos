#include <stdio.h>
#include <string.h>

#define MAX 2123
#define MAXL 123

int primos[MAX], tp, qtdL[MAXL];
char s[MAX], pflag[MAX];

void crivo(){
  int flag, i, j;
  primos[tp = 0] = 2; pflag[2] = 1;
  for(i = 3; i < MAX; i++){
    flag = 0;
    for(j = 0; !flag && j <= tp && primos[j] * primos[j] <= i; j++)
      flag |= !(i % primos[j]);
    if(!flag) { primos[++tp] = i; pflag[i] = 1; }
  }}

char decodifica(int i){
  if(i >= 0 && i <= 9) return i + '0';
  if(i >= 10 && i <= 35) return i + 'A' - 10;
  return i + 'a' - 36;
}

int codifica(char c){
  if(c >= '0' && c <= '9') return c - '0';
  if(c >= 'A' && c <= 'Z') return c - 'A' + 10;
  return c - 'a' + 36;
}

void contaLetras(){
  int i;
  memset(qtdL, 0, sizeof(qtdL));
  for(i = 0; s[i] != '\n'; i++)
    qtdL[codifica(s[i])]++;
}


int main(void){
  int T, flag, caso, i;
  scanf("%d\n", &T);
  memset(pflag, 0, sizeof(pflag)); crivo();
  for(caso = 1; caso <= T; caso++){
    fgets(s, MAX, stdin);
    contaLetras();
    printf("Case %d: ", caso);
    for(flag = i = 0; i < MAXL; i++)
      if(pflag[qtdL[i]]) { printf("%c", decodifica(i)); flag = 1; }
    if(!flag) printf("empty");
    printf("\n");
  }
  return 0;
}

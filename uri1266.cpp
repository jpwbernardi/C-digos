#include <stdio.h>

int N, resp;
int postes[5123];

void printapostes(){
  for(int i = 0; i < N; i++){
    printf("%d ", postes[i]);
  }
  printf("\n");
}

void preenche(int i){
  int cont = 0, pilha[5123], topo, u;
  pilha[topo = 0] = i;
  while(topo >= 0){
    u = pilha[topo--];
    cont++; postes[u] = 1;
    if(!postes[(u - 1 + N) % N]) pilha[++topo] = (u - 1 + N) % N;
    if(!postes[(u + 1) % N]) pilha[++topo] = (u + 1) % N;
  }
  resp += cont / 2;
}

int main(void){
  int i;
  while(scanf("%d", &N), N){
    resp = 0;
    for(i = 0; i < N; i++) scanf("%d", &postes[i]);
    for(i = 0; i < N; i++)
      if(!postes[i]) preenche(i);
    printf("%d\n", resp);
  }
  return 0;
}

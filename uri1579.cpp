#include <stdio.h>

#define MAX 112

int painel[MAX];
int np, cam, frete;

int qtdCaminhoes(int pesoMax) {
  int i;
  int pesoAtual = 0, qtd = 1;
  for (i = 0; i < np; i++) {
    if (pesoAtual + painel[i] > pesoMax) { qtd++; pesoAtual = painel[i]; }
    else pesoAtual += painel[i];
  }
  return qtd;
}

int buscabin(int ini, int fim) {
  int meio;
  while (ini < fim) {
    meio = ini + (fim - ini) / 2;
    if (cam >= qtdCaminhoes(meio)) fim = meio;
    else ini = meio + 1;
  }
  return ini;
}

int main(void) {
  int N, i;
  int min, max, resp;
  scanf("%d", &N);
  while (N--) {
    max = min = 0;
    scanf("%d %d %d", &np, &cam, &frete);
    for (i = 0; i < np; i++) {
      scanf("%d", &painel[i]);
      if (painel[i] > min) min = painel[i];
      max += painel[i];
    }
    resp = buscabin(min, max);
    printf("%d $%d\n", resp, resp * cam * frete);
  }
  return 0;
}

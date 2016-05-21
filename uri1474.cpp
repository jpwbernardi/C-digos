#include <stdio.h>

#define P 1000000

typedef unsigned long long ull;

void identidade(ull c[2][2]) {
  c[0][0] = 1; c[1][0] = 0;
  c[0][1] = 0; c[1][1] = 1;
}

void multmat(ull A[2][2], ull B[2][2], ull C[2][2]) {
  int i, j, k;
  for (i = 0; i < 2; i++)
    for (j = 0; j < 2; j++)
      for (C[i][j] = k = 0; k < 2; k++)
        { C[i][j] += (A[i][k] % P) * (B[k][j] % P) ; C[i][j] %= P; }
}

void expmat(ull A[2][2], ull n, ull B[2][2]) {
  ull C[2][2];
  if (n == 0) { identidade(B); return; }
  if (n & 1) { expmat(A, n - 1, C); multmat(A, C, B); return; }
  expmat(A, n / 2, C); multmat(C, C, B);
}

int main(void) {
  ull N, K, L;
  ull rec[2][2], tmp[2][2], resp[2][2];
  while (scanf("%llu %llu %llu", &N, &K, &L) != EOF) {
    rec[0][0] = 0; rec[0][1] = L; rec[1][0] = 1; rec[1][1] = K;
    expmat(rec, N / 5, tmp);
    rec[0][0] = 1; rec[0][1] = K; rec[1][0] = 0; rec[1][1] = 0;
    multmat(rec, tmp, resp);
    printf("%.6llu\n", resp[0][0] % P);
  }
  return 0;
}

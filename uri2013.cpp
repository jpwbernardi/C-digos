#include <stdio.h>
#include <string.h>

int tam, ret;
char U[22];
char num[10];

int possoDiminuir(int i){
  while(--i >= 0){
    if(num[i] < 2){
      ret = i;
      return 1;
    }}
  return 0;
}

void preenche(int i){
  int j;
  for(; i < tam; i++){
    for(j = 9; j >= 0; j--){
      if(num[j] < 2){
        U[i] = j + '0'; num[j]++;
        break;
      }}}}

int main(void){
  int i;
  fgets(U, 22, stdin);
  memset(num, 0, sizeof(num));
  tam = strlen(U) - 1;
  U[tam] = '\0';
  //Acho o primeiro numero que repete pela terceira vez
  for(i = 0; i < tam; i++){
    num[U[i] - '0']++;
    if(num[U[i] - '0'] > 2) break;
  }
  //Vou voltando no numero tentanndo diminuir um valor
  for(; i != tam && i >= 0; num[U[i] - '0']--, i--){
    if(possoDiminuir(U[i] - '0')){ //Guardo o valor para qual posso diminuir em ret
      num[U[i] - '0']--;
      num[ret]++;
      U[i] = ret + '0';
      //Achei um valor que posso diminuir, então só preencho a partir da posição i + 1 com os maiores valores possíveis
      preenche(i + 1);
      break;
    }
  }
  if(U[0] == '0') printf("%s\n", U + 1); //Trato quando a entrada é 10^18
  else printf("%s\n", U);
  return 0;
}

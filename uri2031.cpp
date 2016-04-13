#include <stdio.h>
#include <string.h>

#define MAX 112
#define PAPEL 0
#define PEDRA 1
#define AEREO 3

char j1[MAX], j2[MAX];
int codj1, codj2;

int cod(char j[MAX]){
    if (!strcmp(j, "pedra")) return PEDRA;
    if (!strcmp(j, "papel")) return PAPEL;
    return AEREO;
}

int main(void){
    int N;
    scanf("%d", &N);
    while(N--){
        scanf(" %s %s", j1, j2);
        codj1 = cod(j1); codj2 = cod(j2);
        if(codj1 == AEREO && codj2 == AEREO) printf("Aniquilacao mutua\n");
        else if(codj1 == PAPEL && codj2 == PAPEL) printf("Ambos venceram\n");
        else if(codj1 == PEDRA && codj2 == PEDRA) printf("Sem ganhador\n");
        else if(codj1 == AEREO || codj2 == PAPEL) printf("Jogador 1 venceu\n");
        else printf("Jogador 2 venceu\n");
    }
    return 0;
}

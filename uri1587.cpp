#include<stdio.h>
#include<string.h>

#define MAX 2551900

int N, E;
int J;
long long jA[MAX], jB[MAX];
long long pA[MAX], pB[MAX];

void atualizaA(int i, int v){
    for(; i < MAX; i += (i & (-i)))
        pA[i] += v;
}

void atualizaB(int i, int v){
    for(; i < MAX; i += (i & (-i)))
        pB[i] += v;
}

int qtdJogadoresA(int i){
    int soma = 0;
    for(; i > 0; i -= (i & (-i)))
        soma += pA[i];
    return soma;
}

int qtdJogadoresB(int i){
    int soma = 0;
    for(; i > 0; i -= (i & (-i)))
        soma += pB[i];
    return soma;
}

int posicaoValidaA(int i){
    return (11 * (J - qtdJogadoresB(jA[i])) < N);
}

int posicaoValidaB(int i){
    return (11 * qtdJogadoresA(jB[i] - 1) < N);
}

int main(void){
    char ev;
    int i, tmp, imp, gA, gB;
    while(scanf("%d %d", &N, &E), N){
        gA = gB = imp = 0; J = N / 2;
        memset(pA, 0, sizeof(pA)); memset(pB, 0, sizeof(pB));
        for(i = 1; i <= J; i++){
            scanf("%d", &tmp); jA[i] = tmp + 1;
            atualizaA(jA[i], 1);
        }
        for(i = 1; i <= J; i++){
            scanf("%d", &tmp); jB[i] = tmp + 1;
            atualizaB(jB[i], 1);
        }
        while(E--){
            scanf(" %c", &ev);
            if(ev == 'S') imp = 0;
            else if(ev == 'G'){
                scanf(" %c", &ev);
                if(imp){ imp = 0; continue; }
                if(ev == 'A') gB++;
                else gA++;
            }else if(ev == 'I' || ev == 'P'){
                scanf(" %c%d", &ev, &tmp);
                if(ev == 'A') imp |= posicaoValidaA(tmp);
                else imp |= posicaoValidaB(tmp);
            } else {
                scanf(" %c%d %d", &ev, &tmp, &i);
                if(ev == 'A'){
                    atualizaA(jA[tmp], -1);
                    atualizaA((jA[tmp] = i + 1), 1);
                }else{
                    atualizaB(jB[tmp], -1);
                    atualizaB((jB[tmp] = i + 1), 1);
                }}}
        printf("%d X %d\n", gA, gB);
    }
    return 0;
}

#include<stdio.h>
#include<string.h>

#define MAX 2551900

int N, E;
int J;
long long jA[MAX], jB[MAX];
long long pA[MAX], pB[MAX];

void incrementa(char t, int i, int v){
    for(; i < MAX; i += (i & (-i)))
        if(t == 'a') pA[i] += v;
        else pB[i] += v;
}

int get(char t, int i){
    int soma = 0;
    for(; i > 0; i -= (i & (-i)))
        if(t == 'a') soma += pA[i];
        else soma += pB[i];
    return soma;
}

int main(void){
    char ev;
    int i, tmp, imp, gA, gB;
    while(scanf("%d %d", &N, &E), N){
        gA = gB = imp = 0;
        memset(pA, 0, sizeof(pA));
        memset(pB, 0, sizeof(pB));
        J = N / 2;
        for(i = 1; i <= J; i++){
            scanf("%d", &tmp);
            jA[i] = tmp + 1;
            incrementa('a', jA[i], 1);
        }
        for(i = J + 1; i <= N; i++){
            scanf("%d", &tmp);
            jB[i] = tmp + 1;
            incrementa('b', jB[i], 1);
        }
        while(E--){
            scanf(" %c", &ev);
            if(ev == 'S'){
                imp = 0;
            }else if(ev == 'G'){
                scanf(" %c", &ev);
                if (!imp){
                    if(ev == 'A') gB++;
                    else gA++;
                }
                imp = 0;
            }else if(ev == 'P' || ev == 'I'){
                scanf(" %c%d", &ev, &tmp);
                if(ev == 'A') {
                    //Conta quantos jogadores do time B tem até a posição do jogar A, mas como quero saber os jogadores que estão depois disso, subtraio de J
                    imp |= (11 * (J - get('b', jA[tmp])) < N);
                } else {

                    // printf("Jtmp: %d, get: %d\n", tmp + J, get('a', jB[tmp + J] - 1));
                    //Conta quantos jogadores do time A encontramos antes do jogador B
                    imp |= (11 * get('a', jB[tmp + J] - 1) < N);
                }
            }else{
                scanf(" %c%d %d", &ev, &tmp, &i);
                //Tiro o cara da posição dele
                incrementa(ev, ev == 'A' ? jA[tmp] : jB[tmp + J], -1);
                //Coloco na posição nova
                incrementa(ev, i + 1, 1);
                //Guardo a posição
                if(ev == 'A') jA[tmp] = i + 1;
                else jB[tmp] = i + 1;
            }
        }
        printf("%d X %d\n", gA, gB);
    }
    return 0;
}


//Créditos: Matheus Dall Rosa :P
//Código ficou muito feio

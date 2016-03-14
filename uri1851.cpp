#include<stdio.h>
#include<queue>
#include<utility>
#include<queue>
using namespace std;

typedef struct{ int t, f; }dragao;
typedef pair< double, int > di;

dragao M[112345];

int main(void){
    long long t = 1, N, j = 1, resp = 0, i;
    priority_queue< di, vector< di >, greater<di> > Q;
    //Lê indexando por dia (dia 1 até o dia N)
    for(N = 1; scanf("%d %d", &M[N].t, &M[N].f) != EOF; N++);
    //N fica com 1 a mais do que deveria, por isso variamos o jota até menor que N
    while(j < N || !Q.empty()){
        //Coloco todos os dragões que chegaram no maximo tempo t(que tem indice <= t) na fila, usando a relação Ti/Fi para decidir quem eu tiro da fila
        while(j <= t && j < N){ Q.push(di(M[j].t / (double)M[j].f, j)); j++; }
        if(!Q.empty()){
            // printf("Escolhido>> (%lf, %d)\n", Q.top().first, Q.top().second);
            i = Q.top().second;
            //Somo na resposta o tempo que o dragão ficou dormindo vezes a multa;
            resp += (t - i) * M[i].f;
            //Somo o tempo que passou para treinar aquele dragão
            t += M[i].t;
            Q.pop();
        } else t++;
    }
    printf("%lld\n", resp);
    return 0;
}

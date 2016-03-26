#include <stdio.h>
#include <string.h>

#define MAX 112
#define max(a, b)  (a) > (b) ? (a) : (b)

int T;
int N, D;
int B[MAX], S[MAX][MAX], dS[MAX], t;

int main(void){
    char tipo;
    int d, resp, i, j, caso, tmp;
    scanf("%d", &T);
    for(caso = 1; caso <= T; caso++){
        scanf("%d %d", &N, &D);
        B[t = 0] = 0; resp = 0; j = 0;
        memset(dS, 0, sizeof(dS));
        while(N--){
            scanf(" %c-%d", &tipo, &d);
            if(tipo == 'S') S[t][j++] = d;
            else { dS[t] = j; B[++t] = d; j = 0;}
        }
        dS[t] = j; B[++t] = D; dS[t] = 0;
        for(i = 0; i < t; i++){
            tmp = 0;
            //Pego a diferença maxima pulando sempre uma pedra
            for(j = 2; j < dS[i]; j++) tmp = max(S[i][j] - S[i][j - 2], tmp);
            //Vejo a diferença das pedras grandes (tratando quando não há pedra pequena)
            if(dS[i] <= 1) tmp = max(B[i + 1] - B[i], tmp);
            else tmp = max(S[i][1] - B[i], max(B[i + 1] - S[i][dS[i] - 2], tmp));
            resp = max(resp, tmp);
        }
        printf("Case %d: %d\n", caso, resp);
    }
    return 0;
}

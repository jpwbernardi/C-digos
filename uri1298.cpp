#include <stdio.h>
#include <string.h>
#define MAX 1500

struct ponto{ int x, y; ponto(){} ponto(int _i, int _j) : x(_i), y(_j){}};

ponto pilha[MAX];
char mapa[MAX][MAX];
int N, resp, ii, jj, topo;
int dx[] = { 0, 0, 1, -1}, dy[] = { 1, -1, 0, 0};

void dfs(int x, int y){
    int i;
    ponto s(x, y), u;
    pilha[topo = 0] = s; mapa[s.x][s.y] = 1;
    while(topo >= 0){
        u = pilha[topo--];
        for(i = 0; i < 4; i++){
            ponto v(u.x + dx[i], u.y + dy[i]);
            if(v.x >= 0 && v.x < ii && v.y >= 0 && v.y < jj && !mapa[v.x][v.y]){
                pilha[++topo] = v;
                mapa[v.x][v.y] = 1;
            }}}}

void imprime(){
    int i, j;
    for(i = 0; i < ii; printf("\n"), i++)
        for(j = 0; j < jj; printf("%d", mapa[i][j]), j++);
    printf("\n");
}

int main(void){
    char aux;
    int i, j;
    while(scanf("%d ", &N) != EOF){
        memset(mapa, 0, sizeof(mapa));
        for(ii = i = 1; i <= 2 * N - 1; getchar(), i++, ii += 2)
            for(jj = !(i & 1) * 2 + 1, j = 0; j < N; j++, jj += 4){
                aux = getchar();
                mapa[ii][jj] = 1;
                if(ii - 2 > 0) mapa[ii - 2][jj] = 1;
                mapa[ii + 2][jj] = 1;
                if(aux == 'H') { mapa[ii][jj - 1] = 1; mapa[ii][jj + 1] = 1; }
                else { mapa[ii - 1][jj] = 1; mapa[ii + 1][jj] = 1; }
            }

        // imprime();

        for(resp = -1, i = 0; i < ii; i++)
            for(j = 0; j < jj; j++)
                if(!mapa[i][j]) { dfs(i, j); resp++; /*imprime();*/}
        printf("%d\n", resp);
    }
    return 0;
}

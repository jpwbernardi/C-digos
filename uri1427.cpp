#include <stdio.h>
#include <string.h>
#include <map>
#include <string>
using namespace std;

#define MAX 112
#define INF 112345678

int P, E;
int caminho[MAX], tam;
int dist[MAX][MAX];
int prox[MAX][MAX];
char pontos[MAX][30];

void floydWarshall(){
    for(int k = 0; k < P; k++)
        for(int i = 0; i < P; i++)
            for(int j = 0; j < P; j++)
                if(dist[i][k] + dist[k][j] < dist[i][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                    prox[i][j] = prox[i][k];
                }
}

void constroiCaminho(int u, int v){
    if(prox[u][v] == (tam = -1)) return;
    caminho[tam = 0] = u;
    do{
        u = prox[u][v];
        caminho[++tam] = u;
    }while(u != v);
}

int main(void){
	int C, i, j;
	char nome[30], origem[30], destino[30];
	scanf("%d", &C);
	while(C--){
		map<string, int> M;
        memset(prox, -1, sizeof(prox));
		scanf("%d", &P);
		for(i = 0; i < P; i++){
			scanf(" %s", pontos[i]);
			string lugar(pontos[i]);
			M[lugar] = i;
		}
		for(i = 0; i < P; i++)
			for(j = 0; j < P; j++){
				scanf("%d", &dist[i][j]);
                if(dist[i][j] == -1) dist[i][j] = INF;
                prox[i][j] = j;
            }
        floydWarshall();
        scanf("%d", &E);
		while(E--){
			scanf(" %s %s %s", nome, origem, destino);
			string o(origem), d(destino);
            int s = M[o], t = M[d];
            constroiCaminho(s, t);
            if(dist[s][t] != INF){
                printf("Mr %s to go from %s to %s, you will receive %d euros\nPath:", nome, origem, destino, dist[s][t]);
                for(i = 0; i <= tam; i++)
                    printf("%s%s", i != 0 ? " " : "", pontos[caminho[i]]);
                printf("\n");
            } else printf("Sorry Mr %s you can not go from %s to %s\n", nome, origem, destino);
        }}
	return 0;
}

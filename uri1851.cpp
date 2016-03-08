#include<stdio.h>
#include<queue>
#include<utility>
#include<queue>
using namespace std;

typedef struct{ int t, f; }dragao;
typedef pair< double, int > di;


dragao M[112345];

int main(void){
    long long t = 1, N = 0, j = 0, resp = 0, i;
    priority_queue< di, vector< di >, greater<di> > Q;
    for(N = 0;scanf("%d %d", &M[N].t, &M[N].f) != EOF; N++);
    while(j < N || !Q.empty()){
        while(j < t && j < N){ Q.push(di(M[j].t / (double)M[j].f, j)); j++; }
        if(!Q.empty()){
            i = Q.top().second;
            resp += (t - i - 1) * M[i].f;
            t += M[i].t;
            Q.pop();
        }else t++;
    }
    printf("%lld\n", resp);
    return 0;
}

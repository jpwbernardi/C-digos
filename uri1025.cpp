#include<stdio.h>
#include<stdlib.h>

#define MAX 1123456

int N, Q, resp;
int v[MAX];

int cmp(const void *a, const void *b){
    return *(int *)a - *(int *)b;
}

int buscabin(int e){
    int in = 0, fim = N - 1, m;
    while(in <= fim){
        m = (in + fim) / 2;
        if(v[m] == e) return m;
        else if(v[m] < e) in = m + 1;
        else fim = m - 1;
    }
    return -1;
}

void consertaResp(){
    while (resp > 0 && v[resp - 1] == v[resp]) resp--;
}

int main(void){
    int i, caso = 1;
    while(scanf("%d %d", &N, &Q), N){
        for(i = 0; i < N; i++) scanf("%d",&v[i]);
        qsort(v, N, sizeof(int), &cmp);
        printf("CASE# %d:\n", caso);
        while(Q--){
            scanf("%d", &i);
            resp = buscabin(i);
            consertaResp();
            if(resp != -1) printf("%d found at %d\n", i, resp + 1);
            else printf("%d not found\n", i);
        }
        caso++;
    }
    return 0;
}

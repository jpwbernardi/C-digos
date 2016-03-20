#include <stdio.h>
#include <string.h>

#define MAX 1123

int X, Y, P;
int c[MAX][MAX];

void set(int x , int y , int val){
    for(int i = x; i <= X; i += (i & -i))
        for (int j = y; j <= Y; j += (j & -j))
            c[i][j] += val;
}

int get(int x, int y){
    int soma = 0;
    for(int i = x; i > 0; i -= (i & -i))
        for (int j = y; j > 0; j -= (j & -j))
            soma += c[i][j];
    return soma;
}

int getExt(int x, int y, int x1, int y1){
    int tmp;
    if(x1 < x){ tmp = x; x = x1; x1 = tmp; }
    if(y1 < y){ tmp = y; y = y1; y1 = tmp; }
    return get(x1, y1) - get(x1, y - 1) - get(x - 1, y1) + get(x - 1, y - 1);
}


int main(void){
    int Q, n, x, y, x1, y1;
    char ev;
    while(scanf("%d %d %d", &X, &Y, &P), X){
        memset(c, 0, sizeof(c));
        scanf("%d", &Q);
        while(Q--){
            scanf(" %c", &ev);
            if(ev == 'A'){
                scanf("%d %d %d", &n, &x, &y);
                x++; y++; set(x, y, n);
            }else{
                scanf("%d %d %d %d", &x, &y, &x1, &y1);
                x++; y++; x1++; y1++;
                printf("%d\n", getExt(x, y, x1, y1) * P);
            }
        }
        printf("\n");
    }
    return 0;
}

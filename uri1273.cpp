#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

#define MAX 59

int main(void){
    int N, maior, i, first = 1;
    char str[MAX][MAX];
    while(scanf("%d", &N), N){
        if(first) first = 0;
        else printf("\n");
        for(maior = i = 0; i < N; i++){
            scanf(" %s", str[i]);
            maior = max(maior, (int)strlen(str[i]));
        }
        for(i = 0; i < N; i++)
            printf("%*s\n", maior, str[i]);
    }
    return 0;
}

#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

#define MAX 212

int main(void){
    int N, maior, i, first = 1;
    char str[MAX][MAX], tmp[MAX];
    while(scanf("%d ", &N), N){
        if(first) first = 0;
        else printf("\n");
        for(maior = i = 0; i < N; i++){
            fgets(tmp, MAX, stdin);
            int espaco = -1, j, k = 0;
            for(j = 0; tmp[j] != '\n'; j++){
                if(tmp[j] != ' ' && espaco == 1){
                    str[i][k] = ' '; k++;
                    str[i][k] = tmp[j]; k++;
                    espaco = 0;
                } else if(tmp[j] != ' ') {
                    str[i][k] = tmp[j]; k++;
                    espaco = 0;
                } else if(espaco != -1) espaco = 1;
            }
            str[i][k] = '\0';
            maior = max(maior, (int)strlen(str[i]));
        }
        for(i = 0; i < N; i++)
            printf("%*s\n", maior, str[i]);
    }
    return 0;
}

#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

#define MAX 112

char nomes[MAX][MAX], freq[MAX];

int main(void){
    int N, T, totalAulas, faltas, first, i, j;
    scanf("%d", &T);
    while(T--){
        scanf("%d", &N); first = 1;
        for(i = 0; i < N; i++) scanf(" %s", nomes[i]);
        for(i = 0; i < N; i++){
            scanf(" %s", freq);
            totalAulas = strlen(freq);
            for(faltas = j = 0; freq[j] != '\0'; j++){
                if(freq[j] == 'M') totalAulas--;
                else if(freq[j] == 'A') faltas++;
            }
            if(4 * (totalAulas - faltas) < 3 * totalAulas){
                if(first) first = 0;
                else printf(" ");
                printf("%s", nomes[i]);
            }
        }
        printf("\n");
    }
    return 0;
}

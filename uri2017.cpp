#include <stdio.h>
#define MAX 112345

int K, dif[5];
char orig[MAX], s[5][MAX];

int main(void){
    int i, menor;
    scanf("%s %d", orig, &K);
    for(i = 0; i < 5; i++){ scanf(" %s", s[i]); dif[i] = 0; }
    for(i = 0; orig[i] != '\0'; i++){
        if(orig[i] != s[0][i]) dif[0]++;
        if(orig[i] != s[1][i]) dif[1]++;
        if(orig[i] != s[2][i]) dif[2]++;
        if(orig[i] != s[3][i]) dif[3]++;
        if(orig[i] != s[4][i]) dif[4]++;
    }
    menor = 0;
    for(i = 1; i < 5; i++)
        if(dif[i] < dif[menor]) menor = i;
    if(dif[menor] > K) printf("-1\n");
    else printf("%d\n%d\n", menor + 1, dif[menor]);

    return 0;
}

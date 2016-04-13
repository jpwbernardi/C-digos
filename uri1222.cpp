#include <stdio.h>
#include <string.h>

#define MAX 11234

int main(void){
    char palavra[MAX];
    int N, L, C, car, linha, aux, i;
    while(scanf("%d %d %d", &N, &L, &C) != EOF){
        linha = 1; car = 0;
        for(i = 0; i < N; i++){
            scanf(" %s", palavra);
            // printf(" %d", car);
            aux = strlen(palavra) + (i != 0);
            if(car + aux > C) { linha++; car = aux - 1; }
            else car += aux;
        }
        printf("%d\n", linha / L + (linha % L != 0));
    }
    return 0;
}

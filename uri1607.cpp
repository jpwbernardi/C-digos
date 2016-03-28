#include <stdio.h>

#define N 26
#define MAX 11234

int T, resp;
char A[MAX], B[MAX];

int main(void){
    scanf("%d", &T);
    while(T--){
        resp = 0;
        scanf(" %s %s", A, B);
        for(int i = 0; A[i] != '\0'; i++){
            resp += ((B[i] - A[i] + N) % N);
        }
        printf("%d\n", resp);
    }
    return 0;
}

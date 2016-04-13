#include <stdio.h>
#define MAX 123

char msg[MAX];

void codifica(){
    int espaco = 1, i;
    for(i = 0; msg[i] != '\n'; i++)
        if(espaco && msg[i] != ' '){ printf("%c", msg[i]); espaco = 0; }
        else if(msg[i] == ' ') espaco = 1;
    printf("\n");
}

int main(void){
    int N;
    scanf("%d ", &N);
    while (N--) {
        fgets(msg, MAX, stdin);
        codifica();
    }
    return 0;
}

#include<stdio.h>

#define MAX 112

int N, desl;
char s[MAX];

char codifica(char a){
    a -= desl;
    a -= 'a';
    if(a < 'A') a += 'Z' - 'A' + 1;
    return a;
}

int main(void){
    scanf("%d ", &N);
    while(N--){
        fgets(s, MAX, stdin);
        scanf("%d ", &desl);
        for(int i = 0; s[i] != '\n'; i++) s[i] = codifica(s[i]);
        printf("%s", s);
    }
    return 0;
}

#include <stdio.h>
#include <string.h>
#define MAX 123

int main(void){
    int i, flag, first;
    char alf[30], s[MAX];
    while(fgets(s, MAX, stdin) != NULL){
        memset(alf, 0, sizeof(alf));
        for(i = 0; s[i] != '\0'; i++)
            if(s[i] != ' ') alf[s[i] - 'a'] = 1;
        for(i = 0, flag = first = 1; i < 30; i++){
            if(flag && alf[i]) { printf("%s%c:", first ? "" : ", ", i + 'a'); flag = first = 0; }
            if(!flag && !alf[i]) { printf("%c", i - 1 + 'a'); flag = 1; }
        }
        printf("\n");
    }
    return 0;
}

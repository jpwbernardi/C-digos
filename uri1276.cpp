#include <stdio.h>
#include <string.h>
#define MAX 123

int main(void){
    int i, imprimindo, first;
    char alf[30], s[MAX];
    while(fgets(s, MAX, stdin) != NULL){
        memset(alf, 0, sizeof(alf));
        for(i = 0; s[i] != '\n'; i++)
            if(s[i] != ' ') alf[s[i] - 'a'] = 1;
        for(imprimindo = i = 0, first = 1; i < 30; i++){
            if (!imprimindo && alf[i]) {
                printf("%s%c:", first ? "" : ", ", i + 'a');
                imprimindo = 1; first = 0;
            } else if (imprimindo && !alf[i]) {
                printf("%c", i - 1 + 'a');
                imprimindo = 0;
            }
        }
        printf("\n");
    }
    return 0;
}

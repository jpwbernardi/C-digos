#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<string>
#include<map>
using namespace std;

int score[400][3];
char paises[400][400];
map<string, int> M;

int cmp(const void *a, const void *b){
    string s((char *) a), s2((char *)b);
    int i = M[s], j = M[s2];
    if(score[i][0] != score[j][0]) return score[j][0] - score[i][0];
    if(score[i][1] != score[j][1]) return score[j][1] - score[i][1];
    if(score[i][2] != score[j][2]) return score[j][2] - score[i][2];
    return strcmp((char *)a, (char *)b);
}

int main(void){
    int cont = 0, p, i, j;
    char lixo[1123], pais[1123];
    memset(score, 0, sizeof(score));
    while(fgets(lixo, 1123, stdin) != NULL)
        for(i = 0; i < 3; i++){
            fgets(pais, 1123, stdin);
            pais[strlen(pais) - 1] = '\0';
            string s(pais);
            if(M.find(s) == M.end()) { strcpy(paises[cont], pais); M[s] = cont++; }
            p = M[s];
            score[p][i]++;
        }
    qsort(paises, cont, sizeof(paises[0]), &cmp);
    printf("Quadro de Medalhas\n");
    for(i = 0; i < cont; i++){
        j = M[string(paises[i])];
        printf("%s %d %d %d\n", paises[i], score[j][0], score[j][1], score[j][2]);
    }
    return 0;
}

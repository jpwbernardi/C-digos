#include<map>
#include<string>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
using namespace std;

#define MAX 112345

char nome[MAX * 2][21];

int cmp(const void *a, const void *b){
    return strcmp((char *)a, (char *)b);
}

int main(void){
    int cont = 0, a;
    map<string, int> M;
    char cs1[21], cs2[21];
    while(scanf("%s %s ", cs1, cs2) != EOF){
        string st1(cs1), st2(cs2);
        if(M.find(st1) == M.end()){ strcpy(nome[cont++], cs1); M[st1] = 1; }
        if(M[st1]) M[st1]++;
        if(M[st2]) M[st2] = 0;
    }
    qsort(nome, cont, sizeof(nome[0]), &cmp);
    printf("HALL OF MURDERERS\n");
    for(int i = 0; i < cont; i++){
        string st1(nome[i]);
        a = M[st1];
        if(a) printf("%s %d\n", nome[i], a - 1);
    }
    return 0;
}

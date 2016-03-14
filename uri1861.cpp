#include<map>
#include<string>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <iostream>
using namespace std;

#define MAX 112345
#define INFTO 112345678

int main(void){
    map<string, int> M;
    char cs1[21], cs2[21];
    while(scanf("%s %s ", cs1, cs2) != EOF){
        string st1(cs1), st2(cs2);
        M[st1]++; M[st2] = -INFTO;
    }
    map<string, int>::iterator i;
    printf("HALL OF MURDERERS\n");
    for(i = M.begin(); i != M.end(); i++)
        if(i->second > 0) printf("%s %d\n", i->first.c_str(), i->second);
    return 0;
}

#include<stdio.h>
#include<set>
#include<string>
#include <iostream>

using namespace std;

int main(void){
    int j = 0;
    char c, palavra[212];
    set<string> dicionario;
    set<string>::iterator i;
    while(scanf("%c", &c) != EOF){
        if(c >= 'A' && c <= 'Z') palavra[j++] = c - 'A' + 'a';
        else if(c >= 'a' && c <= 'z') palavra[j++] = c;
        else if(j != 0){
            palavra[j] = '\0';
            dicionario.insert(string(palavra));
            j = 0;
        }}
    for(i = dicionario.begin(); i != dicionario.end(); i++)
        cout << *i << endl;
}

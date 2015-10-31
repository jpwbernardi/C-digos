#include <stdio.h>
#include <stdlib.h>

#define MAX 1123456

//Crivo 1
int PI[MAX], max;

void crivo1(){
    int topo = 1, i, j;
    PI[0] = 2;
    for(i = 3; i < MAX; i++){
        int primo = 1;
        for(j = 0; primo && j < topo && PI[j] * PI[j] <= i; j++)
            if(i % PI[j] == 0) primo = 0;
        if(primo) PI[topo++] = i;
    }
    max = topo - 1;
}

//Crivo 2
int pri[MAX];

void crivo2(){
  int i, j;
	pri[0] = pri[1] = 0;
	for(i = 2; i < MAX; i++) pri[i] = 1;
    for(i = 2; i * i < MAX ; i++)
      if(pri[i])
			   for(j = i * i ; j < MAX; j += i)
				       pri[j] = 0;
}

//Euclides (Acha o Maximo Divisor Comum)
int mdc (int a, int b) {
	if (a % b == 0) return b;
	else return mdc (b, a % b);
}

//Comparação do qsort
int cmp(const void *a, const void *b){
	return *(int *)a - *(int *)b;
}

int main(void){
    int i;
	crivo1();	crivo2();
	printf("MDC de 15 e 20 é : %d\n", mdc(15, 20));
	//Crivo 2:
	for(i = 0; i < 15; i++)
		printf("%d: %sé primo\n", i, pri[i] ? "" : "não ");

	//Crivo 2:
	printf("Os 15 primeiros primos são:");
	printf(" %d", PI[0]);
	for(i = 1; i < 15; i++)
		printf(", %d", PI[i]);
	printf("\n");

	int vetorQualquer[] = {8, 3, 4, 6, 9, 11, 15, 19};

	//qsort(vetor, qtd de elementos, "peso" de cada elemento, função de comparação)
	qsort(vetorQualquer, 8, sizeof(int), &cmp);
	printf("VetorQualquer ordenado: ");
	printf("%d", vetorQualquer[0]);
	for(i = 1; i < 8; i++)
		printf(", %d", vetorQualquer[i]);
	printf("\n");

	return 0;
}

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "timer.h"
/*

1. Sa se evalueze din punct de vedere al timpului de executie algoritmii de sortare bubblesort si shakersort,
folosind functiie din timer.h/timer.c si sa se compare performantele acestora pentru acelasi 
set de date (ex. N1=10 000, N2= 20 000, ... N10=100 000). Sa se scrie timpii
de executie intr-un fisier txt in urmatorul format, pe cate o linie separata:

Algoritm, N1, timp_executie

Algoritm, N2, timp_executie

*/
void bublesort(int a[], int n){
	int ok = 0, aux, i;
	while (ok == 0){
		ok = 1;
		for (i = 0; i < n; i++){
			if (a[i] < a[i + 1]){
				aux = a[i];
				a[i] = a[i + 1];
				a[i + 1] = aux;
				ok = 0;
			}
		}

	}
}

void swap(int *a, int *b){
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
void shakersort(int a[], int n)
{
	int p, i;
	for (p = 1; p <= n / 2; p++)
	{
		for (i = p - 1; i < n - p; i++)
			if (a[i] > a[i + 1])
				swap(&a[i], &a[i + 1]);
		for (i = n - p - 1; i >= p; i--)
			if (a[i] < a[i - 1])
				swap(&a[i], &a[i - 1]);
	}
}

int main()
{
	FILE *f;
	f = fopen("data.txt", "w");
	if (!f){
		return 1;
	}

	int a[100000], ok,n,j,k;
	double timp;

	//Bublesort
	for (j = 1; j <= 5; j++){

		n = j*10000;
		ok = 0;
		for (k = 0; k < n; k++)
			a[k] = rand();

		starton();
		bublesort(a, n);
		timp=startoff();
		fprintf(f,"Bublesort: N%d=%d , %lf\n", j, n, timp);
	}

	fprintf(f,"\n\n\n");
	j = 0, n = 0;
	for (j = 1; j <= 5; j++){

		n = j * 10000;
		ok = 0;
		for (k = 0; k < n; k++)
			a[k] = rand();
		
		starton();
		shakersort(a, n);
		timp = startoff();
		fprintf(f,"Shakersort: N%d=%d , %lf\n", j, n, timp);
	}
	
	system("pause");

	fclose(f);
	return 0;
}

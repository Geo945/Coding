#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "timer.h"
/*

3. Sa se evalueze din punct de vedere al timpului de executie o implementare recursiva 
si una nerecursiva a calcului termenului n al seriei Fibonacci, 
folosind functiie din timer.h/timer.c si sa se compare performantele
acestor implementari pentru acelasi set de date (ex. N1=5, N2= 10, ... N10=100).
Sa se scrie timpii de executie intr-un fisier txt in urmatorul format, pe cate o linie separata:
Algoritm, N1, timp_executie
Algoritm, N2, timp_executie

0 1 1 2 3 5 8 ...
*/


int fibr(int n)
{
	if (n <= 1)
		return n;
	if (n == 2)
		return n - 1;
	return fibr(n - 1) + fibr(n - 2);
}

int fibn(int n)
{
	int n1 = 0, n2 = 1, n3 , i;
	if (n == 0){
		return n1;
	}
	if (n == 1){
		return n2;
	}
	else
		for (i = 2; i <= n; i++){
			n3 = n1 + n2;
			n1 = n2;
			n2 = n3;
		}
	return n3;


}


int main()
{
	FILE *f;
	f = fopen("data.txt", "w");
	if (!f){
		return 1;
	}

	int n, i, rez;
	double timp;
	fprintf(f,"Metoda recursiva:\n");
	for (i = 0; i < 8; i++){
		n = i * 5;
		starton();
		rez = fibr(n);
		timp = startoff();
		fprintf(f,"%d %lf\n", rez,timp);
	}

	fprintf(f,"Metoda nerecursiva:\n");

	for (i = 0; i < 8; i++){
		n = i * 5;
		starton();
		rez = fibn(n);
		timp = startoff();
		fprintf(f,"%d %lf\n", rez,timp);
	}

	fclose(f);
	return 0;
}
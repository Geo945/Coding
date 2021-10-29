#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "timer.h"

//ecercitiul 3
// 0 1 1 2 3 5 8...
/* 
Sir fibonaci ca functie
fib(n)= {	 fib(0)=0
	    {    fib(1)=1
		{    fib(n)=fib(n-1)+fib(n-2);


*/
long fibr(int n)
{
	if (n <= 1)
		return 1;
	return fibr(n - 1) + fibr(n - 2);


}

long fibn(int n)
{
	long a, b, c;
	int i;
	a = 0;
	b = 1;
	c = a + b;
	if (n == 0)
		return a;
	if (n == 1)
		return b;
	else
		for (i = 2; i <= n; i++)
		{
			a = b;
			b = c;
			c = a;
		}

	return c;

}

int main(void)
{
	int n,i;
	n = 5;
	fibr(n);
	long rez;
	float timp;
	FILE *f;
	f = fopen("date.txt", "w");
	if (!f)
	{
		return 1;
	}
	
	for (i = 0; i < 5; i++)
	{
		n = i * 5;
		starton();
		rez = fibr(n);
		timp = startoff();
		fprintf(f,"%d %ld %f\n", n, fibr(n),timp);
	}

	printf("\n");

	for (i = 0; i < 5; i++)
	{
		n = i * 5;
		starton();
		rez = fibn(n);
		timp = startoff();
		fprintf(f,"%d %ld %f\n", n, fibr(n), timp);
	}
	fclose(f);
	system("pause");
	return 0;
}
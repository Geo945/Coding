#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	char gen;
	int medie;
	char nume[30];
}student;

student a[13];

void citire(student a[], int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		scanf("%d %c %[^\n]s\n", &a[i].medie, &a[i].gen, a[i].nume);
	}

}

void afisare(student a[], int n)
{
	int i;
	printf("\n\n\nstructura este:\n");
	for (i = 0; i < n; i++)
		printf("%d-%s-%c \n", a[i].medie, a[i].nume, a[i].gen);
}

void sortare_insertie(student a[], int n)
{
	int i, j;
	student temp;
	for (i = n - 2; i >= 0; i--)
	{

		a[n] = a[i];
		j = i + 1;
		while (a[j].medie > a[n].medie)
		{

			a[j - 1] = a[j];
			j++;
		}

		a[j - 1] = a[n];
	}


}
#define tt 4

void shellsort(int n)
{
	int i, j, pas;
	unsigned char m;
	int h[tt];
	student temp;


	h[0] = 9;
	h[1] = 5;
	h[2] = 3;
	h[3] = 1;
	for (m = 0; m < tt; ++m)
	{
		pas = h[m];
		for (i = pas; i < n; ++i)
		{
			temp = a[i];
			for (j = i; j >= pas && ((a[j - pas].gen > temp.gen) || (a[j - pas].medie>temp.medie && a[j - pas].gen == temp.gen) || (strcmp(a[j - pas].nume, temp.nume)>0 && a[j - pas].medie>temp.medie && a[j - pas].gen == temp.gen)); j = j - pas)
			{
				a[j] = a[j - pas];
			}
			a[j] = temp;
		}
	}
}

void deplasare(int *s, student *temp, int *d, student a[])
{
	int i, j;
	int ret = 0;
	i = *s; j = 2 * i; *temp = a[i]; ret = 0;
	while ((j <= *d) && (!ret))
	{	//in primu if trb conditile normale cu semn invers
		if (j < *d && ((a[j].gen < a[j + 1].gen) || ((a[j].gen == a[j + 1].gen) && (a[j].medie<a[j + 1].medie)) || ((a[j].gen == a[j + 1].gen) && (a[j].medie<a[j + 1].medie) && strcmp(a[j].nume,a[j+1].nume)>0 ) ) )
			j = j + 1;

		if ((a[j].gen > temp->gen) || ((a[j].gen == temp->gen) && (a[j].medie>temp->medie)) || ((a[j].gen == temp->gen) && (a[j].medie>temp->medie) && strcmp(a[j].nume, temp->nume)<0))
		{
			a[i] = a[j]; i = j; j = 2 * i;
		}
		else
			ret = 1;
	}
	a[i] = *temp;
}

void heapsort(int n)
{
	int s, d;
	student temp;

	s = (n / 2) + 1; d = n - 1;
	while (s>0)
	{
		s = s - 1; deplasare(&s, &temp, &d, a);
	}
	while (d>0)
	{
		temp = a[0]; a[0] = a[d]; a[d] = temp;
		d = d - 1; deplasare(&s, &temp, &d, a);
	}
}

void quicksort(student a[], int s, int d) {
	int i = s, j = d;
	student x = a[(s + d) / 2];
	do {
		while ((a[i].gen <x.gen) || ((a[i].gen == x.gen) && (a[i].medie<x.medie)) || ((a[i].gen == x.gen) && (a[i].medie<x.medie) && strcmp(a[i].nume, x.nume)>0)) i++;
		while ((a[j].gen > x.gen) || ((a[j].gen == x.gen) && (a[j].medie>x.medie)) || ((a[j].gen == x.gen) && (a[j].medie>x.medie) && strcmp(a[j].nume, x.nume)<0)) j--;
		if (i <= j) {
			student temp = a[i];
			a[i] = a[j];
			a[j] = temp;
			i++;
			j--;
		}
	} while (i <= j);

	if (s<j) quicksort(a, s, j);
	if (d>i) quicksort(a, i, d);
}

int main()
{
	int n, i;
	char primuNume[30], doiNume[30];

	scanf("%d", &n);
	citire(a, n);
	sortare_insertie(a, n);
	afisare(a, n);
	getchar();
	scanf("%[^\n]s\n", primuNume);
	for (i = 0; i<n; i++)
	{
		if (strcmp(primuNume, a[i].nume) == 0)
		{
			printf("%d\n", i);
			break;
		}
	}


	//shellsort(n);
	//heapsort(n);
	quicksort(a,0, n - 1);
	afisare(a, n);
	getchar();
	scanf("%[^\n]s\n", doiNume);
	for (i = 0; i<n; i++)
	{
		if (strcmp(doiNume, a[i].nume) == 0)
		{
			printf("%d\n", i);
			break;
		}
	}

	system("pause");

}





















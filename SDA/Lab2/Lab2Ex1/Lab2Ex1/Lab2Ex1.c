#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
	char nume[5000];
	char optional[15];
}student;

student a[5000];
void BinaraPerfomanta(student a[], int k,char aux[35])
{
	int s = 0, d = k, m,contor=0;
	while (s < d)
	{
		m = (s + d) / 2;
		contor++;
		if (strcmp(a[m].nume, aux) < 0 )
			s = m + 1;
		else
			d = m;
	}
	
	if (strcmp(a[d].nume, aux))
		printf("Nume: %sNumar comparatii: %d\n", a[d].nume,contor);
	else
		printf("Nume inexistent");


}

void cautareLiniara(student a[], int k, char aux[4])
{
	int i;
	for (i = 0; i < k ; i++)
	{
		if (strstr(a[i].optional, aux))
			printf("%s\n", a[i].nume);
	}
}

int main()
{
	FILE *f;
	int i,k=0;
	char linie[1000],aux[15];
	f = fopen("FisierTestStudentiAlfabetic.txt", "r");
	if (!f)
	{
		printf("Fisierul nu s-a putut deschide");
		return -1;
	}

	while (fgets(linie, 1000, f) != NULL)
	{
		strcpy(a[k].nume, linie);
		fgets(linie, 1000, f);
		for (i = 0; i < strlen(linie); i++)
			if (linie[i] == ' ' && i!=strlen(linie) )
				linie[i] = ',';
		strcpy(a[k].optional, linie);
		
		k++;

	}
	
	BinaraPerfomanta(a, k, "MATEI STEFAN");
	cautareLiniara(a, k, "d1");

	system("pause");
	fclose(f);
	return 0;
}
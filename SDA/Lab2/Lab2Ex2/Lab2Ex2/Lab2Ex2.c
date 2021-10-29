#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
	char ocupatie[30];
	int cod;
}persoana;

persoana a[10000];

void binaraPerformanta(persoana a[], int k, char aux[30])
{
	int s = 0, d = k, m,contor=0;
	while (s < d)
	{
		m = (s + d) / 2;
		if (strcmp(a[m].ocupatie, aux) < 0)
		{
			s = m + 1;
			contor++;
		}
		else
		{
			d = m;
			contor++;
		}
	}

	if (strcmp(a[d].ocupatie, aux))
		printf("Codul este: %d,Nr. comparatii: %d\n", a[d].cod, contor);
	else
		printf("Ocupatie Inexistenta\n");
}

void cautareLiniara(persoana a[], int k, int min,int max)
{
	int i;
	for (i = 0; i < k; i++)
	{
		if (a[i].cod>min && a[i].cod <max)
			printf("%s\n", a[i].ocupatie);
	}
}

int main()
{
	FILE *f;
	f = fopen("FisierCORalfabetic.txt","r");
	if (!f)
	{
		printf("Fisierul nu a putut fi deschis");
		return -1;
	}
	char linie[1000],aux[20];
	int i,k=0,poz,ok;
	while (fgets(linie, 1000, f) != NULL)
	{
		ok = 0;
		for (i = 0; i < strlen(linie); i++)
		{
			if (isspace(linie[i]))
			{
				i++;
				break;
			}
		}

		for (i; i < strlen(linie); i++)
		{
			if (isdigit(linie[i]))
			{
				aux[ok] = linie[i];
				ok++;
			}
			else {
				poz = i + 1;
				break;
			}
		}
		a[k].cod = atoi(aux);
		strcpy(a[k].ocupatie, linie + poz);
		k++;
	}

	
	binaraPerformanta(a, k, "programator");
	cautareLiniara(a, k, 211101, 211303);


	system("pause");
	fclose(f);
	return 0;
}
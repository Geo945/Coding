#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
typedef struct{
	int cod;
	char ocupatie[351];
}job;


void cautareLiniara(job joburi[], int k,int x){
	int i;
	for (i = 0; (i < k - 1) && (joburi[i].cod!= x); i++);
	if (joburi[i].cod == x)
		printf("Elementul se afla la pozitia %d\n", i);
	else
		printf("Elementul nu a fost gasit\n");
}

void cautareFanion(job joburi[], int k, int x){
	int i;
	joburi[k].cod = x;
	for (i = 0; (joburi[i].cod!=x) ; i++);
	if (i == k)
		printf("Elementul nu a fost gasit\n");
	else
		printf("Elementul se afla la pozitia %d\n", i);
		

}

void cautareBinara(job joburi[], int k, int x){
	int s = 0, d = k - 1, gasit = 0,m;
	while (s <= d)
	{
		m = (s + d) / 2;
		if (joburi[m].cod == x){
			gasit = 1;
			break;
		}
		else 
		if (joburi[m].cod > x)
			s = m + 1;
		else
			d = m - 1;
		

	}
	if (gasit)
		printf("Elementul se afla la pozitia %d\n", m);
	else
		printf("Elementul nu a fost gasit\n");

}

void cautareBinaraPerformanta(job joburi[], int k, int x)
{
	int s = 0, d = k, m;
	while (s < d)
	{
		m = (s + d) / 2;
		if (joburi[m].cod>x)
			s = m + 1;
		else
			d = m;
	}

	if (joburi[m].cod==x)
		printf("Elementul se afla la pozitia %d\n", d);
	else
		printf("Elementul nu a fost gasit\n");

}

void sortare_insertie(job joburi[], int k)
{
	int i, j;
	for (i = k - 2; i >= 0; i--)
	{
		joburi[k].cod = joburi[i].cod;
		strcpy(joburi[k].ocupatie, joburi[i].ocupatie);
		j = i + 1;
		while (joburi[j].cod > joburi[k].cod)
		{
			joburi[j - 1].cod = joburi[j].cod;
			strcpy(joburi[j - 1].ocupatie, joburi[j].ocupatie);
			j++;
		}
		joburi[j - 1] = joburi[k];
		strcpy(joburi[j - 1].ocupatie, joburi[k].ocupatie);
	}
}

void sortare_insertie_binara(job joburi[], int k)
{
	int i, j, s, d, m, aux;
	for (i = 1; i < k; i++)
	{
		aux = joburi[i].cod;
		s = 0;
		d = i - 1;
		while (s <= d)
		{
			m = (s + d) / 2;
			if (joburi[m].cod<=aux)
				s = m + 1;
			else
				d = m - 1;
		}
		for (j = i - 1; j >= s; j--)
		{
			joburi[j + 1].cod = joburi[j].cod;
		}
		joburi[s].cod = aux;
	}
}

void sortare_selectie(job joburi[], int k)
{
	int i, j, min,temp;
	char aux[1000];
	for (i = 0; i <= k-2; i++)
	{
		min = i;
		temp = joburi[i].cod;
		strcpy(aux, joburi[i].ocupatie);
		for (j = i + 1; j < k; j++)
		{
			if (joburi[j].cod < temp)
			{
				min = j;
				temp = joburi[j].cod;
				strcpy(aux, joburi[j].ocupatie);
			}
		}
		joburi[min].cod = joburi[i].cod;
		strcpy(joburi[min].ocupatie, joburi[i].ocupatie);
		joburi[i].cod = temp;
		strcpy(joburi[i].ocupatie, aux);

	}
}

void sortare_selectie_performanta(job joburi[], int k)
{
	int i, j, min, temp;
	char aux[1000];
	for (i = 0; i <= k - 2; i++)
	{
		min = i;
		temp = joburi[i].cod;
		strcpy(aux, joburi[i].ocupatie);
		for (j = i + 1; j < k; j++)
		{
			if (joburi[i].cod < temp)
				min = j;
		}
		temp = joburi[min].cod;
		strcpy(aux, joburi[min].ocupatie);

		joburi[min].cod = joburi[i].cod;
		strcpy(joburi[min].ocupatie, joburi[i].ocupatie);

		joburi[i].cod = temp;
		strcpy(joburi[i].ocupatie, aux);
	}
}

void bublesort(job joburi[], int k)
{
	int i, j, temp;

	for (i = 0; i < k; i++)
	{
		for (j = k - 1; j > i; j--)
		{
			if (joburi[j-1].cod < joburi[j].cod)
			{
				temp = joburi[j-1].cod;
				joburi[j-1].cod = joburi[j].cod;
				joburi[j].cod = temp;
			}
		}
	}
	
}

void shakersort(job joburi[], int k)
{//mai trb si pt denumire swap
	int i, sus = 1, jos = k - 1, temp,ultim=k-1;
	do
	{
		for (i = jos; i >= sus; i--)
		{
			if (joburi[i - 1].cod > joburi[i].cod)
			{
				temp = joburi[i - 1].cod;
				joburi[i - 1].cod = joburi[i].cod;
				joburi[i].cod = temp;
				ultim = i;
			}
		}
		sus = ultim + 1;

		for (i = sus; i <= jos; i++)
		{
			if (joburi[i - 1].cod > joburi[i].cod)
			{
				temp = joburi[i - 1].cod;
				joburi[i - 1].cod = joburi[i].cod;
				joburi[i].cod = temp;
				ultim = i;
			}
		}
		jos = ultim - 1;
	}
	while (!(sus > jos));
}

job joburi[10000];
int main()
{
	FILE *f;

	int i, poz, k = 0;

	f = fopen("COR_Descrescator.txt", "r");
	if (!f){
		printf("Eroare deschidere fisier");
		return -1;
	}

	char linie[358], id[7];
	fgets(linie, 358, f);

	while (fgets(linie, 358, f) != NULL){

		for (i = 0; i < strlen(linie); i++){
			if (linie[i] == '\t'){
				poz = i + 1;
				break;
			}
			id[i] = linie[i];
		}
		joburi[k].cod = atoi(id);
		strcpy(joburi[k].ocupatie, linie + poz);
		k++;
	}




	/*sortare_prin_selectie(joburi, k);
	for (i = 0; i < k; i++){
		printf("cod: %d, ocupatie: %s", joburi[i].cod, joburi[i].ocupatie);
	}
	printf("\n");
	insertie(joburi, k);
	for (i = 0; i < k; i++){
		printf("cod: %d, ocupatie: %s", joburi[i].cod, joburi[i].ocupatie);
	}*/
	cautareLiniara(joburi, k, 962908);
	cautareFanion(joburi, k, 213);
	cautareBinara(joburi, k, 962908);
	cautareBinaraPerformanta(joburi, k, 96290);

	//sortare_insertie(joburi, k);
	//sortare_selectie(joburi, k);
	//sortare_selectie_performanta(joburi, k);
	//bublesort(joburi, k);
	//shakersort(joburi, k);
	sortare_insertie_binara(joburi, k);
	for (i = 0; i < k; i++){
	printf("cod: %d, ocupatie: %s\n", joburi[i].cod, joburi[i].ocupatie);
	}
	system("pause");
	fclose(f);
	return 0;
}

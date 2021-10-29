#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
typedef struct{
	int cod;
	char ocupatie[351];
}job;

void sortare_prin_selectie(job a[],int k)
{
	int i, j, min;int temp,n=k;
	for (i = 0; i <= n - 2; i++)
	{
		min = i; temp = a[i].cod;
		for (j = i + 1; j < n; j++)
			if (a[j].cod<temp)
			{
				min = j; temp = a[j].cod;
			}   
		a[min].cod = a[i].cod; a[i].cod = temp; 
	}   
}    

void insertie(job a[], int k)
{
	int i, j;
	int n = k;
	for (i = n - 2; i >= 0; i--)
	{
		strcpy(a[n].ocupatie, a[i].ocupatie);
		j = i + 1;
		while (strcmp(a[j].ocupatie,a[n].ocupatie)<0 )
		{
			strcpy(a[j - 1].ocupatie,a[j].ocupatie);
			j++;
		}
		strcpy(a[j - 1].ocupatie, a[n].ocupatie);
	}
}

job joburi[10000];
int main()
{
	FILE *f;

	int i, n, poz, k = 0;

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

	
	
	
	sortare_prin_selectie(joburi, k);
	for (i = 0; i < k; i++){
	printf("cod: %d, ocupatie: %s", joburi[i].cod, joburi[i].ocupatie);
	}
	printf("\n");
	insertie(joburi, k);
	for (i = 0; i < k; i++){
	printf("cod: %d, ocupatie: %s", joburi[i].cod, joburi[i].ocupatie);
	}
	//system("pause");
	fclose(f);
	return 0;
}
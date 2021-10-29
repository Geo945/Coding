#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
typedef struct{
	int cod;
	char ocupatie[351];
}job;

void cautareCod(int codCautat, int max,job jobs[])
{
	int m;
	int s = 0, d = max;
	while (s<d) {
		m = (s + d) / 2;
		if (jobs[m].cod > codCautat)
			s = m + 1;
		else
			d = m;
	}
	if (jobs[d].cod == codCautat) {
		printf("%s", jobs[d].ocupatie);
	}
	else {
		printf("COD INEXISTENT\n");
	}
}

void cautare_liniara(job jobs[], int n){

	char cuvant[15];
	int i,j;
	//printf("\nIntroduceti cuvantul de cautat: ");
	scanf("%s", cuvant);
	for (i = 0; i < n; i++)
		if (strstr(jobs[i].ocupatie, cuvant))
			{
				for (j = 0; j < strlen(cuvant); j++)
					if (!(cuvant[j] == jobs[i].ocupatie[j]))
						break;
				
				if (j == strlen(cuvant))
					printf("%s", jobs[i].ocupatie);
			}
}
job joburi[10000];
int main()
{
	FILE *f;

	int i, n, poz, k = 0;

	f = fopen("COR_Descrescator.txt","r");
	if (!f){
		printf("Eroare deschidere fisier");
		return -1;
	}

	char linie[358],id[7];
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

	/*for (i = 0; i < k; i++){
		printf("cod: %d, ocupatie: %s", joburi[i].cod, joburi[i].ocupatie);
	}*/
	int CodCautat;
	//printf("Introduceti codul cautat: ");
	scanf("%d", &CodCautat);
	cautareCod(CodCautat, k,joburi);
	cautare_liniara(joburi, k);
	fclose(f);
	return 0;
}

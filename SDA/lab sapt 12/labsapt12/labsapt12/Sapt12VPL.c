
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define nmax 100;
char v[100][100];
int k = 0;

void interschimbare(char *x, char *y)
{
	char auxiliar;
	auxiliar = *x;
	*x = *y;
	*y = auxiliar;
}


void permuta(char *a, int l, int r)
{
	int i;
	if (l == r) {
		strcpy(v[k], a);
		k++;
		printf("Permutarea este: %s\n", a);
	}
	else
	{
		for (i = l; i <r+1; i++)
		{
			interschimbare(a + l, a + i);
			permuta(a, l + 1, r);
			interschimbare(a + l, a + i);
		}
	}
}

void parola_encode(char pass[10],int s,int d)
{
	int stanga = s, dreapta = d,mijloc=(stanga+dreapta)/2;
	if ((stanga + dreapta) % 2 != 0){
            mijloc++;
    }
	if (stanga <= dreapta){
		if (dreapta - stanga == 1){
			printf("%c%c", pass[dreapta], pass[stanga]);
		}
		else if (stanga == dreapta){
			printf("%c", pass[stanga]);
		}
		else{
			printf("%c", pass[mijloc]);parola_encode(pass, stanga, mijloc - 1);parola_encode(pass, mijloc + 1, dreapta);
		}
	}
    if(s=0)
        printf("Parola encriptata este: %s", pass);
}

int main()
{
	int n,i;
	char alf[100], MUST[100], PASS_CORECTA[100];

	printf("Introduceti parola care este corecta: ");
	scanf("%s", PASS_CORECTA);
	printf("Introduceti alf: ");
	scanf("%s", alf);
	n = strlen(alf);
	printf("Introduceti MUST: ");
	scanf("%s", MUST);
	permuta(alf, 0, n-1);
	printf("%d\n\n", k);

	for (i = 0; i < k; i++)
	{
		if (strcmp(v[i], PASS_CORECTA) == 0)
		{
			parola_encode(PASS_CORECTA,0,k-1);
			break;
		}
	}
	printf("\nParola corecta este: %s", v[i]);

	system("pause");
	return 0;
}

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define nmax 100
/*typedef struct{
	char corp_stiva[nmax][nmax];
	int varf_stiva;
} stiva;*/
typedef struct{
	char *corp_stiva[nmax];
	int varf_stiva;
} stiva;
void push(char car[], stiva *st)
{
	strcpy(st->corp_stiva[st->varf_stiva], car);
	st->varf_stiva++;

}

void pop(stiva *st)
{
	st->varf_stiva--;
}

typedef struct proiect{
	int id;
	int dimEchipa;
	stiva membru;
	struct proiect *urm;
}proiect;


proiect *nou(proiect *urm, int id, int dim)
{
    int i;
	proiect *e = (proiect*)malloc(sizeof(proiect));
	if (!e){
		printf("memorie insuficienta");
		exit(EXIT_FAILURE);
	}
	e->id = id;
	e->dimEchipa = dim;
	e->urm = urm;
	for(i=0;i<dim;i++)
	e->membru.corp_stiva[i]=(char*)malloc(dim*sizeof(char));
	e->membru.varf_stiva=0;
	return e;
}

proiect *adaugaProiect(proiect *lista, int id, int dim)
{
	return nou(lista, id, dim);
}

void adaugaMembru(proiect *lista, int id){
	char aux[100];
	for (; lista; lista = lista->urm)
		if (lista->id == id){
			printf("Introduceti codul membrului: ");
			scanf("%s",aux);
			push(aux, &(lista->membru));
		}
}

void detasareMembru(proiect *lista, int id){
	for (; lista; lista = lista->urm){
		if (lista->id == id){
			pop( &(lista->membru) );
		}
	}
}

void afisare(proiect *lista)
{
    int i;
	for (; lista; lista = lista->urm){
		printf("id: %d, Dimensiune echipe: %d ", lista->id, lista->dimEchipa);
		printf(", Coduri membri: ");
        for(i=0;i<lista->membru.varf_stiva;i++)
            {printf("%s",lista->membru.corp_stiva[i]);
                if(i!=lista->membru.varf_stiva-1)
                    printf(", ");
            }
        printf("\n");
	}
	putchar('\n');
}


void eliberare(proiect *lista)
{
    int i;
	proiect *p;
	while (lista){
		p = lista->urm;
		free(lista);
		lista = p;

	}
}


int main()
{
	proiect *lista1 = NULL;
	int n,id,dim;
	printf("1. Adaugati proiect\n2.Adaugati membru\n3.Detasare membru\n4.Afisare\n5.Iesire");
	printf("\nIntroduceti optiunea:");
	scanf("%d",&n);
	while(n!=5)
	{
        switch(n)
        {
         case 1:
             {
                printf("Introduceti id: ");
                scanf("%d",&id);
                printf("Introduceti dimensiune: ");
                scanf("%d",&dim);
                lista1 = adaugaProiect(lista1, id, dim);
                break;
             }
         case 2:
            {
                printf("Introduceti id: ");
                scanf("%d",&id);
                adaugaMembru(lista1,id);
                break;
            }
         case 3:
            {
                printf("Introduceti id: ");
                scanf("%d",&id);
                detasareMembru(lista1,id);
                break;
            }
        case 4:
            {
                printf("Proiectele sunt: \n");
                afisare(lista1);
                break;
            }
        case 5: break;
        }
    printf("1. Adaugati proiect\n2.Adaugati membru\n3.Detasare membru\n4.Afisare\n5.Iesire");
    printf("\nIntroduceti optiunea:");
	scanf("%d",&n);
	}

	eliberare(lista1);
	return 0;
}

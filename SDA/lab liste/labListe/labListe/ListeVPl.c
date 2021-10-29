#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define nmax 100
typedef struct{

	char corp_stiva[nmax][nmax];
	int varf_stiva;

} stiva;

void push(char car[], stiva st)

{

	strcpy(st.corp_stiva[st.varf_stiva], car);

	st.varf_stiva++;

}

void pop(stiva st)

{

	st.varf_stiva--;

	//return   st.corp_stiva[st.varf_stiva];

}

typedef struct proiect{
	int id;
	int dimEchipa;
	stiva membru;
	struct proiect *urm;
}proiect;


proiect *nou(proiect *urm,int id,int dim)
{
	proiect *e = (proiect*)malloc(sizeof(proiect));
	if (!e){
		printf("memorie insuficienta");
		exit(EXIT_FAILURE);
	}
	e->id = id;
	e->dimEchipa = dim;
	e->urm = urm;
	return e;
}

proiect *adaugaProiect(proiect *lista, int id,int dim)
{
	return nou(lista, id,dim);
}

void adaugaMembru(proiect *lista,int id){
	char aux[100];
	for (; lista;lista=lista->urm)
		if (lista->id == id){
			printf("Introduceti nume membru: ");
			scanf("%s",aux);
			push(aux, lista->membru);
		}
}

void detasareMembru(proiect *lista, int id){
	for (; lista; lista = lista->urm){
		if (lista->id == id){
			pop(lista->membru);
		}
	}
}

void afisare(proiect *lista)
{
    int i;
	for (; lista; lista = lista->urm){
		printf("id: %d, Dimensiune echipe: %d", lista->id,lista->dimEchipa);

		printf(", Nume membri: ");
        for(i=0;i<lista->membru.varf_stiva;i++){
            printf("%s",lista->membru.corp_stiva[i]);
            printf("MEREEEEEEEEE");
        }
        printf("\n");
	}
	putchar('\n');
}


void eliberare(proiect *lista)
{
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
	lista1 = adaugaProiect(lista1, 1, 200);
	lista1 = adaugaProiect(lista1, 2, 200);
	adaugaMembru(lista1, 1);
	adaugaMembru(lista1, 1);
    afisare(lista1);


	eliberare(lista1);

	return 0;
}

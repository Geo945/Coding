#include <stdio.h>
#include <stdlib.h>


typedef struct elem{
int n;
struct elem *urm;
}elem;

elem *nou(int n,elem *urm)
{
    elem *e=(elem*)malloc(sizeof(elem));
    if(!e)
    {
        printf("Eroare");
        exit(EXIT_FAILURE);
    }
    e->n=n;
    e->urm=urm;
    return e;
}

elem *adaugaInceput(elem *lista,int n)
{
    return nou(n,lista);
}

elem *adaugaSfarsit(elem *lista,int n)
{
    if(!lista)return nou(n,NULL);
    elem *e=lista,*urm;
    for(urm=e->urm;urm;urm=e->urm)
        e->urm=nou(n,NULL);

    return lista;
}

void afisare(elem *lista)
{
    for(;lista;lista=lista->urm)
        printf("%d ",lista->n);

    printf("\n");
}

void eliberare(elem *lista)
{
    elem *e;
    while(lista)
    {
        e=lista->urm;
        free(lista);
        lista=e;
    }
}

elem *mere(elem *lista)
{
    elem *lista1=NULL;
    for(;lista;lista=lista->urm)
        lista1=adaugaInceput(lista1,lista->n);

    return lista1;
}

/*Să se scrie o funcție care primește ca parametri o listă (posibil vidă)
 de elemente sortate și un element. Funcția va insera în listă noul element,
  astfel încât lista să rămână sortată. Folosind aceasta funcție,
   să se scrie o funcție de sortare a unei liste,
   care primește ca parametru o listă nesortată și returnează una sortată.
    Programul nu va folosi niciun vector
*/
elem *mere1(elem *lista,int a)
{
    elem *lista3=NULL;
    elem *lista4=NULL;
    int ok=0;
    if(lista==NULL)
    {
        lista3=adaugaInceput(lista3,a);
        return lista3;
    }

    for(;lista;lista=lista->urm)
    {
        if(lista->n<a)
        {
            lista3=adaugaInceput(lista3,lista->n);
        }
        else if(lista->n>a)
                {lista3=adaugaInceput(lista3,a);ok=1;break;}
    }
    for(;lista;lista=lista->urm)
    lista3=adaugaInceput(lista3,lista->n);
    if(ok==0)
        lista3=adaugaInceput(lista3,a);
    for(;lista3;lista3=lista3->urm)
    {
        lista4=adaugaInceput(lista4,lista3->n);
    }
    return lista4;

}

elem *f2(elem *lista)
{
    elem *lista1=NULL;
    elem *lista2=NULL;
    for(;lista;lista=lista->urm)
    {
        lista1=mere1(lista1,lista->n);
    }
    return lista1;
}

int main()
{
    elem *lista1=NULL;
    elem *lista2=NULL;

    lista1=adaugaInceput(lista1,192);
    lista1=adaugaInceput(lista1,50);
    lista1=adaugaInceput(lista1,23);
    lista1=adaugaInceput(lista1,2);
    lista1=adaugaInceput(lista1,1);
    printf("Lista citita este: ");
    afisare(lista1);

    int a;
    printf("Introduceti elementul a: ");
    scanf("%d",&a);
    lista2=mere1(lista1,a);
    printf("Noua lista este: ");
    afisare(lista2);
    eliberare(lista1);
    eliberare(lista2);


    elem *lista3=NULL;
    elem *lista4=NULL;
    lista3=adaugaInceput(lista3,1);
    lista3=adaugaInceput(lista3,50);
    lista3=adaugaInceput(lista3,2);
    lista3=adaugaInceput(lista3,80);
    lista3=adaugaInceput(lista3,34);
    printf("A doua lista citita: ");
    afisare(lista3);
    lista4=f2(lista3);
    printf("Lista formata: ");
    afisare(lista4);

    eliberare(lista4);
    eliberare(lista3);
    return 0;
}

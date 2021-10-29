#include <stdio.h>
#include <stdlib.h>
//Aplicația 9.5: Să se scrie o funcție care primește două liste
// și returnează 1 dacă ele sunt egale, indiferent de ordinea și numărul elementelor, altfel returnează 0.
//Exemple: listele {1, 7, 3, 1, 3} și {7, 1, 3, 7} sunt egale. Listele {1,2} și {2} nu sunt egale.

typedef struct elem{
int n;
struct elem *urm;
}elem;

elem *nou(int n,elem *urm)
{
    elem *e=(elem*)malloc(sizeof(elem));
    if(!e)
    {
        printf("Eroare de alocare");
        exit(EXIT_FAILURE);
    }
    e->n=n;
    e->urm=urm;

    return e;
}

elem *AdaugareInceput(elem *lista,int n)
{
    return nou(n,lista);
}

void afisare(elem *lista)
{
    for(;lista;lista=lista->urm)
    {
        printf("%d ",lista->n);
    }
    printf("\n");
}

void eliberare(elem *lista)
{
    elem *p;
    while(lista){
        p=lista->urm;
        free(lista);
        lista=p;
    }
}

int mere(elem *lista1,elem *lista2)
{
    elem *lista3=NULL;
    elem *lista4=NULL;
    int ok;
    for(;lista1;lista1=lista1->urm)
    {
        lista4=lista2;
        ok=0;
        for(;lista4;lista4=lista4->urm)
        {
            if(lista4->n==lista1->n)
            {
                ok=1;
                lista3=AdaugareInceput(lista3,lista1->n);
                break;
            }
        }
        if(ok==0)
            {
             break;
            }
    }

    eliberare(lista3);

    if(ok==1)
        return 1;
    else
        return 0;

}


int main()
{
    elem *lista1=NULL;
    elem *lista2=NULL;

    lista1=AdaugareInceput(lista1,1);
    lista1=AdaugareInceput(lista1,7);
    lista1=AdaugareInceput(lista1,3);
    lista1=AdaugareInceput(lista1,1);
    lista1=AdaugareInceput(lista1,3);
    printf("Prima lista este: ");
    afisare(lista1);


    lista2=AdaugareInceput(lista2,7);
    lista2=AdaugareInceput(lista2,1);
    lista2=AdaugareInceput(lista2,3);
    lista2=AdaugareInceput(lista2,7);
    printf("A doua lista este: ");
    afisare(lista2);


    printf("Sunt listele egale?(1-da, 0-nu): %d",mere(lista1,lista2));

    eliberare(lista1);
    eliberare(lista2);
    return 0;
}

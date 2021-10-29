#include <stdio.h>
#include <stdlib.h>

//Aplicația 9.1: Să se scrie o funcție care primește două liste și returnează 1 dacă ele sunt identice, altfel 0.

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

elem *AdaugareElement(int n,elem *lista)
{
    return nou(n,lista);
}

void afisare(elem *lista)
{
    for(;lista;lista=lista->urm){
        printf("%d ",lista->n);
        }

}
/*
int mere(elem *lista1,elem *lista2)
{
    int ok;
    for(;lista1;lista1=lista1->urm)
        {
            ok=0;
            for(;lista2;lista2=lista2->urm)
                {
                    if(lista1->n==lista2->n)
                    {
                        ok=1;
                        break;
                    }

                }

        }

    if(ok==1)
        return 1;
    else return 0;

}*/

int functie(elem *lista1,elem *lista2)
{
    int i,ok=1;
    for(;lista1;lista1=lista1->urm)
    {
        if(lista1->n!=lista2->n)
        {
            ok=0;
            break;
        }
        else lista2=lista2->urm;
    }
    if(ok==1)
        return 1;
    else return 0;
}

int main()
{
    elem *lista1=NULL;
    lista1=AdaugareElement(108,lista1);
    lista1=AdaugareElement(2,lista1);
    afisare(lista1);
    printf("\n");

    elem *lista2=NULL;
    lista2=AdaugareElement(108,lista2);
    lista2=AdaugareElement(2,lista2);

    afisare(lista2);

    int a;
    a=functie(lista1,lista2);
    printf("\n%d",a);

    //printf("\nSunt listele egale?(1-da, 0-nu): %d \n",mere(lista1,lista2));

    return 0;
}

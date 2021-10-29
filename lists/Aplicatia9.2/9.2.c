#include <stdio.h>
#include <stdlib.h>


/*Aplicația 9.2:
Să se scrie o funcție care primește o
 listă și returnează lista respectivă cu
  elementele inversate. Funcția va acționa
   doar asupra listei originare, fără a folosi vectori sau alocare de noi elemente
*/

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

elem *AdaugareInceput(int n,elem *lista)
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

elem *ListaNoua(elem *lista)
{
    elem *lista2=NULL;
    for(;lista;lista=lista->urm)
    {
        lista2=AdaugareInceput(lista->n,lista2);
    }
    return lista2;

}

int main()
{
    elem *lista1;
    lista1=NULL;
    lista1=AdaugareInceput(108,lista1);
    lista1=AdaugareInceput(10,lista1);
    afisare(lista1);
    lista1=ListaNoua(lista1);
    afisare(lista1);


    return 0;
}

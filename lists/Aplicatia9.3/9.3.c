#include <stdio.h>
#include <stdlib.h>

/*

Aplicația 9.3:
Să se scrie o funcție care primește ca parametri
 două liste și returnează o listă care reprezintă
  reuniunea elementelor lor, fiecare element apărând
   o singură dată, chiar dacă în listele originare el este duplicat.

*/

typedef struct elem
{
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

elem *adaugaSfarsit(elem *lista,int n)
{
    if(!lista)return nou(n,NULL);
    elem *p=lista,*urm;
    for(urm=p->urm;urm;p=urm,urm=p->urm){}
    p->urm=nou(n,NULL);
    return lista;
}



void afisare(elem *lista)
{
    for(;lista;lista=lista->urm)
    {
        printf("%d ",lista->n);
    }
    printf("\n");
}

elem *ListaNoua(elem *lista1,elem *lista2)
{
    elem *lista3=NULL;
    elem *lista4=NULL;

    int ok,k;

    for(;lista1;lista1=lista1->urm)
    {
        ok=0;
        lista4=lista3;
        for(;lista4;lista4=lista4->urm)
                if(lista1->n==lista4->n)
                    {
                        ok=1;
                        break;
                    }

            if(ok==0)
            {lista3=AdaugareInceput(lista1->n,lista3);
            ok=1;
            }

    }

     for(;lista2;lista2=lista2->urm)
    {
        k=0;
        lista4=lista3;
        for(;lista4;lista4=lista4->urm)
                if(lista2->n==lista4->n)
                    {
                        k=1;
                        break;
                    }

            if(k==0)
            {lista3=AdaugareInceput(lista2->n,lista3);
            ok=1;
            }

    }


    return lista3;
}



void rotire(elem *lista, int k)
{
    elem* prim;
    prim = lista;

    if(k < 0)
        while(k != 0)
    {
        for(;lista;lista = lista->urm)
        if(lista->urm == NULL)
        {
        lista->urm = prim;
        prim->urm = NULL;
        }
        k++;
    }
    else
        while(k != 0)
    {
        for(;lista->urm->urm == NULL;lista = lista->urm)
        if(lista->urm->urm == NULL)
        {
        lista->urm->urm = prim;
        lista->urm = NULL;
        }

        k--;
    }
}

int main()
{
    elem *lista1=NULL;
    int k, i;
   // k = atoi(b[1]);
    char b[] = "324689";
    for(i = 0; i < 6; i++)
        lista1 = AdaugareInceput(b[i],lista1);

   k = -10;
   rotire(lista1, k);



    printf("Prima lista este: ");
    afisare(lista1);


    return 0;
}


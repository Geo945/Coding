#include <stdio.h>
#include <stdlib.h>
/*

Aplicația 9.7:
Pentru implementarea listei
 care memorează ultimul element
 , să se scrie o funcție care
 primește două liste sortate și
 returnează lista sortată care
  conține toate elementele lor.
  Pentru lista rezultată se va
  folosi doar operația de adăugare la sfârșit de listă.

Exemplu: {1, 2, 7, 8} și {2, 9} -> {1, 2, 2, 7, 8, 9}


*/

// un element al listei
typedef struct elem{
    int n;                          // informatia utila
    struct elem *urm;       // camp de inlantuire catre urmatorul element
    }elem;

// aloca un nou element si ii seteaza campurile corespunzatoare
elem *nou(int n,elem *urm)
{
    elem *e=(elem*)malloc(sizeof(elem));
    if(!e){
        printf("memorie insuficienta");
        exit(EXIT_FAILURE);
        }
    e->n=n;
    e->urm=urm;
    return e;
}

typedef struct{
    elem *prim;     // primul element din lista
    elem *ultim;    // ultimul element din lista
    }Lista;

void init(Lista *lista)
{
    lista->prim=NULL;
    lista->ultim=NULL;
}

// adauga un element la inceputul listei
void adaugaInceput(Lista *lista,int n)
{
    elem *prim=lista->prim;
    lista->prim=nou(n,prim);
    if(!prim){      // lista initiala vida - trebuie setat si ultim pe elementul adaugat
        lista->ultim=lista->prim;
        }
}

// adauga un element la sfarsitul listei
void adaugaSfarsit(Lista *lista,int n)
{
    elem *e=nou(n,NULL);
    if(lista->ultim){                   // adaugare in lista nevida
        lista->ultim->urm=e;
        }else{                              // adaugare in lista vida
        lista->prim=e;
        }
    lista->ultim=e;
}

void afisare(Lista *lista)
{
    elem *crt;
    for(crt=lista->prim;crt;crt=crt->urm){
        printf("%d ",crt->n);
        }
    putchar('\n');
}

// elibereaza memoria ocupata de o lista
void eliberare(Lista *lista)
{
    elem *p,*crt=lista->prim;
    while(crt){
        p=crt->urm;
        free(crt);
        crt=p;
        }
}

Lista sortare(Lista *lista1,Lista *lista2)
{
    int a[100],k=0,i,ok=0,aux;
   Lista lista3;
   init(&lista3);

   elem *crt1=lista1->prim;
    elem *crt2=lista2->prim;

   for(crt1=lista1->prim;crt1;crt1=crt1->urm)
   {
        a[k++]=crt1->n;
   }

    for(crt2=lista2->prim;crt2;crt2=crt2->urm)
   {
       a[k++]=crt2->n;
   }

   while(ok==0)
   {
       ok=1;
       for(i=0;i<k-1;i++)
       {
           if(a[i]>a[i+1])
           {
           aux=a[i];
           a[i]=a[i+1];
           a[i+1]=aux;
           ok=0;
           }
       }
   }

    for(i=0;i<k;i++)
        printf("%d ",a[i]);
    printf("\n");

   for(i=0;i<k;i++)
   adaugaSfarsit(&lista3,a[i]);

   return lista3;

}

int main()
{
    Lista lista1;
    init(&lista1);
    adaugaSfarsit(&lista1,108);
    adaugaSfarsit(&lista1,-1);
    adaugaSfarsit(&lista1,49);
    afisare(&lista1);

    Lista lista2;
    init(&lista2);
    adaugaSfarsit(&lista2,108);
    adaugaSfarsit(&lista2,2);
    adaugaSfarsit(&lista2,49);
    afisare(&lista2);


    Lista lista3;
    init(&lista3);
    lista3=sortare(&lista1,&lista2);
    afisare(&lista3);

    eliberare(&lista1);
    eliberare(&lista2);
    eliberare(&lista3);
    return 0;
}

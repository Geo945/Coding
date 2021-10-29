#include <stdio.h>
#include <stdlib.h>

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

Lista stergere(Lista *lista)
{
    int x,a[100];
    printf("Introduceti elementul de sters: ");
    scanf("%d",&x);
   Lista lista3;
   init(&lista3);
   Lista lista4;
   init(&lista4);
   elem *crt=lista->prim;

   for(crt=lista->prim;crt;crt=crt->urm)
   {
       if(crt->n!=x)
        adaugaInceput(&lista3,crt->n);
   }

   return lista3;

}

int main()
{
    Lista lista;
    init(&lista);
    adaugaSfarsit(&lista,108);
    adaugaSfarsit(&lista,-1);
    adaugaSfarsit(&lista,49);
    afisare(&lista);


    lista=stergere(&lista);
    afisare(&lista);


    eliberare(&lista);




    return 0;
}

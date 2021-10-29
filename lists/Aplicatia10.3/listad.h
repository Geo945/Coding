#if !defined(LISTAD_NUME) || !defined(LISTAD_ELEMENT)
    #error "LISTAD_NUME si LISTAD_ELEMENT trebuie definite inainte de a include listad.h"
#endif

typedef struct{
    LISTAD_ELEMENT *prim;
    LISTAD_ELEMENT *ultim;
    }LISTAD_NUME;

#ifndef LISTAD_FN
    // aceste macrouri sunt definite doar daca listad.h nu a mai fost inclus anterior
    #define LISTAD_FNAUX(NUME,OPERATIE)     NUME##_##OPERATIE
    #define LISTAD_FN(NUME,OPERATIE)     LISTAD_FNAUX(NUME,OPERATIE)
#endif

void LISTAD_FN(LISTAD_NUME,init)(LISTAD_NUME *lista)
{
    lista->prim=lista->ultim=NULL;
}

void LISTAD_FN(LISTAD_NUME,adauga)(LISTAD_NUME *lista,LISTAD_ELEMENT *e)
{
    e->pred=lista->ultim;
    if(lista->ultim){
        lista->ultim->urm=e;
        }else{
        lista->prim=e;
        }
    lista->ultim=e;
    e->urm=NULL;
}

void LISTAD_FN(LISTAD_NUME,sterge)(LISTAD_NUME *lista,LISTAD_ELEMENT *e)
{
    if(e->pred){
        e->pred->urm=e->urm;
        }else{
        lista->prim=e->urm;
        }
    if(e->urm){
        e->urm->pred=e->pred;
        }else{
        lista->ultim=e->pred;
        }
    free(e);
}

void LISTAD_FN(LISTAD_NUME,elibereaza)(LISTAD_NUME *lista)
{
    LISTAD_ELEMENT *e,*urm;
    for(e=lista->prim;e;e=urm){
        urm=e->urm;
        free(e);
        }
    LISTAD_FN(LISTAD_NUME,init)(lista);
}

void LISTAD_FN(LISTAD_NUME,inserare)(LISTAD_NUME *lista)
{

	char text[20],succesor[20];
    	printf("Introduceti cuvantul de adaugat: ");
    	scanf("%s",text);
    	printf("Introduceti cuvantul succesor: ");
    	scanf("%s",succesor);

	LISTAD_ELEMENT *c;
	c=Propozitie_cauta(lista,succesor);


    if(c!=NULL)
    {
        Cuvant *nou=Cuvant_nou(text);
              if(c->pred==NULL)
            {
            nou->pred=NULL;
            nou->urm=c;
            c->pred=nou;
            lista->prim=nou;
            }
        else
            {
            c->pred->urm=nou;
            nou->pred=c->pred;
            nou->urm=c;
            c->pred=nou;
            }
    }
    else
    {
        c=Cuvant_nou(text);
        Propozitie_adauga(lista,c);
    }



}

// definitiile trebuie sterse pentru a putea refolosi listad.h de mai multe ori in cadrul aceluiasi fisier
#undef LISTAD_NUME
#undef LISTAD_ELEMENT

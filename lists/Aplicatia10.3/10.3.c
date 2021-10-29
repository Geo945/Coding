#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Aplicația 10.2:
La exemplul 1 să se adauge operația de inserare a unui cuvânt.
 Pentru aceasta se cere un cuvânt de inserat și un cuvânt succesor.
  Dacă succesorul există în propoziție, cuvântul de inserat va fi
   inserat înaintea sa. Dacă succesorul nu există în lista, cuvântul
   de inserat va fi adăugat la sfârșitul listei
*/

typedef struct Cuvant{
    char text[16];
    struct Cuvant *pred;
    struct Cuvant *urm;
    }Cuvant;



Cuvant *Cuvant_nou(const char *text)
{
    Cuvant *c=(Cuvant*)malloc(sizeof(Cuvant));
    if(!c){
        printf("memorie insuficienta");
        exit(EXIT_FAILURE);
        }
    strcpy(c->text,text);
    return c;
}



#define LISTAD_NUME Propozitie
#define LISTAD_ELEMENT Cuvant
#include "listad.h"

void Propozitie_init(Propozitie *p)
{
    p->prim=p->ultim=NULL;
}


void Propozitie_adauga(Propozitie *p,Cuvant *c)
{
    c->pred=p->ultim;
    if(p->ultim){
        p->ultim->urm=c;
        }else{
        p->prim=c;
        }
    p->ultim=c;
    c->urm=NULL;
}


Cuvant *Propozitie_cauta(Propozitie *p,const char *text)
{
    Cuvant *c;
    for(c=p->prim;c;c=c->urm){
        if(!strcmp(c->text,text))return c;
        }
    return NULL;
}


void Propozitie_sterge(Propozitie *p,Cuvant *c)
{
    if(c->pred){
        c->pred->urm=c->urm;
        }else{
        p->prim=c->urm;
        }
    if(c->urm){
        c->urm->pred=c->pred;
        }else{
        p->ultim=c->pred;
        }
    free(c);
}


void Propozitie_elibereaza(Propozitie *p)
{
    Cuvant *c,*urm;
    for(c=p->prim;c;c=urm){
        urm=c->urm;
        free(c);
        }
    Propozitie_init(p);
}

/*
Aplicația 10.2:
La exemplul 1 să se adauge operația de inserare a unui cuvânt.
 Pentru aceasta se cere un cuvânt de inserat și un cuvânt succesor.
  Dacă succesorul există în propoziție, cuvântul de inserat va fi
   inserat înaintea sa. Dacă succesorul nu există în lista, cuvântul
   de inserat va fi adăugat la sfârșitul listei
*/
void Propozitie_inserare(Propozitie *p)
{
    char text[20],succesor[20];
    printf("Introduceti cuvantul de adaugat: ");
    scanf("%s",text);
    printf("Introduceti cuvantul succesor: ");
    scanf("%s",succesor);
    Cuvant *c;
    c=Propozitie_cauta(p,succesor);


    if(c!=NULL)
    {
        Cuvant *nou=Cuvant_nou(text);
              if(c->pred==NULL)
            {
            nou->pred=NULL;
            nou->urm=c;
            c->pred=nou;
            p->prim=nou;
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
        Propozitie_adauga(p,c);
    }



}



int main()
{
    Propozitie p;
    int op;     // optiune
    char text[16],aux1[20],aux2[20];
    Cuvant *c,*c1;

    Propozitie_init(&p);				// initializare propozitie vida
    do{
        printf("1 - propozitie noua\n");
        printf("2 - afisare\n");
        printf("3 - stergere cuvant\n");
        printf("4 - inserare cuvant\n");
        printf("5 - iesire\n");
        printf("optiune: ");scanf("%d",&op);
        switch(op){
            case 1:
                Propozitie_elibereaza(&p);    	// elibereaza posibila propozitie anterioara
                for(;;){
                    scanf("%s",text);
                    // intre ultimul cuvant si punct trebuie sa existe un spatiu, pentru ca punctul sa fie considerat separat
                    if(!strcmp(text,"."))break;      	// atentie: "." este un sir de caractere, nu o litera (char)
                    Cuvant *c=Cuvant_nou(text);
                    Propozitie_adauga(&p,c);
                    }
                break;
            case 2:
                for(c=p.prim;c;c=c->urm)printf("%s ",c->text);
                printf(".\n");
                break;
            case 3:
                printf("cuvant de sters:");scanf("%s",text);
                c=Propozitie_cauta(&p,text);
                if(c){
                    Propozitie_sterge(&p,c);
                    }else{
                    printf("cuvantul \"%s\" nu se gaseste in propozitie\n",text);
                    }
                break;
            case 4:
                {
                    Propozitie_inserare(&p);
                    break;
                }
            case 5:break;
            default:printf("optiune invalida");
            }
        }while(op!=5);
    return 0;
}

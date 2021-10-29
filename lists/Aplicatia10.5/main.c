#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Cuvant{
    char text[1000];
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

typedef struct{
    Cuvant *prim;
    Cuvant *ultim;
    }Propozitie;


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
    Cuvant *c,*urm;
    for(c=p->prim;c;c=c->urm){
        if(strcmp(c->text,text)<0)return c;
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

void inserare(Propozitie *p,char text[20],char succesor[20])
{


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


void Propozitie_elibereaza(Propozitie *p)
{
    Cuvant *c,*urm;
    for(c=p->prim;c;c=urm){
        urm=c->urm;
        free(c);
        }
    Propozitie_init(p);
}

int main(int argc,char *argv[])
{
    Propozitie p;
    Cuvant *c,*urm;
    char text[]="Fisier.txt";
    FILE *f;
    f=fopen(text,"r");
    Propozitie_init(&p);
    if(f==NULL)
    {
        printf("Deschidere nereusita");
        exit(EXIT_FAILURE);
    }

    char linie[1000];

    while(fgets(linie,1000,f)!=NULL)
    {
        c=Cuvant_nou(linie);
        Propozitie_adauga(&p,c);
    }

    char aux1[1000],aux2[1000];
    int ok=0;

    Cuvant *aux;



     for(c=p.prim;c;c=c->urm)
        printf("%s ",c->text);
                printf(".\n");

    Propozitie_elibereaza(&p);
    fclose(f);
    return 0;
}

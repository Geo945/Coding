#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define PI      3.14159


/* Aplicația 3.7: În exemplul de implementare a colecțiilor eterogene folosind
  pointeri la funcții să se adauge o nouă funcție polimorfică, nume,
   care returnează numele tipului elementului, ca pointer la un șir de caractere.
    Să se testeze funcția adăugată pe colecția eterogenă.
*/
void *alocare(size_t nOcteti)
{
    void *p=malloc(nOcteti);
    if(!p){
        printf("memorie insuficienta\n");
        exit(EXIT_FAILURE);
        }
    return p;
}

typedef enum{TFCerc,TFTriunghi,TFDreptunghi}TipFigura;
typedef struct{
    TipFigura tip;
    union{
        struct{
            double r;       // raza
            }cerc;
        struct{
            double a,b,c;   // lungimile laturilor
            }tr;
        struct{
            double latime,inaltime;
            }dr;
        };
    }Figura;

// analogic pentru arie
double perimetru(const Figura *f)
{
    switch(f->tip){
        case TFCerc:return 2*PI*f->cerc.r;
        case TFTriunghi:return f->tr.a+f->tr.b+f->tr.c;
        case TFDreptunghi:return 2*(f->dr.latime+f->dr.inaltime);
        }
}

// analogic pentru Triunghi_new, Dreptunghi_new
Figura *Cerc_new(double r)
{
    Figura *f=(Figura*)alocare(sizeof(Figura));

    f->tip=TFCerc;
    f->cerc.r=r;
    return f;
}
void nume(const Figura *f)
{
    switch(f->tip)
    {
    case TFCerc :
        {
            printf("numele figurii este: cerc\n");
            break;
        }
    case TFTriunghi :
        {
            printf("numele figurii este: triunghi\n");
            break;
        }
    case TFDreptunghi :
        {
            printf("numele figurii este: dreptunghi\n");
            break;
        }
    }
}
int main(void)
{
    Figura *figuri[100];        // vector de pointeri la figuri alocate dinamic
    int i,nFiguri=0;
    // introducere figuri
    figuri[nFiguri++]=Cerc_new(7.3);

    // afisare perimetre
    for(i=0;i<nFiguri;i++){
        printf("%g\n",perimetru(figuri[i]));
        nume(figuri[i]);
        }
    return 0;
}


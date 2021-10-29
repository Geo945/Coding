#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
/*

Aplicația 12.2:
Se cere un n strict pozitiv și patru valori reale: ma, mb, m, d. ma și mb reprezintă masele a două corpuri situate la distanța d unul de celălalt.
 m este masa unui corp care pornește din a și ajunge în b, din n pași egali. Să se calculeze în fiecare punct al traseului lui m forța F de
  atracție gravitațională care acționează asupra lui. F va fi cu semn: negativ înseamnă că m este atras către ma, iar pozitiv către mb.
   Formula atracției gravitaționale dintre două corpuri m1 și m2, situate la distanța d unul de celălalt este: F=G*m1*m2/d2, unde G=6.674e-11.
    Masele sunt exprimate în kilograme, distanțele în metri, iar forțele în newtoni

*/

#define G 6.674e-11

int main()
{

    int n;
    float ma,mb,m,k=0,f,f1,d;

    printf("Introduceti numarul n: ");scanf("%d",&n);
    assert(n>0);
    printf("Introduceti numarul ma: ");scanf("%f",&ma);
    printf("Introduceti numarul mb: ");scanf("%f",&mb);
    printf("Introduceti numarul m: ");scanf("%f",&m);
    d=mb-ma;
    k=(mb-ma)/n;
    f=ma;
    while(f<=mb)
    {
        f1=G*f*(f+k)/d*d;
        if(f1<0)
            printf("%g => atras de ma\n",f1);
        else printf("%g => atras de mb\n",f1);
        f=f+k;
    }

    return 0;
}

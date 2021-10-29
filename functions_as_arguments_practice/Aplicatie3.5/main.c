#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/*

Aplicația 3.5: Să se implementeze o funcție care tabelează o funcție matematică de un parametru, primită ca argument.
 Funcția tabelată primește un parametru de tip double și returnează o valoare tot de tip double.

  Funcția de tabelare va primi ca parametri: a și b - capetele de tip double ale intervalului închis de tabelat,
   n - un număr întreg care arată în câte segmente egale se împarte intervalul [a,b], incluzând capetele acestuia și
    f - funcția de tabelat.

     Să se testeze funcția de tabelare cu valori a,b și n citite de la tastatură, tabelând funcțiile cos, sqrt și fabs din math.h
Exemplu: tabelare(-10,10,20,fabs) va afișa pe câte o linie valori de forma f(-10)=10  f(-9)=9   … f(10)=10


*/

void f(double a,double b,int n, double(*functie)(double) )
{
    double i;

    if(a*b<0)
    i=((double)abs(a)+(double)abs(b))/(double)n;

    if(a>0 && b>0)
    i=( ((double)abs(b)-(double)abs(a))/(double)n );

    if(a<0 && b<0)
    i=( ((double)abs(a)-(double)abs(b))/(double)n );

    while(a<=b)
    {
        printf("f(%0.2lf)=%0.2lf \n",a,functie(a));
        a=a+i;
    }
}

int main()
{
    double a,b;
    int n;
    printf("Introduceti capatul inferior al intervalului: ");
    scanf("%lf",&a);

    printf("Introduceti capatul inferior al intervalului: ");
    scanf("%lf",&b);

    printf("Introduceti numarul n: ");
    scanf("%d",&n);



    f(a,b,n,fabs);

    return 0;
}

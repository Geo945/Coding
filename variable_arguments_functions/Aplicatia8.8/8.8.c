#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
/*

Aplicația 8.8:
Să se scrie o funcție sortare(int n,...)
care pe prima poziție are numărul de elemente de sortat
, iar pe următoarele poziții n adrese de valori de tip int.
 Funcția va sorta crescător valorile de la adresele date.

Exemplu: sortare(3,&i,&j,&k);			// sortează crescător valorile lui i, j și k

*/
void sortare(int n,...)
{
    va_list va;
    va_start(va,n);
    int ok=0,i,a[100],aux,*addr;
    for(i=0;i<n;i++)
        {
            addr=va_arg(va,int*);
            a[i]=*addr;
        }
    while(ok==0)
    {
        ok=1;
        for(i=0;i<n-1;i++)
            if(a[i]>a[i+1])
        {
            aux=a[i];
            a[i]=a[i+1];
            a[i+1]=aux;
            ok=0;
        }
    }
    printf("Vectorul ordonat este: ");
    for(i=0;i<3;i++)
        printf("%d ",a[i]);
    va_end(va);
}

int main()
{
    int i=1,j=-2,k=-13;
    sortare(3,&i,&j,&k);

    return 0;
}

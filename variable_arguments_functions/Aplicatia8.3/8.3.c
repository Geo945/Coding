#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <math.h>
/*


Aplicația 8.3:
Să se scrie o funcție absN(int n,...)
 care primește un număr n de adrese de tip
 float și setează la fiecare dintre aceste
  adrese valoarea absolută de la acea locație.

Exemplu: absN(2,&x,&y);		// echivalent cu x=fabs(x); y=fabs(y);

*/

void absN(int n,...)
{
    va_list va;
    va_start(va,n);
    double *addr,a[100];
    int i;
    for(i=0;i<n;i++)
    {
        addr=va_arg(va,double*);
        if(*addr<0)
        *addr=*addr*(-1);
        a[i]=*addr;

    }
    va_end(va);

}

int main()
{
    double x=1.2,y=-8.99;
    absN(2,&x,&y);
    printf("%lg ,%lg",x,y);
    return 0;
}

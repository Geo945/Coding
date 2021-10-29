#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
/*

Aplicația 8.2:
Să se scrie o funcție float *allocVec(int n,...)
 care primește pe prima poziție un număr de elemente
  iar apoi n elemente reale. Funcția va aloca dinamic
   un vector de tip float în care va depune toate elementele.
Exemplu: allocVec(3,7.2,-1,0)		=> {7.2, -1, 0}

*/

float *allocVec(int n,...)
{
    float *v;
    int k=0;
    va_list va;
    va_start(va,n);
    v=(float*)malloc(n*sizeof(float));
    while(n!=0)
    {
        v[k]=(float)va_arg(va,double);
        k++;
        n--;
    }

    va_end(va);
    return v;

}

int main()
{
    float *v;
    int i;
    v=allocVec(3,7.2,-1.0,23.0);

    //for(i=0;i<3;i++)
       // printf("%lf ",v[i]);
    free(v);
    return 0;
}

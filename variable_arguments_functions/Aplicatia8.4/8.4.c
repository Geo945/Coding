#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
/*

Aplicația 8.4
 Să se scrie o funcție crescator(int n,char tip,...)
  care primește un număr n de valori și returnează 1
  dacă ele sunt în ordine strict crescătoare, altfel 0.
   Caracterul tip indică tipul valorilor și poate fi ‘d’ - int, ‘f’ - double.

Exemplu: printf(“%d”,crescator(3,’d’,-1,7,9));

*/
int crescator(int n,char tip,...)
{
    va_list va;
    va_start(va,tip);
    int k=1,v[20],i;
    double v1[20];

    switch(tip)
        {
        case 'd':
            {
            for(i=0;i<n;i++)
                v[i]=va_arg(va,int);
            for(i=0;i<n-1;i++)
                if(v[i]>v[i+1])
                    k=0;
             break;
            }
        case 'f':
            for(i=0;i<n;i++)
                v1[i]=va_arg(va,double);
            for(i=0;i<n-1;i++)
                if(v1[i]>v1[i+1])
                    k=0;
        }
    va_end(va);

    if(k==1)
        return 1;
    else return 0;

}


int main()
{
    printf("Valoarea returnata este: %d",crescator(3,'d',-1,0,9));
    return 0;
}

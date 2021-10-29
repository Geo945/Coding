#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
/*
Aplicația 8.1:
Să se modifice exemplul 2 astfel încâ
t funcția err să încapsuleze și condiția de eroare
. Pentru aceasta, ea primește în plus pe prima poziție
 o variabilă de tip int care reprezintă o valoare logică.
  Dacă valoarea este true, se va executa err ca în exemplu,
   altfel err nu va avea niciun efect.
Exemplu de folosire: err(n<=0||n>100,"n invalid: %d\n",n);    // fără if în față, deoarece err încapsulează condiția
*/
void err(int a,const char *fmt,...)
{
    if(a==1)
    {
    va_list va;     		// pointer la lista de argumente variabile (varargs)
    va_start(va,fmt);   		// va trebuie initializat cu ultimul argument fix al functiei
    fprintf(stderr,"eroare: ");
    vfprintf(stderr,fmt,va);	// varianta de fprintf care primeste o lista de argumente variabile
    va_end(va);         		// dupa folosirea argumentelor variabile, trebuie apelat va_end
    fputc('\n',stderr);
    exit(EXIT_FAILURE);
    }
}

int main()
{
    int i,n,a;
    float x,y,e,min,max;

    printf("n=");scanf("%d",&n);

    if(n<=0||n>100)
        a=0;
    else a=1;

    err(a,"n invalid: %d\n",n);

    printf("x=");scanf("%g",&x);
    printf("y=");scanf("%g",&y);

    if(x>=y)
     a=0;
    else a=1;

    err(a,"x=%g nu este mai mic decat y=%g\n",x,y);

    max=x;
    min=y;
    for(i=0;i<n;i++){
        printf("e=");scanf("%g",&e);
        if(e<x||e>y)
            a=0;
            else a=1;

        err(a,"element invalid: %g\n",e);
        if(e<min)min=e;
        if(e>max)max=e;
        }
    printf("min: %g, max: %g\n",min,max);
    return 0;
}


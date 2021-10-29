#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

/*Aplicația 8.6:
Să se scrie o funcție char *concat(int n,...)
 care primește un număr de șiruri de caractere
  și apoi șirurile propriu-zise. Funcția va concatena
   într-un nou șir, alocat dinamic, conținuturile tuturor
    șirurilor date, cu câte un spațiu între ele și va returna acest șir.

Exemplu: concat(3,”Ion”,”si”,”Ana”)		=> “Ion si Ana”

*/
char *concat(int n,...)
{
    va_list va;
    va_start(va,n);
    int k=0,i;
    char *a,*aux;
    a=(char*)malloc(k*sizeof(char));
    if(a==NULL)
    {
        printf("eroare de alocare");
        exit(EXIT_FAILURE);
    }
    strcpy(a,"");
    for(i=0;i<n;i++)
    {
        aux=va_arg(va,char*);
        a=(char*)realloc(a,(strlen(a)+strlen(aux)+1)*sizeof(char));

        if(a==NULL)
            {
            printf("eroare de alocare");
            exit(EXIT_FAILURE);
            }

        strcat(a,aux);
        strcat(a," ");
    }

    va_end(va);
    return a;

}


int main()
{
    char *a;
    a=concat(4,"Ion","si","Mara","MERG");

    printf("%s ",a);
    free(a);
    return 0;
}











































//Exemplul 3: Să se scrie o funcție maxN care primește
//ca prim parametru un număr n de elemente, iar apoi n elemente
//de tip real, care vor fi date sub forma unei liste variabile de
 //argumente. Funcția va returna maximul tuturor argumentelor:
/*
double maxN(int n,...)
{
    va_list va;                     		// lista de argumente variabile
    va_start(va,n);             		// initializare cu ultimul argument fix
    double max=va_arg(va,double);	// preia prima valoare din va, ca fiind de tip double
    while(--n){
        double e=va_arg(va,double);	// returneaza pe rand fiecare valoare ramasa in va ca fiind de tip double
        if(max<e)max=e;
        }
    va_end(va);
    return max;
}

int main()
{
    printf("%g\n",maxN(3,8,0,5));		// eroare la executie: 8, 0 si 5 sunt considerate ca fiind de tip int, deci maxN nu le va procesa corect
    printf("%g\n",maxN(3,(double)8,0.0,(float)5));	// apel corect => 8
    return 0;
}

*/
































//Exemplul 1
/*void err(const char *fmt,...)
{
    va_list va;     		// pointer la lista de argumente variabile (varargs)
    va_start(va,fmt);   		// va trebuie initializat cu ultimul argument fix al functiei
    fprintf(stderr,"eroare: ");
    vfprintf(stderr,fmt,va);	// varianta de fprintf care primeste o lista de argumente variabile
    va_end(va);         		// dupa folosirea argumentelor variabile, trebuie apelat va_end
    fputc('\n',stderr);
    exit(EXIT_FAILURE);
}

int main()
{
    int i,n;
    float x,y,e,min,max;

    printf("n=");scanf("%d",&n);
    if(n<=0||n>100)err("n invalid: %d\n",n);
    printf("x=");scanf("%g",&x);
    printf("y=");scanf("%g",&y);
    if(x>=y)err("x=%g nu este mai mic decat y=%g\n",x,y);
    max=x;
    min=y;
    for(i=0;i<n;i++){
        printf("e=");scanf("%g",&e);
        if(e<x||e>y)err("element invalid: %g\n",e);
        if(e<min)min=e;
        if(e>max)max=e;
        }
    printf("min: %g, max: %g\n",min,max);
    return 0;
}
*/


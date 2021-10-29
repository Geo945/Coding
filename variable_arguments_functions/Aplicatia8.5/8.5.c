#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
/*

Aplicația 8.5:
Să se implementeze o funcție input(const char *fmt,...).
 În șirul fmt pot fi caractere obișnuite (orice în afară de %)
  și placeholdere (% urmat de o literă). Pentru fiecare placeholder posibil
   ( %d - int, %f -float, %c - char ), în lista de argumente variabile se va
    afla adresa unei variabile de tipul corespunzător. Funcția afișează pe ecran
     caracterele obișnuite și citește de la tastatură pentru placeholdere.

Exemplu: input(”n=%dch=%c”,&n,&ch);	// citește o valoare de tip int în n și de tip char în ch


*/
void input(const char *fmt,...)
{
    va_list va;
    va_start(va,fmt);
    int *addrint,i;
    float *addrfloat;
    char *addrstr;
    for(i=0;i<strlen(fmt)-1;i++)
    {
        if(fmt[i]=='%' && fmt[i+1]=='d')
        {
            addrint=va_arg(va,int*);
            printf("Introduceti intregul: ");
            scanf("%d",addrint);
        }
        if(fmt[i]=='%' && fmt[i+1]=='f')
        {
            addrfloat=va_arg(va,float*);
            printf("Introduceti float-ul: ");
            scanf("%g",addrfloat);

        }
        if(fmt[i]=='%' && fmt[i+1]=='c')
        {
            addrstr=va_arg(va,char*);
            printf("Introduceti caracterul: ");
            scanf("%s",addrstr);

        }


    }
    va_end(va);


}

int main()
{
    int n;
    float m;
    char a[20];
    input("n=%d, m=%f,a=%c",&n,&m,a);
    printf("n=%d,m=%g,a=%s\n",n,m,a);
    return 0;
}

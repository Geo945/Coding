#include <stdio.h>
#include <stdlib.h>
/*

Aplicația 6.2:
Să se scrie un macro care să genereze
 o funcție de sortare pentru un tip de date dat.
  Funcția va primi ca argumente un
  vector de elemente și dimensiunea
  sa și va sorta vectorul în ordine crescătoare.

Exemplu: FN_SORTARE(unsigned)-> va genera o funcție de sortare pentru valori de tip unsigned

*/


#define fn_sortare(tip) \
void sortare_##tip(tip v[100],int n) \
{ int i,aux,ok=0; \
while(ok==0) \
{ \
ok=1; \
for(i=0;i<n-1;i++) \
    if(v[i]>v[i+1]) \
{ \
aux=v[i]; \
v[i]=v[i+1]; \
v[i+1]=aux; \
ok=0; \
} \
} }


fn_sortare(int);

fn_sortare(double);

int main()
{
    int v[]={7,0,1,-3,4,5},i;
    sortare_int(v,6);
    for(i=0;i<6;i++)
        printf("%d ",v[i]);
    return 0;
}

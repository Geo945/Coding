#include <stdio.h>
#include <stdlib.h>
/*

Aplicația 6.6:
Să se scrie un macro care primește
 ca argumente două tipuri, tip_dst și tip_src.

  Macroul va genera o funcție care
  primește ca argument un vector cu
  elemente de tipul tip_src și numărul
   de elemente din vector.
    Funcția va aloca dinamic un nou
     vector cu elemente de tipul tip_dst
     și va depune în el toate elementele din
     vectorul inițial, convertite la tip_dst. Funcția va returna vectorul alocat.
Exemplu: V_CONV(int,float)               -> va genera funcția ”int *v_conv_int_float(float *v,int n)”

*/

#define MERE(DST,SRC)\
void functie_##SRC(SRC *v,int *n)\
{\
int i;DST *v1;\
v1=(DST*)malloc(*n*sizeof(DST));\
for(i=0;i<*n;i++)\
    v1[i]=(DST)*(v+i);\
printf("Noul vector este: ");for(i=0;i<*n;i++){printf("%"#DST,v1[i]);printf("\n");}}


int main()
{
    int v[]={1,23,421,413,34},n=5;
    MERE(float,int);
    functie_int(&v,&n);
    return 0;

}

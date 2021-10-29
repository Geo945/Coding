#include <stdio.h>
#include <stdlib.h>
/*

Aplicația 3.4: Se introduce un număr întreg n<10 și apoi n numere de tip float.
 Să se folosească funcția qsort pentru a sorta aceste numere în mod crescător.

  Se va introduce apoi un număr x de tip float. Folosind funcția bsearch,
   să se determine dacă x există în vectorul sortat. Se pot consulta paginile de manual pentru funcțiile qsort și bsearch

*/
int cmp(const float *p1,const float *p2)
{
    if(*p1>*p2)
        return 1;

    if(*p1<*p2)
        return -1;

    if(*p1==*p2)
        return 0;
}
int cmp1(const void * a, const void * b)
{
   return ( *(float*)a - *(float*)b );
}

int main()
{
    int n,i;
    float a[20];

    printf("Introduceti numarul n: ");
    scanf("%d",&n);

    printf("Introduceti vectorul: \n");
    for(i=0;i<n;i++)
    {
        printf("a[%d]: ",i);
        scanf("%f",&a[i]);
    }

    qsort(a,n,sizeof(float),cmp);

    printf("Vectorul sortat este: ");
    for(i=0;i<n;i++)
    {
        printf("%f ",a[i]);
    }

    float x,*nr;
    printf("\nIntroduceti numarul x: ");
    scanf("%f",&x);

    nr=(float*) bsearch(&x,a,n,sizeof(float),cmp1);

    if(nr!=NULL)
        printf("\nExista numarul %f in vectorul a.",x);
    else printf("\nNu exista numarul %f in vectorul a.",x);


    return 0;
}

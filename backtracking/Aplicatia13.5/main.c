#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
/*

Aplicația 13.5:
Se cere 0<n<=100 și apoi n valori pozitive întregi, reprezentând laturile unor pătrate.
 În final se cere 0<p<=100, valoare întreagă, reprezentând latura unui pătrat.
 Se cere să se determine dacă există un aranjament al celor n pătrate
  în interiorul pătratului de latură p, astfel încât toate pătratele
  să fie conținute în acesta și să nu existe suprapuneri între pătrate.

*/
void swap(int *x,int *y)
{
    int aux;
    aux=*x;
    *x=*y;
    *y=aux;
}

void bAcKtRaCkInG(int *a,int n,int p)
{

}

int main()
{
    int n,p,i;
    printf("Introduceti numarul n: ");
    scanf("%d",&n);
    assert(n>0);
    assert(n<=100);
    int a[n];
    printf("Introduceti vectorul: ");
    for(i=0;i<n;i++)
    {
        printf("a[%d]: ",i);
        scanf("%d",&a[i]);
    }

    printf("Introduceti numarul p: ");
    scanf("%d",&p);
    assert(p>0);
    assert(p<=100);


    return 0;
}

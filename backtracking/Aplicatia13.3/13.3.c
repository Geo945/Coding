#include <stdio.h>
#include <stdlib.h>
/*

Aplicația 13.3:
Se cere un 0<n<=100 și apoi n valori reale,
 fiecare reprezentând volumul unui obiect.
  În final se cere v, volumul unei cutii.
  Se cere să se umple cutia cu unele dintre
  obiecte date, astfel încât volumul ei să
  fie utilizat în mod optim

*/
void swap(float *x,float *y)
{
    float aux;
    aux=*x;
    *x=*y;
    *y=aux;
}

float max=0;
void cauta(float volum,int n,float *v,int l)
{
    float suma=0;
    int i,j;

    if(l==n)
    {
        return;
    }
    else
    {
        for(i=l;i<n;i++)
        {
            swap( (v+l), (v+i) );
            for(j=0;j<n;j++)
                {
                if( suma+*(v+j)<=volum )
                    suma=suma + *(v+j);
                }
            if(suma>max)
                max=suma;
            cauta(volum,n,v,l+1);
            swap( (v+l), (v+i) );

        }
    }


}

int main()
{
    int n,i;
    printf("Introduceti n: ");
    scanf("%d",&n);
    float v[n],volum;

    for(i=0;i<n;i++)
    {
        printf("\nIntroduceti volumul obiectului: ");
        scanf("%f",&v[i]);
    }

    printf("Introduceti volumul cutiei:");scanf("%f",&volum);

    cauta(volum,n,v,0);
    printf("Volumul maxim ocupat este: %g",max);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
/*
Aplicația 4.1: Se citesc de la tastatură maxim 100 numere reale, până la întâlnirea numărului 0.
 Să se sorteze aceste numere și să se scrie într-un fișier, toate numerele fiind pe o singură linie, separate prin | (bară verticală)
*/
int main()
{
    FILE *f;

    if( (f=fopen("1.txt","w"))==NULL )
    {
        printf("Nu s-a putut deschide fisierul");
        exit(EXIT_FAILURE);
    }

    int a[20],i=0,n,ok=0,aux;

    printf("Introduceti elementele intregi: ");
    do
    {
     printf("a[%d]: ",i);
     scanf("%d",&a[i]);
     i++;
    }while(a[i-1]!=0);

    i--;
    n=i;

    while(ok==0)
    {
        ok=1;
        for(i=0;i<n-1;i++)
        {
            if(a[i]>a[i+1])
            {
                aux=a[i];
                a[i]=a[i+1];
                a[i+1]=aux;
                ok=0;
            }
        }
    }

    fprintf(f,"Elementele vectorului sunt: ");
    for(i=0;i<n;i++)
    {
        fprintf(f,"%d ",a[i]);
        if(i!=n-1)
        {
            fprintf(f,"|");
        }
    }

    fclose(f);


    return 0;
}

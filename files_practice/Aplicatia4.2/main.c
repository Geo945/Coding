#include <stdio.h>
#include <stdlib.h>
/*
Aplicația 4.2:
Se citesc m și n de la tastatură,
 iar apoi o matrice a[m][n].
  Matricea va fi alocată dinamic.
   Să scrie într-un fișier atât matricea
   originală cât și transpusa ei,
   separate  printr-o linie goală.
*/

int main()
{
    FILE *f;

    if( (f=fopen("1.txt","w"))==NULL )
    {
        printf("Eroare deschidere fisier");
        exit(EXIT_FAILURE);
    }

    int m,n,**a,i,j,b[100][100];
    printf("Introduceti numarul de linii: ");scanf("%d",&n);
    printf("Introduceti numarul de coloane: ");scanf("%d",&m);

    a=(int**)malloc(n*sizeof(int*));
    if(a==NULL)
    {
        printf("Eroare de alocare");
        exit(EXIT_FAILURE);
    }
    for(i=0;i<n;i++)
    {
        a[i]=(int*)malloc(m*sizeof(int));
        if(a[i]==NULL)
        {
            printf("Eroare de alocare");
            exit(EXIT_FAILURE);
        }
    }
    printf("Introduceti matricea: \n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            printf("a[%d][%d]: ",i,j);
            scanf("%d",&a[i][j]);
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            fprintf(f,"%d ",a[i][j]);
        }
        fprintf(f,"\n");
    }
    fprintf(f,"\n");

    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
           b[i][j]=a[j][i];
           fprintf(f,"%d ",b[i][j]);
        }
        fprintf(f,"\n");
    }


    for(i=0;i<n;i++)
        free(a[i]);

    free(a);
    fclose(f);
    return 0;
}








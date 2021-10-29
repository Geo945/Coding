#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/*

Aplicația 12.3:
Definim reducerea unei matrici cu elemente întregi ca
 fiind valoarea calculată astfel: dacă matricea nu are niciun element,
  reducerea este 0. Dacă matricea are un element, reducerea este valoarea
   acelui element.


   Pentru orice alte cazuri, matricea se subîmparte în 4
    matrici prin tăierea ei în cruce, prin mijlocul matricii.
    Reducerea va fi maximul reducerilor celor două matrici superioare,
     minus minimul reducerilor celor două matrici inferioare.
     Să se calculeze reducerea unei matrici de dimensiuni m,n citită de la tastatură

    1 2 3
    4 5 6
    7 8 9



    9 8 7
    6 5 4
    3 2 1
*/

int det(int a[5][5],int n)
{

    int i,j,k,d=0,l=0 ;
    if(n==2)
        {

            d=a[0][0]*a[1][1]-a[0][1]*a[1][0];
            return d;
        }
    else
        for (k=0;k<n;k++)
        {
            int b[n-1][n-1];
            for (i=1;i<n;i++)
            {
                for(j=0 && j!=k ; j<n; j++)
                {
                    b[i][j]=a[i][j];
                }
            }
            l = a[0][j]*pow(-1,j)*det(b,n-1)+l;
        }
    return 1;

}

int main()
{
    int a[20][20],i,j,n,m,m1[5][5],m2[5][5],m3[5][5],m4[5][5],red1,k,k1;
    int red2,red3,red4,max,min,n1;

    printf("Introduceti numarul n: ");
    scanf("%d",&n);
    printf("Introduceti numarul m: ");
    scanf("%d",&m);

    if(n==0 && m==0)
        {printf("Reducerea matricii este 0");return 0;}

    printf("Introduceti matricea:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            printf("a[%d][%d]: ",i,j);
            scanf("%d",&a[i][j]);
        }
    }
    if(n==1 && m==1)
        {printf("Reducere matricii este: %d",a[0][0]);return 0;}

    if(n==2 && m==2)
    {
    if(a[0][0]>a[0][1])
        max=a[0][0];
    else max=a[0][1];

    if(a[1][0]<a[1][1])
        min=a[1][0];
    else min=a[1][1];
    printf("\nReducere matricei este: %d ",max-min);
    return 0;
    }

    if(n%2==1 && m%2==1)
    {
        for(i=0;i<=n/2;i++)
        {
            for(j=0;j<=m/2;j++)
            {
                m1[i][j]=a[i][j];
            }
        }

         for(i=0;i<=n/2;i++)
        {
            k=0;
            for(j=m/2;j<m;j++)
            {
                m2[i][k]=a[i][j];
                k++;
            }
        }
        k=0;
         for(i=n/2;i<=n/2+1;i++)
        {

            for(j=0;j<=m/2;j++)
            {
                m3[k][j]=a[i][j];
            }
            k++;
        }

        k=0;
         for(i=n/2;i<n;i++)
        {
            k1=0;
            for(j=m/2;j<m;j++)
            {
                m4[k][k1]=a[i][j];
                k1++;
            }
            k++;
        }
    }
    else
    {

          for(i=0;i<n/2;i++)
        {
            for(j=0;j<m/2;j++)
            {
                m1[i][j]=a[i][j];
            }
        }

         for(i=0;i<n/2;i++)
        {
            k=0;
            for(j=m/2;j<m;j++)
            {
                m2[i][k]=a[i][j];
                k++;
            }
        }
        k=0;
         for(i=n/2;i<n/2+1;i++)
        {
            for(j=0;j<m/2;j++)
            {
                m3[k][j]=a[i][j];
            }
            k++;
        }
         k=0;
         for(i=n/2;i<n;i++)
        {
            k1=0;
            for(j=m/2;j<m;j++)
            {
                m4[k][k1]=a[i][j];
                k1++;
            }
             k++;
        }

    }

    if(n%2==1 && m%2==1)
    {
            printf("\nAfisare m1:\n");
             for(i=0;i<n/2+1;i++)
                {
                    for(j=0;j<n/2+1;j++)
                    printf("%d ",m1[i][j]);
                    printf("\n");
                }
            printf("\nAfisare m2:\n");
             for(i=0;i<n/2+1;i++)
                {
                    for(j=0;j<n/2+1;j++)
                    printf("%d ",m2[i][j]);
                    printf("\n");

                }
            printf("\nAfisare m3:\n");
             for(i=0;i<n/2+1;i++)
                {
                    for(j=0;j<n/2+1;j++)
                    printf("%d ",m3[i][j]);
                    printf("\n");
                }
            printf("\nAfisare m4:\n");
              for(i=0;i<n/2+1;i++)
                {
                    for(j=0;j<n/2+1;j++)
                    printf("%d ",m4[i][j]);
                    printf("\n");
                }
    }
    else
    {

        printf("\nAfisare m1:\n");
             for(i=0;i<n/2;i++)
                {
                    for(j=0;j<n/2;j++)
                    printf("%d ",m1[i][j]);
                    printf("\n");
                }
            printf("\nAfisare m2:\n");
             for(i=0;i<n/2;i++)
                {
                    for(j=0;j<n/2;j++)
                    printf("%d ",m2[i][j]);
                    printf("\n");

                }
            printf("\nAfisare m3:\n");
             for(i=0;i<n/2;i++)
                {
                    for(j=0;j<n/2;j++)
                    printf("%d ",m3[i][j]);
                    printf("\n");
                }
            printf("\nAfisare m4:\n");
              for(i=0;i<n/2;i++)
                {
                    for(j=0;j<n/2;j++)
                    printf("%d ",m4[i][j]);
                    printf("\n");
                }


    }

    if(n%2==1)
    n1=n/2+1;
    else n1=n/2;


    red1=det(m1,n1);
    red2=det(m2,n1);
    red3=det(m3,n1);
    red4=det(m4,n1);
    printf("%d %d %d %d",red1,red2,red3,red4);

    if(red1>red2)
        max=red1;
    else max=red2;

    if(red3<red4)
        min=red3;
    else min=red4;


    printf("\nReducere matricei este: %d ",max-min);


    return 0;
}

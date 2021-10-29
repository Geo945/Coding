#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

/*Aplicația 8.7:Să se scrie o funcție int comune(int nVec,...)
 care primește un număr de vectori cu valori de tip int și
 vectorii propriu-ziși. Fiecare vector se dă prin 2 argumente:
      un pointer la elementele sale și dimensiunea. Funcția va
      returna numărul de elemente comune care se regăsesc în toți vectorii.

Exemplu: comune(3,v1,2,v2,3,v3,3)		=> returnează 2 pentru v1={5,8}, v2={8,3,5}, v3={5,0,8}
*/
int comune(int nVec,...)
{
    va_list va;
    va_start(va,nVec);
    int i,a[100][100],b[100],k=0,j,l=0,ok=0;

    for(i=0;i<nVec;i++)
    {
        k=0;
        int *v=va_arg(va,int*);
        b[i]=va_arg(va,int);
        for(j=0;j<b[i];j++)
            {a[l][k]=*(v+j);
            k++;
            }
        l++;

    }
     for(i=0;i<nVec;i++)
     {for(j=0;j<b[i];j++)

        printf("%d ",a[i][j]);
        printf("\n");
     }
    printf("\n");

    printf("Vectorul b este: ");
    for(i=0;i<nVec;i++)
    printf("%d ",b[i]);

    for(j=0;j<b[0];j++)
    {

        for(i=1;i<nVec;i++)
            {
                for(l=0;l<b[i];l++)
                    {
            if(a[0][j]==a[i][l])
            {
            break;
            }


                }
            if(l==b[i])
                break;
            else if(i==nVec-1)
            ok++;

            }

    }


    va_end(va);
    return ok;

}

int main()
{
    int v1[]={5,8},v2[]={8,3,5},v3[]={5,0,8},a[100],v4[]={5,0,3};
    printf("\n%d\n",comune(4,v1,2,v2,3,v3,3,v4,3));

    return 0;
}


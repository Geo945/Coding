#include <stdio.h>
#include <stdlib.h>
/*

Aplicația 3.3: Să se implementeze o funcție care primește ca parametri un vector de întregi,
 numărul elementelor din vector transmis prin adresă și un predicat care testează dacă un întreg îndeplinește o anumită condiție.

  Funcția va sterge din vector toate elementele care nu îndeplinesc condiția dată și va actualiza numărul elementelor cu numărul de elemente rămas în vector.
   Să se testeze funcția cu un predicat care testează dacă un număr este negativ și să se afișeze vectorul rezultat.

*/
int cond(int a)
{
    if(a<0)
        return 1;
    else return 0;

}


void mere(int a[20],int *n,int(*cond)(int))
{
    int i,j;
    for(i=0;i<*n;i++)
    {
        if(!cond(a[i]))
        {
            for(j=i;j<*n-1;j++)
                a[j]=a[j+1];
            i--;
            *n=*n-1;
        }

    }

}


int main()
{
    int n,a[20],i;
    printf("Introduceti numarul de elemente: ");
    scanf("%d",&n);

    printf("Introduceti vectorul: \n");
    for(i=0;i<n;i++)
    {
        printf("a[%d]: ",i);
        scanf("%d",&a[i]);
    }

    mere(a,&n,cond);

    printf("Noul vector este: ");
    for(i=0;i<n;i++)
        printf("%d ",a[i]);



    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*

Aplicația 13.4:
De-a lungul unei șosele trebuie amplasate una lângă alta următoarele entități: case, blocuri, grădini, ateliere.
 O entitate se poate învecina doar cu una de același tip (ex: casă cu casă) sau conform următoarelor reguli
  (orice relație o implică și pe cea inversă):

   un bloc poate avea ca vecini case; o casă sau un atelier poate avea
   ca vecini grădini. Se cer de la tastatură numerele c,b,g,a care reprezintă respectiv numărul de case, blocuri,
    grădini și ateliere. Să se determine toate variantele în care acestea pot fi aranjate

*/

void interschimbare(char *sir1,char *sir2)
{
    char aux;
    aux=*sir1;
    *sir1=*sir2;
    *sir2=aux;
}

void aranjare(int l,int n,char *v)
{
    int i,j,k=1;
    if(l==n)
        {
           // for(j=0;j<n;j++)
            //{
               // if( (*(v+j)=='b' && *(v+j+1)=='g') || ( *(v+j)=='b' && *(v+j-1)=='g') ||
                 //  ( *(v+j)=='a' && *(v+j+1)=='b' ) || ( *(v+j)=='a' && *(v+j+1)=='c' ) ||
                  // ( *(v+j)=='c' && *(v+j-1)=='b' ) || ( *(v+j)=='c' && *(v+j-1)=='a' )
                   //  )
               //     k=0;
           // }

            if(k==1)
                printf("Combinata este: %s\n",v);
        }
    else
        {
            for(i=l;i<n;i++)
            {
                interschimbare( (v+l) , (v+i) );
                aranjare(l+1,n,v);
                interschimbare( (v+l) , (v+i) );
            }
        }
}



int main()
{
    int c,b,g,a,l;
    l=0;
    printf("Introduceti numarul de case: ");
    scanf("%d",&c);

    printf("Introduceti numarul de blocuri: ");
    scanf("%d",&b);

    printf("Introduceti numarul de gradini: ");
    scanf("%d",&g);

    printf("Introduceti numarul de ateliere: ");
    scanf("%d",&a);

    int n=c+b+g+a,i;
    char v[n];

    for(i=0;i<c;i++)
        v[i]='c';
    for(i;i<c+b;i++)
        v[i]='b';
    for(i;i<c+b+g;i++)
        v[i]='g';
    for(i;i<c+b+g+a;i++)
        v[i]='a';

    v[c+b+g+a]='\0';

    aranjare(l,n,v);


    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/*

Aplicația 12.1:
Se cere un n<100, iar apoi coordonatele reale (x,y) a n puncte din plan.
 Fiecare punct reprezintă poziția unde va trebui dată o gaură într-o placă.

  Bormașina se află inițial la locația (0,0). Să se afișeze ordinea de dat găuri,
   astfel încât întotdeauna bormașina să fie mutată la punctul cel mai apropiat de ea.
*/


typedef struct
{
float x;
float y;
}punct;

void afisare(punct puncte[100],int *n)
{
  float minx=0,miny=0,dist,comp;
  int i,j,k,m;
  char aux[30],aux1[30];
    printf("(0,0)\n");
    m=*n;
  for(i=0;i<*n;i++)
  {

      dist=sqrt( (puncte[0].x-minx)*(puncte[0].x-minx) + (puncte[0].y-miny)*(puncte[0].y-miny) );
      for(j=1;j<m;j++)
      {
          if( sqrt( (puncte[j].x-minx)*(puncte[j].x-minx) + (puncte[j].y-miny)*(puncte[j].y-miny) )<dist )
          {
              dist=sqrt( (puncte[j].x-minx)*(puncte[j].x-minx) + (puncte[j].y-miny)*(puncte[j].y-miny) );

          }
      }

      for(j=0;j<m;j++)
      {
        comp=sqrt( (puncte[j].x-minx)*(puncte[j].x-minx) + (puncte[j].y-miny)*(puncte[j].y-miny) );
        if(comp==dist)
                {
                        printf("(%g,%g)\n",puncte[j].x,puncte[j].y);
                      minx=puncte[j].x;
                      miny=puncte[j].y;

                        for(k=j;k<m-1;k++)
                            {
                              puncte[k].x=puncte[k+1].x;
                              puncte[k].y=puncte[k+1].y;
                            }
                        m--;
                      break;
                }
      }

  }


}
// printf("\n\n%g  %g  %g  %g \n\n",dist,puncte[j].x,puncte[j].y,sqrt ((puncte[j].x-minx)*(puncte[j].x-minx) + (puncte[j].y-miny)*(puncte[j].y-miny) ));
int main()
{
    punct puncte[100];
    int n,i;
    printf("Introduceti numarul de puncte: ");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        printf("\nIntroduceti punctul:\n");
        printf("Coordonata x:");scanf("%g",&puncte[i].x);
        printf("Coordonata y:");scanf("%g",&puncte[i].y);
    }

    afisare(puncte,&n);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*

Aplicația 4.5: Să se contorizeze de câte ori apare într-un fișier fiecare cuvânt și să se afișeze.
 Nu se va face distincție între literele mari și mici.

*/
int main()
{
    FILE *f;
    char *p,sep[]=" ",linie[1000],*p1,a[100][100],aux[1000];
    if( (f=fopen("5.txt","r"))==NULL )
    {
        printf("Eroare");
        exit(EXIT_FAILURE);
    }
    int i=0,k,j,l=0,m;

    while( fgets(linie,1000,f)!=NULL )
    {

        p=strtok(linie,sep);
        while(p!=0)
        {
            strcpy(a[i],p);
            i++;
            p=strtok(NULL,sep);
        }

    }
    for(j=0;j<i;j++)
    {
        l=0;
        for(k=0;k<i;k++)
            if(strcmp(a[k],a[j])==0)
                l++;

       printf("Cuvantul %s apare de %d ori\n",a[j],l);

       strcpy(aux,a[j]);
       for(k=0;k<i;k++)
            if(strcmp(a[k],aux)==0)
                {for(m=k;m<i;m++)
                    strcpy(a[m],a[m+1]);
                 i--;
                }

        j--;
    }

    fclose(f);
    return 0;
}

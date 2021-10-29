#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*

Aplicația 12.4:
La un campionat iau parte n jucători,
fiecare definit prin nume (max 15 caractere) și valoare (int).
Jucătorii sunt distribuiți în m grupe, n divizibil cu m.
Distribuția jucătorilor în grupe se face după valoarea lor,

astfel încât cei mai valoroși m jucători să fie fiecare în
altă grupă, apoi următorii m cei mai valoroși rămași să fie
și ei în grupe diferite și tot așa, până când toți jucătorii
sunt distribuiți. Să se afișeze împărțirea jucătorilor pe grupe,
pentru valori citite dintr-un fișier.

*/

typedef struct
{
    char nume[15];
    int valoare;
}jucator;

typedef struct
{
    char nume1[1000];
    int valoare1;

}grupa;

int main()
{
    FILE *f;
    if( (f=fopen("1.txt","r"))==0 )
    {
        printf("Fisierul nu s-a putut deschide");
        exit(EXIT_FAILURE);
    }
    char linie[100],aux[100];
    int i,j,n,m,k=0,l;
    printf("Introduceti numarul de jucatori:");
    scanf("%d",&n);
    printf("Introduceti nr de grupe: ");
    scanf("%d",&m);
    jucator a[n];
    while(fgets(linie,100,f)!=NULL)
    {
        for(i=0;i<strlen(linie);i++)
        {
            if(linie[i]==',')
            {
                    for(j=0;j<i;j++)
                    {
                        aux[j]=linie[j];
                        strcpy(a[k].nume,aux);
                    }
                    a[k].nume[i]='\0';
                    strcpy(aux,linie+i+1);
                    a[k].valoare=atoi(aux);
                    k++;
                    break;
            }
        }

    }


    grupa b[m];
    int max,gr=0,p;
    for(i=0;i<m;i++)
    {
        strcpy(b[i].nume1,"");
    }
    for(i=0;i<k;i++)
    {
        max=0;
        for(j=0;j<k;j++)
        {
            if(a[j].valoare>max)
                {max=a[j].valoare;
                strcpy(aux,a[j].nume);
                }
        }

        for(j=0;j<k;j++)
        {
            if(max==a[j].valoare)
            {

                for(l=j;l<k-1;l++)
                {
                    strcpy(a[l].nume,a[l+1].nume);
                    a[l].valoare=a[l+1].valoare;
                }
                k--;
                i--;
                break;
            }
        }

        strcpy(b[gr].nume1+strlen(b[gr].nume1),aux);
        strcat(b[gr].nume1," ");
        gr++;
        if(gr==m)
            gr=0;


    }

    printf("\n\nGrupele formate sunt:\n");
    for(i=0;i<m;i++)
    {
        printf("%s ",b[i].nume1);
        printf("\n");
    }

    fclose(f);

    return 0;
}

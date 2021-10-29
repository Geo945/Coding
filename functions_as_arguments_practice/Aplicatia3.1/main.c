#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
/*

Aplicația 3.1: Se cere un număr n și apoi un vector de n rezultate ale studenților la un examen.
 Fiecare rezultat este definit prin (nume,nota).
  Se cere să se sorteze folosind qsort vectorul în ordinea notelor,
  notele cele mai mari fiind primele. Dacă două note sunt identice, rezultatele respective se vor sorta în ordinea alfabetică a numelor.

*/

typedef struct
{
    char nume[20];
    int nota;
}rez;

int cmp(const void *p1,const void *p2)
{
    const rez *r1=(const rez*)p1;
    const rez *r2=(const rez*)p2;

    if(r1->nota>r2->nota)
        return -1;

    if(r1->nota<r2->nota)
        return 1;

    if(strcmp(r1->nume,r2->nume)==0)
        return 0;

    if(strcmp(r1->nume,r2->nume)>0)
        return 1;

    if(strcmp(r1->nume,r2->nume)<0)
        return -1;

}

int main()
{
    int n,i;
    rez a[20];
    printf("Introduceti numarul de studenti: ");
    scanf("%d",&n);


    for(i=0;i<n;i++)
    {
        printf("Introduceti numele studentului: ");
        scanf("%s",a[i].nume);
        printf("Introduceti nota elevului: ");
        scanf("%d",&a[i].nota);
    }

    qsort(a,n,sizeof(rez),cmp);

    printf("Strucutra sortata este:\n");
    for(i=0;i<n;i++)
    {
        printf("\n#%d:\n",i);
        printf("-Nume: %s\n-Nota: %d",a[i].nume,a[i].nota);
    }



    return 0;
}

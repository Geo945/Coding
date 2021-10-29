#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*

Aplicația 3.8: Folosind funcții polimorfice,
 să se implementeze o colecție eterogenă de produse
 . Vor fi 2 tipuri de produse: calculatoare,
  definite prin {nume CPU, capacitate memorie în GB}
  și monitoare, definite prin {diagonală în inch,
   rezoluție orizontală, rezoluție verticală}.
    Singura funcție polimorfică va fi afisare,
     care afișează tipul și toate proprietățile
      unui produs pe o linie. De exemplu,
       dacă avem un calculator și un monitor,
        afișarea va fi de forma:
calculator: cpu:Ryzen, memorie:8GB
monitor: diagonala:24, rezolutie:1920x1080


*/

typedef enum{Calculator,Monitor}TP;
typedef struct
{
    TP f;

    union
    {
        int memorie;
        char numeCPU[20];

    }PC;

    union
    {
        char rezolutie[20];
       int diagonala;


    }MO;


}mere;

void afisare(mere *f1)
{

    switch(f1->f)
    {

    case Calculator:
        {

            printf("Calculator: cpu: %s, memorie: %dGB\n",f1->PC.numeCPU,f1->PC.memorie);

            break;
        }
    case Monitor:
        {

            printf("Monitor: diagonala: %d, rezolutie: %s\n",f1->MO.diagonala,f1->MO.rezolutie);
            break;
        }

    }
}

int main()
{
    int n,i;
    printf("Introduceti numarul de produse: ");
    scanf("%d",&n);
    mere a[20];
    for(i=0;i<n;i++)
    {
        printf("Introduceti tipul produsului(0-Calculator,1-Monitor):");
        scanf("%d",&a[i].f);

        switch(a[i].f)
            {
                case Calculator:
                    {
                        printf("Introduceti numele cpu: ");
                        scanf("%s",a[i].PC.numeCPU);
                        printf("Introduceti capacitatea de memorie: ");
                        scanf("%d",&a[i].PC.memorie);
                        break;
                    }
                case Monitor:
                    {
                        printf("Introduceti lungimea diagonalei(in inch): ");
                        scanf("%d",&a[i].MO.diagonala);
                        printf("Introduceti rezolutia: ");
                        scanf("%s",a[i].MO.rezolutie);
                        break;
                    }

            }
    }
    for(i=0;i<n;i++)
        afisare(&a[i]);



    return 0;
}

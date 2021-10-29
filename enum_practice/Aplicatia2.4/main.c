#include <stdio.h>
#include <stdlib.h>
/*
Aplicația 2.4: Folosind câmpuri pe biți, definiţi o structură pentru memorarea următoarelor informaţii despre animale:

numărul de picioare: număr întreg, minim 0 (ex. şarpe), maxim 1000 (ex. miriapod)
greutatea în kg: număr real
periculos pentru om: da/nu
abrevierea ştiinţifică a speciei: şir de maxim 8 caractere
vârsta maximă în ani: număr întreg, minim 0, maxim 2000

Unde este posibil, codificaţi informaţiile prin numere întregi de dimensiune cât mai mică, spre exemplu “da”=1, “nu”=0.

Definiţi structura în aşa fel încât să ocupe spaţiul minim de memorie posibil.

 Afişaţi spaţiul de memorie ocupat, folosind operatorul sizeof.
Folosind structura definită, citiţi de la tastatură informaţii despre un animal, iar pe urmă afişaţi-le pe ecran

*/
typedef struct
{
    int a:10;
    int varsta:11;
    float greutate;
    int periculos;
    char abrev[8];

}mere;

int main()
{
    printf("Spatiul de memorie ocupat este: %d\n",sizeof(mere));

    mere v[10];
    int aux,i,n;
    float aux1;

    printf("Introduceti numarul de animale: ");
    scanf("%d",&n);

    for(i=0;i<n;i++)
        {

            printf("Introduceti numarul de picioare a animalului(0-1000): ");
            scanf("%d",&aux);
            v[i].a=aux;

            printf("Introduceti varsta maxima in ani: ");
            scanf("%d",&aux);
            v[i].varsta=aux;

            printf("Introduceti greutatea(in kg): ");
            scanf("%f",&aux1);
            v[i].greutate=aux1;

            printf("Introduceti daca este sau nu periculos(1-da,0-nu): ");
            scanf("%d",&aux);
            v[i].periculos=aux;

            printf("Introduceti abrevierea stiintifica a speciei: ");
            scanf("%s",v[i].abrev);
        }

    printf("Structura citita este: \n");
    for(i=0;i<n;i++)
    {
        printf("#%d: ",i);
        printf("-Nr. de picioare: %d\n-Varsta: %d\n-Greutatea: %f\n-Abrevierea speciei: %s\n",v[i].a,v[i].varsta,v[i].greutate,v[i].abrev);
        if(v[i].periculos==1)
            printf("-Periculos: da\n");
        else printf("Periculos: nu\n");

        printf("\n");
    }

    return 0;
}

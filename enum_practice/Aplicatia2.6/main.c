#include <stdio.h>
#include <stdlib.h>

/*Aplicația 2.6: Să se codifice următoarele informații despre un medicament,
astfel încât ele să ocupe în total un singur octet. Să se scrie un program care
 să citească datele unui medicament și ulterior să le afișeze.

gradul de periculozitate: scăzută, medie, mare
dacă se eliberează doar pe bază de rețetă: da, nu
vârsta minimă de administrare: 1...18 ani inclusiv
*/
typedef enum{Scazuta,media,mare}grad;
typedef enum{da,nu}baza;
typedef struct
{
    int grad:2;
    int baza:1;
    int varsta:5;

}medicament;

int main()
{
    medicament a[20];
    int i,n,aux;
    printf("Introduceti numarul de mediamente: ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Introduceti gradul de pericol(0-scazut,1-mediu,2-mare): ");
        scanf("%d",&aux);
        a[i].grad=aux;
        printf("Introduceti daca baza este periculoasa(0-da,1-nu): ");
        scanf("%d",&aux);
        a[i].baza=aux;
        printf("Introduceti varsta minim de administrare(0-18): ");
        scanf("%d",&aux);
        a[i].varsta=aux;
    }

    printf("Strucutra citita este: \n");
    for(i=0;i<n;i++)
    {
        printf("#%d \n",i);
        if(a[i].grad==0)
            printf("Grad pericol: scazut\n");
        else if (a[i].grad==1)
            printf("Grad pericol: mediu\n");
        else printf("Grad pericol: mare\n");

        if(a[i].baza==0)
            printf("Baza periculoasa: da\n");
        else printf("Baza periculoasa: nu\n");
        printf("Varsta: %d\n",a[i].varsta);
    }



    return 0;
}

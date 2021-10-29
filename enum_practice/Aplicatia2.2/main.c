#include <stdio.h>
#include <stdlib.h>
/*
Aplicația 2.2: Folosind struct și union, definiți o structură de date care să poată memora următoarele informații despre viețuitoare:
tipul (poate fi: mamifer, insectă, pește, pasăre)
durata medie de viață în ani
dacă e mamifer: perioada de gestație, numărul mediu de pui pe care îi naște
dacă e insectă: numărul de picioare, dacă poate să zboare sau nu, dacă este periculoasă sau nu pentru om
dacă e pește:  tipul de apă: sărată/dulce, adâncimea maximă la care se poate întâlni, viteza maximă de înot
dacă e pasăre: anvergura aripilor, altitudinea maximă de zbor, viteza maximă de zbor
Definiți structura în așa fel încât memoria consumată să fie minimă. Citiți și afișați informațiile despre o viețuitoare

*/

typedef enum{Mamifer,Insecta,Peste,Pasare}tip;

typedef struct
{
    tip a;
    int dmv;

    union
    {
      int PerioadaGestatie;
      int NrMediuPui;
    }mamifer;

    union
    {
      int NrPicioare;
      char zbor[2];
      char pericol[2];
    }insecta;

    union
    {
      char tipApa[6];
      float adancime;
      float viteza;
    }peste;

    union
    {
     int LungimeAripi;
     float altitudine;
     float vitezaMax;
    }pasare;


}mere;
void citire(mere *v)
{
    printf("Introduceti tipul vietuitoare(0-mamifer,1-insecta,2-peste,3-pasare: ");
    scanf("%d",&v->a);
    printf("Introduceti durata medie de viata: ");
    scanf("%d",&v->dmv);

    switch (v->a)
    {
    case 0 :
        {
            printf("Introduceti perioada de gestatie: ");
            scanf("%d",&v->mamifer.PerioadaGestatie);

            printf("Introduceti numărul mediu de pui pe care îi naște: ");
            scanf("%d",&v->mamifer.NrMediuPui);
            break;
        }
    case 1 :
        {
            printf("Introduceti numarul de picioare: ");
            scanf("%d",&v->insecta.NrPicioare);

            printf("Introduceti dacă poate să zboare sau nu(da/nu): ");
            scanf("%s",v->insecta.zbor);

            printf("Introduceti dacă este periculoasă sau nu pentru om(da/nu): ");
            scanf("%s",v->insecta.pericol);
            break;
        }
    case 2 :
        {
            printf("Introduceti tipul de apa(sarat/dulce): ");
            scanf("%s",v->peste.tipApa);

            printf("Introduceti adâncimea maximă la care se poate întâlni: ");
            scanf("%f",&v->peste.adancime);

            printf("Introduceti viteza maximă de înot(in km): ");
            scanf("%f",&v->peste.viteza);
            break;
        }
    case 3 :
        {
            printf("Introduceti anvergura aripilor: ");
            scanf("%d",&v->pasare.LungimeAripi);

            printf("Introduceti altitudinea maxima de zbor: ");
            scanf("%f",&v->pasare.altitudine);

            printf("Introduceti viteza maxima de zbor: ");
            scanf("%f",&v->pasare.vitezaMax);
            break;
        }
    default :
        {
            break;
        }

    }
}
void afisare(mere *v)
{
    switch (v->a)
    {
        case 0 :
            {
                    printf("\nStructura citita este:\n-Tip Vietuitoare: mamifer\n-Durata de viata: %d\n-Perioada de gestatie: %d\n-Numar mediu de pui: %d\n",v->dmv,v->mamifer.PerioadaGestatie,v->mamifer.NrMediuPui);
                    break;
            }
        case 1 :
            {
                printf("\nStructura citita este:\n-Tip Vietuitoare: insecta\n-Durata de viata: %d\n-Nr. Picioare: %d\n-Poate sa zboare: %s\n-Periculoasa: %s\n",v->dmv,v->insecta.NrPicioare,v->insecta.zbor,v->insecta.pericol);
                break;
            }
        case 2 :
            {
                printf("\nStructura citita este:\n-Tip Vietuitoare: peste\n-Durata de viata: %d\n-Tip apa: %s\n-Adancime: %f\n-Viteza maxima: %f\n",v->dmv,v->peste.tipApa,v->peste.adancime,v->peste.viteza);
                break;
            }
        case 3 :
            {
                printf("\nStructura citita este:\n-Tip Vietuitoare: pasare\n-Durata de viata: %d\n-Anvergura aripilor: %d\n-Altitudine maxima de zbor: %f\n-Viteza maxima: %f\n",v->dmv,v->pasare.LungimeAripi,v->pasare.altitudine,v->pasare.vitezaMax);
                break;
            }
        default :
            {
                break;
            }

    }
}

int main()
{
    mere v;
    citire(&v);
    afisare(&v);


    return 0;
}

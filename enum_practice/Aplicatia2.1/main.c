#include <stdio.h>
#include <stdlib.h>
/*
Aplicația 2.1: Pentru structura Vehicul de mai sus, să se implementeze funcțiile de introducere de la tastatură și de afișare.
*/
typedef enum{TMBenzina, TMMotorina, TMElectric}TipMotor;
typedef enum{TVPersoane, TVMarfa, TVSpecial}TipVehicul;

typedef struct{
    TipMotor tm;
    char marca[20];
    TipVehicul tv;

    union
    {

        struct{
            int nrLocuri;
            int nrAirbaguri;
            }p;

        struct{
            double capacitate;
            char frigorific[2];
            }m;

        char special[20];

    }specific;

    }Vehicul;
void introducere(Vehicul *v)
{
    printf("Introduceti tipul vehiculului(0-de persoane, 1-de marfa, 2-special :");
    scanf("%d",&v->tv);

    switch (v->tv)
    {
        case TVPersoane :
            {
                printf("Introduceti numarul de locuri: ");
                scanf("%d",&v->specific.p.nrLocuri);

                printf("Introduceti numarul de airbaguri: ");
                scanf("%d",&v->specific.p.nrAirbaguri);

                printf("Introduceti tipul motorului(0-benzina, 1-motorina, 2-electric:");
                scanf("%d",&v->tm);
                break;
            }
        case TVMarfa :
            {
              printf("introduceti capacitatea: ");
              scanf("%lf",&v->specific.m.capacitate);

              printf("Introduceti daca are sau nu frigorific(da/nu): ");
              scanf("%s",v->specific.m.frigorific);

              printf("Introduceti tipul motorului(0-benzina, 1-motorina, 2-electric:");
                scanf("%d",&v->tm);

              break;
            }
        case TVSpecial :
            {
                printf("Introduceti tipul vehiculului special(tractor etc): ");
                scanf("%s",v->specific.special);

                printf("Introduceti tipul motorului(0-benzina, 1-motorina, 2-electric:");
                scanf("%d",&v->tm);

                break;
            }

    }


}
void afisare(Vehicul *v)
{


    switch (v->tv)
    {
        case TVPersoane :
            {
                printf("Strctura citita este:\n-Motor: %d\n-Numarul de airbaguri: %d\n",v->specific.p.nrLocuri,v->specific.p.nrAirbaguri);
                if(v->tm==0)
                    printf("-TipMotor: benzina");
                if(v->tm==1)
                    printf("-TipMotor: motorina");
                if(v->tm==2)
                    printf("-TipMotor: electric");
                break;
            }
        case TVMarfa:
            {
                printf("Structura citita este:\n-Capacitate: %lf\n-frigorific: %s\n",v->specific.m.capacitate,v->specific.m.frigorific);
                if(v->tm==0)
                    printf("-TipMotor: benzina");
                if(v->tm==1)
                    printf("-TipMotor: motorina");
                if(v->tm==2)
                    printf("-TipMotor: electric");
                break;
            }
        case TVSpecial:
            {
                printf("Structura citita este:\n-Tip vehicul special: %s\n",v->specific.special);
               if(v->tm==0)
                    printf("-TipMotor: benzina");
                if(v->tm==1)
                    printf("-TipMotor: motorina");
                if(v->tm==2)
                    printf("-TipMotor: electric");
                break;
            }
    }


}
int main()
{
    Vehicul v;
    introducere(&v);
    afisare(&v);
    return 0;
}

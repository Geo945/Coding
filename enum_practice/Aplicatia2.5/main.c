#include <stdio.h>
#include <stdlib.h>
/*
Aplicația 2.5:
Se consideră că o măsurătoare are asociată unitatea de măsură (gram, metru, litru) și multiplicatorul acesteia (pico, nano, mili, centi, deci, deca, hecto, kilo, mega, giga).
Să se codifice o măsurătoare astfel încât să conțină o valoare întreagă pozitivă care să acopere un interval cât mai mare de valori, unitatea de măsură și multiplicatorul acesteia.
 O măsurătoare va ocupa exact 2 octeți.
Să se citească o valoare unsigned și o unitate de măsură. La citire nu există multiplicator. Să se determine multiplicatorul astfel încât valoarea stocată să fie cât mai mică,
 fără a se pierde precizie, iar apoi să se stocheze într-o măsurătoare. Dacă valoarea nu încape, se va afișa o eroare. Să se afișeze toate câmpurile măsurătorii.
Exemplu: valoare=147000, unitate:gram     =>     147 kilogram

*/
typedef enum{gram,metru,litru}UM;
typedef enum{pico,nano,mili,centi,deci,deca,hecto,kilo,mega,giga}UM1;
int main()
{
    UM a;
    UM1 c;
    unsigned b;
    char d[20];
    printf("Introduceti valoarea: ");
    scanf("%uf",&b);
    printf("Introduceti unitatea de masura(0-gram,1-metru,1-litru):");
    scanf("%d",&a);

    int k=0;
    switch (a)
    {
    case gram:
        {

            if(b>0)
            {
                while(b%10==0)
                {k++;
                b=b/10;
                }

                if(k==1)
                printf("%d decagram",b);
                if(k==2)
                printf("%d hectogram",b);
                if(k==3)
                printf("%d kilogram",b);
                if(k==4)
                printf("%d megagram",b);
                if(k==5)
                printf("%d gigagram",b);
                 if(k>5) {printf("Eroare");
                exit(EXIT_FAILURE);};
            }


        }
    case metru:
        {
             if(b>0)
            {
                while(b%10==0)
                {k++;
                b=b/10;
                }
                if(k==1)
                printf("%d decametru",b);
                if(k==2)
                printf("%d hectometru",b);
                if(k==3)
                printf("%d kilometru",b);
                if(k==4)
                printf("%d megametru",b);
                if(k==5)
                printf("%d gigametru",b);
                if(k>5) {printf("Eroare");
                exit(EXIT_FAILURE);};
                break;
            }

        }
            case litru:
        {
             if(b>0)
            {
                while(b%10==0)
                {k++;
                b=b/10;
                }
                if(k==1)
                printf("%d decalitru",b);
                if(k==2)
                printf("%d hectolitru",b);
                if(k==3)
                printf("%d kilolitru",b);
                if(k==4)
                printf("%d megalitru",b);
                if(k==5)
                printf("%d gigalitru",b);
                if(k>5) {printf("Eroare");
                exit(EXIT_FAILURE);};
                break;
            }

        }
    }





    return 0;
}

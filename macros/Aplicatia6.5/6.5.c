#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/*

Aplicația 6.5:
 Să se scrie un macro care
  generează o structură Punct
   cu componentele {x,y} de un
    tip specificat în macro și
    totodată o funcție care
    primește ca parametru o
    variabilă de tipul Punct și
    returnează distanța de la
    punct la origine.

Exemplu: PUNCT(float)                       -> va genera structura Punct_float și funcția ”float len_float(Punct_float pt)”

*/



#define macro(tip)\
typedef struct{\
tip x;\
tip y;\
}PUNCT;\
int f(PUNCT a)\
{\
printf("Introduceti x:");scanf("%"#tip,&a.x);\
printf("Introduceti y:");scanf("%"#tip,&a.y);\
tip b=sqrt(a.x*a.x+a.y*a.y) ;return b;\
}



int main()
{
    macro(float);
    PUNCT a;
    float b;
    b=f(a);
    printf("%g",b);


    return 0;
}


/*
#define MERE(TIP) \
typedef struct \
{ \
TIP x;\
TIP y; \
}Punct_##TIP; \
void functie_##TIP(Punct_##TIP a)\
{printf("Introduceti numarul x:");\
scanf("%"#TIP,&a.x);\
printf("Introduceti numarul y:");\
scanf("%"#TIP,&a.y);\
printf("Distanta:%g",sqrt(a.x*a.x+a.y*a.y));}


int main()
{
    MERE(float);
    Punct_float a;
    functie_float(a);
    return 0;
}*/






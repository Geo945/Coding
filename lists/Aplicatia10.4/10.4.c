#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct natural{

    int v;
    struct natural *pred;
    struct natural *urm;

}natural;

natural *natural_nou(const int v)
{
    natural *e=(natural*)malloc(sizeof(natural));
    if(!e)
    {
        printf("memorie insuficienta");
        exit(EXIT_FAILURE);
    }

    e->v=v;

    return e;
}

#define LISTAD_NUME         ListaN
#define LISTAD_ELEMENT      natural
#include "listad.h"

typedef struct real{

    double v;
    struct real *pred;
    struct real *urm;

}real;

real *real_nou(const double v)
{
    real *e=(real*)malloc(sizeof(real));
    if(!e)
    {
        printf("memorie insuficienta");
        exit(EXIT_FAILURE);
    }

    e->v=v;

    return e;
}

#define LISTAD_NUME         ListaR
#define LISTAD_ELEMENT      real
#include "listad.h"

int main()
{
    ListaN ln;
    natural *en;
    ListaR lr;
    real *er;
    double n;

    ListaN_init(&ln);
    ListaR_init(&lr);

    printf("Citeste numere pana la introducerea lui 0 :\n");
    do{

        printf("n=");
        scanf("%lf", &n);

        if(floorf(n) == n)
        {
            natural *e = natural_nou(n);
            ListaN_adauga(&ln, e);
        }
        else
        {
            real *e = real_nou(n);
            ListaR_adauga(&lr, e);
        }

    }while(n!=0);

    printf("\nLista numerelor naturale : ");

    for(en=ln.prim; en; en=en->urm)
        printf("%d ", en->v);

    printf("\nLista numerelor reale : ");

    for(er=lr.prim; er; er=er->urm)
        printf("%lg ", er->v);

    ListaN_elibereaza(&ln);
    ListaR_elibereaza(&lr);

    return 0;
}

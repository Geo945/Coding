#include <stdio.h>
#include <stdlib.h>
/*

Aplicația 3.2: Să se citească fiecare dintre următoarele declarații:
                int *(*a[10])(double);      double *b(int(*)(float),char)

*/
int main()
{
    int *(*a[10])(double);

    a vector de 10 elemente fiecare element avand tipul pointer la o functie ce are un paramatru double si returneaza un pointer la int.

    double *b(int(*)(float),char)

    b este o functie care are ca si parametri o functie ce are ca paramtru un numar real si returneaza un intreg si un sir de carctere care returneaza un pointer la double.


    return 0;
}

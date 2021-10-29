#include <stdio.h>
#include <stdlib.h>
//Aplicația 6.1: Să se scrie un macro care returnează maximul a 3 argumente.

#define max(a,b,c)  (a)>(b)&&(a)>(c)?(a):(b)>(a)&&(b)>(c)?(b):c


int main()
{
    printf("Numarul maxim este: %d",max(38,88,4));
    return 0;
}

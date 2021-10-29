#include <stdio.h>
#include <stdlib.h>
/*

Aplicația 6.4:
 Să se scrie un macro care primește ca
  argumente un text, un placeholder pentru
   print/scanf, un nume de variabilă și 2
   valori, min și max. Macroul va trebui să
    ceară de la tastatură o valoare în mod
    repetat, până când ea se încadrează în intervalul închis dat.

Exemplu: CITIRE(”x=”,g,x,0,100)         -> citește variabila x până când valoarea citită se încadrează în [0,100]

*/

#define macro(TEXT,P,NUME,MIN,MAX) do{printf(TEXT);scanf("%"#P,&NUME);}while( NUME>=MIN && NUME<=MAX)


int main()
{
    int x;
    macro("x=",g,x,0,100);
    return 0;
}

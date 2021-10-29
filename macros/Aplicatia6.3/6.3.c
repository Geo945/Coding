#include <stdio.h>
#include <stdlib.h>
/*

Aplicația 6.3: Să se modifice exemplul 6 astfel încât
 fiecare valoare din tabelă să aibă următoarea semnificație:
  bitul 0==1 => literă mică, bitul 1==1 => literă mare, bitul 2==1 => cifră.
   Să se scrie 3 macrouri, ISLOWER, ISUPPER și ISDIGIT care, folosind tabela,
    să testeze încadrarea argumentului lor în aceste clase de caractere

*/
#define VAL(v)     ((v)>='a'&&(v)<='z'?1:((v)>='A'&&(v)<='Z')?2:((v)>='0'&&(v)<='9'?4:0 ) )

#define LINIE(baza)	VAL(16*baza+0),VAL(16*baza+1),VAL(16*baza+2),VAL(16*baza+3),	\
                                  	VAL(16*baza+4),VAL(16*baza+5),VAL(16*baza+6),VAL(16*baza+7),	\
                                  	VAL(16*baza+8),VAL(16*baza+9),VAL(16*baza+10),VAL(16*baza+11),	\
                                  	VAL(16*baza+12),VAL(16*baza+13),VAL(16*baza+14),VAL(16*baza+15)
const char tabela[]={
    LINIE(0),LINIE(1),LINIE(2),LINIE(3),
    LINIE(4),LINIE(5),LINIE(6),LINIE(7),
    LINIE(8),LINIE(9),LINIE(10),LINIE(11),
    LINIE(12),LINIE(13),LINIE(14),LINIE(15)
    };
#define ISLOWER(c)  ((tabela[(unsigned char)(c)])>>0==1?1:0)
#define ISUPPER(c)  ((tabela[(unsigned char)(c)])>>1==1?1:0)
#define ISDIGIT(c)  ((tabela[(unsigned char)(c)])>>2==1?1:0)


int main()
{


    printf("%d\n",ISLOWER('A'));
    printf("%d\n",ISUPPER('A'));
    printf("%d\n",ISDIGIT('F'));
    return 0;
}


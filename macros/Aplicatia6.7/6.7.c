
#include<stdio.h>
#include<stdlib.h>


#define NBITI4(u) (tabela[((u)>>0)&0xff]+tabela[((u)>>8)&0xff]+tabela[((u)>>16)&0xff]+tabela[((u)>>24)&0xff])

#define VAL(NR) ( ((NR>>0)&1)+((NR>>1)&1)+((NR>>2)&1)+((NR>>3)&1)+((NR>>4)&1)+((NR>>5)&1)+((NR>>6)&1)+((NR>>7)&1) )

#define LINIE(baza)	VAL(16*baza+0),VAL(16*baza+1),VAL(16*baza+2),VAL(16*baza+3),   \
                    VAL(16*baza+4),VAL(16*baza+5),VAL(16*baza+6),VAL(16*baza+7),    \
                    VAL(16*baza+8),VAL(16*baza+9),VAL(16*baza+10),VAL(16*baza+11),	 \
                    VAL(16*baza+12),VAL(16*baza+13),VAL(16*baza+14),VAL(16*baza+15)



int tabela[]={
    LINIE(0),LINIE(1),LINIE(2),LINIE(3),
    LINIE(4),LINIE(5),LINIE(6),LINIE(7),
    LINIE(8),LINIE(9),LINIE(10),LINIE(11),
    LINIE(12),LINIE(13),LINIE(14),LINIE(15)
};


int main()
{
    int i;
    printf("\n%d\n",NBITI4(0x01FF0325) );


    return 0;
}

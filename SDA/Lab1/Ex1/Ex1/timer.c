/* fisierul timer.c */
#include <time.h>
#include "timer.h"
clock_t aux; 
void starton(void)
{ aux=clock(); 
} 
double startoff(void)
{ return(clock()-(double)aux)/CLK_TCK;
}

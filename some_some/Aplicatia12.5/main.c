#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*

Aplicația 12.5:
Să se scrie o funcție care primește un număr întreg 0<=n<1000 și îl afișează  în formă literară.
 Să se apeleze funcția pentru numere introduse de la tastatură, pană la apariția valorii 1000.
Exemple: 108 → o suta opt;           520 → cinci sute douazeci;        16 → saisprezece

*/

void functie(int n)
{

    char a[12][6];
    strcpy(a[0],"zero");
    strcpy(a[1],"unu");
    strcpy(a[2],"doi");
    strcpy(a[3],"trei");
    strcpy(a[4],"patru");
    strcpy(a[5],"cinci");
    strcpy(a[6],"sase");
    strcpy(a[7],"sapte");
    strcpy(a[8],"opt");
    strcpy(a[9],"noua");
    strcpy(a[10],"zece");
    strcpy(a[11],"zeci");

    if(n==1000)
    {printf("o mie\n");return;}

    if( (n/100)!=0 )
    {
        if( (n/100)==1 )
            printf("o suta\n");
        else if( (n/100)==2 )
            printf("doua sute ");
        else {
            printf("%s sute ",a[n/100]);
        }

    }

    if(n%100<=10 && n%10!=0 )
    {
        if(n==10)
            printf("Zece\n");
        else
        printf("%s \n",a[n%10]);
    }

    if(n%100>10 && n%100<=20)
    {
        if(n%100==20)
        printf("douazeci\n");
        else if(n%100==11)
        printf("unsprezece\n");
        else if(n%100==16)
            printf("saisprezece\n");
        else printf("%ssprezece\n",a[n%10]);
    }

    if(n>100)
    n=n%100;
    if( (n%100)>20 && (n%100)<30 )
    {
        printf("douazeci si %s\n",a[n%10]);
    }
    if( (n%100)>=30 && (n%100)<=99 )
    {

        if(n/10==6)
        {
            printf("saizeci ");
            return;
        }

        printf("%szeci ",a[n/10]);
        if(n%10!=0)
            printf("si %s\n",a[n%10]);

    }

    printf("\n");
}

int main()
{
    int n;
    printf("Introduceti numarul n: ");
    scanf("%d",&n);

    do
    {
        functie(n);
        printf("Introduceti numarul n: ");
        scanf("%d",&n);
    }while(n<1000 && n>=0);


    return 0;
}

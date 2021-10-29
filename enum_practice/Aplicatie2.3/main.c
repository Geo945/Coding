#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
Aplicația 2.3: Se citește de la tastatură o linie de text care conține o atribuire a unei variabile cu o valoare.
 Linia are forma ”nume_variabila=valoare”. Numele variabilei poate conține doar litere sau cifre, cu restricția ca primul caracter să fie literă.
  Valoarea poate fi număr (începe cu o cifră și poate avea zecimale), caracter (începe cu apostrof) sau șir de caractere (începe cu ghilimele).
  Câteva exemple de astfel de atribuiri:
raza=10.12
B22 = 'c'
adresa="Bd. Vasile Parvan nr. 2"
Folosind struct și union definiți o structură de date pentru a păstra în mod eficient informația din linia citită de la tastatură.
 Transferați informația din linia citită într-o variabilă de tipul structurii de date definite. Afișați informația păstrată în variabilă,
 folosind formatul original (nume_variabila=valoare). Tratați posibile erori ce pot să apară în linia citită (nume incorect de variabilă,
lipsește semnul egal, valoarea atribuită este invalidă)
*/

typedef struct
{
    char a[50];

    union
    {
        float numar;
        char caracter;
        char sir[50];

    }mere1;


}mere;



int main()
{
    char text[30];
    int i,k=0,j,ok=0,p=1,tip,l=0;
    mere v;
    printf("Introduceti textul(nume_variabila=valoare): ");
    fgets(text,30,stdin);
    text[strlen(text)-1]=text[strlen(text)];





    for(i=0;i<strlen(text);i++)
        {

         if( text[i]=='=')
            {
                k=i;
                v.a[i]=='\0';
                break;
            }

            v.a[i]=text[i];

        }

    for(i=0;i<k;i++)
        if(isspace(text[i]))
            l=1;
    if(l==1)
    {
        printf("nume incorect de variabila");
        return 1;
    }
    if(k==0)
    {printf("Lipseste semnul =");
    return 1;
    }




    for(i=0;i<strlen(text);i++)
    {

    }


        i=k+1;

        if(text[i]=='\'')
                {
                v.mere1.caracter=text[i+1];
                tip=1;
                }
        else
        if(text[i]=='"')
            {
                strcpy(v.mere1.sir,text+k+2);
                tip=2;
                v.mere1.sir[strlen(v.mere1.sir)-1]='\0';
            }

        else
        {
            v.mere1.numar=0;
            for(j=i;j<strlen(text);j++)
            {
                if( isdigit(text[j]) )
                {

                    if(ok==0)
                    v.mere1.numar=v.mere1.numar*10+ text[j]-'0';
                    else
                    {v.mere1.numar=v.mere1.numar+(float)(text[j]-'0')/(p*10) ;
                    p=p*10;
                    }
                }
                if(text[j+1]=='.')
                {
                    ok=1;
                }
            }
            tip=3;

        }


    if(tip==1)
        printf("Nume Variabila: %s\nValoare:%c",v.a,v.mere1.caracter);
    if(tip==2)
        printf("Nume Variabila: %s\nValoare:%s",v.a,v.mere1.sir);
     if(tip==3)
        printf("Nume Variabila: %s\nValoare:%0.4f",v.a,v.mere1.numar);


    return 0;
}

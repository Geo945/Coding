#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*

Aplicația 4.6: Un fișier conține pe fiecare linie un produs dat
 prin numele său (un cuvânt) și preț (număr real), separate prin spațiu.
  Să se încarce fișierul în memorie și să se implementeze într-o buclă infinită un meniu cu următoarele opțiuni:
Caută un produs după nume și, dacă e găsit, îi afișează prețul
Afișează toate produsele
Adaugă un nou produs
Șterge un produs, după numele său
Salvează în fișierul originar baza de date din memorie
Ieșire din program


*/
int main()
{
    FILE *f;
    FILE *f1;

       if( (f1=fopen("61.txt","w"))==NULL )
    {
        printf("Eroare");
        exit(EXIT_FAILURE);
    }
    int n;
    float k;
    char aux[50],*p,sep[]=" ",linie[1000],ok;
    printf("\n1.Cautare \n2.Afisare \n3.Adaugare\n4.Stergere \n5.Salvare \n6.Iesire \n");
    printf("Introduceti optiunea: ");
    scanf("%d",&n);
    while(n!=6)
    {
        switch (n)
        {
        case 1 :
            {
                if( (f=fopen("6.txt","r"))==NULL )
                {
                    printf("Eroare");
                    exit(EXIT_FAILURE);
                }
                printf("Introduceti cuvantul de cautat: ");
                scanf("%s",aux);
                ok=1;
                while( fgets(linie,1000,f)!=NULL )
                {
                    p=strtok(linie,sep);
                    if(strcmp(p,aux)==0)
                    {
                        p=strtok(NULL,sep);
                        printf("Pretul este: %f",atof(p));
                        ok=0;
                        break;
                    }

                }
                if(ok==1)
                    printf("Nu am gasit cuvantul");
                fclose(f);
                break;
            }
        case 2 :
            {
                if( (f=fopen("6.txt","r"))==NULL )
                {
                    printf("Eroare");
                    exit(EXIT_FAILURE);
                }
                printf("Linile fisierului sunt: \n");
                while( fgets(linie,1000,f)!=NULL )
                    printf("%s \n",linie);
                    fclose(f);
                break;
            }
        case 3 :
            {
                if( (f=fopen("6.txt","a+"))==NULL )
                {
                    printf("Eroare");
                    exit(EXIT_FAILURE);
                }
                printf("Introduceti numele produsului de adaugat: ");
                scanf("%s",aux);
                printf("Introduceti pretul produslui: ");
                scanf("%f",&k);
                printf("\n");
                fprintf(f,"%s ",aux);
                fprintf(f,"%0.2f",k);
                fclose(f);
                break;
            }
        case 4 :
            {
                printf("Introduceti numele produsului de sters: ");
                scanf("%s",aux);


                while( fgets(linie,1000,f)!=NULL )
                {
                    p=strtok(linie,sep);
                    if(strcmp(aux,p)!=0)
                    {
                        fprintf(f1,"%s ",linie);

                    }

                }

                break;
            }

        }

        printf("\n1.Cautare \n2.Afisare \n3.Adaugare\n4.Stergere \n5.Salvare \n6.Iesire \n");
        printf("Introduceti optiunea: ");
        scanf("%d",&n);
    }

    fclose(f);
    fclose(f1);

    return 0;
}

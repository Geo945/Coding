#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 //Aplicația 4.7: Să se modifice exemplul de sortare al liniilor din fișier, astfel încât o linie să poată avea orice lungime.
char **linii; 	// vector de linii: char *linii[]
int nLinii;
FILE *fin;      	// fisierul de intrare
FILE *fout;    	// fisierul de iesire

void eliberare()
{
    int i;
    for(i=0;i<nLinii;i++)free(linii[i]);
    free(linii);
    fclose(fin);
    fclose(fout);
}

void adauga(const char *linie)    // adauga o linie in linii
{
    // duplica linia
    char *linieNoua=(char*)malloc((strlen(linie)+1)*sizeof(char));
    if(!linieNoua){
        printf("memorie insuficienta");
        eliberare();
        exit(EXIT_FAILURE);
        }
    strcpy(linieNoua,linie);
    // face loc in linii pentru linia noua
    char **p=(char**)realloc(linii,(nLinii+1)*sizeof(char*));
    if(!p){
        printf("memorie insuficienta");
        free(linieNoua);
        eliberare();
        exit(EXIT_FAILURE);
        }
    linii=p;
    linii[nLinii]=linieNoua;
    nLinii++;
}

// functia de comparare pentru qsort
// deoarece qsort transmite elementele vectorului prin adresele lor
// si fiecare element din linii este un sir de caractere (char*)
// inseamna ca de fapt se va transmite char** (adresa unui sir de caractere)
int cmp(const void *p1,const void *p2)
{
    // se transmit lui strcmp valorile pointate de sirurile de caractere transmise prin adresa
    // strcmp are aceeasi conventie pentru valorile returnate ca si qsort
    // deci valoarea returnata de strcmp se poate returna direct lui qsort
    return strcmp(*(char **)p1,*(char**)p2);
}

int main(void)
{
    char linie[1000];
    int i;

    if((fin=fopen("linii.txt","rt"))==NULL){
        printf("eroare deschidere fisier de intrare\n");
        exit(EXIT_FAILURE);
        }

    while(fgets(linie,1000,fin)!=NULL){


        if(strlen(linie)<=1)continue;
        adauga(linie);
        }
    // nu mai este nevoie de fisierul de intrare, deci se putea inchide aici. va fi inchis la sfarsit, de eliberare()

    qsort(linii,nLinii,sizeof(char*),cmp);

    // scrie liniile sortate in fisierul de iesire
    if((fout=fopen("sortate.txt","wt"))==NULL){
        printf("eroare deschidere fisier de iesire\n");
        exit(EXIT_FAILURE);
        }
    for(i=0;i<nLinii;i++)fputs(linii[i],fout);
    fclose(fout);
    eliberare();
    return 0;
}

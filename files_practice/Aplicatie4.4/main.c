#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*

Aplicația 4.4: Citind caracter cu caracter dintr-un fișier, să se contorizeze de câte ori
 apare fiecare literă din alfabet și să se afișeze. Nu se va face distincție între literele
  mari și mici.

*/
int main()
{
    FILE *f;
    if( (f=fopen("4.txt","r"))==NULL )
    {
        printf("Eroare");
        exit(EXIT_FAILURE);
    }
    int a[26],i;
    for(i=0;i<26;i++)
        a[i]=0;

    char c=fgetc(f);
    while(c!=EOF)
    {
        tolower(c);
        a[c-'a']++;
        c=fgetc(f);

    }
    printf("Literele sunt: \n");
    for(i=0;i<26;i++)
    {
        if(a[i]!=0)
        printf("%c: %d\n",'a'+i,a[i]);
    }

    fclose(f);
    return 0;
}

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>


#define LMAX        100


char lab[LMAX][LMAX];
int nLab;
int startI,startJ;

void citire(const char *numeFisier)
{
    FILE *fis=fopen(numeFisier,"rt");
    if(!fis){
        printf("fisierul %s nu poate fi deschis\n",numeFisier);
        exit(EXIT_FAILURE);
        }
    fscanf(fis,"%d",&nLab);
    fscanf(fis,"%d %d",&startI,&startJ);
    int i,j;
    char linie[LMAX+1];
    fgets(linie,LMAX,fis);
    for(i=0;i<nLab;i++){
        fgets(linie,LMAX,fis);
        for(j=0;j<nLab;j++)lab[i][j]=linie[j];
        }
    fclose(fis);
}


void afisare()
{
    int i,j;
    for(i=0;i<nLab;i++){
        for(j=0;j<nLab;j++){
            putchar(lab[i][j]);
            }
        putchar('\n');
        }
}

#define TMAX   1000

int traseuI[TMAX],traseuJ[TMAX];
int nTraseu;
int nSolutii;

int di[4]={1,-1,0,0};
int dj[4]={0,0,1,-1};
int traseuIMin[TMAX],traseuJMin[TMAX];
int nTraseuMin=INT_MAX;

void solutie()
{
    int k;
    for(k=0;k<nTraseu;k++){
        traseuIMin[k]=traseuI[k];
        traseuJMin[k]=traseuJ[k];
        }
    nTraseuMin=nTraseu;
}


void cauta(int i,int j)
{
    if(nTraseu==nTraseuMin)return;
    if(i<0||i>=nLab||j<0||j>=nLab)return;
    if(lab[i][j]!='.')return;


    traseuI[nTraseu]=i;
    traseuJ[nTraseu]=j;
    lab[i][j]='0'+nTraseu%10;
    nTraseu++;

    if(i==0||i==nLab-1||j==0||j==nLab-1){
        solutie();
        }else{
        int k;
        for(k=0;k<4;k++){
            cauta(i+di[k],j+dj[k]);
            }
        }


    nTraseu--;
    lab[i][j]='.';
}

int main()
{
    citire("1.txt");
    cauta(startI,startJ);
    if(nTraseuMin==INT_MAX){
        printf("nu exista solutie");
        }else{
        int k;
        printf("Solutia minima are lungimea %d si este compusa din:",nTraseuMin);
        for(k=0;k<nTraseuMin;k++){
            printf(" (%d,%d)",traseuIMin[k],traseuJMin[k]);
            lab[traseuIMin[k]][traseuJMin[k]]='0'+k%10;
            }
        putchar('\n');
        afisare();
        putchar('\n');
        }
    return 0;
}

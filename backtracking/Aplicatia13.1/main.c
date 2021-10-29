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
int di[8]={1,-1,0,0,-1,1,-1,1};
int dj[8]={0,0,1,-1,-1,-1,1,1};

void solutie()
{
    int k;
    nSolutii++;
    printf("Solutia %d, lungime %d:",nSolutii,nTraseu);
    for(k=0;k<nTraseu;k++)printf(" (%d,%d)",traseuI[k],traseuJ[k]);
    putchar('\n');
    afisare();
    putchar('\n');
}

void cauta(int i,int j)
{

    if(i<0||i>=nLab||j<0||j>=nLab)return;
    if(lab[i][j]!='.')return;


    traseuI[nTraseu]=i;
    traseuJ[nTraseu]=j;
    lab[i][j]='a'+nTraseu%26;
    nTraseu++;

    if(i==0||i==nLab-1||j==0||j==nLab-1){
        solutie();
        }else{
        int k;
        for(k=0;k<8;k++){
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
    printf("numar solutii: %d\n",nSolutii);
    return 0;
}

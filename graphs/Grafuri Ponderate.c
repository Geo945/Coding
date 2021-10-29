/*
Sa se redacteze un program care citeste de la intrarea standard doua numere N-reprezentand numarul de noduri si M-reprezentand numarul de arce, apoi M triplete de valori (sursa destinatie pondere), fiecare pereche reprezentand un arc al unui graf neorientat si ponderat.

Programul insereaza N noduri in graf, avand cheile de la 1 la N inclusiv. Apoi insereaza cele M arce. Folosind, la alegere, algoritmul lui Prim sau Kruskal, programul va trebui sa calculeze arborele de acoperire minim si sa afiseze suma ponderilor arcelor acestuia.

Limite date de intrare:

1 <= N <= 256

0 <= M <= 256

-1024 <= pondere_arc <= 1024

Exemplu:

input = 9 11

2 6 6

9 4 9

4 8 9

3 8 6

6 5 -2

7 1 -5

1 3 10

1 4 -3

9 7 -4

1 5 -10

3 2 -5

output = -17
*/
#include <stdio.h>
#include <stdlib.h>
#define NR_MAX_NODURI 100

int set[NR_MAX_NODURI];

typedef struct{
    int cheie;
    int vizitat;
}Nod;

typedef struct{
    int idx_nod_1,idx_nod_2;
    int pondere;
}Arc;

typedef struct{
    int nr_noduri;
    Nod Noduri[NR_MAX_NODURI];
    int Arce[NR_MAX_NODURI][NR_MAX_NODURI];
}Graf;
Graf *graf;
void Initializare(Graf *g){
    g->nr_noduri=0;
}

void InsertNod(Graf *g, Nod n){
    g->nr_noduri++;
    int index_nod=g->nr_noduri;
    g->Noduri[index_nod]=n;
    int i;
    for(i=1;i<=g->nr_noduri;i++){
        g->Arce[index_nod][i]=g->Arce[i][index_nod]=0;
    }
}

void InsertArc(Graf *g, Arc a){
    g->Arce[a.idx_nod_1][a.idx_nod_2] = g->Arce[a.idx_nod_2][a.idx_nod_1] = a.pondere;
}

void afisare(Graf *g){
    int i,j;
    for(i = 1; i <= g->nr_noduri; i++)
    {
        for(j = 1; j <= g->nr_noduri; j++)
        {
            printf("%3d ", g->Arce[i][j]);
        }
        printf("\n");
    }
}

int prim(Graf *g){
    set[1]=1;
    int i,j,pas,min,mini,minj,suma=0;
    for(pas=1;pas<=g->nr_noduri-1;pas++){
        min=1025;mini=-1;minj=-1;
        for(i=1;i<=g->nr_noduri;i++){
            for(j=1;j<=g->nr_noduri;j++){
                if(g->Arce[i][j]!=0 && g->Arce[i][j]<min && set[i]==0 && set[j]==1){
                    min=g->Arce[i][j];
                    mini=i;
                    minj=j;
                }
            }
        }
        set[mini]=1;
        printf("%d ",g->Noduri[mini]);
        suma+=g->Arce[mini][minj];
    }
    return suma;
}
int sett[NR_MAX_NODURI];
int kruskal(Graf *g){
    int i,j,pas,mini,minj,min,k,suma=0;
    for(pas=1;pas<=g->nr_noduri-1;pas++){
        sett[pas]=1;
        min=1025;mini=-1;minj=-1;
        for(i=1;i<=g->nr_noduri;i++){
            for(j=1;j<=g->nr_noduri;j++){
                if(g->Arce[i][j]!=0 && g->Arce[i][j]<min && sett[i]!=sett[j]){
                    min=g->Arce[i][j];
                    mini=i;
                    minj=j;
                }
            }
        }
         suma+=g->Arce[mini][minj];
        for(k=1;k<=g->nr_noduri;k++)
        if(sett[k]==sett[minj]){
                sett[k]=sett[mini];
        }
    }
    return suma;
}

int main()
{
    int n,m,i;
    scanf("%d",&n);
    scanf("%d",&m);
    graf=(Graf*)malloc(sizeof(Graf));
    Initializare(graf);
    Nod nod;Arc a;
    for(i=1;i<=n;i++)
    {
        nod.cheie = i;
        nod.vizitat = 0;
        InsertNod(graf,nod);
    }
    for(i=1;i<=m;i++)
    {
        scanf("%d %d %d",&a.idx_nod_1,&a.idx_nod_2, &a.pondere);
        InsertArc(graf,a);
    }
    printf("Drumul de acoperire minim este: ");
    printf("\nSuma ponderilor arborelui de acoperire minima folosind prim este: %d\n",prim(graf));
    printf("\nSuma ponderilor arborelui de acoperire minima folosind kruskal este: %d\n",kruskal(graf));
    afisare(graf);
    free(graf);
    return 0;
}






















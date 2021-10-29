/*
Sa se redacteze un program care citeste de la intrarea standard doua numere N -reprezentand numarul se noduri si M reprezentand numarul de arce, apoi citeste M perechi de valori, fiecare pereche reprezentand un arc.

Programul insereaza N noduri in graf, avand cheile de la 1 la N inclusiv. Apoi insereaza cele M arce. Programul afiseaza in ordine crescatoare cheile care respecta urmatoarea regula:

pornind de la aceasta cheie, atat parcugerea in adancime cat si in cuprindere a unei componente conexe genereaza aceeasi secventa de chei
Ex:
input =

5 6

1 2

1 3

2 3

3 4

4 5

3 5

output = 1 2 3
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX_NR_NODURI 100

typedef struct{
    int cheie;
    int vizitat;
}Nod;

typedef struct{
    int idx_nod_1;
    int idx_nod_2;
}Arc;

typedef struct{
    int nr_noduri;
    Nod noduri[MAX_NR_NODURI];
    int Arce[MAX_NR_NODURI][MAX_NR_NODURI];
}Graf;
Graf *graf;
void Initializare(Graf *g){
    g->nr_noduri=0;
}

void InsertNod(Graf *g, Nod n){
    g->nr_noduri++;
    int index_nod = g->nr_noduri;
    g->noduri[index_nod]=n;
    int i;
    for(i=1;i<=g->nr_noduri;i++){
        g->Arce[i][index_nod] = g->Arce[index_nod][i] = 0;
    }
}

void InsertArc(Graf *g, Arc a){
    g->Arce[a.idx_nod_1][a.idx_nod_2] = g->Arce[a.idx_nod_2][a.idx_nod_1] = 1;
}

void afisare(Graf *g){
    int i,j;
    for(i=1;i<=g->nr_noduri;i++){
        for(j=1;j<=g->nr_noduri;j++)
            printf("%d ",g->Arce[i][j]);
        printf("\n");
    }
}
int adanc[100],cuprinde[100];
int k1,k2;
void adancime(int radacina){
    int i;
    adanc[k1++]=radacina;
   // printf("%d ",radacina);
    graf->noduri[radacina].vizitat=1;
    for(i=1;i<=graf->nr_noduri;i++){
        if(graf->Arce[radacina][i] && !graf->noduri[i].vizitat){
            adancime(i);
        }
    }
}

void cuprindere(int radacina){
    int coada[100],k=0,i,top;
    coada[k]=radacina;
    k++;
    while(k>0){
        top=coada[0];
        for(i=0;i<k-1;i++)
            coada[i]=coada[i+1];
        k--;
        cuprinde[k2++]=top;
        graf->noduri[top].vizitat=1;
        for(i=1;i<=graf->nr_noduri;i++){
            if(graf->Arce[top][i] && !graf->noduri[i].vizitat){
                coada[k++]=i;
                graf->noduri[i].vizitat=1;
            }
        }
    }
}

int main()
{
    int n,m,i,aux,ok,j;
    Nod nod;
    Arc a;
    scanf("%d %d", &n, &m);
    graf=(Graf*)malloc(sizeof(Graf));
    Initializare(graf);
    for(i=1;i<=n;i++){
        nod.cheie=i;
        nod.vizitat=0;
        InsertNod(graf,nod);
    }
    for(i=1;i<=m;i++){
        scanf("%d", &aux);
        a.idx_nod_1=aux;
        scanf("%d", &aux);
        a.idx_nod_2=aux;
        InsertArc(graf,a);
    }




    //afisare(graf);
    for(i=1;i<=n;i++){
        k1=0;k2=0;ok=1;
        for(j=1;j<=graf->nr_noduri;j++){
            graf->noduri[j].vizitat=0;
        }
        adancime(i);
        for(j=1;j<=graf->nr_noduri;j++){
            graf->noduri[j].vizitat=0;
        }
        cuprindere(i);

        for(j=0;j<k1;j++){
            if(adanc[j]!=cuprinde[j]){
                ok=0;
                break;
            }
        }
        if(ok==1)
            printf("%d ",i);
    }

    free(graf);
    return 0;
}



























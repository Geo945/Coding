/*
Sa se redacteze un program care citeste de la intrarea standard doua numere N -reprezentand numarul se noduri si M reprezentand numarul de arce, apoi citeste M perechi de valori, fiecare pereche reprezentand un arc.

Programul insereaza N noduri in graf, avand cheile de la 1 la N inclusiv. Apoi insereaza cele M arce. Programul afiseaza in ordine:

numarul de componente conexe ale grafului
1 daca draful este ciclic, si 0 daca acesta este aciclic
Ex:

input =

7 6

1 2

2 3

3 4

4 5

5 3

6 7

output =

2 1
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

void adancime(int radacina){
    int i;
    graf->noduri[radacina].vizitat=1;
    for(i=1;i<=graf->nr_noduri;i++){
        if(graf->Arce[radacina][i] && !graf->noduri[i].vizitat){
            adancime(i);
        }
    }
}

int nrComponenteConexe(){
    int count=0,i;
    for(i=1;i<=graf->nr_noduri;i++){
        if(!graf->noduri[i].vizitat){
            adancime(i);
            count++;
        }
    }
    return count;
}

int ciclic(int radacina, int previous){
    int i;
    graf->noduri[radacina].vizitat=1;
    for(i=1;i<=graf->nr_noduri;i++){
        if(graf->Arce[radacina][i]){
            if(!graf->noduri[i].vizitat){
                ciclic(i,radacina);
            }
            if(i!=previous){
                return 1;
            }
        }
    }
    return 0;
}

int main()
{
    int n,m,i,aux,ok,j,rez=0;
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
    printf("Numarul de componente conexe este: %d \n",nrComponenteConexe());

    for(i=1;i<=graf->nr_noduri;i++){
        for(j=1;j<=graf->nr_noduri;j++){
            graf->noduri[j].vizitat=0;
        }
        if(ciclic(i,i)){
            rez=1;break;
        }
    }
    printf("Este graful ciclic(1-da,0-nu): %d\n", rez);
    free(graf);
    return 0;
}

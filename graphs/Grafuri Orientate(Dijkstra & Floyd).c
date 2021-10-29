/*
Sa se redacteze un program care citeste de la intrarea standard doua numere N-reprezentand numarul de noduri si M-reprezentand numarul de arce, apoi M triplete de valori (sursa destinatie pondere), fiecare pereche reprezentand un arc al unui graf orientat si ponderat.

Programul insereaza N noduri in graf, avand cheile de la 1 la N inclusiv. Apoi insereaza cele M arce. Folosind algoritmul lui Dijkstra, programul va calcula si afisa n-1 valori separate prin spatiu, reprezentand distanta minima de la primul nod (nodul cu cheia 1) la toate celalalte noduri(2, 3, ..., n). Atentie, este posibil sa nu existe drum de la primul nod la unele noduri, caz in care se va afisa lungimea 0.

Limite date de intrare:

1 <= N <= 256

0 <= M <= 256

1 <= pondere_arc <= 1024

Exemplu:

input = 4 9

2 1 64

1 4 12

2 4 72

3 2 94

3 4 27

1 2 95

4 1 97

3 1 96

4 2 16

output = 28 0 12

Explicatie:

28 - distanta minima de la 1 la 2 (1 -> 4 -> 2)

0 - nu exista drum de la 1 la 3

12 - distanta minima de la 1 la 4 (1 -> 4)
*/
#include <stdio.h>
#include <stdlib.h>
#define MAX_NR_NODURI 100

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
    Nod noduri[MAX_NR_NODURI];
    int Arce[MAX_NR_NODURI][MAX_NR_NODURI];
}Graf;
Graf *graf;
void Initializare(Graf *g){
    g->nr_noduri=0;
}

void InsertNod(Graf *g, Nod n){
    g->nr_noduri++;
    int index_nod=g->nr_noduri;
    g->noduri[index_nod]=n;
    int i;
    for(i=1;i<=g->nr_noduri;i++){
        g->Arce[index_nod][i]=g->Arce[i][index_nod]=0;
    }
}

void afisare(Graf *g){
    int i;
    int j;
    for(i = 1; i <= g->nr_noduri; i++)
    {
        for(j = 1; j <= g->nr_noduri; j++)
        {
            printf("%3d ", g->Arce[i][j]);
        }
        printf("\n");
    }
}

void InsertArc(Graf *g, Arc a){
    g->Arce[a.idx_nod_1][a.idx_nod_2]=a.pondere;
}

void dijkstra(Graf *g,int startnode){
    int distance[MAX_NR_NODURI],cost[MAX_NR_NODURI][MAX_NR_NODURI];
    int count,mindinstance,nextnode,i,j;

    for(i=1;i<=g->nr_noduri;i++){
        for(j=1;j<=g->nr_noduri;j++){
            if(g->Arce[i][j]==0)
                cost[i][j]=1025;
            else cost[i][j]=g->Arce[i][j];
        }
    }

    for(i=1;i<=g->nr_noduri;i++){
        distance[i]=cost[startnode][i];
        g->noduri[i].vizitat=0;
    }

    distance[startnode]=1;
    g->noduri[startnode].vizitat=1;
    count=1;

    while(count<g->nr_noduri-1){
        mindinstance=1025;
        for(i=1;i<=g->nr_noduri;i++)
                if(distance[i]<mindinstance && !g->noduri[i].vizitat){
                    mindinstance=distance[i];
                    nextnode=i;
                }

            g->noduri[nextnode].vizitat=1;
            for(i=1;i<=g->nr_noduri;i++)
                if(!g->noduri[i].vizitat)
                    if(mindinstance + cost[nextnode][i] < distance[i]){
                        distance[i]=mindinstance+cost[nextnode][i];
                    }
        count++;
    }

    for(i=1;i<=g->nr_noduri;i++){
        if(i!=startnode){
            if(distance[i]==1025)
                printf("%d ",0);
            else
                printf("%d ",distance[i]);
        }
    }

}

void floydWarshall(Graf *g){
    int i,dist[MAX_NR_NODURI][MAX_NR_NODURI],j,k;
    for(i=1;i<=g->nr_noduri;i++)
        for(j=1;j<=g->nr_noduri;j++)
            dist[i][j]=g->Arce[i][j];
    for(k=1;k<=g->nr_noduri;k++){
        for(i=1;i<=g->nr_noduri;i++){
            for(j=1;j<=g->nr_noduri;j++){
                if(dist[i][j]>dist[i][k]+dist[k][j] && (dist[k][j]!=0 && dist[i][k]!=0) ){
                    dist[i][j]=dist[i][k]+dist[k][j];
                }
            }
        }
    }
    printf("\n");
    for(i=1;i<=g->nr_noduri;i++){
        for(j=1;j<=g->nr_noduri;j++){
            if(dist[i][j]==0)
                printf("%s ", "INF");
            else printf("%d ",dist[i][j]);
        }
        printf("\n");
    }
}



int main()
{
    int n,m,i;
    Nod nod;
    Arc arc;
    graf=(Graf*)malloc(sizeof(Graf));
    Initializare(graf);
    scanf("%d %d", &n, &m);
    for(i=1;i<=n;i++){
        nod.cheie=i;
        nod.vizitat=0;
        InsertNod(graf,nod);
    }

    for(i=1;i<=m;i++){
        scanf("%d %d %d", &arc.idx_nod_1, &arc.idx_nod_2, &arc.pondere);
        InsertArc(graf,arc);
    }
    printf("Drumurile minime sunt: ");
    dijkstra(graf,1);
    printf("\n");
    printf("\n");
    printf("Drumurile minime folosind floyd sunt: ");
    floydWarshall(graf);
    free(graf);
    return 0;
}











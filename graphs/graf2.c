#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_NR_NODURI 100

int latime[100],adanc[100],k1,k2;

typedef struct {
  int cheie;
  int info;
} Nod;

typedef struct {
    int idx_nod_1, idx_nod_2;
} Arc;

typedef struct Graf {
  int nr_noduri;
  Nod Noduri[MAX_NR_NODURI];
  int Arce[MAX_NR_NODURI][MAX_NR_NODURI];//matricea de adiacenta
} Graf;

Graf *g;

void Initializare(Graf *g){
  g->nr_noduri = 0;
}

void InsertNod(Graf *g, Nod n){
  //se adauga nodul n in graf(primul nod e pe pozitia 0)
  int index_nod = g->nr_noduri;
  g->Noduri[index_nod] = n; 
  g->nr_noduri++;
  //se initializeaza matricea de adiacenta pentru noul nod
  int i;
  for(i = 1; i <= g->nr_noduri; i++){
    g->Arce[index_nod][i] = g->Arce[i][index_nod] = 0;
  }  
}

void InsertArc(Graf *g, Arc a){
  g->Arce[a.idx_nod_1][a.idx_nod_2] = g->Arce[a.idx_nod_2][a.idx_nod_1] = 1;
}

void adancime(int radacina,int n)
{
    int i,j=0;
    g->Noduri[radacina].info=1;
    adanc[k1++]=radacina;
   // printf("%d",radacina);
    for(i=1;i<=n;i++)
    {
        if (g->Arce[radacina][i] && !g->Noduri[i].info)
        {
            adancime(i,n);
        }
    }
}

void cuprindere(int radacina, int n)
{
    int coada[100],k=0,i,top,j=0;
    
    coada[k]=radacina;
    k++;
    while(k>0){
        int top=coada[0];
        for(i=0;i<k-1;i++)
            coada[i]=coada[i+1];
        k--;
        //printf("%d",top);
        latime[k2++]=top;
        g->Noduri[top].info=1;
        
        for(i=1;i<=n;i++){
            if(g->Arce[top][i] && !g->Noduri[i].info){
                g->Noduri[i].info=1;
                coada[k]=i;
                k++;
            }
        }
    }
}

int main()
{
    int n,m,i,aux,j,ok;
    
    Nod nd;
    Arc bow;
    g=(Graf*)malloc(sizeof(Graf));
    Initializare(g);
    
    scanf("%d",&n);
    scanf("%d",&m);
 
    for(i=1;i<=n;i++)
    {
        nd.cheie=i;
        nd.info=0;
        InsertNod(g,nd);
    }
    
    for(i=1;i<=m;i++)
    {
        scanf("%d",&aux);
        bow.idx_nod_1=aux;
        scanf("%d",&aux);
        bow.idx_nod_2=aux;
        InsertArc(g,bow);
    }
    
    printf("\n");
    for(i=1;i<=n;i++)
    {
        k1=0;k2=0;ok=1;
        for(j=1;j<=n;j++)
        {
            g->Noduri[j].info=0;
        }
        adancime(i,n);
        
        for(j=1;j<=n;j++)
        {
            g->Noduri[j].info=0;
        }
        cuprindere(i,n);
        
        for(j=0;j<k1;j++){
            if(adanc[j]!=latime[j]){
                ok=0;break;
            }
        }
        if(ok==1){
            printf("%d ",i);
        }
    }
    
    
    
        
            
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    return 0;
}
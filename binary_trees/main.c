#include <stdio.h>
#include <stdlib.h>

typedef struct ABO{
    int cheie;
    struct ABO *stanga,*dreapta;
}ABO;

int max=0,n;
ABO *arbore;

ABO* add(ABO *r,int x){
    if(r!=NULL){
        if(x <= r->cheie)
            r->stanga=add(r->stanga,x);
        if(x > r->cheie)
            r->dreapta=add(r->dreapta,x);
        return r;
    }else{
        r=(ABO*)malloc(sizeof(ABO));
        r->cheie=x;
        return r;
    }
}

void preordine(ABO *r){
    if(r!=NULL){
    printf("%d ",r->cheie);
    preordine(r->stanga);
    preordine(r->dreapta);
    }
}

void lungime(ABO *r,int i){
    if(r!=NULL)
    {
        if(r->stanga!=NULL)
            lungime(r->stanga,i+1);
        if(r->dreapta!=NULL)
            lungime(r->dreapta,i+1);
        if(i>max)
        max=i;
    }
}

int inaltime(){
   lungime(arbore,1);
   if(n==0){
       return 0;
   }
   return max;
}

int main(){
    
    int x,i;
    scanf("%d",&n);
    
    for(i=0;i<n;i++){
        scanf("%d",&x);
        arbore=add(arbore,x);
    }
    
    printf("%d\n",inaltime());
    preordine(arbore);

    free(arbore);
    return 0;
}
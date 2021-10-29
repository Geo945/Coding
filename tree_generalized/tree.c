#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int cheie;
    int parinte;
}Nod;

Nod a[100];
int k=0,n;

void adauga(int cheie,int cheie_parinte){
    if(k==0){
        a[k].cheie=cheie;
        a[k].parinte=cheie;
    }else{
        a[k].cheie=cheie;
        a[k].parinte=cheie_parinte;
    }
    k++;
}

int b[1000],count=0;

void lungime(int p,int c)
{
    int i;
    for(i=1;i<n;i++)
    {
        
        if(p==a[i].parinte)
        {
            if(a[i].cheie==p)
            goto here;
            
            lungime(a[i].cheie,c+1);
            b[count]=c;
            count++;
           
        }
      here:
      printf("");
       
    }
    
}

int inaltime()
{
   int i,max;
   for(i=0;i<n;i++)
   {
       lungime(a[i].parinte,1);
   }
   
   max=b[0];
   for(i=1;i<count;i++)
   {
       if(b[i]>max)
       {
           max=b[i];
       }
   }
   
   return max+1;
    
}

void grad(){
    int i,j,max=1,h;
    
    for(i=0;i<n;i++){
        h=0;
        
        for(j=0;j<n ;j++){
            if(a[i].parinte==a[j].parinte)
                h++;
        }
        
        if(a[i].parinte==a[0].parinte){
            h--;
        }
        
        if(h>max){
            max=h;
        }
        
    }
    printf("\n%d",max);
}



int main()
{
    int i,x,y;

    scanf("%d",&n);
    
    for(i=0;i<n;i++){
        scanf("%d %d", &x, &y);
        adauga(x,y);
    }
    
    printf("%d",inaltime());
    grad();
    return 0;
}
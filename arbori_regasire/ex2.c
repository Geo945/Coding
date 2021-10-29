#include <stdlib.h>
#include <stdio.h>
#include <string.h>


typedef struct NodArboreDeRegasire {
	struct NodArboreDeRegasire *alfabet[27]; //alfabetul A B ... Z [
}NodArboreDeRegasire;

NodArboreDeRegasire *arbore;


int k=0;
int max=0;
int nrpag=1;
int ok=0;
void Initializare(NodArboreDeRegasire *Nod)
{
	//ATENTIE, aceasta functie trebuie apelata cu *Nod deja alocat
	char c;
	for (c = 'a'; c <= 'z'+1; c++)
		Nod->alfabet[c - 'a'] = NULL;
}

void Atribuie(NodArboreDeRegasire *Nod, char c, NodArboreDeRegasire *p)
{
	Nod->alfabet[c - 'a'] = p;
}

NodArboreDeRegasire *Valoare(NodArboreDeRegasire *Nod, char c)
{
	return Nod->alfabet[c - 'a'];
}

void NodNou(NodArboreDeRegasire *Nod, char c)
{
	Nod->alfabet[c - 'a'] = (NodArboreDeRegasire *)malloc(sizeof(struct NodArboreDeRegasire));
	Initializare(Nod->alfabet[c - 'a']);
}


void Adauga(char *x, NodArboreDeRegasire *cuvinte)  //x=cuvantul, cuvinte=radacina arborelui de regasire

{
	unsigned i;

	NodArboreDeRegasire *t;

	t = cuvinte;

	for (i = 0; i < strlen(x);i++) 
	{

		if (Valoare(t, x[i]) == NULL){ //nodul curent nu are fiu pentru caracterul x[i], deci se creaza unul nou
			NodNou(t, x[i]);
            nrpag++;
		}   
		t = Valoare(t, x[i]); //avansez in arborele de regasire
        k++;
	}
	
    if(max<k)
		max=k;
	Atribuie(t, '{', t); //se face o bucla pentru '[', pentru a marca un nod terminal

}
void Parcurge(NodArboreDeRegasire *Nod, char cuv[], int niv) //nodul curent, un buffer pentru construirea cuvantului, nivelul curent
{ 
	char c;

	
	for (c = 'z'; c >= 'a'; c--)		//pentru toate literele considerate
	{
		if (Valoare(Nod, c))			//daca exista legatura in dictionar
		{
			cuv[niv] = c;				//adaug litera gasita in buffer
			Parcurge(Valoare(Nod, c),cuv,niv+1);
			break;
		}
	}
	ok++;
	if(ok==1){
    	if (Valoare(Nod, 'a'-1))			//exista terminator=>am gasit un cuvant intreg
    	{
    		cuv[niv] = '\0';	
    		printf("%s\n", cuv);
    		ok++;
    	}
	}
	
}



int main()
{
    int n,i;
    char aux[30];
    scanf("%d",&n);
    arbore=(NodArboreDeRegasire*)malloc(sizeof(NodArboreDeRegasire));
    Initializare(arbore);
    for(i=0;i<n;i++)
    {
        k=1;
        scanf("%s",aux);
        Adauga(aux,arbore);
        
    }
    strcpy(aux,"");
    Parcurge(arbore,aux,0);
    
    free(arbore);
    return 0;
}




















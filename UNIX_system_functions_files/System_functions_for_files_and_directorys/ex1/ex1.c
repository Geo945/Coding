/*primul arg e un nr, iar restul sunt intrari, orice intrari. minim 2 argumente + mesaj in caz ca nu sunt minim 2. 
1) Daca e legatura simbolica sa afisam dimensiunea in octeti a legaturii simbolice,  si daca legatura simbolica indica la un fisier obisnuit atunci afisam si dimensiunea fisierului. 
2)Sa creeam o legatura simbolica numita my_link catre acel fisier(catre ultimul fisier obisnuit din lista).   avem mai multe arg in linia de comanda primul arg un numar si apoi celelalte sunt intrati in director (putem avea orice acolo) minim 2 argumente (verificare) afisam mesaj de informare ca nu rulam bine ca la shell folosim numele executabilului exit cu cod diferit de 0 stim ca e numar, doar convertim parcurgem fiecare arg din linia de comanda si daca e legatura simbolica sa afisam dimensiunea in octeti a legaturii simbolice daca legatura simbolica indica la un fisier obisnuit (test de tip) atunci afisam si dimensiunea fisierului respectiv (deoarece la hard link e acelasi*/
//primu arg(nr) nu face nimic, e degeaba
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

int main(int a, char *b[])
{

	if(a<=1){
		printf("Function requires at least 1 argument");
		exit(EXIT_FAILURE);
	}
	
	struct stat info;
	
	for(int i=1 ; i<a ; i++){
		if( lstat(b[i],&info) == 0 ){
			if( S_ISLNK(info.st_mode) ){
				printf("Byte size of symbolic link: %ld\n",info.st_size);
				printf("File size: %ld Bytes\n",info.st_size);
			}else{
				if( symlink(b[i],"my_link") < 0){
					printf("Unable to create symlink");
					exit(EXIT_FAILURE);
				}
			}
		}
	}



	return 0;
} 

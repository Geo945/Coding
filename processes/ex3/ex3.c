/*Sa se implementeze un program C, folosind apeluri sistem si functii de biblioteca, care se apeleaza sub forma: ./executabil c file1 file2 …

Se va verifica faptul ca exista minim 2 argumente, dintre care primul este un caracter alfanumeric (c), iar celelalte (file1, file2, …) sunt cai catre fisiere obisnuite. In caz de erori la numarul sau tipul argumentelor, se vor afisa mesaje de utilizare corespunzatoare. Argumentele care nu sunt fisiere obisnuite nu vor fi prelucrate.

Se va parcurge lista de argumente (excluzand caracterul dat) si se va crea cate un proces fiu pentru fiecare fisier obisnuit. Fiecare proces fiu va calcula numarul de aparitii ale caracterului c in fisierul asociat si va afisa pe ecran o linie de forma "<nume_fisier>: <numar_aparitii>". Parintele va afisa pe ecran caracterul "." in mod repetat, pana la terminarea tuturor proceselor fiu. La terminarea fiecarui proces fiu, parintele va afisa pe ecran un mesaj de forma "Procesul fiu cu PID-ul <PID> s-a incheiat cu codul <cod>".

Procesele fiu si procesul parinte vor rula obligatoriu in paralel.

Se vor trata cazurile de eroare pentru apelurile sistem folosite.

Functiile de biblioteca permise sunt DOAR pentru formatări (printf) şi verificări de tip de caracter.*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

#define BUFSIZE 4096

void parcurge(int a,char *b[])
{
	int i,fd,count,status;
	struct stat info;
	pid_t pid,wpid;
	const char *c=b[1];
	char buf[BUFSIZE];
	char *ptr, *next;
	
	for(i=2;i<a;i++){
		count=0;
		if((lstat(b[i],&info))<0){
			perror("Calling lstat");
			exit(EXIT_FAILURE);
		}
		
		if(S_ISREG(info.st_mode)){
			
			if( (pid=fork())<0){
				perror("Calling fork");
				exit(EXIT_FAILURE);
			}
			
			if(pid==0){
				if( (fd=open(b[i],O_RDONLY))<0 ){
					perror("Opening file");
					exit(EXIT_FAILURE);
				}
				
				while( (read(fd,buf,BUFSIZE))>0){
					next=NULL;
					for(ptr=buf; (next=strstr(ptr,c)); ptr=next+1)
						count++;
				}
				printf("%s: %d",b[i],count);
				close(fd);
				exit(2);	
			}
			//parinte
			printf(".");
			wpid=wait(&status);
			if(WIFEXITED(status)){
				printf("\nChild %d ended with code %d\n",wpid, WEXITSTATUS(status));
			}else{
				printf("\nChild %d ended abnormally\n",wpid);
			}
			
		}

	}
	
}

int main(int a,char *b[])
{
	if(a<2){
		fprintf(stderr,"Incorrect usage");
		exit(EXIT_FAILURE);
	}

	if(strlen(b[1])>1){
		fprintf(stderr,"First argument should be a character");
		exit(EXIT_FAILURE);
	}
	
	parcurge(a,b);

	return 0;
}

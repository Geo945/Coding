/*argumente:3
-a0 - primul termen dintr-o serie (double)
-r - ratie
-n - un nr (indice) (valoare foarte mare ex 1 0000 0000)
Facem test de argumente.(exact 3 argumente)
creem un proces fiu care calculeaza seria de forma an+1 = an + 1/r (r valoare f mare, ex 10000)
nu declaram vectori 
dupa o sec fiul trebuie sa trimita parintelui sigusr1
parintele (cu sigchld) dupa ce se termina un fiu apelam wait in handlerul de sigchld 
(va fi fara blocarea parintelui) 
parintele o sa afiseze stelute(*) in continuu, dupa ce primeste sigusr1 v-a afisa plusuri(+)
fiul se termina cand ajunge la indexul n (trebuie sa afiseze valoarea) si transmite val 3 (exit(3))
cand se termina parintede (dupa ce preia starea fiului) si afiseaza codul de retur a fiului
 

Pt a dura > 1 sec calculul
.a0 = 1
r = 10 000 (4 zero)
N = 100 000 000 (8 zero)*/
//  ./ex 1 10000 100000000

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <sys/wait.h>

char c='*';

void alarm_handler(){
	if( kill(getppid(),SIGUSR1) <0){
		perror("Calling kill");
		exit(1);
	}
	alarm(1);
}

void child(int a,char *b[]){
	const long int r = atol(b[2]);
	alarm(1);
	struct sigaction alarm;
  	memset(&alarm, 0x00, sizeof(struct sigaction));
  	alarm.sa_handler = alarm_handler;
	if( (sigaction(SIGALRM, &alarm, NULL))<0){
		perror("Calling sigaction");
		exit(1);
	}
		
	long int i;
	double result=atof(b[1]);
	for(i=0;i<atol(b[3]);i++){
		result += 1/r;
	}
	printf("Resultatul seriei: %lf", result);
	exit(3);
	
}

void handle_sgchild(int sig){
	int status;
	pid_t wpid;
	wpid=wait(&status);
	if(WIFEXITED(status)){
		printf("\nChild %d ended with code %d",wpid,WEXITSTATUS(status));
	}else{
		printf("\nChild %d ended abnormally",wpid);
	}
	exit(0);
}

void handle_sigusr(int sig){
	c='+';
}

void parent(){

	struct sigaction handler_sigusr1;
	memset(&handler_sigusr1, 0x00, sizeof(struct sigaction));
	handler_sigusr1.sa_handler = handle_sigusr;
	if( (sigaction(SIGUSR1, &handler_sigusr1, NULL))<0){
		perror("Calling sigaction");
		exit(1);
	}

	struct sigaction handler_sgchild;
	memset(&handler_sgchild, 0x00, sizeof(struct sigaction));
	handler_sgchild.sa_handler = handle_sgchild;
	if( (sigaction(SIGCHLD, &handler_sgchild, NULL))<0){
		perror("Calling sigaction");
		exit(1);
	}
	
	while(1){
		printf("%c",c);
	}
}

void function(int a, char *b[]){
	pid_t pid;
	if( (pid=fork())<0){
		perror("Calling fork");
		exit(1);
	}
	
	if(pid==0){
		child(a,b);
		
	}else{
		parent();
	}
}

int main(int a, char *b[])
{	
	if(a<3){
		fprintf(stderr,"Invalid number of arguments");
		exit(1);
	}
	
	function(a,b);

	return 0;
}

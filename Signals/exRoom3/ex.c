/*

Să se scrie un program C care poate fi apelat sub forma:

```
fibonacci N
```

------------------------------------[CERINȚE]-----------------------------------

1. Programul va aștepta pentru semnalul `SIGUSR1` pentru a începe rularea.

2. Când `SIGUSR1` este primit de program, va începe sa calculeze elementul de
   rang `N` din șirul lui fi bocanci, afișând toate elementele intermediare.
   Programul va afișa data și ora la care a început sa calculeze.

3. Când `SIGUSR2` este primit de program, va afișa cate elemente a calculat și
   elementul curent.

4. Calculul șirului lui fibonacci se va face intru-n proces fiu. Procesul
   părinte va afișa din 5 în 5 secunde cat timp a trecut de la primirea
   `SIGUSR1`.

------------------------------------[INDICAȚII]-----------------------------------

1. Citiți atent paginile de manual pentru `sigaction()`, `fork()`, `strtol()`
   și pagina pentru semnale (`man 7 signal`).

2. Pentru a afișa data și ora curentă, puteți folosi `ctime()` și `time()`
*/
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include <sys/wait.h>

int start=0;
long int count=0,current;
long long el;

long long fib(int n){
   if (n <= 1){
   	count++;
      	return n;
   }
   count++;
   el=n;
   return fib(n-1) + fib(n-2);
}

void handle_sigusr1(int sig){
	start=1;
	current=0;
}

void handle_sigusr2(int sig){
	printf("%ld %lld\n",count,el);
}

void alarm_handler(int sig){
	current +=5;
	printf("Current time: %ld seconds\n",current);
	alarm(5);
}

void child(int a,char *b[]){
	
	struct sigaction handler_sigusr1;
  	memset(&handler_sigusr1, 0x00, sizeof(struct sigaction));
  	handler_sigusr1.sa_handler = handle_sigusr1;
	if(sigaction(SIGUSR1,&handler_sigusr1,NULL)){
		perror("Calling sigaction");
		exit(EXIT_FAILURE);
	}
	

	
	struct sigaction handler_sigusr2;
  	memset(&handler_sigusr2, 0x00, sizeof(struct sigaction));
  	handler_sigusr2.sa_handler = handle_sigusr2;
	if(sigaction(SIGUSR2,&handler_sigusr2,NULL)){
		perror("Calling sigaction");
		exit(EXIT_FAILURE);
	}
	
	while(1){
		if(start){
			alarm(5);
			struct sigaction alarm;
		  	memset(&alarm, 0x00, sizeof(struct sigaction));
		  	alarm.sa_handler = alarm_handler;
			if( (sigaction(SIGALRM, &alarm, NULL))<0){
				perror("Calling sigaction");
				exit(1);
			}
			long long a;
			time_t curtime;
   			time(&curtime);
   			printf("Current time = %s\n", ctime(&curtime));
			a=fib(atoi(b[1]));
			printf("Result: %lld\n",a);
			exit(2);
			start=0;
		}
	}
	
	
}
void handle_chld(int sig)
{	
	int status;
	pid_t wpid;
	wpid=wait(&status);
	if(WIFEXITED(status)){
		printf("\nChild %d ended with code %d\n",wpid,WEXITSTATUS(status));
	}else{
		printf("\nChild %d ended abnormally\n",wpid);
	}
	exit(0);
}

void function(int a, char *b[]){
	pid_t pid;
	if( (pid=fork())<0){
		perror("Calling fork");
		exit(EXIT_FAILURE);
	}
	
	
	
	if(pid==0){
		child(a,b);
	}else{
		struct sigaction handler_sigchld={0};
	  	handler_sigchld.sa_handler = handle_chld;
		if(sigaction(SIGCHLD,&handler_sigchld,NULL)){
			perror("Calling sigaction");
			exit(EXIT_FAILURE);
		}
	}
	
	while(1)
	;

}

int main(int a,char *b[])
{
	if(a<2){
		fprintf(stderr,"Invalid no. of args.\n");
		exit(EXIT_FAILURE);
	}
	
	function(a,b);

	return 0;
}











#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

#define BUFSIZE 4096

void f(int a,char *b[]){

	int i,j,status;
	pid_t pid,wpid;
	
	for(i=2;i<a;i++){
	
		if( (pid=fork())<0 ){
			perror("Calling fork");
			exit(1);
		}
		
		if(pid==0){
			for(j=1;j<=atoi(b[i]);j++){
				printf("%d %d\n",getpid(),j);
			}
			printf("\n");
			exit(2);
		}
		
		
	}
	for(i=2;i<a;i++){
		wpid=wait(&status);
		
		if(WIFEXITED(status)){
			printf("Child %d ended with code %d\n", wpid, WEXITSTATUS(status));
		}else{
			printf("Child %d ended abnormally\n",wpid);
		}
	}

}

int main(int a,char *b[])
{
	if(a<3){
		fprintf(stderr,"Invalid number of arguments\n");
		exit(1);
	}	

	f(a,b);
	printf("\n");
	int status;
	pid_t pid,wpid;
	
	if( (pid=fork())<0){
		perror("Calling fork");
		exit(1);
	}
	
	if(pid==0){
	
		if( (execlp("grep","grep","if",b[1],NULL))<0){
			perror("Calling exec");
			exit(2);
		}
	}
	
	wpid=wait(&status);
	if(WIFEXITED(status)){
		printf("Child %d ended with code %d\n", wpid, WEXITSTATUS(status));
	}else{
		printf("Child %d ended abnormally\n",wpid);
	}

	return 0;
}


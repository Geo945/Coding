#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define BUFSIZE 4096

int main(int a,char *b[])
{

	if(a!=3){
		printf("Invalid no. arguments");
		exit(EXIT_FAILURE);
	}

	int fd1;
	if( (fd1=open(b[1], O_RDONLY , 0)) < 0){
		perror("Opening file");
		exit(EXIT_FAILURE);
	}
	int i;
	char buf[BUFSIZE];
	while( (read(fd1,buf,BUFSIZE)) >0){
		for(i=0;i<strlen(buf);i++)
			printf("%c\n",buf[i]);
	}
	
	close(fd1);



	return 0;
}
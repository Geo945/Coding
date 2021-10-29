#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>

#define BUFSIZE 4096

typedef struct{
	int litere_mici;
	int litere_mari;
	int cifre;
	int count;
	int dimensiune_fisier;
}statistici;

int main(int a,char *b[])
{
	statistici stats;
	char buf[BUFSIZE];
	int i;
	char out[PATH_MAX];
	
	stats.litere_mici=0;
	stats.litere_mari=0;
	stats.cifre=0;
	stats.count=0;
	stats.dimensiune_fisier=0;

	if(a!=4){
		perror("Invalid number of arguments");
		exit(EXIT_FAILURE);
	}


	int fd1;
	if( (fd1=open(b[1], O_RDONLY, S_IRUSR)) < 0){
		perror("Failed to open file");
		exit(EXIT_FAILURE);
	}
	while( (read(fd1,buf,BUFSIZE)) > 0){
		
		
		for(i=0;i<strlen(buf);i++){
			if(isdigit(buf[i]))
				stats.cifre++;
			if(isalpha(buf[i])){
				if(islower(buf[i]))
					stats.litere_mici++;
				if(isupper(buf[i]))
					stats.litere_mari++;
			}
			if(tolower(buf[i])==tolower(b[3][0]))
				stats.count++;
			stats.dimensiune_fisier++;
		}
	}
	close(fd1);
	

	if( (fd1=open(b[2], O_WRONLY, S_IRUSR)) < 0){
		perror("Failed to open file");
		exit(EXIT_FAILURE);
	}

	snprintf(out, sizeof(out),"numar litere mici: %d\nnumar litere mari: %d\nnumar cifre: %d\nnumar aparitii caracter: %d\ndimensiune fisier: %d\n",stats.litere_mici, stats.litere_mari,stats.cifre,stats.count,stats.dimensiune_fisier);

	if( (write(fd1,out,strlen(out)))<0){
		perror("Failed to write");
		exit(EXIT_FAILURE);
	}
	close(fd1);

	return 0;
}






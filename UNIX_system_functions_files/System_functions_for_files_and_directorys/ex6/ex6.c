#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <dirent.h>

#define BUFSIZE 4096

long int count=0;

void myfunction(char file_path[]){

	struct stat info;

	if( (lstat(file_path,&info))<0 ){
		perror("Using lstat");
		exit(EXIT_FAILURE);
	}
	
	if(S_ISDIR(info.st_mode)){
		DIR *dir;
		struct dirent *in;
		char temp[256];
		
		if( (dir=opendir(file_path))<0){
			perror("Opening directory");
			exit(EXIT_FAILURE);
		}
		
		while( (in=readdir(dir))!=NULL){
			
			if(strcmp(in->d_name,".")==0 || strcmp(in->d_name,"..")==0)
				continue;
			
			strcpy(temp,file_path);
			strcat(temp,"/");
			strcat(temp,in->d_name);
			myfunction(temp);
		}
		
		closedir(dir);
	}

	if(S_ISREG(info.st_mode)){
		if(strstr(file_path,".txt")!=NULL){
			int fd1;
			char buf[BUFSIZE];
			const char *ptr, *lastfind;
			if( (fd1=open(file_path, O_RDONLY, S_IRUSR)) <0){
				perror("Opening file");
				exit(EXIT_FAILURE);
			}
			
			while( (read(fd1,buf,BUFSIZE))>0){
				lastfind=NULL;
				for(ptr=buf; (lastfind=strstr(ptr," "));ptr=lastfind+1)
					count++;
			}
			
			close(fd1);
			
		}
	}

}

int main(int a,char *b[])
{
	if(a!=3){
		printf("Invalid no. arguments");
		exit(EXIT_FAILURE);
	}

	int number=atoi(b[2]);
	
	myfunction(b[1]);
	
	if(count>number){
		char tmp[256];
		strcpy(tmp,b[1]);
		strcat(tmp,"_spaces");
		symlink(b[1],tmp);
	}

	return 0;
}
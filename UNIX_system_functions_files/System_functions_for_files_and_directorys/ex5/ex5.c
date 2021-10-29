#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <dirent.h>

#define BUFSIZE 4096

long int count;

void myfunction(char file_path[]){

	struct stat info;
	struct dirent *in;
	DIR *dir;
	char tmp[256];
	
	if( (lstat(file_path,&info))<0){
		perror("Using lstat");
		exit(EXIT_FAILURE);
	}
	if(S_ISDIR(info.st_mode)){
		
		if( (dir=opendir(file_path))<0){
			perror("Opening directory");
			exit(EXIT_FAILURE);
		}
		
		while( (in=readdir(dir))!=NULL){
		
			if(strcmp(in->d_name,".")==0 || strcmp(in->d_name,"..")==0){
				continue;
			}
		
			strcpy(tmp,file_path);
			strcat(tmp,"/");
			strcat(tmp,in->d_name);
			//printf("%s\n",tmp);
			myfunction(tmp);
		}
		
		closedir(dir);
		
	}
	if(S_ISREG(info.st_mode) || S_ISLNK(info.st_mode)){
		count +=info.st_size;
	}
		
}


int main(int a,char *b[])
{
	char directory_list[100][100];
	int i,fd1,k=0,column=0;
	char buf[BUFSIZE];
	
	if(a!=3){
		printf("Invalid number of arguments");
		exit(EXIT_FAILURE);
	}

	
	if( (fd1=open(b[1], O_RDONLY, S_IRUSR)) < 0){
		perror("Opening directory");
		exit(EXIT_FAILURE);
	}
	
	strcpy(directory_list[k],"");
	while( (read(fd1,buf,BUFSIZE)) > 0){
		
		for(i=0;i<strlen(buf);i++){
			if(buf[i]=='\n'){
				k++;
				strcpy(directory_list[k],"");
				column=0;
				continue;
			}
			directory_list[k][column]=buf[i];
			column++;
		}
	}
	
	for(i=0;i<k;i++){
		count=0;
		struct stat info;
		if( (lstat(directory_list[i],&info))<0){
		perror("Using lstat");
		exit(EXIT_FAILURE);
		}	
		if(S_ISREG(info.st_mode))
			goto here;
		myfunction(directory_list[i]);
		here:
		printf("%s: %ld Bytes\n",directory_list[i], count);
	}
	close(fd1);






	return 0;
}




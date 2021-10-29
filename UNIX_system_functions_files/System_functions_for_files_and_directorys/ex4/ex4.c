#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <limits.h>
#include <fcntl.h>

#define BUFSIZE 4096

void myfind(char file[], char searchName[], int doOrNot, char cwd[], char string[], char cmp[]){
	
	DIR *dir;
	struct dirent *in;
	struct stat info;
	char path[1000];
	char buf[BUFSIZE];
	int fd1,n;
	
	
	if( !(dir=opendir(file)) ){
		perror("Failed to open directory");
		exit(EXIT_FAILURE);
	}
	
	while( (in = readdir(dir)) != NULL){
		if(strcmp(in->d_name,".")==0 || strcmp(in->d_name,"..")==0){
			continue;
		}
		strcpy(path,cwd);
		strcat(path,"/");
		strcat(path,in->d_name);

		if(lstat(path, &info)==0){
			if(S_ISDIR(info.st_mode)){
				myfind(path,searchName, doOrNot, path, string,cmp);
				
			}
		}else{
			perror("Failed to use stat");
			exit(EXIT_FAILURE);
		}
		
			
		if(!doOrNot){
			printf("%s\n",path);		
		}else{
			if(strcmp(in->d_name,cmp)==0){
				if((fd1=open(path, O_RDONLY, S_IRWXU))<0){
					perror("failed to open file");
					exit(EXIT_FAILURE);
				}
					
				while( (n = read(fd1, buf, BUFSIZE)) > 0){
					if(strstr(buf,string)!=NULL){
						printf("%s\n",path);
						break;
					}
				}
					
				close(fd1);
			}
		}
	}
	
	closedir(dir);

}

int main(int a, char *b[])
{
	int i=2;
	int searchIndex=1;
	int doOrNot=0;
	char cwd[PATH_MAX];
	char string[100]="";
	getcwd(cwd,sizeof(cwd));
	char cmp[100];
	
	if(strcmp(b[1],"-p")==0){
		i=4;
		searchIndex=2;
		doOrNot=1;
		strcpy(string,b[2]);
		strcpy(cmp,b[3]);
	}

	for(i;i<a;i++){
		getcwd(cwd,sizeof(cwd));
		strcat(cwd,"/");
		strcat(cwd,b[i]);	
		myfind(b[i],b[searchIndex],doOrNot,cwd,string,cmp);	
	}

	return 0;
} 

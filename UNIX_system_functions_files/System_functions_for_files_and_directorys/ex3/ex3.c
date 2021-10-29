#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <pwd.h>
#include <time.h>
#include <fcntl.h>
#include <dirent.h>

#define BUFSIZE 4096


typedef struct{
	int flagH;
	int flagV;
	int flagD;
}flags;

typedef struct{
	char src[256];
	char dest[256];
	char str[256];
}greps;

void mygrep(greps grep, flags flag){
	
	struct stat info;
	struct passwd *pass;
	
	
	if(lstat(grep.src, &info) < 0){
		perror("Failed to use lstat");
		exit(EXIT_FAILURE);
	}
	
	if(S_ISDIR(info.st_mode)){
		DIR *dir;
		struct dirent *in;
		
		
		if( (dir=opendir(grep.src))<0){
			perror("Failed to open directory");
			exit(EXIT_FAILURE);
		}
		
		while( (in=readdir(dir))!=NULL ){
		
			if(strcmp(in->d_name,".")==0 || strcmp(in->d_name,"..")==0)
				continue;
			greps temp=grep;
			strcat(temp.src,"/");
			strcat(temp.src,in->d_name);
			mygrep(temp, flag);
		}
		
		closedir(dir);
	}
	
	if(flag.flagV){
		printf("%s: ",grep.src);
		if(S_ISDIR(info.st_mode)){
			printf("Directory ");
		}else if (S_ISREG(info.st_mode)){
			printf("Regular file ");
		}else if (S_ISLNK(info.st_mode)){
			printf("Symbolic link ");
		}
		printf("%ld ",info.st_size);
		pass=getpwuid(info.st_uid);
		printf("%s ",pass->pw_name);
		char date[10];
    		strftime(date, 10, "%d-%m-%y", gmtime(&(info.st_ctime)));
    		printf("%s \n",date);
	}
	
	if (S_ISREG(info.st_mode)){
		int count=0;
		int fd1;
		char buf[BUFSIZE];
		const char *ptr, *lastfind=NULL;
		if( (fd1=open(grep.src, O_RDONLY, S_IRWXU)) < 0 ){
			perror("Failed to open file");
			exit(EXIT_FAILURE);
		}
		
		while( (read(fd1,buf,BUFSIZE))>0){
			lastfind=NULL;
			for(ptr=buf; (lastfind=strstr(ptr, grep.str)); ptr=lastfind+1)
				count++;
		}
		
		printf("The string \"%s\" appers %d times in %s file\n\n",grep.str,count,grep.src);
		
	}
	
	if(flag.flagD){
		printf("redirect to file");
	}

}

int main(int a, char *b[])
{
	flags flag;
	greps grep;
	int i=1;
	
	if(strcmp(b[1],"-h")==0){
		printf("Requested option: h\n");
		flag.flagH=1;
		i=2;
	}
	
	if(strcmp(b[1],"-v")==0){
		flag.flagV=1;
		i=2;
	}
	
	if(strcmp(b[2],"-v")==0){
		flag.flagV=1;
		i=3;
	}
	
	if(a<3){
		printf("Invalid arguments");
		exit(EXIT_FAILURE);
	}

	if(b[i+2]!=NULL){
		flag.flagD=1;
	}

	if(flag.flagD){
		strcpy(grep.src, b[i]);
		strcpy(grep.dest,b[i+1]);
		strcpy(grep.str,b[i+2]);
	}else{
		strcpy(grep.src, b[i]);
		strcpy(grep.str,b[i+1]);
	}

	mygrep(grep, flag);


	return 0;
}

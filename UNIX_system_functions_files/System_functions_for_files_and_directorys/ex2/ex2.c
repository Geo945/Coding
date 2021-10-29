#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>
#include <dirent.h>

typedef struct{
	int flagP;
	int flagR;
}flags;

void check(char file_path[], flags flag){

	struct stat info;
	struct passwd * pass;
	struct group * grp;
	struct dirent *in;
	DIR *dir;
	char temp[256];
	
	if(lstat(file_path,&info) < 0){
		perror("Failed to use lstat");
		exit(EXIT_FAILURE);
	}
	
	if(S_ISDIR(info.st_mode)){
		if(!flag.flagP){
			printf( (info.st_mode & S_IRUSR) ? "r" : "-");
			printf( (info.st_mode & S_IWUSR) ? "w" : "-");
			printf( (info.st_mode & S_IXUSR) ? "x" : "-");
			printf( (info.st_mode & S_IRGRP) ? "r" : "-");
			printf( (info.st_mode & S_IWGRP) ? "w" : "-");
			printf( (info.st_mode & S_IXGRP) ? "x" : "-");
			printf( (info.st_mode & S_IROTH) ? "r" : "-");
			printf( (info.st_mode & S_IWOTH) ? "w" : "-");
			printf( (info.st_mode & S_IXOTH) ? "x " : "- ");
			pass=getpwuid(info.st_uid);
			printf("%s ",pass->pw_name);
			grp=getgrgid(info.st_uid);
			printf("%s ",grp->gr_name);
			printf("%ld ",info.st_size);
			printf("Directory %s",file_path);
			printf("\n");
		}
		if(flag.flagR){
			if( !(dir=opendir(file_path) )){
				perror("Failed to open directory");
				exit(EXIT_FAILURE);
			}
			
			
			while( (in=readdir(dir))>0 ){
			
				if(strcmp(in->d_name,".")==0 || strcmp(in->d_name,"..")==0){
					continue;
				}
			
				strcpy(temp, file_path);
				strcat(temp,"/");
				strcat(temp,in->d_name);
				check(temp, flag);
				
			}
			
			closedir(dir);
		}
	}
	
	if (S_ISREG(info.st_mode)){
		printf( (info.st_mode & S_IRUSR) ? "r" : "-");
		printf( (info.st_mode & S_IWUSR) ? "w" : "-");
		printf( (info.st_mode & S_IXUSR) ? "x" : "-");
		printf( (info.st_mode & S_IRGRP) ? "r" : "-");
		printf( (info.st_mode & S_IWGRP) ? "w" : "-");
		printf( (info.st_mode & S_IXGRP) ? "x" : "-");
		printf( (info.st_mode & S_IROTH) ? "r" : "-");
		printf( (info.st_mode & S_IWOTH) ? "w" : "-");
		printf( (info.st_mode & S_IXOTH) ? "x " : "- ");
		pass=getpwuid(info.st_uid);
		printf("%s ",pass->pw_name);
		grp=getgrgid(info.st_uid);
		printf("%s ",grp->gr_name);
		printf("%ld ",info.st_size);
		printf("Regular file %s", file_path);
		printf("\n");
	}

}

int main(int a, char *b[])
{
	int i=1;
	flags flag;
	
	if(strcmp(b[1],"-p")==0){
		i=2;
		flag.flagP=1;
	}
	
	if(strcmp(b[a-1],"-R")==0){
		flag.flagR=1;
	}
	
	for(i;i<a;i++){

		check(b[i], flag);

	}

	return 0;
} 

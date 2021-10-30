#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>           
#include <dirent.h>
#include <string.h>
#include <sys/wait.h>

void parcurge(char filePath[]) {
	struct stat info;
	struct stat nextInfo;
	struct dirent *in;
	pid_t pid;
	pid_t wpid;
	int status;
	if (lstat(filePath, &info) < 0) {
		perror("Error");
		exit(1);
	}
	if (S_ISDIR(info.st_mode)) {
		DIR *dir;
		if (!(dir = opendir(filePath))) {
			perror("Eroare deschiedere director");
			exit(1);
		}
		if(chdir(filePath)==-1){
			perror("Up directory");
			exit(EXIT_FAILURE);
		}
		
		while ((in = readdir(dir)) > 0) {
			if (strcmp(in->d_name, ".") == 0 || strcmp(in->d_name, "..") == 0) {
				continue;
			}
			if (lstat(in->d_name, &nextInfo) < 0) {
				perror("Error lstat");
				exit(1);
			}
			if (S_ISDIR(nextInfo.st_mode)) {
				parcurge(in->d_name);
			}
			
			if (S_ISREG(nextInfo.st_mode) || S_ISLNK(nextInfo.st_mode)) {
				if( ( pid=fork() ) < 0)
				  {
				    perror("Eroare");
				    exit(1);
				  }
				  
				if(pid==0)
				  {
				  	
					execlp("md5sum", "md5sum", in->d_name,NULL);
					perror("Error");
				   	exit(2);
				  }
				  wpid = wait(&status);
				if (WIFEXITED(status)) {
					printf("child %d ended with code %d\n", wpid,WEXITSTATUS(status));
				} else {
					printf("child %d ended with error", wpid);
				}
				
			}	
		}
		if( chdir("..")==-1) {
			perror("Previous directory");
			exit(EXIT_FAILURE);
		}
		closedir(dir);
	}

}

int main(int a, char *b[]) {
	
	if(a<2){
		fprintf(stderr,"Incorrect usage");
		exit(EXIT_FAILURE);
	}
	
	parcurge(b[1]);

	return 0;
}
 

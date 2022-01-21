#include <stdio.h>
#include <stdlib.h>  
#include <time.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#define READ 0
#define WRITE 1
int main(){
        int fd[2];
        pipe(fd);
        int pid=fork();
        if(pid==0)
        {
                dup2(fd[READ],STDIN_FILENO);
                char str[10];
                fgets(str,10,stdin);
                int random=atoi(str);
                if(random<500)
                {
                        printf("menor que 500\n");
                }
                else{
                        printf("mayor o igual a 500\n");
                }

        }
        else if (pid==-1)
        {
                perror("fork() failed");
                exit(EXIT_FAILURE);
        }
        else
        { close(fd[READ]);
	  dup2(fd[WRITE],STDOUT_FILENO);
	  srand(time(NULL));
	  int random=rand()%1000+1;
	  printf("%d\n",random);
	}
	return 0;
}

#include <sys/types.h>  // fork
#include <unistd.h>     // execlp, fork, pipe
#include <stdio.h>      // perror
#include <stdlib.h>     // exit
#include <string.h>     // memset

int main()
{
    // pipefd[0]: read; pipefd[1]: write
    int pipefd[2];
    int ret = pipe(pipefd);
    if (ret==-1)
    {
        perror("pipe");
        exit(0);
    }
    if(fork())
    {
        // parent
        dup2(pipefd[1], STDOUT_FILENO);
        execlp("ps", "ps", "-aux", NULL);
    }
    else
    {
        // child
        char buf[1024];
        while(read(pipefd[0], buf, sizeof(buf)-1))
        {
            printf("%s", buf);
            memset(buf, 0, 1024);
        }
        
    }
    return 0;
}
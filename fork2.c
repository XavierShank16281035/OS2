#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    pid_t pid = fork();

    //在子进程
    if(pid == 0)
    {
        int num  = execl("/usr/bin/vim","vim","NULL");
        if(num == -1)
            perror("execl");
    
    }

    else if(pid>0)
    {
    //在父进程
    while(1){}
    }

    else
    {
        printf("fork调用失败");
    }
    return (0);
}

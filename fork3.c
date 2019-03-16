#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <time.h>
#include <stdarg.h>
#include<sys/types.h> //这个头文件不能少，否则pid_t没有定义 

int main(int argc, char *argv[])
{
    pid_t pidA,pidB,pidC,pidD;
    int i;
    printf("这是父进程，P1，PID是%d\n",getpid());

    pidA = fork(); //创建新进程

    if(pidA<0)
    {
        printf("新进程创建失败\n");
        exit(0);
    }

    else if(pidA == 0)
    {
        i=100;
        while(i-->0)
        {
        printf("这是子进程，P3，PID是%d  它的父进程，P1，PID是%d\n",getpid(),getppid());
        }
        return 0;
    }

    else
    {
        pidB = fork();
        if(pidB<0)
        {
           printf("新进程创建失败\n");
          return 0;
        }

        else if(pidB == 0)
        {
            i=100;
             pidC = fork();
             if(pidC == 0)
             {
                 i=100;
                while(i-->0){
                printf("这是子进程，P4，PID是%d  它的父进程，P2，PID是%d\n",getpid(),getppid());}
            
               return 0;//防止产生孙进程
             }

             pidD = fork();
             if(pidD == 0)
             {
                i=100;
                while(i-->0){
                printf("这是子进程，P5，PID是%d  它的父进程，P2，PID是%d\n",getpid(),getppid());
                 }
                 
                return 0;//防止产生孙进程
             }
              i=100;
            while(i-->0)
            {
             printf("这是子进程，P2，PID是%d  它的父进程，P1，PID是%d\n",getpid(),getppid());
             if(i==50) {
                 int *ptr = NULL;
                 *ptr = 0;
             }
            }

             int *status;
             waitpid(pidC,status, 0);
             waitpid(pidD,status, 0);
             return 0;
        }
    }
    int *status;
    waitpid(pidB,status, 0);
    waitpid(pidA,status, 0);
    return 0;

}
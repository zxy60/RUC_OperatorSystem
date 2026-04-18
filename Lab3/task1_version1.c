#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int main() {
    pid_t pid;
    int status;
    int user_exit_code;
    int common=111;
    printf("初始common值：%d\n",common);
    pid = fork(); 

    if (pid < 0) {
        perror("fork failed");
        exit(1);
    } else if (pid == 0) {
        printf("子进程：子进程PID: %d, 父进程 PID: %d\n", getpid(), getppid()); 
        
        printf("子进程：请输入一个返回值（整数）作为退出状态：\n");
        scanf("%d", &user_exit_code);
        common+=10;
        printf("子进程：将common加10，修改common值为%d\n",common);
        printf("子进程：子进程即将退出...\n");
        exit(user_exit_code); 
    } else {
        
        printf("父进程：父进程PID: %d, 子进程 PID: %d\n", getpid(), pid); 
        common+=5;
        printf("父进程：将common加5，修改common值为%d\n",common);
        printf("父进程：正在等待子进程退出...\n");
        wait(&status); 
        common+=20;
        printf("父进程：再将common加20，修改common值为%d\n",common);
        if (WIFEXITED(status)) { 
            printf("父进程：子进程已退出，它返回的值是：%d\n", WEXITSTATUS(status)); 
        }
    }

    return 0;
}
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    pid_t pid;

    pid = fork();

    if (pid < 0) {
        perror("fork failed");
        exit(1);
    } else if (pid == 0) {
        printf("子进程：PID%d，即将执行 'ls' 命令。\n", getpid());
        if (execlp("ls", "ls", "-l", NULL) == -1) { 
            perror("exec 失败");
            exit(1);
        }
        printf("子进程：如果还记得原来我在干嘛，就执行这条")
    } else {
        printf("父进程：正在等待子进程完成 ls 命令...\n");
        wait(NULL);
        printf("父进程：子进程已执行完毕。\n");
    }

    return 0;
}
/**
 * 无名管道, 只能在亲缘关系进程间通信
 * 管道只能单工通信, 固定一段发送, 另一端接受 
 */

// Rerfence: https://linux.die.net/man/2/pipe


#include <stdio.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
	int fd[2];                         // 两个文件描述符, fd[0]读, fd[1]写
    pid_t pid;
    char buff[20];

    if (pipe(fd) < 0)                   // 创建管道
        printf("Create Pipe Error!\n");

    if ((pid = fork()) < 0) {          // 创建子进程
        printf("Fork Error!\n");
    } 

    if(pid > 0) {               		// 父进程
        close(fd[0]);                  // 关闭读端
        write(fd[1], "hello child!", 13);   
    } else {
        close(fd[1]);                  // pid=0, 子进程，关闭写端
        read(fd[0], buff, 20);
        printf("%s", buff);
    }

	return 0;
}
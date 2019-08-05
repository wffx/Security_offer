/*
 * FIFO有名管道通信, read端
 */
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
	int fd;
	int len;
	char buf[1024];

	printf("The process id %d\n", getpid());

	if (mkfifo("fifo_test",0666) == -1) { 	//read & write permission for the owner, group, and others
		perror("Create FIFO failed！\n");
	}

	fd = open("fifo_test", O_RDONLY);

	if(fd == -1) {
		perror("Open fifo file failed！\n");
		exit(1);
	}

	while (len = read(fd, buf, 1024) > 0) {
		printf("From A: %s\n", buf);
	}

	close(fd);
	return 0;
}
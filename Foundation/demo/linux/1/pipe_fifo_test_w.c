/*
 * FIFO有名管道通信, write端
 */

#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int main() {
	int fd;
	char input[1024];

	printf("The process id %d\n", getpid());

	fd = open("fifo_test", O_WRONLY);
	if (fd == -1) {
		perror("Open fifo file failed!\n");
		exit(1);
	}

	while (input[0] != '#') {
		scanf("%s", input);
		if (write(fd, input, 1024) == -1) {
			perror("Write the error failed!\n");
			close(fd);
			exit(1);
		}
		sleep(1);
	}

	close(fd);
	return 0;
}
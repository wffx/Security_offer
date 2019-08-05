/*
 * Client for msg queue ipc
 * the execution needs the root permission, 
 * otherwise there is permission denied error EACCES in function msgsnd 
 * or soulution
 * #define MSG_R 0400 #define MSG_W 0200
 * myMsgQueue = msgget(IPC_PRIVATE, MSG_W | MSG_R);
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/types.h>
#include <fcntl.h>

#define PATHNAME "/etc/passwd"

struct msgbuf {
    long mtype;       /* message type, must be > 0 */
    char mtext[100];    /* message data */
};

int main() {
	struct msgbuf buf;
	key_t key;
	int que_i;
	int pid;
	//int msgflg = IPC_CREAT | IPC_EXCL;
	int msgflg = IPC_CREAT;

	key = ftok(PATHNAME, 1);
	if (key == -1) {
		perror("The key generated failed!\n");
	}
	// printf("%d\n", IPC_PRIVATE);
	// IPC_CREAT:Create the queue if it doesn't already exist in the kernel.
	// IPC_EXCL: When used with IPC_CREAT, fail if queue already exists.
	que_i = msgget(key, msgflg);

	if (que_i == -1) {
		perror("msgget failed!");
	}

	printf("the key: %d, the msgid: %d, the pid: %d\n", key, que_i, getpid());

	if ((pid = fork()) < 0) {          // 创建子进程
		printf("Fork Error!\n");
	}

	strcpy(buf.mtext, "client: hello ");
	if(pid > 0) {               		// 父进程, 发送消息
		while(buf.mtext[0] != '#') {
			buf.mtype = 11;
			// IPC_NOWAIT
			if(msgsnd(que_i, &buf, 100, 0) == -1) {
				perror("msgsnd failed!");
			}
			scanf("%s", buf.mtext);
		}
	} else {							// 子进程，接收消息
		while (buf.mtext[0] != '#') {
			if(msgrcv(que_i, &buf, 100, 12, 0) == -1) {
				perror("msgrcv failed!");
			} else {
				printf("Rec from Serve: %ld, %s\n", buf.mtype, buf.mtext);
			}  
		}
	}

	return 0;
}
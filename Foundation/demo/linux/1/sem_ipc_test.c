#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>

union semun {
   int              val;    /* Value for SETVAL */
   struct semid_ds *buf;    /* Buffer for IPC_STAT, IPC_SET */
   unsigned short  *array;  /* Array for GETALL, SETALL */
   struct seminfo  *__buf;  /* Buffer for IPC_INFO
                               (Linux-specific) */
};

int main() {
    key_t semkey;
    int semid;
    struct sembuf sbuf;
    union semun tmp;
    
    /* Get unique key for semaphore. */
    if ((semkey = ftok("/etc/passwd", 'a')) == -1) {
        perror("IPC error: ftok"); 
        exit(1);
    }

    /* Get semaphore ID associated with this key. */
    semid = semget(semkey, 1, IPC_CREAT | S_IRUSR |
        S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
    if ( semid == -1) {
        perror("IPC error: semget");
        exit(1);
    }
    tmp.val = 4;
    if (semctl(semid, 0, SETVAL, tmp) == -1) {
        perror("IPC error, init semctl");
        exit(1);
    }

    printf("The semid is %d\n", semid);
    // printf("The judge %o, %o\n", IPC_CREAT | S_IRUSR |
    //     S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH, IPC_CREAT| IPC_EXCL | S_IRUSR |
    //     S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
    
    /* Initialize the semaphore. */
    sbuf.sem_num = 0;
    sbuf.sem_op = 2;  /* This is the number of runs without queuing. */
    sbuf.sem_flg = 0;

    if (semop(semid, &sbuf, 1) == -1) {
        perror("IPC error: semop"); 
        exit(1);
    }

    if (semctl(semid, 0, IPC_RMID, tmp) == -1) {
        perror("IPC error: delete semctl");
        exit(1);
    }

    return 0;
}

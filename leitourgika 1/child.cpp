#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>
#include <limits.h>
#include <errno.h>
#include <semaphore.h>
#include <sys/wait.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/time.h>
#include <sys/types.h>

#define SEM_PERMS (S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP)
#define SEM_KEY_FILE ("sem.key")
#define TEXT_SZ 2048
#define MAX_CHARACTERS_PER_LINE 100

using namespace std;

int main(int argc, char *argv[]){
    cout << "Starting Child operations\n" << endl;
    clock_t t;
    int sem_fd;
    key_t sem_key;
    int sem_id;
    int i;
    struct sembuf sop;

    // Total time for N requests to server
    int sum_time = 0;

    char *shared_memory = ( char *)0;
	
	int shmid;

    string lines = argv[1];
    string requestperchild = argv[2];
    string numberofsegments = argv[3];
    int linespersegment = stoi(lines);
    int requestPerchild = stoi(requestperchild);
    int numberOfsegments = stoi(numberofsegments);

    //cout << lines << " lines" << linespersegment << " linespersegment"<< endl;
    //cout << requestPerchild << " requestPerchild" << endl;

    // Recover the sem_key from file
    sem_fd = open(SEM_KEY_FILE, O_RDONLY);
    if (sem_fd < 0) {
        perror("Could not open sem key for reading");
        exit(1);
    }

    if (read(sem_fd, &sem_key, sizeof(key_t)) != sizeof(key_t)) {
        perror("Error reading the semaphore key");
        exit(2);
    }

    // Done getting the semaphore key
    close(sem_fd);

    // Now obtain the (hopefully) existing sem
    sem_id = semget(sem_key, 0, 0);
    if (sem_id < 0) {
        perror("Could not obtain semaphore");
        exit(3);
    }


	srand( ( unsigned int )getpid() );
	shmid = shmget( (key_t)1235, MAX_CHARACTERS_PER_LINE * linespersegment, 0666 | IPC_CREAT );
	
    if (shmid == -1){
		fprintf( stderr, "shmget failed\n" );
		exit( EXIT_FAILURE );
	}
	
    shared_memory = (char*)shmat(shmid, (void *)0, 0);
	
    if (shared_memory == (void *)-1){
		fprintf(stderr, "shmat failed\n");
		exit(EXIT_FAILURE);
	}

	cout << "Shared memory segment with id " << shmid << " attached at " << &shared_memory << "\n" << endl;

    //int requests = 0;
    //while(requests < childrequests){
    //
    //    // Rand seed and generate random line
    //    unsigned int curtime = time(NULL);
    //    srand((unsigned int) curtime - getpid());
    //    int line = rand() % linenum + 1;
    //
    //    // Write to shared memory segment
    //    shared_memory->line = line;
    //
    //    t = clock();    // Begin timing
    //
    //    // End timing
    //    t = clock() - t;    
    //    sum_time += t;
    //    
    //    requests++;
    //    if(requests == childrequests){
    //        shared_memory->completed = 1;
    //    
    //    }
    //}
    
    for (i = 0; i < requestPerchild ; ++i) {
        
        cout << "Starting Child" << endl;
        
        //Rand seed and generate random line
        //unsigned int curtime = time(NULL);
        //srand((unsigned int) curtime - getpid());
        //int line = rand() % n + 1;
        int line = rand() % numberOfsegments + 1;

        sop.sem_num = line;
        sop.sem_op = +0;
        sop.sem_flg = SEM_UNDO;

        cout << "Client # "<< getpid() << " waiting" << endl ;
        semop( sem_id, &sop, 1 );

        cout << "Client # "<< getpid() << " acquired. Round "<< i+1 << " of " << requestPerchild << ". Sleeping" << endl;
        sleep(0.2);
        cout << "Client # "<< getpid() << " releasing" << endl;
        

        //sop.sem_op = 1;
        //semop(sem_id, &sop, 1);
        //semop(sem_id, &sop, 0);
        //
        //cout << "Child finishing" << endl;
        //sop.sem_num = 0;
        //sop.sem_op = -requestPerchild;
        //sop.sem_flg = IPC_NOWAIT;
        //semop(sem_id, &sop, 1);
   
    }

    //double time_taken = ((double)sum_time)/CLOCKS_PER_SEC; // calculate the total elapsed time
    //printf("Child %d waited on average %.15lf seconds for server response\n", getpid(), time_taken/childrequests);
    cout << "Child finishing" << endl;
    sop.sem_num = 0;
    sop.sem_op = +1;
    sop.sem_flg = IPC_NOWAIT;
    semop(sem_id, &sop, 1);


    exit(0);

}
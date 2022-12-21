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

#define CLIENT_PATH_BUFSIZE 255
#define SEM_PERMS (S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP)
#define SEM_KEY_FILE ("sem.key")
#define TEXT_SZ 2048
#define MAX_CHARACTERS_PER_LINE 100


using namespace std;

int main( int argc, char *argv[] ){

    // Get command line arguments from Terminal to set the number of lines in each Sector
    int linenum;
    int counter;
    int childrequests;
    int requests_per_child;
    struct sembuf sop;

    cout << "You have set the number of " << argv << " per sector" << "\n";

    cout << "Program Name Is: " << argv[0] << "\n" << endl;

    if ( argc == 1 ){

        cout << "\nNo Extra Command Line Argument Passed Other Than Program Name"<< endl;

    }

    if ( argc == 5 ){

        cout << "\nNumber Of Arguments Passed: " << argc << endl;
        cout << "\nFollowing Are The Command Line Arguments Passed" << endl;

        for ( counter = 0; counter < argc; counter++ ){

            cout << "\nargv[" << counter << "]: " << argv[counter] << "\n" << endl;

        }

        string linenumstr = argv[1];
        linenum = stoi( linenumstr );
        string requestStr = argv[2];
        string inputFile = argv[3];
        childrequests = stoi( requestStr );
        string requestPerchild = argv[4];
        requests_per_child = stoi ( requestPerchild );
       
        char const *linenum_char = linenumstr.c_str();
        //cout << linenum_char << " linenum_char" << endl;
        char const *request_char = requestStr.c_str();
        //cout << request_char << " request_char" << endl;
        char const *requestPerchild_char = requestPerchild.c_str();
        //cout << requestPerchild_char << "requestPerchild_char" << endl;
        


        // Open the file for reading

        ifstream myfile( inputFile );

        if ( !myfile.is_open() ){

            cout << "Error opening file" << endl;
            return 1;
        
        }

        // Read the file line by line
        string line;
        int lineCount = 0;

        while ( getline( myfile, line ) ){
            // Print the line
            //cout << line << endl;

            // Increment the line count
            lineCount++;

        }

        int number_of_segments;
        if (lineCount % linenum == 0 ){
            number_of_segments = lineCount / linenum;
        }
        else{
            number_of_segments = ( lineCount / linenum ) + 1;
        }
        
        cout << "\nInfo :\n" << endl;
        cout << "The file was set to be splitted in segments of: " << linenum << " lines\n" << endl;
        cout << "File name: " << inputFile << "\n" << endl;
        cout << "Processes set for each child: " << childrequests << "\n" << endl;

        char *shared_memory = (char *)0;
        
        int shmid;
        srand( ( unsigned int ) getpid() );
        shmid = shmget( (key_t)1235, MAX_CHARACTERS_PER_LINE * linenum , 0666 | IPC_CREAT );
        
        if ( shmid == -1 ){

            fprintf( stderr, "shmget failed\n" );
            exit( EXIT_FAILURE );

        }
        
        shared_memory = (char *)shmat( shmid, (void *)0, 0 );
 
        if ( shared_memory == ( void * )-1 ){

            fprintf( stderr, "shmat failed\n" );
            exit( EXIT_FAILURE );
            
        }

        cout << "Shared memory segment with id " << shmid << " attached at shared_memory " << &shared_memory << "\n" << endl;

        pid_t pids[childrequests];

        // Initialize K kids

        key_t sem_key;
        int sem_id;
        int sem_fd;
        char client_exe[CLIENT_PATH_BUFSIZE];
        int dir_len;
        int pid;
        int status;

        sem_key = ftok( SEM_KEY_FILE, 42 );

        // Write the key to a file for children to pick it up
        sem_fd = open( SEM_KEY_FILE, O_WRONLY | O_EXCL | O_CREAT, 0644 );
        
        if ( sem_fd < 0 ){

            perror( "Could not open sem.key" );
            exit(1);

        }

        // Actual write of the key
        if ( write( sem_fd, &sem_key, sizeof( key_t ) ) < 0 ){

            perror( "Could not write key to file" );
            exit(2);

        }

        // Done with the key
        close( sem_fd );

        cout << number_of_segments << " number of segments" << endl;
        
        // Create the semaphore
        sem_id = semget( sem_key, number_of_segments , IPC_CREAT | 0600 );
        //cout << sem_id << endl;

        if ( sem_id < 0 ) {

            perror("Could not create sem");
            unlink(SEM_KEY_FILE);
            exit(3);

        }

        semctl( sem_id, 0, SETVAL, 0 );

        for ( int i = 1; i < number_of_segments + 1; i++) {
                //cout << i << endl;
            if ( semctl( sem_id, 0, SETVAL, 1 ) < 0 ) {
                //cout << i << endl;
                perror("Could not set value of semaphore");
                exit(4);

            }

        }

       std::string number_Of_segments = std::to_string(number_of_segments);
       char const *number_Of_Segments = number_Of_segments.c_str();

        // Now create some clients
        // First create the path to the client exec
        getcwd( client_exe, CLIENT_PATH_BUFSIZE );
        dir_len = strlen( client_exe );
        strcpy( client_exe + dir_len, "/child" );
        cout << "\n" << client_exe << endl;
        for ( int i = 0; i < childrequests; ++i ){
            
            if ( ( pid = fork() ) < 0 ){

                perror( "Could not fork, please create clients manually" );
                
            }
            else if ( pid == 0 ){

                // We're in the child process, start a client
                cout<< "Creating Child" << endl;
                execl( "child", "child", linenum_char, requestPerchild_char, number_Of_Segments , (char *)0 );
                _exit(127);

            }

        }

        cout << "Done creating clients, sleeping for a while" << endl;
        //sleep(1);
        cout << "Increasing sem count\n" << endl;
        // Wait for all children to finish
        int return_code = -1;
        int index = 1;
        int prev_index = 1;

        while( return_code == -1 ){
                     
            sop.sem_num = index;
            sop.sem_op = +1;
            sop.sem_flg = IPC_NOWAIT;
            //cout << "Client # "<< getpid() << " waiting\n" << endl ;
            return_code = semop(sem_id, &sop, 1);
            prev_index = index;
            //cout << index << endl;
            
            if ( index == number_of_segments ){

                index = 1;

            }

            else{

                index++;

            }
            //cout << index << endl;
            sleep(0.2);

            sop.sem_num = prev_index;
            sop.sem_op = -1;
            sop.sem_flg = IPC_NOWAIT;
            //cout << "Client # "<< getpid() << " waiting\n" << endl ;
            return_code = semop(sem_id, &sop, 1);

            //Safe to change shared memory

            sop.sem_num = 0;
            sop.sem_op = -childrequests;
            sop.sem_flg = IPC_NOWAIT;
            //cout << "Client # "<< getpid() << " waiting\n" << endl ;
            return_code = semop(sem_id, &sop, 1);


            // Close the file

        }

        myfile.close();
        exit(0);

    }

    else{

        cout << "\nError! Not corrext number of arguments passed! " << endl;

    }

    return 0;

}
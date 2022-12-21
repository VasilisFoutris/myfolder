#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <iostream>
#include <fstream>
#include <time.h>  

using namespace std;

int open_and_check(){
  ifstream file("new.txt");

  // Check if the file was opened successfully
  if (!file.is_open()) {
    cout << "Failed to open the file!" << endl;
    return 1;
  }

  // Use the file stream as usual
  string line;
  while (getline(file, line)) {
    cout << line << endl;
  }
  // Close the file when we're done with it
  file.close();
  return 0;
}

int make_paragraphs(int linenum){
// Open the file for reading
    ifstream inFile( "new.txt" );
    if ( !inFile.is_open() )
    {
        cout << "Error opening file" << endl;
        return 1;
    }

    // Read the file line by line
    string line;
    int lineCount = 0;
    while ( getline( inFile, line ) ){
        // Print the line
        cout << line << endl;

        // Increment the line count
        lineCount++;

        // If the line count is divisible by 100, insert a new paragraph
        if (lineCount % linenum == 0){
            cout << "\n\n\nNew paragraph here!\n\n\n" << endl;
        }
    }
    int randsect;
    int randline;
    srand (time(NULL));

    randsect = rand() % 100; 
    randline = rand() % 100;

    cout << "Sector: " << randsect << " was randomly selected!\n" << endl;
    cout << "Line: " << randline << " was randomly selected!\n" << endl;
    

    // Close the file
    inFile.close();

    return 0;
}

class line{

  private:
    /* data */
  public:
    
    line(/* args */);
    
    ~line();

};

line::line(/* args */){

}

line::~line(){

}

class sector{

  private:

    /* data */

  public:

    sector(/* args */);

    ~sector();

};

sector::sector(/* args */){
}

sector::~sector(){
}



// πρεπει οι παραγραφοι να αποθηκευονται στη μνημη ετσι ωστε οι 2 rand να ξερουν που απευθυνονται
// δηλαδη πρέπει οταν επιλεγεται τομεας και γραμμη να ρυθμιστει να ναι το σωστο και όχι αν πχ ειναι επιλεγμενος ο τομεας 20 να δειχνει γραμμη απο τον τομεα 0

int main(int argc, char *argv[]){
  int i;
  int seekp;
  int fd;
  char *s1;
  char s2[1000];

  int linenum;
  //Get command line arguments from Terminal to set the number of lines in each Sector
  cout << "You have set the number of " << argv << " per sector" << "\n";
  
  int counter;
  printf("Program Name Is: %s",argv[0]);

  if ( argc == 1 )
      printf( "\nNo Extra Command Line Argument Passed Other Than Program Name" );

  if ( argc >= 2 ){

      printf( "\nNumber Of Arguments Passed: %d", argc );
      printf( "\n----Following Are The Command Line Arguments Passed----" );

      for( counter = 0; counter < argc; counter++ ){

        printf( "\n argv[%d]: %s", counter, argv[counter] );

      }

  }

    string str = argv[1];   
    linenum = stoi(str);

  //cout << argv[i] << "\n" << endl;  
    

   /* Open a file for writing, and then call fork(). */
  //open_and_check();

  make_paragraphs(linenum);
  fd = open("example.txt", O_WRONLY | O_TRUNC | O_CREAT, 0666);
  s1 = "Before forking\n";
  write(fd, s1, strlen(s1));
  i = fork();
  printf("My pid = %d.  My parent's pid = %d\n", getpid(), getppid());
  return 0;
  
}
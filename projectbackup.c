#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>


// TOREMOVE == Marking lines for debugging
// TODO == Does this need to be explained?

// defining size of chrachter array for files
#define Estfilesize 10000

#define Crontabsize 10000
#define Crontablen 1000

int main(int argcount, char argvalue[]) {

  // checking to see we have the correct number of arguments (debuggin bs)
  printf("argument count: %d\n", argcount); 
  if (argcount > 4){
    printf("Error, too many arguments\n");
    exit(EXIT_FAILURE);
  }
  else if (argcount < 4) {
    printf("Error, not enough arguments\n");
    exit(EXIT_FAILURE);
  }
  char estfile[] = argvalue[3];
  char month[] = argvalue[1];
  char Crontab[] = argvalue[2];
  error_check(Crontab);
  error_check(estfile);
   
  exit(EXIT_SUCCESS);
}


//**CURRENTLY DOESN'T WORK, NEED TO FIGURE OUT WHY AND HOW TO GET IT TO WORK
void error_check(char filename[]) {
  // opening file of name passed via parameter of filename
  

  if (file == NULL) {
    printf("Cannot open '%S'\n", file);
    exit(EXIT_FAILURE);
  }
}

// use with if statment for if it's the string version, we'll relie on string
// version for this stuff I rekon


void reading_Estfil(char estfile) {
  // TODO
  printf("Reading estfil...");

	
}
//just did some file error and opening stuff. converted it into an array of string
void reading_Crontabfile(char Crontab) {
  // TODO
  printf("ReadingContabfile");
}


//setup counter maybe in the reading function or possibly its own function
//deciding which is less messy
//thiking of making an array for the counter, so we can use a for loop possibly to determine which one occured the most
//may be easier way not too sure
//not too sure how to determine max no. of commands running at any time

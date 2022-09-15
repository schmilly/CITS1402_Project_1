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

//**CURRENTLY DOESN'T WORK, NEED TO FIGURE OUT WHY AND HOW TO GET IT TO WORK
void error_check(char *filename) {
  // opening file of name passed via parameter of filename
  printf("Checking that %s actually exists\n", filename);
  int file = open(filename, O_RDONLY);
  if (file == -1) {
    printf("Cannot open %s\n", file);
    exit(EXIT_FAILURE);
  }
  prinf("File Found!");
  //TODO fix this so it doesn't core dump or seg faults
  //every time it trys to read a file that doesn't exist
}

// use with if statment for if it's the string version, we'll relie on string
// version for this stuff I rekon


void reading_Estfil(char estfile) {
  // TODO
  printf("Reading estfil...");

	
}
//just did some file error and opening stuff. converted it into an array of string
void reading_CrONTABfile(char Crontab) {
  // TODO
  char data[Crontabsize][Crontablen];

  FILE *file;

  file = fopen("file.txt", "r");

  if (file == NULL)
  {
	  printf("Error opening file.\n");
	  exit(EXIT_FAILURE);
  }

  int line = 0;

  while(!feof(file) && ferror(file))
	  if(fgets(data[line], Crontablen, file) != NULL)
		  line++;
  fclose(file);

  for (int i = 0; i < line; i++)
	  printf("%s", data[i]);
}


//setup counter maybe in the reading function or possibly its own function
//deciding which is less messy
//thiking of making an array for the counter, so we can use a for loop possibly to determine which one occured the most
//may be easier way not too sure
//not too sure how to determine max no. of commands running at any time


//Main function goes here or c compiler yells at me :((
int main(int argcount, char *argvalue[]) {

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
  printf("%s\n", argvalue[2]);
  char *estfile = argvalue[3];
  char *month = argvalue[1];
  char *Crontab = argvalue[2];
  printf("Sucesfully assigned Terminal arguments; moving on...\n"); //TOREMOVE
  error_check(Crontab);
  error_check(estfile);
   
  exit(EXIT_SUCCESS);
}

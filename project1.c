#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// defining size of chrachter array for files
#define Estfilesize 10000
#define Crontabsize 10000

//**CURRENTLY DOESN'T WORK, NEED TO FIGURE OUT WHY AND HOW TO GET IT TO WORK
void error_check(char filename) {
  // opening file of name passed via parameter of filename
  int file = open(filename, O_RDONLY);
  if (file == -1) {
    printf("Cannot open '%S'\n", filename);
    exit(EXIT_FAILURE);
  }
}

// use with if statment for if it's the string version, we'll relie on string
// version for this stuff I rekon
void which_month(char month) {
  // TODO
}

void reading_Estfil(char estfile) {
  // TODO
  char buffer[Estfilesize];
}

void reading_CrONTABfile(char Crontab) {
  // TODO
  char buffer[Crontabsize];
}

//*****MAIN FUNCTION V. IMPORTANT HOPEFLY THIS HELPS U FIND*****
int main(int argcount, char *argvalue[]) {
  // defining parameters to pass to functions
  if (argcount > 3) {
    printf("Error, too many arguments");
    exit(EXIT_FAILURE);
  }
  if (argcount < 3) {
    printf("Error, not enough arguments");
    exit(EXIT_FAILURE);
  }

  char month = atof(argvalue[1]);
  char Crontab = atof(argvalue[2]);
  char estfile = atof(argvalue[3]);

  error_check(Crontab);
  error_check(estfile);

  exit(EXIT_SUCCESS);
}

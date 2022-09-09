#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// defining size of chrachter array for files
#define Estfilesize 10000
#define Crontabsize 10000

void error_check(char filename) {
  // opening file of name passed via parameter of filename
  int file = open(filename, O_RDONLY);
  if (file == -1) {
    printf("Cannot open '%S'\n", filename);
    exit(EXIT_FAILURE);
  }
}

void reading_Estfil(char estfile) {
  // TO DO
  char buffer[Estfilesize];
}

void reading_CrONTABfile(char Crontab) {
  // TO DO
  char buffer[Crontabsize];
}

int main(int argcount, char *argvalue[]) {
  // MAIN THINGY
  // defining parameters to pass to functions
  char month = atof(argvalue[1]);
  char Crontab = atof(argvalue[2]);
  char estfile = atof(argvalue[3]);

  error_check(Crontab);
  error_check(estfile);

  exit(EXIT_SUCCESS);
}

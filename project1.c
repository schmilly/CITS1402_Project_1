#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <string.h>

// TOREMOVE == Marking lines for debugging
// TODO == Does this need to be explained?

// defining size of chrachter array for files
#define filesize 10000
#define Crontablen 1000
void error_check(char *filename) {
  // opening file of name passed via parameter of filename
  printf("Attempting to check %s actually exists\n", filename);
  int file = open(filename, O_RDONLY);
  if (file == -1) {
    printf("Cannot open %s\n", file);
    exit(EXIT_FAILURE);
  }
  printf("File Found!\n");
  //TODO fix this so it doesn't core dump or seg faults
  //every time it trys to read a file that doesn't exist
}

char reading_file(char *filename) {
  // TODO
  printf("Reading file %s\n", filename);
  FILE *file = fopen(filename, "r");
  if (file == NULL) {
    printf("cannot open %s\n", filename);
    exit(EXIT_FAILURE);
  }

  printf("File sucesfully opened \n");
  // fseek(file, 0L, SEEK_END);
  // int sz = ftell(*file);
  // printf("file size is: %s\n",sz);
  
  int i;
  int x;
  char Filearray[filesize];
  //File read loop
  while((i = fgetc(file)) != EOF) {
    i = Filearray[x];
    printf("%s|",x);
    printf("%d|",i);
    x++;
  }
  return Filearray; 
}

//This is where the month conversion function would go but still broken so idk

void argumentcheck(int argcount){
  if (argcount > 4){
    printf("Error, too many arguments\n");
    exit(EXIT_FAILURE);
  }
  else if (argcount < 4) {
    printf("Error, not enough arguments\n");
    exit(EXIT_FAILURE);
  }
}

//Main function goes here or c compiler yells at me :((
int main(int argcount, char *argvalue[]) {
  printf("Spinning up program now!\n");
  
  //Converted to function for sake of it looking nicer
  argumentcheck(argcount);

  char *estfile = argvalue[3];
  char *month = argvalue[1];
  char *Crontab = argvalue[2];
  printf("Sucesfully assigned Terminal arguments; moving on...\n"); //toremove, user doesn't care
  //Error Checking of files
  error_check(Crontab);
  error_check(estfile);
  printf("All files exist; moving on....\n");
  //Reading files specifically

  char cronout = reading_file(Crontab);
  char estout = reading_file(estfile);
  exit(EXIT_SUCCESS);
}

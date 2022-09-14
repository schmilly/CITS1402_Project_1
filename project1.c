#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// defining size of chrachter array for files
#define Estfilesize 10000

#define Crontabsize 10000
#define Crontablen 1000

//**CURRENTLY DOESN'T WORK, NEED TO FIGURE OUT WHY AND HOW TO GET IT TO WORK
void error_check(char *file[]) {
  // opening file of name passed via parameter of filename
  if (file == NULL) {
    printf("Cannot open '%S'\n", file);
    exit(EXIT_FAILURE);
  }
}

// use with if statment for if it's the string version, we'll relie on string
// version for this stuff I rekon
void which_month(char month) {
  // TODO
  
	int daysinmonth = 0;
	int monthNum = 0;
	switch (month) {
		case "jan":
			daysinmonth = 31;
			monthNum = 1;
			break;
		case "feb":
			daysinmonth = 28;
			monthNum = 2;
			break;
		case "mar":
			daysinmonth = 31;
			monthNum = 3;
			break;
		case "apr":
			daysinmonth = 30;
			monthNum = 4;
			break;
		case "may":
			daysinmonth = 31;
			monthNum = 5;
			break;
		case "jun":
			daysinmonth = 30;
			monthNum = 6;
			break;
		case "jul":
			daysinmonth = 31;
			monthNum = 7;
			break;
		case "aug":
			daysinmonth = 31;
			monthNum = 8;
			break;
		case "sep":
			daysinmonth = 30;
			monthNum = 9;
			break;
		case "oct":
			daysinmonth = 31;
			monthNum = 10;
			break;
		case "nov":
			daysinmonth = 30;
			monthNum = 11;
			break;
		case "dec":
			daysinmonth = 31;
			monthNum = 12;
			break;



}


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



//*****MAIN FUNCTION V. IMPORTANT HOPEFLY THIS HELPS U FIND*****
int main(int argcount, char **argvalue) {
  // defining parameters to pass to functions
  if (argcount > 3) {
    printf("Error, too many arguments");
    exit(EXIT_FAILURE);
  }
  if (argcount < 3) {
    printf("Error, not enough arguments");
    exit(EXIT_FAILURE);
  }
  
  FILE *f = fopen(argvalue[3], "r");
  char month = atof(argvalue[1]);
  char Crontab = atof(argvalue[2]);

  error_check(Crontab);
  error_check(estfile);

  exit(EXIT_SUCCESS);
}

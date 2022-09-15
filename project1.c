#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <string.h>


// CITS2002 Project 1 2022
// Student1: 
// Student2: 22902133 JIOW JOSHUA


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
<<<<<<< HEAD
  char data[Crontabsize][Crontablen];

  FILE *file;

  file = fopen(Crontab, "r");

  if (file == NULL)
  {
	  printf("Error opening file.\n");
	  exit(EXIT_FAILURE);
  }

  int line = 0;

//use to find out wat each line is
  char daily = "daily-backup";
  char weekly = "weekly-backup";
  char deep = "deep_thought";
  char submit = "submit-project";
  char send = "send-monthly-newsletter";

//count use to find out the most used command

  int dailyCount = 0;
  int weeklyCount = 0;
  int deepCount = 0;
  int submitCount = 0;
  int sendCount= 0;


  while(!feof(file) && ferror(file)){
	  if(fgets(data[line], Crontablen, file) != NULL){
		  line++;
		  fclose(file);
	  }
  }

//calcs and everything start here

  for(int i = 0; i < line; i++){
	  if(strstr(i, daily)){
		  dailyCount++;
	  }
	  else if(strstr(i, weekly)){
		  weeklyCount++;
	  }
	  else if(strstr(i, deep)){
		  deepCount++;
	  }
	  else if(strstr(i, submit)){
		  submitCount++;
	  }
	  else if(strstr(i, send)){
		  sendCount++;
	  }

  }

//calculate the most called command

int d_or_w_max = max(dailyCount, weeklyCount);
int d_or_s_max = max(deepCount, submitCount);
int second_max = max(d_or_w_max, d_or_s_max);
int most_called = max(second_max, sendCount);

//total amount of commands

int total_commands = 0;
int total_commands = dailyCount + weeklyCount + deepCount + submitCount + sendCount;



=======
  printf("ReadingContabfile");
>>>>>>> ca461935e8a987d2a050693ea4ed4836b980e751
}



//little funciton to find max value

int max(int x, int y){
	if(x > y){
		return x;
	}
	else{
		return y;
	}
}


//setup counter maybe in the reading function or possibly its own function
//deciding which is less messy
//thiking of making an array for the counter, so we can use a for loop possibly to determine which one occured the most
//may be easier way not too sure
//not too sure how to determine max no. of commands running at any time

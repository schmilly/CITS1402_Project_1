#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
https://github.com/schmilly/CITS1402_Project_1/pull/1/conflicts#include <unistd.h>
#include <ctype.h>



#include <time.h>
#include <string.h>

// CITS2002 Project 1 2022
// Student1: 
// Student2: 22902133 JIOW JOSHUA



// TOREMOVE == Marking lines for debugging
// TODO == Does this need to be explained?

// defining size of chrachter array for files
#define filesize 10000
#define Crontablen 1000

void fileprocess(char *line, char estcron){
  printf("Processing file!");
  //todo
}
void reading_file(char *filename, char estcron) {
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
  
  int i = 0;
  char Line[100];
  //File read loop
  while ( fgets(Line, sizeof Line, file)){
    trim_line( Line );
    fileprocess( Line, estcron);
  } 


// Yonked from FileIO lecture (very useful thanks)
void trim_line(char line[])
{
    int i = 0;

//  LOOP UNTIL WE REACH THE END OF line
    while(line[i] != '\0') {

//  CHECK FOR CARRIAGE-RETURN OR NEWLINE
        if( line[i] == '\r' || line[i] == '\n' ) {
            line[i] = '\0'; // overwrite with nul-byte
            break;          // leave the loop early
        }
        i = i+1;            // iterate through character array
    }
}

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

void reading_Estfil(char estfile) {
  // TODO
  printf("Reading estfil...");

	
}
//just did some file error and opening stuff. converted it into an array of string
void reading_Crontabfile(char Crontab) {
  // TODO
  char data[Crontabsize][Crontablen];

  FILE *file;

  file = fopen(Crontab, "r");

  if (file == NULL)
  {
	  printf("Error opening file.\n");
	  exit(EXIT_FAILURE);
  }

  int line = 0;

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
//the mains stuffs
  for(int i = 0; i < line: i++){
	  for(int j = 0; j < Crontablen, j++){
		  if(data[0][6] == "*" || data[0][6] == monthNum){	

			  //daily count
			  if(data[0][0] == "*" && data[0][2] == "*"){
			  	dailyCount = 1440 * daysinmonth;
			  }
			  else if(data[0][0] == "*" && data[0][2] != "*"){
				dailyCount = (24 - (data[0][2])-1) * 60 * daysinmonth;
			}
			else if(data[0][0] != "*" && data[0][2] == "*"){
				dailyCount = 24 * daysinmonth;
			}
			else if(data[0][0] != "*" && data[0][2] != "*"){
				dailyCount = (24 - (data[0][2])-1) * daysinmonth;
			}

		  }
		  //weekly
		  if (data[1][6] == "*" || data[1][6] == monthNum){

		  }
		  //deepthought
		  if(data[2][6] == "*" || data [2][6] == monthNum){

		  }
		  //submit-project
		  if(data[3][6] == "*" || data[3][6] == monthNum){

		  }
		  //send-monthly
		  if(data[4][6] == "*" || data[4][6] == monthNum){
			  sendCount = 1;
		  }
	  }

  }

//calculate the most called command
//just did ladder, required less lines
//most likely make it its own function
char most_called_command[]
	if(dailyCount > weeklyCount && dailyCount > deepCount && dailyCount > submitCount && dailyCount > sendCount){
		most_called_command = "daily-backup";
	}
	else if(weeklyCount > dailyCount && weeklyCount > deepCount && weeklyCount > submitCount && weeklyCount > sendCount){
		most_called_command = "weekly-backup";
	}

	else if(deepCount > dailyCount && deepCount > weeklyCount && deepCount > submitCount && deepCount > sendCount){
		most_called_command = "deep-thought";
	}
	else if(submitCount > dailyCount && submitCount > weeklyCount && submitCount> deepCount && submitCount > sendCount){
		most_called_command = "submit_project";
	}
	else{
		most_called_command = "send-monthly-newsletter";
	}




//total amount of commands
//can make its own function, but kinda of small so not required
int total_commands = 0;
int total_commands = dailyCount + weeklyCount + deepCount + submitCount + sendCount;



  printf("ReadingContabfile");
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


  reading_file(Crontab, "cron");
  reading_file(estfile, "est");
  exit(EXIT_SUCCESS);
}

//printf(most frequent command executed, total num of commands invoked, maximum num of commands running);
 

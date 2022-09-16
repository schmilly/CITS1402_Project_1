#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <time.h>


// CITS2002 Project 1 2022
// Student1: 23086983 WILLIAM VAN DEN WALL BAKE
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



=======
  printf("ReadingContabfile");
>>>>>>> ca461935e8a987d2a050693ea4ed4836b980e751
}






//printf(most frequent command executed, total num of commands invoked, maximum num of commands running);
